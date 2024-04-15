#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void tambahDepan(string nama, int usia) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    void tambahBelakang(string nama, int usia) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* lastNode = head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    void tambahTengah(string nama, int usia, int posisi) {
        if (posisi < 0) {
            cout << "Posisi harus lebih besar dari 0" << endl;
            return;
        }
        if (posisi == 0) {
            tambahDepan(nama, usia);
            return;
        }

        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;

        Node* current = head;
        for (int i = 0; i < posisi - 1; ++i) {
            if (current == nullptr) {
                cout << "Posisi melebihi panjang linked list" << endl;
                return;
            }
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void hapusData(string nama) {
        Node* current = head;
        Node* prev = nullptr;

        if (current != nullptr && current->nama == nama) {
            head = current->next;
            delete current;
            return;
        }

        while (current != nullptr && current->nama != nama) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << nama << " tidak ditemukan dalam linked list" << endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    void editData(string namaLama, string namaBaru, int usiaBaru) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama == namaLama) {
                current->nama = namaBaru;
                current->usia = usiaBaru;
                return;
            }
            current = current->next;
        }
        cout << namaLama << " tidak ditemukan dalam linked list" << endl;
    }

    void tampilkan() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->nama << "\t" << current->usia << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    string nama;
    int usia;
    int pilihan;
    int posisi;
    string namaLama;
    string namaBaru;
    int usiaBaru;

    // Memasukkan data pertama
    cout << "Masukkan nama Anda: ";
    cin >> nama;
    cout << "Masukkan usia Anda: ";
    cin >> usia;
    linkedList.tambahDepan(nama, usia);

    // Memasukkan data sesuai dengan urutan yang diminta
    do {
        cout << "\nPilihan Menu:\n";
        cout << "1. Tambahkan data di awal\n";
        cout << "2. Tambahkan data di belakang\n";
        cout << "3. Tambahkan data di tengah\n";
        cout << "4. Edit data\n";
        cout << "5. Hapus data\n";
        cout << "6. Tampilkan data\n";
        cout << "7. Selesai\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> usia;
                linkedList.tambahDepan(nama, usia);
                break;
            case 2:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> usia;
                linkedList.tambahBelakang(nama, usia);
                break;
            case 3:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan usia mahasiswa: ";
                cin >> usia;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                linkedList.tambahTengah(nama, usia, posisi);
                break;
            case 4:
                cout << "Masukkan nama mahasiswa yang ingin diubah: ";
                cin >> namaLama;
                cout << "Masukkan nama baru mahasiswa: ";
                cin >> namaBaru;
                cout << "Masukkan usia baru mahasiswa: ";
                cin >> usiaBaru;
                linkedList.editData(namaLama, namaBaru, usiaBaru);
                break;
            case 5:
                cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
                cin >> nama;
                linkedList.hapusData(nama);
                break;
            case 6:
                cout << "\nData Mahasiswa:\n";
                linkedList.tampilkan();
                break;
            case 7:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 7);

    return 0;
}