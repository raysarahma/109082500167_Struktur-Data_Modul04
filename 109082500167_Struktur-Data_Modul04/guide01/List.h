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