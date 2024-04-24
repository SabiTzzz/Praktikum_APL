#include <iostream>
#include <conio.h>
using namespace std;

string user = "Muhammad Arya Fayyadh Razan";
string pass = "2309106010";
string *userPtr = &user;
string *passPtr = &pass;

void clears() {
    system("cls");
}

struct detail {
    string tipe;
    string nama;
    double harga;
};

struct merchandise {
    detail barang;
};

merchandise merchand[32];
int jumlahdata = 0;
bool tipesorted = false;
bool namasorted = false;

bool login(string *userPtr, string *passPtr, int coba = 0) {
    if (coba == 3) {
        cout << "(!) Anda telah melewati batas percobaan, program berhenti.";
        return false;
    }

    string nama, nim;
    cout << "[  Menu Login  ]" << endl;
    cout << "Nama : ";
    getline(cin, nama);
    cout << "NIM  : ";
    getline(cin, nim);

    if (nama == *userPtr && nim == *passPtr) {
        cout << "\nLogin berhasil!";
        cout << "\nHalo, " << nama << "!" << endl;
        cout << "\n";
        cout << "=================================" << endl;
        return true;
    } else {
        int percobaan = 2 - coba;
        cout << "\n(!) Login gagal, Nama atau NIM yang anda masukkan salah." << endl;
        if (coba != 2) {
            cout << "(!) Sisa percobaan anda " << percobaan << " kali lagi.\n" << endl;
        }
        return login(userPtr, passPtr, coba + 1);
    }
}

void bubblesort_tipeascend(merchandise merchand[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (merchand[j].barang.tipe > merchand[j + 1].barang.tipe) {
                swap(merchand[j], merchand[j + 1]);
            }
        }
    }
}

void selectionsort_namadescend(merchandise merchand[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (merchand[j].barang.nama > merchand[maxIndex].barang.nama) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(merchand[i], merchand[maxIndex]);
        }
    }
}

