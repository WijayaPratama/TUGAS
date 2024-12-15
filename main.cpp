#include <iostream>
#include "bioskop.h"

using namespace std;

int main() {
    list_Film filmList;
    list_Penonton penontonList;
    list_Relasi relasiList;

    createListFilm(filmList);
    createListPenonton(penontonList);
    createListRelasi(relasiList);

     Film dataFilm1;
     Film dataFilm2;
     Film dataFilm3;

     dataFilm1.id_Film = 1;
     dataFilm1.judul = "SPIDERMAN";
     dataFilm1.jam_Tayang = "13:00";
     dataFilm1.harga = 30000;
     dataFilm1.jumlah_Penonton = 0;

     dataFilm2.id_Film = 2;
     dataFilm2.judul = "AGAK LAEN";
     dataFilm2.jam_Tayang = "14:00";
     dataFilm2.harga = 25000;
     dataFilm2.jumlah_Penonton = 0;

     dataFilm3.id_Film = 3;
     dataFilm3.judul = "DORAEMON";
     dataFilm3.jam_Tayang = "15:00";
     dataFilm3.harga = 25000;
     dataFilm3.jumlah_Penonton = 0;


    adr_Film newFilmNode1 = newFilm(dataFilm1);
    insert_last_Film(filmList, newFilmNode1);
    adr_Film newFilmNode2 = newFilm(dataFilm2);
    insert_last_Film(filmList, newFilmNode2);
    adr_Film newFilmNode3 = newFilm(dataFilm3);
    insert_last_Film(filmList, newFilmNode3);

    Penonton dataPenonton1;
    Penonton dataPenonton2;
    Penonton dataPenonton3;

    dataPenonton1.id_Penonton = 1;
    dataPenonton1.nama = "arya";
    dataPenonton1.banyak_Tiket = 0;

    dataPenonton2.id_Penonton = 2;
    dataPenonton2.nama = "razan";
    dataPenonton2.banyak_Tiket = 0;

    dataPenonton3.id_Penonton = 3;
    dataPenonton3.nama = "nabil";
    dataPenonton3.banyak_Tiket = 0;


    adr_Penonton newPenontonNode1 = newPenonton(dataPenonton1);
    insert_last_Penonton(penontonList, newPenontonNode1);
    adr_Penonton newPenontonNode2 = newPenonton(dataPenonton2);
    insert_last_Penonton(penontonList, newPenontonNode2);
    adr_Penonton newPenontonNode3 = newPenonton(dataPenonton3);
    insert_last_Penonton(penontonList, newPenontonNode3);

    int choice = -1;
    int inst;

    while (choice != 0) {
        cout << "==============================" << endl;
        cout << "         MENU BIOSKOP         " << endl;
        cout << "==============================" << endl;
        cout << "1. Tambah Film" << endl; // 1
        cout << "2. Tampilkan Semua Film" << endl;// 2
        cout << "3. Hapus Film dan penontonnya" << endl; //3
        cout << "4. Mencari data Film" << endl; //4
        cout << "5. Tambah Penonton" << endl; //5
        cout << "6. Tampilkan Semua Penonton" << endl; // 5
        cout << "7. Edit Data Film" << endl; // 6
        cout << "8. Edit Data Penonton" << endl; // 6
        cout << "9. Tambah Relasi Film-Penonton" << endl; //7
        cout << "10. Tampilkan Semua Film Beserta Penontonnya" << endl; //7
        cout << "11. Mencari data penonton pada film tertentu" << endl; //8
        cout << "0. EXIT" << endl; //10
        cout << "Pilih Menu: ";
        cin >> choice;

        // 1. Insert Data Parent dari Depan/Belakang
        if (choice == 1) {
            Film dataFilm;
            cout << "Masukkan ID Film: ";
            cin >> dataFilm.id_Film;
            cout << "Masukkan Judul Film: ";
            cin.ignore();
            getline(cin, dataFilm.judul);
            cout << "Masukkan Jam Tayang: ";
            cin >> dataFilm.jam_Tayang;
            cout << "Masukkan Harga: ";
            cin >> dataFilm.harga;
            cout << "Insert depan(0)/belakang(1) = ";
            cin >> inst;
            dataFilm.jumlah_Penonton = 0;

            adr_Film newFilmNode = newFilm(dataFilm);
            if (inst == 1){
                insert_last_Film(filmList, newFilmNode);
            }else if (inst == 0){
                insert_first_Film(filmList,newFilmNode);
            }else{
                cout <<"Masukkan 0 atau 1 !!!"<<endl;
            }

        // 2. Show All Data Parent dan 10. Menghitung total penonton
        } else if (choice == 2) {
            showAllFilms(filmList);

        // 3. Menghapus data parent dan childnya dan 9. Menghapus data child pada parent tertentu
        }else if (choice == 3) {
            int idFilm;
            cout << "Masukkan ID Film yang akan dihapus: ";
            cin >> idFilm;

            deleteFilm(filmList, relasiList, idFilm);

        // 4. Mencari data parent
        } else if (choice == 4) {
            int idFilm;
            cout<<"MASUKKAN ID FILM YANG INGIN DICARI = ";
            cin >> idFilm;
            adr_Film P = findFilm(filmList,idFilm);
            if(P == NULL){
                cout << "FILM TIDAK DITEMUKAN" << endl;
            }else{
                cout << "FILM DITEMUKAN" << endl;
                cout << "ID Film: " << info(P).id_Film
                     << ", Judul: " << info(P).judul
                     << ", Jam Tayang: " << info(P).jam_Tayang
                     << ", Total Penonton: " << info(P).jumlah_Penonton << endl;
            }

        // 5. Insert Data Child dari Depan/Belakang
        } else if (choice == 5) {
            Penonton dataPenonton;
            cout << "Masukkan ID Penonton: ";
            cin >> dataPenonton.id_Penonton;
            cout << "Masukkan Nama Penonton: ";
            cin.ignore();
            getline(cin, dataPenonton.nama);
            cout << "Insert depan(0)/belakang(1) = ";
            cin >> inst;
            dataPenonton.banyak_Tiket = 0;

            adr_Penonton newPenontonNode = newPenonton(dataPenonton);
            if (inst == 1){
                insert_last_Penonton(penontonList, newPenontonNode);
            }else if(inst == 0){
                insert_first_Penonton(penontonList, newPenontonNode);
            }else{
                cout <<"Masukkan 0 atau 1 !!!"<<endl;
            }

        } else if (choice == 6) {
            ShowAllPenonton(penontonList);

        // 6. Mengubah data parent dan child
        } else if (choice == 7) {
            int idFilm;
            cout << "Masukkan ID Film yang akan diubah: ";
            cin >> idFilm;
            editFilm(filmList, idFilm);

        } else if (choice == 8) {
            int idPenonton;
            cout << "Masukkan ID Penonton yang akan diubah: ";
            cin >> idPenonton;
            editPenonton(penontonList, idPenonton);

        } else if (choice == 9){
            int idPenonton;
            int idFilm;
            adr_Film targetFilm;
            adr_Penonton targetPenonton;

            cout << "Masukkan ID Penonton: ";
            cin >> idPenonton;

            cout << "Masukkan ID Film yang ditonton: ";
            cin >> idFilm;
            targetFilm = findFilm(filmList, idFilm);
            targetPenonton = findPenonton(penontonList,idPenonton);

            if (targetFilm != NULL) {
                info(targetFilm).jumlah_Penonton++;
                info(targetPenonton).banyak_Tiket++;
                insertRelasi(relasiList, targetFilm, targetPenonton);
                cout << "Penonton berhasil ditambahkan ke film.\n";
            } else {
                cout << "Film tidak ditemukan.\n";
            }

        //7. Menampilkan seluruh data parent beserta childnya
        }else if (choice == 10){
            showFilmPenonton(relasiList);

        //8. Mencari data child pada parent tertentu
        }else if (choice == 11){
            int idFilm;
            cout<<"MASUKKAN ID FILM YANG MAU DICARI PENONTONNYA = ";
            cin >> idFilm;
            findPenontonFromFilm(relasiList,idFilm);

        } else if (choice == 0) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;

        } else {
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }

        cout << endl;
    }

    return 0;
}
