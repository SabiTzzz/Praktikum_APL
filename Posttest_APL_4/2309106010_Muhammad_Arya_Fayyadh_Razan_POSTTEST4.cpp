#include <iostream>
#include <conio.h>
using namespace std;

string user = "Muhammad Arya Fayyadh Razan";
string pass = "2309106010";

void clears() {
    system("cls");
}

struct detail {
    string tipe;
    string nama;
    double harga;
};

struct merchandise {
    detail barang[32];
};

merchandise merchand;
int jumlahdata = 0;

bool login(int coba = 0) {
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

    if (nama == user && nim == pass) {
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
        return login(coba + 1);
    }
}

bool tambah() {
    cout << "Tambah data merchandise" << endl;
    if (jumlahdata >= 32) {
        cout << "(!) Data sudah penuh, hubungi Arya." << endl;
        return false;
    }
    else {
        while (true) {
            string tipebrg, namabrg;
            double hargabrg;
            int tipenya;
            cout << "Tipe barang :\n";
            cout << "1. Jersey\n";
            cout << "2. Apparel\n";
            cout << "3. Aksesoris\n";
            cout << "Pilih tipe barang (1/2/3): ";
            cin >> tipenya;
            cin.ignore();
            if (!cin || tipenya == 0 || tipenya < 0 || tipenya > jumlahdata) {
                cout << "(!) Tipe tidak valid!" << endl;
                cin.clear();
                cin.ignore();
                return false;
            }


            switch (tipenya) {
                case 1 :
                    tipebrg = "Jersey";
                    break;
                case 2 :
                    tipebrg = "Apparel";
                    break;
                case 3 :
                    tipebrg = "Aksesoris";
                    break;
                default :
                    cout << "(!) Pilihan tidak valid!" << endl;
                    return false;
            }
            
            cout << "Nama barang : ";
            getline(cin, namabrg);
            if (namabrg == "") {
                cout << "(!) Nama barang tidak valid" << endl;
                return false;
            }
            cout << "Harga barang : Rp.";
            cin >> hargabrg;
            if (hargabrg == 0 || hargabrg < 0 || !cin) {
                cout << "(!) Harga barang tidak valid!" << endl;
                cin.clear();
                cin.ignore();
                return false;
            }

            merchand.barang[jumlahdata].tipe = tipebrg;
            merchand.barang[jumlahdata].nama = namabrg;
            merchand.barang[jumlahdata].harga = hargabrg;

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
            } 
            else {
                clears();
                break;
            }
        }
        return true;
    }
}

void tampilkan() {
    if (jumlahdata == 0) {
        cout << "Data masih kosong." << endl;
    }
    else {
        cout << "Data merchandise yang tersimpan:" << endl;
        for (int i = 0; i < jumlahdata; i++) {
            cout << "\nData ke-" << i+1 << endl;
            cout << "Tipe barang : " << merchand.barang[i].tipe << endl;
            cout << "Nama barang : " << merchand.barang[i].nama << endl;
            cout << "Harga barang : Rp." << merchand.barang[i].harga << endl;
        }
    }
}

bool ubah() {
    if (jumlahdata == 0) {
        cout << "Data masih kosong." << endl;
        return false;
    }
    else {
        while (true) {
            tampilkan();
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
                cout << "1. Jersey\n";
                cout << "2. Apparel\n";
                cout << "3. Aksesoris\n";
                cout << "Pilih tipe barang (1/2/3): ";
                cin >> tipenya;
                cin.ignore();
                if (!cin || tipenya == 0 || tipenya < 0 || tipenya > jumlahdata) {
                    cout << "(!) Tipe tidak valid!" << endl;
                    cin.clear();
                    cin.ignore();
                    return false;
                }

                switch (tipenya) {
                    case 1:
                        tipebrg = "Jersey";
                        break;
                    case 2:
                        tipebrg = "Apparel";
                        break;
                    case 3:
                        tipebrg = "Aksesoris";
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

                merchand.barang[pilihan-1].tipe = tipebrg;
                merchand.barang[pilihan-1].nama = namabrg;
                merchand.barang[pilihan-1].harga = hargabrg;

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

bool hapus() {
    if (jumlahdata == 0) {
        cout << "Data masih kosong." << endl;
        return false;
    }
    else {
        while (true) {
            tampilkan();
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
                cout << "\nData yang dihapus:" << endl;
                cout << "Tipe barang : " << merchand.barang[pilihan - 1].tipe << endl;
                cout << "Nama barang : " << merchand.barang[pilihan - 1].nama << endl;
                cout << "Harga barang : " << merchand.barang[pilihan - 1].harga << endl;

                for (int i = pilihan - 1; i < jumlahdata - 1; i++) {
                    merchand.barang[i] = merchand.barang[i + 1];
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

void menu() {
    string pilihan;
    cout << "\n";
    cout << "   Merchandise Borneo FC\n"
            << "1. Tambah data merchandise\n"
            << "2. Tampilkan data merchandise\n"
            << "3. Ubah data merchandise\n"
            << "4. Hapus data merchandise\n"
            << "0. Keluar\n"
            << "Pilih menu (1/2/3/4/0): ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == "1") {
        clears();
        tambah();
        menu();
    }
    else if (pilihan == "2") {
        clears();
        tampilkan();
        cout << "\n";
        string lanjut;
        cout << "Tekan [Enter] untuk ke menu utama...";
        getch();
        clears();
        menu();
    }
    else if (pilihan == "3") {
        clears();
        ubah();
        menu();
    }
    else if (pilihan == "4") {
        clears();
        hapus();
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

    merchand.barang[0].tipe = "Jersey";
    merchand.barang[0].nama = "JERSEY HOME BORNEO FC";
    merchand.barang[0].harga = 450000;

    merchand.barang[1].tipe = "Jersey";
    merchand.barang[1].nama = "JERSEY AWAY BORNEO FC";
    merchand.barang[1].harga = 450000;

    jumlahdata = 2;
    
    clears();
    if (login() == true) {
        menu();
    }
    else {
        return 0;
    }
}