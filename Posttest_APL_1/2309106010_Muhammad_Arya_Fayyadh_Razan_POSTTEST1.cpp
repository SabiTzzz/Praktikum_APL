#include <iostream>
#include <iomanip>

using namespace std;

void clears() {
   system("cls");
}

string user = "Muhammad Arya Fayyadh Razan";
string pass = "2309106010";

int rupiah() {
    double rupiah, dollar, euro, yen;
    while (true) {
        cout << "Program Konversi Mata Uang Rupiah\n"
                "Masukkan jumlah Rupiah : ";
        cin >> rupiah;
        dollar = rupiah / 15700;
        euro = rupiah / 17000;
        yen = rupiah / 105;
        cout << "\n";
        cout << "Hasil Konversi : " << endl;
        cout << "Dollar : " << fixed << setprecision(6) << dollar << " Dollar" << endl;
        cout << "Euro   : " << fixed << setprecision(6) << euro << " Euro" << endl;
        cout << "Yen    : " << fixed << setprecision(6) << yen << " Yen" << endl;
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
    return 0;
}

int dollar() {
    double rupiah, dollar, euro, yen;
    while (true) {
        cout << "Program Konversi Mata Uang Dollar\n"
                "Masukkan jumlah dollar : ";
        cin >> dollar;
        rupiah = dollar * 15700;
        euro = dollar * 0.92;
        yen = dollar * 150;
        cout << "\n";
        cout << "Hasil Konversi : " << endl;
        cout << "Rupiah : " << fixed << setprecision(0) << rupiah << " Rupiah" << endl;
        cout << "Euro   : " << fixed << setprecision(2) << euro << " Euro" << endl;
        cout << "Yen    : " << fixed << setprecision(0) << yen << " Yen" << endl;
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
    return 0;
}

int euro() {
    double rupiah, dollar, euro, yen;
    while (true) {
        cout << "Program Konversi Mata Uang Euro\n"
                "Masukkan jumlah Euro : ";
        cin >> euro;
        rupiah = euro * 17000;
        dollar = euro / 0.92;
        yen = euro * 162;
        cout << "\n";
        cout << "Hasil Konversi : " << endl;
        cout << "Rupiah : " << fixed << setprecision(0) << rupiah << " Rupiah" << endl;
        cout << "Dollar : " << fixed << setprecision(6) << dollar << " Dollar" << endl;
        cout << "Yen    : " << fixed << setprecision(0) << yen << " Yen" << endl;
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
    return 0;
}

int yen() {
    double rupiah, dollar, euro, yen;
    while (true) {
        cout << "Program Konversi Mata Uang Yen\n"
                "Masukkan jumlah Yen : ";
        cin >> yen;
        rupiah = yen * 105;
        dollar = yen / 150;
        euro = yen / 162;
        cout << "\n";
        cout << "Hasil Konversi : " << endl;
        cout << "Rupiah : " << fixed << setprecision(0) << rupiah << " Rupiah" << endl;
        cout << "Dollar : " << fixed << setprecision(6) << dollar << " Dollar" << endl;
        cout << "Euro   : " << fixed << setprecision(6) << euro << " Euro" << endl;
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
    return 0;
}

int menu_utama() {
    int pilihan;
    while (true) {
        cout << "\n";
        cout << "===================================" << endl;
        cout << "\n";
        cout << "Program Konversi Mata Uang\n"
                "\n"
                "         [ Menu Utama ]\n"
                "1. Rupiah ke (Dollar, Euro, Yen)\n"
                "2. Dollar ke (Rupiah, Euro, Yen)\n"
                "3. Euro ke (Rupiah, Dollar, Yen)\n"
                "4. Yen ke (Rupiah, Dollar, Euro)\n"
                "[Input key selain 1,2,3,4 untuk Keluar]\n"
                "\n"
                "Pilihan (1/2/3/4/any) : ";    
        cin >> pilihan;

        if (pilihan == 1) {
            clears();
            rupiah();
        } else if (pilihan == 2) {
            clears();
            dollar();
        } else if (pilihan == 3) {
            clears();
            euro();
        } else if (pilihan == 4) {
            clears();
            yen();
        } else {
            cout << "\n";
            cout << "Terima kasih telah menggunakan program ini." << endl;
            exit(0);
        }
    }
    return 0;
}

int main() {
    clears();
    string nama, nim;
    int coba = 0;
    while (coba < 3) {
        cout << "[  Menu Login  ]" << endl;
        cout << "Nama : ";
        getline(cin,nama);
        cout << "NIM  : ";
        getline(cin,nim);
        if (nama == user && nim == pass) {
            cout << "\nLogin berhasil!";
            cout << "\nHalo, " << nama << "!" << endl;
            menu_utama();
            break;
        } else {
            coba++;
            cout << "\n(!) Login gagal, Nama atau NIM yang anda masukkan salah." << endl;
            if (coba == 3) {
                cout << "(!) Anda telah melewati batas percobaan, program berhenti.";
            } else
                cout << "(!) Sisa percobaan anda " << 3-coba << " kali lagi.\n"<< endl;
        }
    }
    exit(0);
    return 0;
}