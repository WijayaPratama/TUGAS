#include "bioskop.h"

void createListFilm(list_Film &L) {
    first(L) = NULL;
}

void createListPenonton(list_Penonton &L) {
    first(L) = NULL;
    last(L) = NULL;
}

void createListRelasi(list_Relasi &L) {
    first(L) = NULL;
}

adr_Film newFilm(Film data) {
    adr_Film P = new elm_Film;
    info(P) = data;
    next(P) = NULL;
    return P;
}


adr_Penonton newPenonton(Penonton data) {
    adr_Penonton P = new elm_Penonton;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

adr_Relasi newRelasi(adr_Film film, adr_Penonton penonton) {
    adr_Relasi P = new elm_Relasi;
    nextFilm(P) = film;
    nextPenonton(P) = penonton;
    next(P) = NULL;
    return P;
}


// 1. Insert Data Parent dari Depan
void insert_first_Film(list_Film &L, adr_Film P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

// 1. Insert Data Parent dari Belakang
void insert_last_Film(list_Film &L, adr_Film P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr_Film i = first(L);
        while(next(i) != NULL){
            i = next(i);
        }
        next(i)=P;
    }
}

// 2. Show All Data Parent
void showAllFilms(list_Film L){
    adr_Film i = first(L);
    while(i!=NULL){
         cout << "ID Film: " << info(i).id_Film
              << ", Judul: " << info(i).judul
              << ", Jam Tayang: " << info(i).jam_Tayang
              << ", Total Penonton: " << info(i).jumlah_Penonton << endl;
         i = next(i);
    }
}

void ShowAllPenonton(list_Penonton L){
    adr_Penonton i = first(L);
    while (i != NULL) {
        cout << "ID Penonton: " << info(i).id_Penonton
                << ", Nama: " << info(i).nama
                << ", Banyak Tiket: " << info(i).banyak_Tiket << endl;
        i = next(i);
    }
}


// 3. Menghapus Data Parent dan Child-nya
void deleteFilm(list_Film &filmList, list_Relasi &relasiList, int idFilm){
    adr_Film i = first(filmList);
    adr_Film prev = NULL;
    while (i != NULL && info(i).id_Film != idFilm) {
        prev = i;
        i = next(i);
    }
    if(i == NULL){
        cout<<"DATA TIDAK DI TEMUKAN"<<endl;
    }else if(i == first(filmList)){
        first(filmList) = next(i);
    }else if(next(i) == NULL){
        next(prev) = NULL;
    }else{
        next(prev) = next(i);
    }

    adr_Relasi R = first(relasiList);
    adr_Relasi prevRel = NULL;
    while (R != NULL ) {
        if (nextFilm(R) == i) {
            if (R == first(relasiList)) {
                first(relasiList) = next(R);
            } else if (next(R) == NULL) {
                next(prevRel) = NULL;
            } else {
                next(prevRel) = next(R);
            }
            adr_Relasi temp = R;
            R = next(R);
        } else {
            prevRel = R;
            R = next(R);
        }
    }
}


// 4. Mencari Data Parent
adr_Film findFilm(list_Film L, int idFilm) {
    adr_Film i = first(L);
    while (i != NULL && info(i).id_Film != idFilm) {
        i = next(i);
    }
    return i;
}

adr_Penonton findPenonton(list_Penonton L, int idPenonton) {
    adr_Penonton i = first(L);
    while (i != NULL && info(i).id_Penonton != idPenonton) {
        i = next(i);
    }
    return i;
}

// 5. Insert Data Child dari Depan
void insert_first_Penonton(list_Penonton &L, adr_Penonton P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

// 5. Insert Data Child dari Belakang
void insert_last_Penonton(list_Penonton &L, adr_Penonton P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

// 6. Mengubah data parent dan child
void editFilm(list_Film &L, int idFilm){
    int pilihan = -1;
    adr_Film i = findFilm(L,idFilm);
    while (pilihan != 0){
        cout << "EDIT FILM DENGAN ID = "<<info(i).id_Film<<endl;
        cout << "DATA YANG INGIN DIUBAH : " << endl;
        cout << "1.JUDUL"<<endl;
        cout << "2.JAM TAYANG"<<endl;
        cout << "3.HARGA"<<endl;
        cout << "4.EXIT"<<endl;
        cout << "MASUKKAN PILIHAN = ";
        cin >> pilihan;
        if (pilihan == 1){
            cout << "JUDUL BARU = ";
            cin.ignore();
            getline(cin, info(i).judul);
        }else if(pilihan == 2){
            cout << "JAM TAYANG BARU = ";
            cin >> info(i).jam_Tayang;
        }else if (pilihan == 3){
            cout << "HARGA BARU = ";
            cin >> info(i).harga;
        }else{
            pilihan = 0;
        }
        cout <<endl;
    }
}

// 6. Mengubah data parent dan child
void editPenonton(list_Penonton &L, int idPenonton){
    int pilihan = -1;
    adr_Penonton i = findPenonton(L,idPenonton);
    while (pilihan != 0){
        cout << "EDIT DATA PENONTON DENGAN ID = "<<info(i).id_Penonton<<endl;
        cout << "DATA YANG INGIN DIUBAH : " <<endl;
        cout << "1.NAMA"<<endl;
        cout << "2.BANYAK TIKET"<<endl;
        cout << "3.EXIT"<<endl;
        cout << "MASUKKAN PILIHAN = ";
        cin >> pilihan;
        if (pilihan == 1){
            cout << "NAMA BARU = ";
            cin.ignore();
            getline(cin, info(i).nama);
        }else if(pilihan == 2){
            cout << "BANYAK TIKET BARU = ";
            cin >> info(i).banyak_Tiket;
        }else{
            pilihan = 0;
        }
        cout <<endl;
    }
}

void insertRelasi(list_Relasi &L, adr_Film film, adr_Penonton penonton) {
    adr_Relasi newRel = new elm_Relasi;
    nextFilm(newRel) = film;
    nextPenonton(newRel) = penonton;
    next(newRel) = NULL;

    if (first(L) == NULL) {
        first(L) = newRel;
    } else {
        adr_Relasi temp = first(L);
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = newRel;
    }
}

//7.Menampilkan seluruh data parent beserta childnya
void showFilmPenonton(list_Relasi L){
    adr_Relasi P = first(L);
    while(P!=NULL){
         cout << "Film: " << nextFilm(P)->info.judul
             << " - Penonton: " << nextPenonton(P)->info.nama
             << " (" << nextPenonton(P)->info.banyak_Tiket << ")" << endl;
        P = next(P);
    }
}

//Mencari data child pada parent tertentu
void findPenontonFromFilm(list_Relasi &L, int idFilm) {
    adr_Relasi P = first(L);
    bool found = false;

    while (P != NULL) {
        if (nextFilm(P)->info.id_Film == idFilm) {
            if (!found) { // Cetak judul film hanya sekali
                cout << "FILM: " << nextFilm(P)->info.judul << endl;
                found = true;
            }
            cout << "Penonton ID: " << nextPenonton(P)->info.id_Penonton
                 << ", Nama: " << nextPenonton(P)->info.nama << endl;
        }
        P = next(P);
    }

    if (!found) {
        cout << "Tidak ada penonton yang ditemukan untuk ID Film " << idFilm << ".\n";
    }
}








