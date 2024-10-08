#include <iostream>
#include "penerbangan.h"

void Create_List(List &L)
{
    first(L) = NULL;
}

adr New_Elemen(infotype x)
{
    adr p;
    p = new elmlist;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void Insert_First(List &L,adr P)
{
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void Insert_Last(List &L , adr P)
{
    if(first(L) == NULL){
        first(L) = P;
    }else{
        adr q;
        q = first(L);
        while (next(q) != NULL){
            q = next(q);
        }
        next(q) = P;
    }
}

void Insert_After(List &L,adr prec ,adr P)
{
    if(first(L) == NULL){
        first(L) = P;
    }else{
    next(P)=next(prec);
    next(prec) = P;
    }
}

void Delete_First(List &L, adr P)
{
    if (first(L) == NULL){
        P = NULL;
    }else{
        P = first(L);
        first(L) = next(first(L));
        next(P) = NULL;
    }
}

void Delete_Last(List &L ,adr P)
{
    if (first(L) == NULL){
        P = NULL;
    }else if(next(first(L))== NULL){
        Delete_First(L,P);
    }else{
        P = first(L);
        while (next(next(P))!= NULL){
            P = next(P);
        }
        next(P) = NULL;
    }
}

void Delete_After(List &L,adr prec,adr P)
{
    if (first(L) == NULL){
        P = NULL;
    }else{
        next(prec) = next(P);
        next(P) = NULL;
    }
}

void Show(List L)
{
    if(first(L) == NULL){
      cout << "List Kosong" << endl ;
    }else{
        adr p;
        int i;
        i = 1;
        p = first(L);
        while(p!= NULL){
            cout << i << endl ;
            cout << "Nomor Penerbangan: " << info(p).flightNumber << " HARGA: " << info(p).price <<" dengan tujuan " <<info(p).tujuan << endl;
            cout << "----------------------------------" << endl;
            i++;
            p = next(p);
        }
    }
}

void SortBy_SelectionSort(List &L)
{
    adr SL,minimum,P,Q,Prec;
    SL = NULL;
    // Jika list tidak kosong dan elemen list lebih dari 1
    if (first(L) != NULL && next(first(L))!= NULL) {
        while (first(L) != NULL) {
            minimum = first(L);
            P = next(minimum);
            while (P != NULL) {
                if (info(P).flightNumber < info(minimum).flightNumber) {
                    minimum = P;
                }
                P = next(P);
            }

            // Proses delete elemen minimum
            if (minimum == first(L)) {
                first(L) = next(minimum);
                next(minimum) = NULL;
            } else if (first(L) != NULL && next(minimum)!= NULL) {
                // Jika elemen minimum ada di tengah list
                Prec = first(L);
                while (next(Prec) != minimum) {
                    Prec = next(Prec);
                }
                next(Prec) = next(minimum);
                next(minimum) = NULL;
            } else {
                // Jika elemen minimum ada di akhir list
                Prec = first(L);
                while (next(Prec) != minimum) {
                    Prec = next(Prec);
                }
                next(Prec)= NULL;
            }

            // Proses insert elemen minimum ke SL (sorted list)
            if (SL == NULL) {
                SL = minimum;
            } else {
                Q = SL;
                while(next(Q)!= NULL){
                    Q = next(Q);
                }
                next(Q) = minimum;
            }
        }
        first(L) = SL;
    }else if(first(L) == NULL){
        cout << "list kosong" << endl;
    }
};
adr SearchBy_Tujuan(List L, string data) {
    adr p = first(L);
    while (p != NULL) {
        if (info(p).tujuan == data) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}




