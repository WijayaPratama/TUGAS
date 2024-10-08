#include <iostream>
#include "penerbangan.h"

using namespace std;

int main()
{
    List WIN;
    adr P1,P2,P3,P4,P5,P6;
    Create_List(WIN);

    penerbangan data1;
    cout << "Masukkan Nomor Penerbangan Pertama: ";
    cin >> data1.flightNumber;
    cout << "Masukkan Harga Tiket Pertama: ";
    cin >> data1.price;
    cout << "Masukkan Kota Tujuan Pertama: ";
    cin >> data1.tujuan;

    // 02. Melakukan create new elemen berdasarkan data yang diinputkan user
    P1 = New_Elemen(data1);

    // 03. Memanggil salah satu jenis insert (jangan insert after)
    Insert_First(WIN, P1);

    // Meminta user data kedua yang akan dimasukkan ke list
    penerbangan data2;
    cout << "\nMasukkan Nomor Penerbangan Kedua: ";
    cin >> data2.flightNumber;
    cout << "Masukkan Harga Tiket Kedua: ";
    cin >> data2.price;
    cout << "Masukkan Kota Tujuan Kedua: ";
    cin >> data2.tujuan;

    // 04. Melakukan create new elemen berdasarkan data yang diinputkan user
    P2 = New_Elemen(data2);

    // 05. Memanggil salah satu jenis insert (berbeda dengan insert yang data pertama, jangan Insert after)
    Insert_Last(WIN, P2);

    // Meminta user data ketiga yang akan dimasukkan ke list
    penerbangan data3;
    cout << "\nMasukkan Nomor Penerbangan Ketiga: ";
    cin >> data3.flightNumber;
    cout << "Masukkan Harga Tiket Ketiga: ";
    cin >> data3.price;
    cout << "Masukkan Kota Tujuan Ketiga: ";
    cin >> data3.tujuan;

    // 06. Melakukan create new elemen berdasarkan data yang diinputkan user
    P3 = New_Elemen(data3);

    // 07. Memanggil salah satu jenis insert (Insert First)
    Insert_First(WIN, P3);

    // Meminta user data keempat yang akan dimasukkan ke list
    penerbangan data4;
    cout << "\nMasukkan Nomor Penerbangan Keempat: ";
    cin >> data4.flightNumber;
    cout << "Masukkan Harga Tiket Keempat: ";
    cin >> data4.price;
    cout << "Masukkan Kota Tujuan Keempat: ";
    cin >> data4.tujuan;

    // 08. Melakukan create new elemen berdasarkan data yang diinputkan user
    P4 = New_Elemen(data4);

    // 09. Memanggil salah satu jenis insert (Insert Last)
    Insert_Last(WIN, P4);

    // Meminta user data kelima yang akan dimasukkan ke list
    penerbangan data5;
    cout << "\nMasukkan Nomor Penerbangan Kelima: ";
    cin >> data5.flightNumber;
    cout << "Masukkan Harga Tiket Kelima: ";
    cin >> data5.price;
    cout << "Masukkan Kota Tujuan Kelima: ";
    cin >> data5.tujuan;

    // 10. Melakukan create new elemen berdasarkan data yang diinputkan user
    P5 = New_Elemen(data5);

    // 11. Memanggil salah satu jenis insert (Insert After pada data keempat)
    Insert_After(WIN, P4, P5);

    // Meminta user data keenam yang akan dimasukkan ke list
    penerbangan data6;
    cout << "\nMasukkan Nomor Penerbangan Keenam: ";
    cin >> data6.flightNumber;
    cout << "Masukkan Harga Tiket Keenam: ";
    cin >> data6.price;
    cout << "Masukkan Kota Tujuan Keenam: ";
    cin >> data6.tujuan;

    // 12. Melakukan create new elemen berdasarkan data yang diinputkan user
    P6 = New_Elemen(data6);

    // 13. Memanggil salah satu jenis insert (Insert After pada data keempat)
    Insert_After(WIN, P4, P6);

    // Memanggil show (01)
    cout << " SHOW1: " << endl;
    Show(WIN);

    // 14. Melakukan pencarian dan penghapusan data kedua dengan delete after
    adr prec2 ;
    prec2 = SearchBy_Tujuan(WIN,data1.tujuan);
    if (prec2 != NULL ){
        Delete_After(WIN, prec2, P2);
    }

    // 15. Melakukan penghapusan data keenam dengan pengkondisian
    adr prec6;
    prec6 = SearchBy_Tujuan(WIN,data5.tujuan);
    if (prec6!= NULL){
        Delete_After(WIN,prec6,P6);
    }

    // 16. Melakukan pengurutan elemen pada list berdasarkan sub data yang didefinisikan
    SortBy_SelectionSort(WIN);

    // Memanggil show (02)
    cout << "SHOW 2: " << endl;
    Show(WIN);

    return 0;
}
