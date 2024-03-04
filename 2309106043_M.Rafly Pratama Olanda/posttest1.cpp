#include <iostream>
using namespace std;

int main() {
    string nama, nim;
    string nama_data = "rafly"; 
    string nim_data = "2309106043";
    int pilihan;

    
    for(int i = 1; i<=3; i++){
        cout << "Masukkan nama anda : ";
        cin >> nama;
        cout << "Masukan NIM anda : ";
        cin >> nim;
        if ((nama == nama_data) && (nim == nim_data)){
            cout<< "Data yang dimasukkan telah sesuai." << endl;
            break;
        }
        else if (i<2){
            cout<< "Kesempatan input tersisa: " << i+1 << endl;
        }
        else if (i<3){
            cout<< "Kesempatan input tersisa: " << i-1 << endl;
        }
        else if (i==3){
            cout << "Kesempatan telah habis";
            return 0;
        }
    
    }

    do {
        float hasil;
        float jumlah;
        cout << "===============================" << endl;
        cout << "PILIHAN MENU KONVERSI MATA UANG" << endl;
        cout << "===============================" << endl;
        cout << "1. Konversi Rupiah ke (Dollar, Euro, Yen)" << endl;
        cout << "2. Konversi Dollar ke (Rupiah, Euro, Yen)" << endl;
        cout << "3. Konversi Euro ke (Rupiah, Dollar, Yen)" << endl;
        cout << "4. Konversi Yen ke (Rupiah, Dollar, Euro)" << endl;
        cout << "Masukkan pilihan konversi yang diinginkan (1/2/3/4) :";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan jumlah Rupiah: ";
                cin >> jumlah;
                // Konversi Rupiah ke Dollar, Euro, dan Yen
                hasil = jumlah / 15701;
                cout << "Hasil konversi ke Dollar: " << hasil << endl;
                hasil = jumlah / 17043;
                cout << "Hasil konversi ke Euro: " << hasil << endl;
                hasil = jumlah / 104;
                cout << "Hasil konversi ke Yen: " << hasil << endl;
                break;
            case 2:
                cout << "Masukkan jumlah Dollar: ";
                cin >> jumlah;
                // Konversi Dollar ke Rupiah, Euro, dan Yen
                hasil = jumlah * 15701;
                cout << "Hasil konversi ke Rupiah: " << hasil << endl;
                hasil = jumlah * 0.92;
                cout << "Hasil konversi ke Euro: " << hasil << endl;
                hasil = jumlah * 150;
                cout << "Hasil konversi ke Yen: " << hasil << endl;
                break;
            case 3:
                cout << "Masukkan jumlah Euro: ";
                cin >> jumlah;
                // Konversi Euro ke Rupiah, Dollar, dan Yen
                hasil = jumlah * 17037;
                cout << "Hasil konversi ke Rupiah: " << hasil << endl;
                hasil = jumlah * 1.09;
                cout << "Hasil konversi ke Dollar: " << hasil << endl;
                hasil = jumlah * 162;
                cout << "Hasil konversi ke Yen: " << hasil << endl;
                break;
            case 4:
                cout << "Masukkan jumlah Yen: ";
                cin >> jumlah;
                // Konversi Yen ke Rupiah, Dollar, dan Euron
                hasil = jumlah* 130; 
                cout << "Hasil konversi ke Rupiah: " << hasil << endl;
                hasil = jumlah / 150;
                cout << "Hasil konversi ke Dollar: " << hasil << endl;
                hasil = jumlah / 162; 
                cout << "Hasil konversi ke Euro: " << hasil << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                continue;
        }
        char ulangi;
        do {
            cout << "Apakah Anda ingin mengulang konversi mata uang? (y/n): ";
            cin >> ulangi;
            if (ulangi == 'n' || ulangi == 'N') {
                return 0; 
            } else if (ulangi == 'y' || ulangi == 'Y') {
                break; 
            } else {
                cout << "Pilihan tidak tersedia." << endl;
            }
        } while (true);

    } while (true) ; 

    return 0;
}
