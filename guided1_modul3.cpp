#include <iostream>
using namespace std;

// deklarasi struct node
struct node {
    int data;
    node* next;
};

node* head;
node* tail;

//inisialisasi node
void init(){
    head = NULL;
    tail = NULL;
}

// pengecekan apakah list kosong
bool isEmpty(){
    return head == NULL;
}

// tambah node di depan
void insertDepan(int nilai){
    node* baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()){
        head = tail = baru;
    }else{
        baru->next = head;
        head = baru;
    }
}

// tambah Node dibelakang
void insertBelakang(int nilai){
    node* baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()){
        head = tail = baru;
        tail = baru;
    }
}

// hitung jumlah node di list
int hitungList(){
    node* hitung = head;
    int jumlah = 0;
    while (hitung != NULL){
        jumlah ++;
        hitung = hitung->next;
    }
    return jumlah;
}

//tambah Node di posisi tengah
void insertTengah(int data, int posisi){
    if (posisi < 1 || posisi > hitungList()){
        cout << "posisi bukan posisi tengah" <<  endl;
    }else {
        node* baru = new node();
        baru->data = data;
        node* bantu = head;
        int nomor = 1;
        while (nomor < posisi -1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// hapus node di depan
void hapusDepan(){
    if (!isEmpty()){
        node * hapus = head;
        if (head->next != NULL){
            head = head->next;
            delete hapus;
        }else {
            head = tail = NULL;
            delete hapus;
            }
    }else {
        cout << "List kosong!" << endl;
    }
}




// hapus node di belakang
void hapusBelakang(){
    if (!isEmpty()){
        if (head != tail){
            node* hapus = tail;
            node* bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }else {
            head = tail = NULL;
        }
    }else{
        cout << "list kosong!" << endl;
    }
}
// hapus node di posisi tengah
void hapusTengah(int posisi){
    if(posisi < 1 || posisi > hitungList()){
        cout << "posisi diluar jangkauan" << endl;
    } else if (posisi == 1){
            cout << "posisi diluar jangkauan" << endl;
        } else {
            node* hapus;
            node* bantu = head;
            for (int nomor = 1; nomor < posisi-1; nomor++){
                bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}
// ubah data node di depan
void ubahDepan(int data){
    if (!isEmpty()){
        head-> data = data;
    }else{
        cout << "List masih kosong!" << endl;
    }
}
//ubah data Node di posisi tengah
void ubahTengah(int data, int posisi){
    if (!isEmpty()){
        if(posisi < 1 || posisi > hitungList()){
            cout << " posisi diluar jangkauan" << endl;
        }else if (posisi==1){
            cout << "Posisi bukan di posisi tengah" << endl;
        }else {
            node* bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++){
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    }else {
        cout << "List masih kosong!" << endl;
    }
}
// ubah data node di belakang
void ubahBelakang(int data){
    if(!isEmpty()){
        tail->data = data;
    }else {
        cout << " List masih kosong!" << endl;
    }
}
// hapus semua Node di list
void clearList(){
    node* bantu = head;
    while (bantu != NULL){
        node* hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// tampilkan semua data Node di list
void tampil(){
    if (!isEmpty()){
        node* bantu = head;
        while (bantu != NULL){
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }else {
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    int();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    return 0;
}
