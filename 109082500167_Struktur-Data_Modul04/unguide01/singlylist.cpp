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