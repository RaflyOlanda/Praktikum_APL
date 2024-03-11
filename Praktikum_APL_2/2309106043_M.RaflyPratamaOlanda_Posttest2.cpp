#include <iostream>
using namespace std;

// Data menu kopi
string menu[6][2] = {
    {"arabika", "19500"},
    {"affogato", "22000"},
    {"latte", "21500"},
    {"macchiato", "32500"},
    {"espresso", "40000"},
    {"chocolate", "30250"}
};

int totalMenu = 6; 

// menampilkan menu yang tersedia sekarang
void tampilkanMenu() {
    cout << "========Daftar Menu========" << endl;
    for (int i = 0; i < totalMenu; ++i) {
        cout << menu[i][0] << " - Rp. " << menu[i][1] << endl;
    }
    cout << "===========================" << endl;
}

// Menambahkan menu baru
void tambahMenu() {
    tampilkanMenu();
    string nama_menu, harga_menu;
    cout << "Masukkan nama menu baru: ";
    cin.ignore();
    getline(cin, nama_menu);
    cout << "Masukkan harga menu: ";
    cin >> harga_menu;
    menu[totalMenu][0] = nama_menu;
    menu[totalMenu][1] = harga_menu;
    totalMenu++;
    cout << "Menu " << nama_menu << " berhasil ditambahkan." << endl;
}

// Menghapus menu yang ada
void hapusMenu() {
    tampilkanMenu();
    string nama_menu;

    cout << "Masukkan nama menu yang ingin dihapus: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool nilai = false;
    for (int i = 0; i < totalMenu; ++i) {
        if (menu[i][0] == nama_menu) {
            nilai = true;
            for (int j = i; j < totalMenu - 1; ++j) {
                menu[j][0] = menu[j+1][0];
                menu[j][1] = menu[j+1][1];
            }
            totalMenu--;
            cout << "Menu " << nama_menu << " berhasil dihapus." << endl;
            break;
        }
    }
    if (!nilai) {
        cout << "Menu " << nama_menu << " tidak ditemukan." << endl;
    }
}

// Mengupdate harga menu yang ada
void updateMenu() {
    tampilkanMenu();
    string nama_menu, hargaBaru;

    cout << "Masukkan nama menu yang ingin diupdate: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool nilai = false;
    for (int i = 0; i < totalMenu; ++i) {
        if (menu[i][0] == nama_menu) {
            nilai = true;
            cout << "Masukkan harga baru untuk menu " << nama_menu << ": ";
            cin >> hargaBaru;
            menu[i][1] = hargaBaru;
            cout << "Harga menu " << nama_menu << " berhasil diupdate dengan harga " << hargaBaru << endl;
            break;
        }
    }
    if (!nilai) {
        cout << "Menu " << nama_menu << " tidak ditemukan." << endl;
    }
}

// Menampilkan semua menu
void tampilan_kasir() {
    int pilihan;
    while (true) {
        cout << "===== Corporation Coffeeshop =====" << endl;
        cout << "1. Tambah Menu" << endl;
        cout << "2. Hapus Menu" << endl;
        cout << "3. Tampilkan Menu Saat Ini" << endl;
        cout << "4. Update Menu" << endl;
        cout << "5. Keluar" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan pilihan anda (1/2/3/4/5): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahMenu();
                break;
            case 2:
                hapusMenu();
                break;
            case 3:
                tampilkanMenu();
                break;
            case 4:
                updateMenu();
                break;
            case 5:
                return ;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}

// tampilan pemesanan menu di user pelanggan
void pesanMenu() {
    tampilkanMenu();
    string nama_menu;
    int jumlah;
    cout << "Masukkan nama menu yang ingin dipesan: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool nilai = false;
    for (int i = 0; i < totalMenu; ++i) {
        if (menu[i][0] == nama_menu) {
            nilai = true;
            break;
        }
    }
    if (!nilai) {
        cout << "Menu " << nama_menu << " tidak ditemukan." << endl;
        return; 
    }
    
    cout << "Masukkan jumlah yang ingin dipesan: ";
    cin >> jumlah;
    
    int harga = 0;
    for (int i = 0; i < totalMenu; ++i) {
        if (menu[i][0] == nama_menu) {
            harga = stoi(menu[i][1]) * jumlah;
            break;
        }
    }
    cout << "Pesanan Anda: " << nama_menu << ", Jumlah: " << jumlah << ", Total: Rp. " << harga << endl;
    
    int bayar;
    do {
        cout << "Masukkan jumlah pembayaran: Rp. ";
        cin >> bayar;
        if (bayar < harga) {
            cout << "Pembayaran kurang. Silakan masukkan jumlah pembayaran yang cukup." << endl;
        }
    } while (bayar < harga);
    
    int kembalian = bayar - harga;
    cout << "Kembalian Anda: Rp. " << kembalian << endl;
}

// tampilan untuk user pelanggan
void tampilan_pelanggan() {
    int pilihan;
    while (true) {
        cout << "===== Selamat datang di Corporation Coffeeshop =====" << endl;
        cout << "1. Pesan Menu" << endl;
        cout << "2. Keluar" << endl;
        cout << "=====================================================" << endl;
        cout << "Masukkan pilihan anda (1/2): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                pesanMenu();
                break;
            case 2:
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}

// menu utama
int main(){
    int pilihan;
    string nama, nim;
    string nama_data = "rafly"; 
    string nim_data = "2309106043";

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
    while (true) {
        cout << "===== Corporation Coffeeshop =====" << endl;
        cout << "1. Kasir " << endl;
        cout << "2. Pelanggan " << endl;
        cout << "3. Keluar Menu" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tampilan_kasir();
                break;
            case 2:
                tampilan_pelanggan();
                break;
            case 3:
                cout<< "Terima kasih telah berkunjung.";
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;

    }
}
}