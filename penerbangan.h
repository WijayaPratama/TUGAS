#ifndef PENERBANGAN_H_INCLUDED
#define KERUCUT_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

struct penerbangan
{
    int flightNumber;
    float price;
    string tujuan;
};

typedef penerbangan infotype;
typedef struct elmlist *adr;

struct elmlist
{
    infotype info;
    adr next;
};

struct List
{
    adr first;
};

void Create_List(List &L);
adr New_Elemen(infotype x);
void Insert_First(List &L, adr P);
void Insert_Last(List &L, adr P);
void Insert_After(List &L, adr prec, adr P);
void Delete_First(List &L, adr P);
void Delete_Last(List &L, adr P);
void Delete_After(List &L, adr prec, adr P);
void Show(List L);
void SortBy_SelectionSort(List &L);
adr SearchBy_Tujuan(List L, string data);

#endif // PENERBANGAN_H_INCLUDED
