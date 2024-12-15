#ifndef BIOSKOP_H_INCLUDED
#define BIOSKOP_H_INCLUDED
#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define nextFilm(R) R->nextFilm
#define nextPenonton(Q) Q->nextPenonton
#define first(L) L.first
#define last(L) L.last

using namespace std;
// ADT FILM
struct Film
{
    int id_Film;
    string judul;
    string jam_Tayang;
    int harga;
    int jumlah_Penonton;
};

typedef struct elm_Film *adr_Film;

struct elm_Film
{
    Film info;
    adr_Film next;
};

struct list_Film
{
    adr_Film first;
};

// ADT PENONTON

struct Penonton
{
    int id_Penonton;
    string nama;
    int banyak_Tiket;
};

typedef struct elm_Penonton *adr_Penonton;

struct elm_Penonton
{
    Penonton info;
    adr_Penonton next;
    adr_Penonton prev;
};

struct list_Penonton
{
    adr_Penonton first;
    adr_Penonton last;
};


//ADT RELASI
typedef struct elm_Relasi *adr_Relasi;

struct elm_Relasi
{
    adr_Film nextFilm;
    adr_Penonton nextPenonton;
    adr_Relasi next;
};

struct list_Relasi
{
    adr_Relasi first;
};

void createListFilm(list_Film &L);
void createListPenonton(list_Penonton &L);
void createListRelasi(list_Relasi &L);
adr_Film newFilm(Film data);
adr_Penonton newPenonton(Penonton data);
adr_Relasi newRelasi(adr_Film film, adr_Penonton penonton);

void insert_first_Film(list_Film &L, adr_Film P);
void insert_last_Film(list_Film &L, adr_Film P);
void showAllFilms(list_Film L);
void ShowAllPenonton(list_Penonton L);
void deleteFilm(list_Film &filmList, list_Relasi &relasiList, int idFilm);
adr_Film findFilm(list_Film L, int idFilm);

adr_Penonton findPenonton(list_Penonton L, int idPenonton);
void insert_first_Penonton(list_Penonton &L, adr_Penonton P);
void insert_last_Penonton(list_Penonton &L, adr_Penonton P);
void editFilm(list_Film &L, int idFilm);
void editPenonton(list_Penonton &L, int idPenonton);

void showFilmPenonton(list_Relasi L);
void insertRelasi(list_Relasi &L, adr_Film film, adr_Penonton penonton);
void findPenontonFromFilm(list_Relasi &L,int idFilm);


#endif // BIOSKOP_H_INCLUDED
