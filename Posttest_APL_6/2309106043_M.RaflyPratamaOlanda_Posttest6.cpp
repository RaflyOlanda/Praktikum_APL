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

void tampilkanMenu(const DaftarMenu *ptr) {
    cout << "========Daftar Menu========" << endl;
    for (int i = 0; i < ptr->totalMenu; ++i) {
        cout << ptr->menu[i].nama << " - Rp. " << ptr->menu[i].harga << endl;
    }
    cout << "===========================" << endl;
}

// Menambahkan menu baru
void tambahMenu(DaftarMenu *ptr) {
    tampilkanMenu(ptr);
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
    for (int i = 0; i < ptr->totalMenu; ++i) {
        if (ptr->menu[i].nama == nama_menu) {
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
    } else {
        if (ptr->totalMenu < max_menu) { 
            ptr->menu[ptr->totalMenu].nama = nama_menu;
            ptr->menu[ptr->totalMenu].harga = harga_menu;
            ptr->totalMenu++;
            cout << "Menu " << nama_menu << " berhasil ditambahkan." << endl;
        } else {
            cout << "Kapasitas menu penuh." << endl;
        }
    }
}

void hapusMenu(DaftarMenu *ptr) {
    tampilkanMenu(ptr);
    string nama_menu;
    cout << "Masukkan nama menu yang ingin dihapus: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool ditemukan = false;
    for (int i = 0; i < ptr->totalMenu; ++i) {
        if (ptr->menu[i].nama == nama_menu) {
            ditemukan = true;
            for (int j = i; j < ptr->totalMenu - 1; ++j) {
                ptr->menu[j] = ptr->menu[j + 1];
            }
            ptr->totalMenu--;
            cout << "Menu " << nama_menu << " berhasil dihapus." << endl;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Menu " << nama_menu << " tidak ditemukan." << endl;
    }
}

// Mengupdate harga menu yang ada
void updateMenu(DaftarMenu *ptr) {
    tampilkanMenu(ptr);
    string nama_menu;
    int harga_baru;

    cout << "Masukkan nama menu yang ingin diupdate: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool ditemukan = false;
    for (int i = 0; i < ptr->totalMenu; ++i) {
        if (ptr->menu[i].nama == nama_menu) {
            ditemukan = true;
            cout << "Masukkan harga baru untuk menu " << nama_menu << ": ";
            cin >> harga_baru;
            if (cin.fail() || harga_baru <= 0) {
                cout << "Input harga tidak valid. Harap masukkan angka yang lebih besar dari 0." << endl;
                cin.clear(); 
                cin.ignore(10000, '\n');
                return; 
            }
            ptr->menu[i].harga = harga_baru;
            cout << "Harga menu " << nama_menu << " berhasil diupdate menjadi " << harga_baru << endl;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Menu " << nama_menu << " tidak ditemukan." << endl;
    }
}

void tampilanKasir(DaftarMenu *ptr) {
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
        if (cin.fail() || pilihan <= 0) {
                cout << "Input harga tidak valid. Harap masukkan angka yang lebih besar dari 0." << endl;
                cin.clear(); 
                cin.ignore(10000, '\n');
                return; 
            }
        switch (pilihan){
            case 1:
                tambahMenu(ptr);
                break;
            case 2:
                hapusMenu(ptr);
                break;
            case 3:
                tampilkanMenu(ptr);
                break;
            case 4:
                updateMenu(ptr);
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
void pesanMenu(const DaftarMenu *ptr) {
    tampilkanMenu(ptr);
    string nama_menu;
    int jumlah;
    cout << "Masukkan nama menu yang ingin dipesan: ";
    cin.ignore();
    getline(cin, nama_menu);

    bool ditemukan = false;
    for (int i = 0; i < ptr->totalMenu; ++i) {
        if (ptr->menu[i].nama == nama_menu) {
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
    for (int i = 0; i < ptr->totalMenu; ++i) {
        if (ptr->menu[i].nama == nama_menu) {
            harga = ptr->menu[i].harga * jumlah;
            break;
        }
    }
    cout << "Pesanan Anda: " << nama_menu << ", Jumlah: " << jumlah << ", Total: Rp. " << harga << endl;
    pembayaran(harga);
}

// Tampilan untuk user pelanggan
void tampilanPelanggan(const DaftarMenu *ptr) {
    int pilihan;
    while (true) {
        cout << "===== Selamat datang di Corporation Coffeeshop =====" << endl;
        cout << "1. Pesan Menu" << endl;
        cout << "2. Keluar" << endl;
        cout << "=====================================================" << endl;
        cout << "Masukkan pilihan anda (1/2): ";
        cin >> pilihan;
        if (cin.fail() || pilihan <= 0) {
                cout << "Input harga tidak valid. Harap masukkan angka yang lebih besar dari 0." << endl;
                cin.clear(); 
                cin.ignore(10000, '\n');
                return; 
            }
        switch (pilihan) {
            case 1:
                pesanMenu(ptr);
                break;
            case 2:
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}

void menuAscendingBubble(Menu menu[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (menu[j].nama > menu[j + 1].nama) {
                swap(menu[j], menu[j + 1]);
            }
        }
    }
    cout << "Menu diurutkan secara ascending menggunakan Bubble Sort." << endl;
}

void hargaDescendingSelection(Menu menu[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (menu[j].harga > menu[max_idx].harga) {
                max_idx = j;
            }
        }
        swap(menu[max_idx], menu[i]);
    }
    cout << "Harga diurutkan secara descending menggunakan Selection Sort." << endl;
}


void menuDescendingInsertion(Menu menu[], int n) {
    for (int i = 1; i < n; ++i) {
        Menu key = menu[i];
        int j = i - 1;
        while (j >= 0 && menu[j].nama < key.nama) {
            menu[j + 1] = menu[j];
            j = j - 1;
        }
        menu[j + 1] = key;
    }
    cout << "Menu diurutkan secara descending menggunakan Insertion Sort." << endl;
}

void tampilanSorting(){
    int pilihan;
    while (true) {
        cout << "===== Sorting Menu =====" << endl;
        cout << "1. Sorting Menu Ascending (Bubble sort)" << endl;
        cout << "2. Sorting Harga Descending (Selection sort)" << endl;
        cout << "3. Sorting Menu Descending (Insertion sort)" << endl;
        cout << "4. Keluar" << endl;
        cout << "=====================================================" << endl;
        cout << "Masukkan pilihan anda (1/2/3/4): ";
        cin >> pilihan;
        if (cin.fail() || pilihan <= 0) {
                cout << "Input harga tidak valid. Harap masukkan angka yang lebih besar dari 0." << endl;
                cin.clear(); 
                cin.ignore(10000, '\n');
                return; 
            }
        switch (pilihan) {
            case 1:
                menuAscendingBubble(daftarMenu.menu, daftarMenu.totalMenu);
                tampilkanMenu(&daftarMenu);
                break;
            case 2:
                hargaDescendingSelection(daftarMenu.menu, daftarMenu.totalMenu);
                tampilkanMenu(&daftarMenu);
                break;
            case 3:
                menuDescendingInsertion(daftarMenu.menu, daftarMenu.totalMenu);
                tampilkanMenu(&daftarMenu);
                break;
            case 4:
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}

void AscendingInterpolationSearch(const DaftarMenu *ptr, const string &key) {
    int low = 0;
    int high = ptr->totalMenu - 1;
    bool found = false;
    while (low <= high && key >= ptr->menu[low].nama && key <= ptr->menu[high].nama) {
        int pos = low + ((key.compare(ptr->menu[low].nama)) * (high - low)) / (ptr->menu[high].nama.compare(ptr->menu[low].nama));
        if (ptr->menu[pos].nama == key) {
            found = true;
            cout << "Menu ditemukan pada posisi " << pos + 1 << " dari daftar menu." << endl;
            tampilkanMenu(ptr);
            break;
        } else if (ptr->menu[pos].nama < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    if (!found) {
        cout << "Menu tidak ditemukan dalam daftar." << endl;
    }
}


void DescendingBinarySearchHarga(const DaftarMenu *ptr, int harga_key) {
    int low = 0;
    int high = ptr->totalMenu - 1;
    bool found = false;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ptr->menu[mid].harga == harga_key) {
            found = true;
            while (mid < ptr->totalMenu && ptr->menu[mid].harga == harga_key) {
                cout << "Menu dengan harga Rp. " << harga_key << ": " << ptr->menu[mid].nama << endl;
                tampilkanMenu(&daftarMenu);
                mid++;
            }
            break;
        } else if (ptr->menu[mid].harga < harga_key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (!found) {
        cout << "Harga tidak ditemukan dalam daftar." << endl;
    }
}

void tampilanSearching() {
    int pilihan;
    int harga_key;
    string key;
    while (true) {
        cout << "===== Searching Menu =====" << endl;
        cout << "1. Searching menu Ascending (Interpolation Search)" << endl;
        cout << "2. Searching harga Descending (Binary Search)" << endl;
        cout << "3. Keluar" << endl;
        cout << "=====================================================" << endl;
        cout << "Masukkan pilihan anda (1/2/3): ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                menuAscendingBubble(daftarMenu.menu, daftarMenu.totalMenu);
                cout << "Masukkan nama menu yang ingin dicari: ";
                cin.ignore();
                getline(cin, key);
                AscendingInterpolationSearch(&daftarMenu, key);
                break;
            case 2:
                hargaDescendingSelection(daftarMenu.menu, daftarMenu.totalMenu);
                cout << "Masukkan harga menu yang ingin dicari: ";
                cin >> harga_key; 
                if (cin.fail() || pilihan <= 0) {
                cout << "Input harga tidak valid." << endl;
                cin.clear(); 
                cin.ignore(10000, '\n');
                return; 
            }
                DescendingBinarySearchHarga(&daftarMenu, harga_key); 
                break;
            case 3:
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}

bool login(string &nama_data, string &nim_data, int kesempatan = 3){
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
    cout << "3. Sorting Menu" << endl;
    cout << "4. Searching Menu" << endl;
    cout << "5. Keluar Menu" << endl;
    cout << "==================================" << endl;
    cout << "Masukkan pilihan anda (1/2/3/4/5): ";
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
                tampilanKasir(&daftarMenu);
                break;
            case 2:
                tampilanPelanggan(&daftarMenu);
                break;
            case 3:
                tampilanSorting();
                break;
            case 4:
                tampilanSearching();
                break;
            case 5:
                cout<< "Terima kasih telah berkunjung.";
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }
}
