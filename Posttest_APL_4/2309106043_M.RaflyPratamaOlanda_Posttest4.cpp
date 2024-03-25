#include <iostream>
using namespace std;

const int max_menu = 100;


struct Menu {
    string nama;
    int harga;
};


struct DaftarMenu {
    Menu menu[max_menu];
    int totalMenu;
};

DaftarMenu daftarMenu = {
    {{"arabika", 19500},
     {"affogato", 22000},
     {"latte", 21500},
     {"macchiato", 32500},
     {"espresso", 40000},
     {"chocolate", 30250}},
    6
};


void tampilkanMenu() {
    cout << "========Daftar Menu========" << endl;
    for (int i = 0; i < daftarMenu.totalMenu; ++i) {
        cout << daftarMenu.menu[i].nama << " - Rp. " << daftarMenu.menu[i].harga << endl;
    }
    cout << "===========================" << endl;
}

// Menambahkan menu baru
void tambahMenu() {
    tampilkanMenu();
    string nama_menu;
    int harga_menu;
    cout << "Masukkan nama menu baru: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool nilai = false;
    for (char c : nama_menu) {
        if (isdigit(c)) {
            nilai = true;
            break;
        }
    }
    if (nilai) {
        cout << "Nama menu tidak boleh mengandung angka." << endl;
        return;
    }
    for (int i = 0; i < daftarMenu.totalMenu; ++i) {
        if (daftarMenu.menu[i].nama == nama_menu) {
            cout << "Menu dengan nama yang sama sudah ada dalam daftar." << endl;
            return;
        }
    }
    cout << "Masukkan harga menu: ";
    cin >> harga_menu;
    if (cin.fail() || harga_menu <= 0) {
    cout << "Input harga tidak valid. Harap masukkan angka yang lebih besar dari 0." << endl;
    cin.clear(); 
    cin.ignore(10000, '\n'); 
    return;
    }
    else{
    if (daftarMenu.totalMenu < max_menu) { 
        daftarMenu.menu[daftarMenu.totalMenu].nama = nama_menu;
        daftarMenu.menu[daftarMenu.totalMenu].harga = harga_menu;
        daftarMenu.totalMenu++;
        cout << "Menu " << nama_menu << " berhasil ditambahkan." << endl;
    } else {
        cout << "Kapasitas menu penuh." << endl;
    }
    }
}

void hapusMenu() {
    tampilkanMenu();
    string nama_menu;

    cout << "Masukkan nama menu yang ingin dihapus: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool ditemukan = false;
    for (int i = 0; i < daftarMenu.totalMenu; ++i) {
        if (daftarMenu.menu[i].nama == nama_menu) {
            ditemukan = true;
            for (int j = i; j < daftarMenu.totalMenu - 1; ++j) {
                daftarMenu.menu[j] = daftarMenu.menu[j + 1];
            }
            daftarMenu.totalMenu--;
            cout << "Menu " << nama_menu << " berhasil dihapus." << endl;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Menu " << nama_menu << " tidak ditemukan." << endl;
    }
}

// Mengupdate harga menu yang ada
void updateMenu() {
    tampilkanMenu();
    string nama_menu;
    int harga_baru;

    cout << "Masukkan nama menu yang ingin diupdate: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool ditemukan = false;
    for (int i = 0; i < daftarMenu.totalMenu; ++i) {
        if (daftarMenu.menu[i].nama == nama_menu) {
            ditemukan = true;
            cout << "Masukkan harga baru untuk menu " << nama_menu << ": ";
            cin >> harga_baru;
            if (cin.fail() || harga_baru <= 0) {
            cout << "Input harga tidak valid. Harap masukkan angka yang lebih besar dari 0." << endl;
            cin.clear(); 
            cin.ignore(10000, '\n');
            return; 
}
            daftarMenu.menu[i].harga = harga_baru;
            cout << "Harga menu " << nama_menu << " berhasil diupdate menjadi " << harga_baru << endl;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Menu " << nama_menu << " tidak ditemukan." << endl;
    }
}

void tampilanKasir() {
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
        switch (pilihan){
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
            return;
        default:
            cout << "Pilihan tidak valid." << endl;
}
}
}
// Fungsi untuk melakukan pembayaran
int pembayaran(int harga) {
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
    return kembalian;
}

// Fungsi untuk memesan menu
void pesanMenu() {
    tampilkanMenu();
    string nama_menu;
    int jumlah;
    cout << "Masukkan nama menu yang ingin dipesan: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool ditemukan = false;
    for (int i = 0; i < daftarMenu.totalMenu; ++i) {
        if (daftarMenu.menu[i].nama == nama_menu) {
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Menu " << nama_menu << " tidak ditemukan." << endl;
        return; 
    }
    
    cout << "Masukkan jumlah yang ingin dipesan: ";
    cin >> jumlah;
    if (cin.fail() || jumlah <= 0) {
    cout << "Input harga tidak valid. Harap masukkan angka yang lebih besar dari 0." << endl;
    cin.clear(); 
    cin.ignore(10000, '\n'); 
    return;
    } 
    int harga = 0;
    for (int i = 0; i < daftarMenu.totalMenu; ++i) {
        if (daftarMenu.menu[i].nama == nama_menu) {
            harga = daftarMenu.menu[i].harga * jumlah;
            break;
        }
    }
    cout << "Pesanan Anda: " << nama_menu << ", Jumlah: " << jumlah << ", Total: Rp. " << harga << endl;
    pembayaran(harga);
}

// Tampilan untuk user pelanggan
void tampilanPelanggan() {
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

bool login(string nama_data, string nim_data, int kesempatan = 3){
    string nama;
    string nim;
        cout << "Masukkan nama anda : ";
        cin >> nama;
        cout << "Masukan NIM anda : ";
        cin >> nim;
        if ((nama == nama_data) && (nim == nim_data)){
            cout<< "Data yang dimasukkan telah sesuai." << endl;
            return true;
        }
        else if (kesempatan>1){
            cout<< "Kesempatan input tersisa: " << kesempatan-1 << endl;
            return login(nama_data,nim_data,kesempatan-1);
        }
        else{
            cout << "Kesempatan telah habis"<< endl;
            return false;
        }
}

int main_menu(){
    int pilihan;
    cout << "===== Corporation Coffeeshop =====" << endl;
    cout << "1. Kasir " << endl;
    cout << "2. Pelanggan " << endl;
    cout << "3. Keluar Menu" << endl;
    cout << "==================================" << endl;
    cout << "Masukkan pilihan anda (1/2/3): ";
    cin >> pilihan;
    return pilihan;

}


// Program utama
// menu utama
int main(){
    int pilihan;
    string nama, nim;
    string nama_data = "rafly"; 
    string nim_data = "2309106043";
    login(nama_data,nim_data,3);
    while (true) {
        pilihan=main_menu();
        switch (pilihan) {
            case 1:
                tampilanKasir();
                break;
            case 2:
                tampilanPelanggan();
                break;
            case 3:
                cout<< "Terima kasih telah berkunjung.";
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;

    }
}
}
