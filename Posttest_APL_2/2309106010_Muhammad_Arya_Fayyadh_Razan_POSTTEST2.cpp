#include <iostream>
using namespace std;

string user = "Muhammad Arya Fayyadh Razan";
string pass = "2309106010";

void clears() {
    system("cls");
}

void login() {
    string nama, nim;
    int coba = 0;
    while (coba < 3) {
        cout << "[  Menu Login  ]" << endl;
        cout << "Nama : ";
        getline(cin, nama);
        cout << "NIM  : ";
        getline(cin, nim);
        if (nama == user && nim == pass) {
            cout << "\nLogin berhasil!";
            cout << "\nHalo, " << nama << "!" << endl;
            break;
        } else {
            coba++;
            cout << "\n(!) Login gagal, Nama atau NIM yang anda masukkan salah." << endl;
            if (coba == 3) {
                cout << "(!) Anda telah melewati batas percobaan, program berhenti.";
                exit(0);
            } else
                cout << "(!) Sisa percobaan anda " << 3 - coba << " kali lagi.\n" << endl;
        }
    }
}

string databrg[32][3] = {
    {"Jersey", "JERSEY HOME BORNEO FC", "450.000"},
    {"Jersey", "JERSEY AWAY BORNEO FC", "450.000"},
    {"Jersey", "JERSEY THIRD BORNEO FC", "450.000"},
    {"Apparel", "T-SHIRT BORNEO TYPE FONT BLACK", "140.000"},
    {"Aksesoris", "SCARF BORNEO HITAM", "220.000"}
};

int jumlahdata = 4;


bool tambah() {
    cout << "Tambah data merchandise" << endl;
    if (jumlahdata >= 32) {
        cout << "(!) Data sudah penuh, hubungi Arya." << endl;
        return false;
    }
    else {
        while (true) {
            string tipebrg, namabrg, hargabrg;
            cout << "Tipe barang (Jersey/Apparel/Aksesoris): ";
            cin >> tipebrg;
            cin.ignore();
            cout << "Nama barang : ";
            getline(cin, namabrg);
            cout << "Harga barang : ";
            getline(cin, hargabrg);

            databrg[jumlahdata][0] = tipebrg;
            databrg[jumlahdata][1] = namabrg;
            databrg[jumlahdata][2] = hargabrg;

            jumlahdata++;
            cout << "Data berhasil ditambahkan!" << endl;
            cout << "\n";
            string lanjut;
            cout << "Tekan [Enter] untuk melanjutkan... (Atau key apa saja untuk ke menu utama)";
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
        cout << "(!) Belum ada data merchandise yang tersimpan." << endl;
    }
    else {
        cout << "Data Merchandise yang tersimpan :" << endl;
        for (int i = 0; i < jumlahdata; i++) {
            cout << "\nData ke-" << i + 1 << endl;
            cout << "Tipe Barang : " << databrg[i][0] << endl;
            cout << "Nama Barang : " << databrg[i][1] << endl;
            cout << "Harga Barang: Rp. " << databrg[i][2] << endl;
        }
    }
}

bool ubah() {
    cout << "Ubah data merchandise" << endl;
    if (jumlahdata == 0) {
        cout << "(!) Belum ada data merchandise yang tersimpan." << endl;
        return false;
    }
    else {
        tampilkan();
        int nomor;
        cout << "\nPilih nomor data yang ingin diubah: ";
        cin >> nomor;
        cin.ignore();

        if (nomor < 1 || nomor > jumlahdata || nomor == 0) {
            cout << "(!) Nomor data tidak ditemukan." << endl;
            return false;
        }

        int index = nomor - 1;

        cout << "Data ditemukan! Silakan masukkan data baru:" << endl;
        cout << "Tipe barang (Jersey/Apparel/Aksesoris): ";
        getline(cin, databrg[index][0]);
        cout << "Nama barang: ";
        getline(cin, databrg[index][1]);
        cout << "Harga barang: ";
        getline(cin, databrg[index][2]);
        cout << "Data dengan nomor " << nomor << " berhasil diubah!" << endl;
        
        cout << "\n";
        string lanjut;
        cout << "Tekan [Enter] untuk melanjutkan... (Atau key apa saja untuk ke menu utama)";
        getline(cin, lanjut);
        if (lanjut == "") {
            cout << "\n";
            cout << "============================================================================" << endl;
            cout << "\n";
        } 
        else {
            clears();
        }
        return true;
    }
}

bool hapus() {
    cout << "Hapus data merchandise" << endl;
    if (jumlahdata == 0) {
        cout << "(!) Belum ada data merchandise yang tersimpan." << endl;
        return false;
    }
    else {
        while (true) {
            tampilkan();
            int nomor;
            cout << "\nPilih nomor data yang ingin dihapus: ";
            cin >> nomor;
            cin.ignore();

            if (nomor < 1 || nomor > jumlahdata || nomor == 0) {
                cout << "(!) Nomor data tidak ditemukan." << endl;
                return false;
            }

            int index = nomor - 1;

            for (int i = index; i < jumlahdata - 1; i++) {
                databrg[i][0] = databrg[i + 1][0];
                databrg[i][1] = databrg[i + 1][1];
                databrg[i][2] = databrg[i + 1][2];
            }
            jumlahdata--;

            cout << "Tipe Barang : " << databrg[index][0] << endl;
            cout << "Nama Barang : " << databrg[index][1] << endl;
            cout << "Harga Barang: " << databrg[index][2] << endl;
            cout << "Data dengan nomor " << nomor << " berhasil dihapus." << endl;
            
            cout << "\n";
            string lanjut;
            cout << "Tekan [Enter] untuk melanjutkan... (Atau key apa saja untuk ke menu utama)";
            getline(cin, lanjut);
            if (lanjut == "") {
                cout << "\n";
                cout << "============================================================================" << endl;
                cout << "\n";
            } 
            else {
                clears();
            }
            return true;
        }
    }
}

int main() {
    string pilihan, jawab;
    clears();
    login();
    while (true) {
        cout << "\n";
        cout << "===================================" << endl;
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
        }
        else if (pilihan == "2") {
            clears();
            tampilkan();
            cout << "\n";
            string lanjut;
            cout << "Tekan [Enter] untuk ke menu utama...";
            getline(cin, lanjut);
            if (lanjut == "") {
                clears();       
            } 
            else {
                clears();
            }
        }
        else if (pilihan == "3") {
            clears();
            ubah();
        }
        else if (pilihan == "4") {
            clears();
            hapus();
        }
        else if (pilihan == "0") {
            cout << "Terima Kasih & Sampai Jumpa!" << endl;
            break;
        }
        else {
            cout << "(!) Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}