void merge(merchandise merchand[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    merchandise leftmerchand[n1], rightmerchand[n2];

    for (int i = 0; i < n1; i++) {
        leftmerchand[i] = merchand[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightmerchand[j] = merchand[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftmerchand[i].barang.harga <= rightmerchand[j].barang.harga) {
            merchand[k] = leftmerchand[i];
            i++;
        } else {
            merchand[k] = rightmerchand[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        merchand[k] = leftmerchand[i];
        i++;
        k++;
    }

    while (j < n2) {
        merchand[k] = rightmerchand[j];
        j++;
        k++;
    }
}

void mergesort_hargaascend(merchandise merchand[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort_hargaascend(merchand, left, mid);
        mergesort_hargaascend(merchand, mid + 1, right);
        merge(merchand, left, mid, right);
    }
}

void sort(merchandise merchand[], int jumlahdata) {
    string sorting;

    cout << "Apakah ingin sorting data? ([Enter] untuk ya, key apa saja untuk tidak) : ";
    getline(cin, sorting);
    if (sorting == "") {
        cout << "Sorting berdasarkan:" << endl;
        cout << "1. Tipe barang (Ascending)" << endl;
        cout << "2. Nama barang (Descending)" << endl;
        cout << "3. Harga barang (Ascending)" << endl;
        cout << "Pilih sort (1/2/3): ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();
        if (!cin || pilihan == 0 || pilihan < 0) {
            cout << "(!) pilihan tidak valid!" << endl;
            cin.clear();
            cin.ignore();
            return;
        } else {
            if (pilihan == 1) {
                bubblesort_tipeascend(merchand, jumlahdata);
                tipesorted = true;
            } else if (pilihan == 2) {
                selectionsort_namadescend(merchand, jumlahdata);
                namasorted = true;
            } else if (pilihan == 3) {
                mergesort_hargaascend(merchand, 0, jumlahdata - 1);
            } else {
                cout << "(!) Pilihan tidak valid!" << endl;
                return;
            }
        }
    } 
    else {
        return;
    }
}

void binarysearch_tipe(merchandise merchand[], int jumlahdata) {
    string cari;
    cout << "Masukkan tipe barang yang ingin dicari : ";
    getline(cin, cari);
    if (cari == "") {
        cout << "(!) Tipe barang tidak boleh kosong!" << endl;
        return;
    }
    for (char &c : cari) {
        c = toupper(c);
    }
    for (int i = 0; i < jumlahdata; ++i) {
        string& tipe = merchand[i].barang.tipe;
        for (char &c : tipe) {
            c = toupper(c);
        }
    }
    bool found = false;
    cout << "Data ditemukan!" << endl;
    cout << "Data dengan tipe barang \"" << cari << "\" adalah:" << endl;
    for (int i = 0; i < jumlahdata; ++i) {
        if (merchand[i].barang.tipe == cari) {
            cout << "\nData ke-" << i + 1 << endl;
            cout << "Tipe barang : " << merchand[i].barang.tipe << endl;
            cout << "Nama barang : " << merchand[i].barang.nama << endl;
            cout << "Harga barang : Rp." << merchand[i].barang.harga << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "(!) Data barang dengan \"" << cari << "\" tidak ditemukan" << endl;
    }
}

void sequentialsearch_nama(merchandise merchand[], int jumlahdata) {
    string cari;
    cout << "Masukkan nama barang yang ingin dicari : ";
    getline(cin, cari);
    if (cari == "") {
        cout << "(!) Nama barang tidak boleh kosong!" << endl;
        return;
    }
    for (char &c : cari) {
        c = toupper(c);
    }
    for (int i = 0; i < jumlahdata; ++i) {
        string& tipe = merchand[i].barang.nama;
        for (char &c : tipe) {
            c = toupper(c);
        }
    }
    bool found = false;
    for (int i = 0; i < jumlahdata; i++) {
        if (merchand[i].barang.nama == cari) {
            cout << "Data ditemukan!" << endl;
            cout << "Data ke-" << i + 1 << endl;
            cout << "Tipe barang : " << merchand[i].barang.tipe << endl;
            cout << "Nama barang : " << merchand[i].barang.nama << endl;
            cout << "Harga barang : Rp." << merchand[i].barang.harga << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "(!) Data barang dengan nama \"" << cari << "\" tidak ditemukan" << endl;
    }
}

bool tambah(merchandise merchand[], int &jumlahdata) {
    cout << "Tambah data merchandise" << endl;
    if (jumlahdata >= 32) {
        cout << "(!) Data sudah penuh, hubungi Arya." << endl;
        return false;
    } else {
        while (true) {
            string tipebrg, namabrg;
            double hargabrg;
            int tipenya;
            cout << "Tipe barang :\n";
            cout << "1. JERSEY\n";
            cout << "2. APPAREL\n";
            cout << "3. AKSESORIS\n";
            cout << "Pilih tipe barang (1/2/3): ";
            cin >> tipenya;
            cin.ignore();
            if (!cin || tipenya == 0 || tipenya < 0) {
                cout << "(!) Tipe tidak valid!" << endl;
                cin.clear();
                cin.ignore();
                return false;
            }

            switch (tipenya) {
            case 1:
                tipebrg = "JERSEY";
                break;
            case 2:
                tipebrg = "APPAREL";
                break;
            case 3:
                tipebrg = "AKSESORIS";
                break;
            default:
                cout << "(!) Pilihan tidak valid!" << endl;
                return false;
            }

            cout << "Nama barang : ";
            getline(cin, namabrg);
            if (namabrg == "") {
                cout << "(!) Nama barang tidak valid" << endl;
                return false;
            }
            // membuat inputan nama barang menjadi huruf kapital semua
            for (int i = 0; i < namabrg.length(); i++) {
                if (namabrg[i] >= 'a' && namabrg[i] <= 'z') {
                    namabrg[i] = namabrg[i] - 32;
                }
            }
            cout << "Harga barang : Rp.";
            cin >> hargabrg;
            if (hargabrg == 0 || hargabrg < 0 || !cin) {
                cout << "(!) Harga barang tidak valid!" << endl;
                cin.clear();
                cin.ignore();
                return false;
            }

            merchand[jumlahdata].barang.tipe = tipebrg;
            merchand[jumlahdata].barang.nama = namabrg;
            merchand[jumlahdata].barang.harga = hargabrg;

            jumlahdata++;
            cout << "Data berhasil ditambahkan!" << endl;
            cout << "\n";

            string lanjut;
            cout << "Tekan [Enter] untuk melanjutkan... (Atau key apa saja untuk ke menu utama)";
            cin.ignore();
            getline(cin, lanjut);
            if (lanjut == "") {
                cout << "\n";
                cout << "============================================================================" << endl;
                cout << "\n";
                continue;
            } else {
                clears();
                break;
            }
        }
        return true;
    }
}

void tampilkan(merchandise merchand[]) {
    if (jumlahdata == 0) {
        cout << "Data masih kosong." << endl;
    } else {
        sort(merchand, jumlahdata);
        cout << "Data merchandise yang tersimpan:" << endl;
        for (int i = 0; i < jumlahdata; i++) {
            cout << "\nData ke-" << i + 1 << endl;
            cout << "Tipe barang : " << merchand[i].barang.tipe << endl;
            cout << "Nama barang : " << merchand[i].barang.nama << endl;
            cout << "Harga barang : Rp." << merchand[i].barang.harga << endl;
        }
    }
}

bool ubah(merchandise merchand[], int &jumlahdata) {
    if (jumlahdata == 0) {
        cout << "Data masih kosong." << endl;
        return false;
    }
    else {
        while (true) {
            cout << "Data merchandise yang tersimpan:" << endl;
            for (int i = 0; i < jumlahdata; i++) {
                cout << "\nData ke-" << i + 1 << endl;
                cout << "Tipe barang : " << merchand[i].barang.tipe << endl;
                cout << "Nama barang : " << merchand[i].barang.nama << endl;
                cout << "Harga barang : Rp." << merchand[i].barang.harga << endl;
            }
            cout << "\nPilih nomor data yang ingin diubah : ";
            int pilihan;
            cin >> pilihan;
            cin.ignore();
            if (!cin || pilihan == 0 || pilihan < 0 || pilihan > jumlahdata) {
                cout << "(!) Pilihan tidak valid!" << endl;
                cin.clear();
                cin.ignore();
                return false;
            }
            else {
                string tipebrg, namabrg;
                double hargabrg;
                int tipenya;
                cout << "[Ubah data merchandise]" << endl;
                cout << "Tipe barang :\n";
                cout << "1. JERSEY\n";
                cout << "2. APPAREL\n";
                cout << "3. AKSESORIS\n";
                cout << "Pilih tipe barang (1/2/3): ";
                cin >> tipenya;
                cin.ignore();
                if (!cin || tipenya == 0 || tipenya < 0) {
                    cout << "(!) Tipe tidak valid!" << endl;
                    cin.clear();
                    cin.ignore();
                    return false;
                }

                switch (tipenya) {
                    case 1:
                        tipebrg = "JERSEY";
                        break;
                    case 2:
                        tipebrg = "APPAREL";
                        break;
                    case 3:
                        tipebrg = "AKSESORIS";
                        break;
                    default:
                        cout << "(!) Pilihan tidak valid!" << endl;
                        return false;
                }

                cout << "Nama barang : ";
                getline(cin, namabrg);
                if (namabrg == "") {
                    cout << "(!) Nama barang tidak boleh kosong!" << endl;
                    return false;
                }
                cout << "Harga barang : Rp.";
                cin >> hargabrg;
                if (hargabrg == 0 || hargabrg < 0 || !cin) {
                    cout << "(!) Harga barang invalid!" << endl;
                    cin.clear();
                    cin.ignore();
                    return false;
                }

                merchand[pilihan-1].barang.tipe = tipebrg;
                merchand[pilihan-1].barang.nama = namabrg;
                merchand[pilihan-1].barang.harga = hargabrg;

                cout << "Data berhasil diubah!" << endl;
                cout << "\n";
                cout << "Tekan [Enter] untuk melanjutkan... (Atau key apa saja untuk ke menu utama)";
                string lanjut;
                cin.ignore();
                getline(cin, lanjut);
                if (lanjut == "") {
                    cout << "\n";
                    cout << "============================================================================" << endl;
                    cout << "\n";
                    continue;
                }
                else {
                    clears();
                    break;
                }
            }
        }
        return true;
    }       
}

bool hapus(merchandise merchand[], int &jumlahdata) {
    if (jumlahdata == 0) {
        cout << "Data masih kosong." << endl;
        return false;
    }
    else {
        while (true) {
            cout << "Data merchandise yang tersimpan:" << endl;
            for (int i = 0; i < jumlahdata; i++) {
                cout << "\nData ke-" << i + 1 << endl;
                cout << "Tipe barang : " << merchand[i].barang.tipe << endl;
                cout << "Nama barang : " << merchand[i].barang.nama << endl;
                cout << "Harga barang : Rp." << merchand[i].barang.harga << endl;
            }
            cout << "\nPilih nomor data yang ingin dihapus : ";
            int pilihan;
            cin >> pilihan;
            cin.ignore();
            if (!cin || pilihan == 0 || pilihan < 0 || pilihan > jumlahdata) {
                cout << "(!) Pilihan tidak valid!" << endl;
                cin.clear();
                cin.ignore();
                return false;
            }
            else {
                cout << "\nData yang dihapus:" << endl;
                cout << "Tipe barang : " << merchand[pilihan - 1].barang.tipe << endl;
                cout << "Nama barang : " << merchand[pilihan - 1].barang.nama << endl;
                cout << "Harga barang : " << merchand[pilihan - 1].barang.harga << endl;

                for (int i = pilihan - 1; i < jumlahdata - 1; i++) {
                    merchand[i] = merchand[i + 1];
                }
                jumlahdata--;

                cout << "Data berhasil dihapus!" << endl;
                cout << "\n";

                cout << "Tekan [Enter] untuk melanjutkan... (Atau key apa saja untuk ke menu utama)";
                string lanjut;
                getline(cin, lanjut);
                if (lanjut == "") {
                    cout << "\n";
                    cout << "============================================================================" << endl;
                    cout << "\n";
                    continue;
                }
                else {
                    clears();
                    break;
                }
            }
        }
        return true;
    }
}

void menu();
void cari(merchandise merchand[], int jumlahdata) {
    if (jumlahdata == 0) {
        cout << "Data masih kosong." << endl;
    }
    else {
        cout << "Cari data merchandise :" << endl;
        cout << "1. Berdasarkan tipe barang" << endl;
        cout << "2. Berdasarkan nama barang" << endl;
        cout << "Pilih menu (1/2): ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();
        if (!cin || pilihan == 0 || pilihan < 0) {
            cout << "(!) pilihan tidak valid!" << endl;
            cin.clear();
            cin.ignore();
            return;
        }
        else {
            if (pilihan == 1) {
                if (tipesorted == false) {
                    bubblesort_tipeascend(merchand, jumlahdata);
                    binarysearch_tipe(merchand, jumlahdata);
                }
                else {
                    binarysearch_tipe(merchand, jumlahdata);
                }
                cout << "\n";
                string lanjut;
                cout << "Tekan [Enter] untuk ke menu utama...";
                getch();
                clears();
                menu();
            }
            else if (pilihan == 2) {
                if (namasorted == false) {
                    selectionsort_namadescend(merchand, jumlahdata);
                    sequentialsearch_nama(merchand, jumlahdata);
                }
                else {
                    sequentialsearch_nama(merchand, jumlahdata);
                }
                cout << "\n";
                string lanjut;
                cout << "Tekan [Enter] untuk ke menu utama...";
                getch();
                clears();
                menu();
            }
            else {
                cout << "(!) Pilihan tidak valid!" << endl;
            }
        }
    }
}

void menu() {
    string pilihan;
    cout << "\n";
    cout << "   Merchandise Borneo FC\n"
            << "[1] Tambah data merchandise\n"
            << "[2] Tampilkan data merchandise\n"
            << "[3] Ubah data merchandise\n"
            << "[4] Hapus data merchandise\n"
            << "[5] Cari data merchandise\n"
            << "[0] Keluar\n"
            << "Pilih menu (1/2/3/4/0): ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == "1") {
        clears();
        tambah(merchand, jumlahdata);
        menu();
    }
    else if (pilihan == "2") {
        clears();
        tampilkan(merchand);
        cout << "\n";
        string lanjut;
        cout << "Tekan [Enter] untuk ke menu utama...";
        getch();
        clears();
        menu();
    }
    else if (pilihan == "3") {
        clears();
        ubah(merchand, jumlahdata);
        menu();
    }   
    else if (pilihan == "4") {
        clears();
        hapus(merchand, jumlahdata);
        menu();
    }
    else if (pilihan == "5") {
        clears();
        cari(merchand, jumlahdata);
        menu();
    }
    else if (pilihan == "0") {
        cout << "Terima Kasih & Sampai Jumpa!" << endl;
    }
    else {
        cout << "(!) Pilihan tidak valid!" << endl;
        menu(); 
    }

}

int main() {
    
    merchand[0].barang.tipe = "JERSEY";
    merchand[0].barang.nama = "JERSEY HOME BORNEO FC";
    merchand[0].barang.harga = 450000;

    merchand[1].barang.tipe = "JERSEY";
    merchand[1].barang.nama = "JERSEY AWAY BORNEO FC";
    merchand[1].barang.harga = 450000;

    merchand[2].barang.tipe = "JERSEY";
    merchand[2].barang.nama = "JERSEY THIRD BORNEO FC";
    merchand[2].barang.harga = 450000;

    merchand[3].barang.tipe = "APPAREL";
    merchand[3].barang.nama = "T-SHIRT BORNEO TYPE FONT BLACK";
    merchand[3].barang.harga = 140000;

    merchand[4].barang.tipe = "APPAREL";
    merchand[4].barang.nama = "JAKET COACH MANYALA";
    merchand[4].barang.harga = 450000;

    merchand[5].barang.tipe = "AKSESORIS";
    merchand[5].barang.nama = "SCARF HITAM BORNEO FC";
    merchand[5].barang.harga = 220000;

    jumlahdata = 5;
    
    clears();
    if (login(userPtr, passPtr) == true) {
        menu();
    }
    else {
        return 0;
    }
}