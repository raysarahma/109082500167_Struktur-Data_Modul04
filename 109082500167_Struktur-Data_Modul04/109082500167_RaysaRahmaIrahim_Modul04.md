# <h1 align="center"> Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA) </h1>

<p align="center"> Raysa Rahma Irahim - 109082500167 </p>

## Dasar Teori
### A. Konsep Linked List<br/>
Linked list adalah struktur data yang isinya berupa rangkaian elemen yang saling terhubung dan bisa bertambah atau berkurang sesuai kebutuhan. Data yang disimpan bisa berupa data tunggal, misalnya satu string, atau data majemuk berupa record seperti data mahasiswa yang punya nama, NIM, dan alamat [1]. Tiap elemen disebut node, dan antar node dihubungkan memakai pointer, jadi datanya tidak harus tersimpan berurutan di memori [2].
### 1. Linked List dengan Pointer<br/>
Linked list sebenarnya bisa dibuat dengan array maupun pointer, tapi di praktikum ini dipakai pointer. Alasannya, array sifatnya statis sedangkan pointer dinamis, jadi lebih cocok dengan linked list yang ukurannya fleksibel. Array lebih pas dipakai kalau jumlah maksimum elemennya sudah diketahui dari awal [1][2]. Pointer sendiri adalah variabel yang isinya alamat memori variabel lain [3]. Untuk membuat node dipakai struct yang berisi data dan pointer ke node selanjutnya [2][3]. Isi node yang ditunjuk pointer bisa diakses dengan operator panah (->) atau titik (.) [1].
### 2. Operasi pada Linked List<br/>
Di C++Secara umum ada enam operasi pada linked list, yaitu create list, insert, delete, view, searching, dan update [1].

### B. Singly Linked List<br/>
ADT di C++ diterapkan dengan struct sebagai type serta fungsi dan prosedur sebagai operasinya, lalu dipisah ke beberapa file agar program lebih teratur [3].
### 1. Sifat Singly Linked List<br/>
Singly linked list hanya butuh satu pointer pada tiap node. Node terakhir menunjuk ke Nil (kecuali pada list circular), list hanya bisa dibaca maju, dan kalau datanya tidak terurut pencariannya dilakukan satu per satu dari depan (sekuensial). Kelebihannya, menyisipkan atau menghapus elemen di tengah list lebih mudah dibanding array [1][2].
### 2. Istilah pada Singly Linked List<br/>
First/head adalah pointer yang menunjuk ke elemen pertama list. Next adalah pointer di dalam elemen yang menunjuk ke elemen sesudahnya. Nil/NULL berarti tidak mengacu ke mana pun atau kosong. Node adalah tempat penyimpanan data pada memori tertentu [1].
### 3.Pembentukan Komponen List <br/>
CreateList dipakai untuk membuat list kosong, caranya dengan mengisi first dengan Nil. Alokasi dipakai untuk membuat elemen baru (di C memakai malloc, di C++ cukup memakai new), sedangkan dealokasi mengembalikan memori ke sistem (di C memakai free, di C++ memakai delete) [1]. Menurut dokumentasi C++, objek yang dibuat dengan new akan tetap ada sampai pointernya dipakai pada delete, jadi kalau lupa di-delete akan terjadi memory leak [4]. Ada juga ListEmpty/isEmpty untuk mengecek apakah list kosong atau tidak [1].

## Guided
### GUIDE 1

