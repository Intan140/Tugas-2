#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    string penulis;
    Buku* prev;
    Buku* next;
};

Buku* head = nullptr;
Buku* tail = nullptr;

void tambahDepan(string judul, string penulis) {
    Buku* baru = new Buku{judul, penulis, nullptr, head};
    if (head != nullptr) head->prev = baru;
    else tail = baru;
    head = baru;
    cout << "Buku ditambahkan di depan.\n";
}

void tambahBelakang(string judul, string penulis) {
    Buku* baru = new Buku{judul, penulis, tail, nullptr};
    if (tail != nullptr) tail->next = baru;
    else head = baru;
    tail = baru;
    cout << "Buku ditambahkan di belakang.\n";
}

void hapusBuku(string judul) {
    Buku* hapus = head;
    while (hapus != nullptr) {
        if (hapus->judul == judul) {
            if (hapus->prev) hapus->prev->next = hapus->next;
            else head = hapus->next;
            if (hapus->next) hapus->next->prev = hapus->prev;
            else tail = hapus->prev;
            delete hapus;
            cout << "Buku berhasil dihapus.\n";
            return;
        }
        hapus = hapus->next;
    }
    cout << "Buku tidak ditemukan.\n";
}

void tampilkanBuku() {
    if (head == nullptr) {
        cout << "Daftar buku kosong.\n";
        return;
    }
    Buku* tampil = head;
    cout << "\nDaftar Buku:\n";
    while (tampil != nullptr) {
        cout << "Judul\t: " << tampil->judul << endl;
        cout << "Penulis\t: " << tampil->penulis << "\n\n";
        tampil = tampil->next;
    }
}

void cariBuku(string judul) {
    Buku* cari = head;
    while (cari != nullptr) {
        if (cari->judul == judul) {
            cout << "Buku ditemukan:\n";
            cout << "Judul\t: " << cari->judul << endl;
            cout << "Penulis\t: " << cari->penulis << endl;
            return;
        }
        cari = cari->next;
    }
    cout << "Buku tidak ditemukan.\n";
}

void editBuku(string judul) {
    Buku* ubah = head;
    while (ubah != nullptr) {
        if (ubah->judul == judul) {
            cout << "Masukkan judul baru\t: ";
            getline(cin, ubah->judul);
            cout << "Masukkan penulis baru\t: ";
            getline(cin, ubah->penulis);
            cout << "Data buku berhasil diedit.\n";
            return;
        }
        ubah = ubah->next;
    }
    cout << "Buku tidak ditemukan.\n";
}

void sortingBuku() {
    if (!head || !head->next) {
        cout << "Data buku masih sedikit.\n";
        return;
    }

    bool tukar;
    Buku* sekarang;
    do {
        tukar = false;
        sekarang = head;
        while (sekarang->next != nullptr) {
            if (sekarang->judul > sekarang->next->judul) {
                swap(sekarang->judul, sekarang->next->judul);
                swap(sekarang->penulis, sekarang->next->penulis);
                tukar = true;
            }
            sekarang = sekarang->next;
        }
    } while (tukar);

    cout << "Data buku berhasil diurutkan (judul A-Z).\n";
}

void menu() {
    int pilih;
    string judul, penulis;

    do {
        cout << "\n===== MENU MANAJEMEN DAFTAR BUKU =====\n";
        cout << "1. Tambah buku dari depan\n";
        cout << "2. Tambah buku dari belakang\n";
        cout << "3. Hapus buku berdasarkan judul\n";
        cout << "4. Tampilkan semua buku\n";
        cout << "5. Cari buku berdasarkan judul\n";
        cout << "6. Edit data buku\n";
        cout << "7. Urutkan buku berdasarkan judul (A-Z)\n";
        cout << "8. Keluar\n";
        cout << "=======================================\n";
        cout << "Pilihan\t: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                cout << "Judul\t: ";
                getline(cin, judul);
                cout << "Penulis\t: ";
                getline(cin, penulis);
                tambahDepan(judul, penulis);
                break;
            case 2:
                cout << "Judul\t: ";
                getline(cin, judul);
                cout << "Penulis\t: ";
                getline(cin, penulis);
                tambahBelakang(judul, penulis);
                break;
            case 3:
                cout << "Judul buku yang dihapus: ";
                getline(cin, judul);
                hapusBuku(judul);
                break;
            case 4:
                tampilkanBuku();
                break;
            case 5:
                cout << "Judul buku yang dicari: ";
                getline(cin, judul);
                cariBuku(judul);
                break;
            case 6:
                cout << "Judul buku yang ingin diedit: ";
                getline(cin, judul);
                editBuku(judul);
                break;
            case 7:
                sortingBuku();
                break;
            case 8:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 8);
}

int main() {
    menu();
    return 0;
}