### list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL
#include <iostream>
using namespace std;
struct mahasiswa
{
    string nama, nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node
{
    dataMahasiswa isidata;
    address next;
};
struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string nama, string nim, int umur);
void dealokasi (address &node);
void printList(linkedlist list);
void insertFirst (linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast (linkedlist &list);
void delAfter (linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deletelist (linkedlist &list);
#endif
```

### list.cpp
```C++
#include "List.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist list)
{
    if (list.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &list)
{
    list.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedlist &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid." << endl;
    }
}

void insertLast(linkedlist &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &list)
{
        address nodeHapus;
        if (!isEmpty(list)==false)
        {
            nodeHapus = list.first;
            list.first = list.first->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "List kosong" << endl;
        }
}

void delLast(linkedlist &list)
{
    address nodeHapus, nodePrev;
    if (!isEmpty(list)==false)
    {
        nodeHapus = list.first;
        if (nodeHapus->next == Nil)
        {
            list.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedlist &list, address nodeHapus, address nodePrev)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deletelist(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus." << endl;
}
```

### main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs) << endl;
    return 0;
}#include "List.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist list)
{
    if (list.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &list)
{
    list.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedlist &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid." << endl;
    }
}

void insertLast(linkedlist &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &list)
{
        address nodeHapus;
        if (!isEmpty(list)==false)
        {
            nodeHapus = list.first;
            list.first = list.first->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "List kosong" << endl;
        }
}

void delLast(linkedlist &list)
{
    address nodeHapus, nodePrev;
    if (!isEmpty(list)==false)
    {
        nodeHapus = list.first;
        if (nodeHapus->next == Nil)
        {
            list.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedlist &list, address nodeHapus, address nodePrev)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
        nodeHapus = nodePrev->next;
        nodePrev->next = nodeHapus->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deletelist(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus." << endl;
}
```

penjelasan singkat guided 2 : Guided ini berisi ADT singly linked list yang dipisah jadi dua file. list.h berisi type elmlist (info dan next), type List (first), dan prototipe fungsi, sedangkan list.cpp berisi isi fungsinya. CreateList membuat list kosong, alokasi membuat elemen baru dengan new, dan dealokasi menghapusnya dengan delete. Elemen bisa ditambah di awal (insertFirst), di akhir (insertLast), atau setelah elemen tertentu (insertAfter), dan dihapus dari awal atau akhir (deleteFirst dan deleteLast). printInfo dipakai untuk menampilkan isi list dan nbList untuk menghitung jumlah elemennya.


## Unguided

### 1. Buatlah ADT Singly Linked list di dalam file “Singlylist.h” dengan type infotype (int), address (pointer ke ElmList), ElmList (info dan next), List (first), serta primitif CreateList, alokasi, dealokasi, printInfo, dan insertFirst. Buat implementasinya pada file “Singlylist.cpp” lalu cobalah pada file “main.cpp”.

### singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED
#include <iostream>
#include <cstddef>
#define Nil NULL
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif 
```
### singlylist.cpp
```C++
#include <iostream>
#include "Singlylist.h"
using namespace std;

void CreateList(List &L){
    L.first = Nil;
}

address alokasi(infotype x){
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P){
    delete P;
    P = Nil;
}

void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P){
    P->next = L.first;
    L.first = P;
}
```
### main.cpp
```C++
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/raysarahma/109082500167_Struktur-Data_Modul04/blob/main/output/output-unguide01.png)

##### Output 1
![Screenshot Output Unguided 1_2](https://github.com/raysarahma/109082500167_Struktur-Data_Modul04/blob/main/output/output-unguide01(JAM).png)

penjelasan unguided 1 : Pada unguided 1, ADT dibuat dalam tiga file. Singlylist.h berisi type dan prototipe fungsi, Singlylist.cpp berisi isi fungsinya, dan main.cpp sebagai driver. CreateList membuat list kosong dengan first = Nil, lalu alokasi membuat elemen baru dengan new dan mengisi info dengan x. Pada insertFirst, elemen baru disambung ke elemen yang tadinya paling depan (P->next = L.first), lalu dijadikan first. printInfo menelusuri list dari first sampai Nil sambil mencetak isinya. Karena semua angka (2, 0, 8, 12, 9) dimasukkan dengan insertFirst, angka yang masuk paling akhir jadi paling depan, makanya outputnya kebalikan dari urutan input, yaitu 9 12 8 0 2. Di modul, pemanggilan di main ditulis createList, tapi C++ membedakan huruf besar dan kecil, jadi saya samakan dengan prototipe di soal, yaitu CreateList.

## Kesimpulan
Dari praktikum modul 4 ini saya belajar bahwa singly linked list adalah struktur data yang node-nodenya dihubungkan oleh pointer next dan hanya bisa ditelusuri satu arah, dari first sampai Nil. Berbeda dengan array yang ukurannya tetap, elemen pada list dibuat saat dibutuhkan dengan new dan dibebaskan dengan delete. Saya juga jadi paham cara kerja operasi dasarnya, yaitu insert first, insert last, dan insert after yang intinya mengatur pointer next, view dengan menelusuri list, serta delete first dan delete last. Selain itu, memisahkan ADT ke file .h, .cpp, dan main.cpp membuat kode lebih rapi dan primitifnya bisa dipakai lagi.

## Referensi
[1] Telkom University. (2023). Modul 4 Singly Linked List (Bagian Pertama), Modul Praktikum Struktur Data. Fakultas Informatika, Telkom University.<br/> 
[2] Rahman, S., Hartono, Joni, Dafitri, H., Tanjung, J. P., & Chiuloto, K. (2025). Struktur Data dan Algoritma: Pendekatan Visual dan Praktis dalam C++ (Bab II Single Linked List). Medan: Universitas Medan Area Press. Diakses melalui https://phki-pghc.uma.ac.id/wp-content/uploads/2025/06/web-8.pdf.<br/> 
[3] Budiman, Alamsyah, N., & Al Rasyid, A. (2023). Buku Ajar Pemrograman C++ (Bab IX Struct dan Bab X Pointer). Bandung: Unibi Press. Diakses melalui https://repository.unibi.ac.id/531/1/PEMROGRAMAN%20C%2B%2B.pdf.<br/> 
[4] cppreference.com. (n.d.). New expression dan Delete expression. Diakses melalui https://en.cppreference.com/w/cpp/language/new dan https://en.cppreference.com/w/cpp/language/delete.<br/>