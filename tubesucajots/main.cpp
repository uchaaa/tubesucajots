#include "relasi.h"
#include <stdlib.h>

int main(){
    listFilm LF;
    listArtis LA;
    listRelasi LR;
    adrfilm F;
    adrartis A;
    adrR R;
    string x;
    int no;

    createListFilm(LF);
    createListArtis(LA);
    createListRelasi(LR);

    system("CLS");
    cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl;
    cout << "                   ^^ SELAMAT DATANG ^^                   " << endl;
    cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>> " << endl << endl;

    cout << "             | Pilihan Menu Data Perfilman |              " << endl;
    cout << " -------------------------------------------------------- " << endl;
    cout << " -------------- [1] | Menambahkan data | ---------------- " << endl;
    cout << " -------------- [2] | Mengedit data    | ---------------- " << endl;
    cout << " -------------- [3] | Menghapus data   | ---------------- " << endl;
    cout << " -------------- [4] | Menampilkan data | ---------------- " << endl;
    cout << " -------------------------------------------------------- " << endl << endl;
    cout << " |PILIHAN| : ";
    cin  >> no;

    while (no != 0) {
        if (no == 1) {
            system("CLS");
            cout << endl;
            cout << "               | Menu Penambahan Data |              " << endl;
            cout << "              --------------------------             " << endl;
            cout << " ---------- [1] Menambahkan Data Film -------------- " << endl;
            cout << " ---------- [2] Menambahkan Data Artis ------------- " << endl;
            cout << " ---------- [3] Menambahkan Data Pemeran Film ------ " << endl;
            cout << " ---------- [0] Keluar ----------------------------- " << endl;
            cout << " --------------------------------------------------- " << endl << endl;
            cout << " |PILIHAN| : ";
            cin  >> no;

            while (no != 0){
                if (no == 1){
                    system("CLS");
                    createElmLF(F);
                    insertlastFilm(LF, F);
                    cout << endl;
                    printFilm(LF);
                    cout << endl;
                    system("PAUSE");
                } else if (no == 2){
                    system("CLS");
                    createElmLA(A);
                    insertfirstArtis(LA, A);
                    cout << endl;
                    printArtis(LA);
                    cout << endl;
                    system("PAUSE");
                } else if (no == 3) {
                    system("CLS");
                    createElmR(F, A);
                    inputrelasi(LR, LF, LA);
                    cout << endl;
                    printRelasi(LR);
                    cout << endl;
                    system("PAUSE");
                } else if (no > 4) {
                    system("CLS");
                    cout << endl;
                    cout << " MAAF. TIDAK ADA PILIHAN UNTUK 4 KEATAS " << endl;
                    system("PAUSE");
                }

                system("CLS");
                cout << endl;
                cout << "               | Menu Penambahan Data |              " << endl;
                cout << "              --------------------------             " << endl;
                cout << " ---------- [1] Menambahkan Data Film -------------- " << endl;
                cout << " ---------- [2] Menambahkan Data Artis ------------- " << endl;
                cout << " ---------- [3] Menambahkan Data Pemeran Film ------ " << endl;
                cout << " ---------- [0] Keluar ----------------------------- " << endl;
                cout << " --------------------------------------------------- " << endl << endl;
                cout << " |PILIHAN| : ";
                cin  >> no;

            }
        } else if (no == 2){
            system("CLS");
            cout << endl;
            cout << "                  | Menu Edit Data |                 " << endl;
            cout << "              --------------------------             " << endl;
            cout << " --------------- [1] Edit Data Film ---------------- " << endl;
            cout << " --------------- [2] Edit Data Artis --------------- " << endl;
            cout << " --------------- [0] Keluar ------------------------ " << endl;
            cout << " --------------------------------------------------- " << endl << endl;
            cout << "|PILIHAN| : ";
            cin  >> no;

            while (no != 0) {
                if (no == 1) {
                    system("CLS");
                    printFilm(LF);
                    cout << endl;
                    editFilm(LF, F);
                    cout << endl;
                    printFilm(LF);
                    system("PAUSE");
                } else if (no == 2){
                    system("CLS");
                    printArtis(LA);
                    cout << endl;
                    editArtis(LA, A);
                    cout << endl;
                    printArtis(LA);
                    system("PAUSE");
                } else if (no > 2) {
                    system("CLS");
                    cout << endl;
                    cout << " MAAF. TIDAK ADA PILIHAN UNTUK 2 KEATAS " << endl;
                    system("PAUSE");
                }
                system("CLS");
                cout << "                  | Menu Edit Data |                " << endl;
                cout << "              --------------------------            " << endl;
                cout << " --------------- [1] Edit Data Film ----------------" << endl;
                cout << " --------------- [2] Edit Data Artis ---------------" << endl;
                cout << " --------------- [0] Keluar ------------------------" << endl;
                cout << " ---------------------------------------------------" << endl << endl;
                cout << " |PILIHAN| : ";
                cin  >> no;
            }
        } else if (no == 3){
            system("CLS");
            cout << endl;
            cout << "                  | Menu Hapus Data |               " << endl;
            cout << "              --------------------------            " << endl;
            cout << " --------------- [1] Hapus Data Film ---------------" << endl;
            cout << " --------------- [2] Hapus Data Artis --------------" << endl;
            cout << " --------------- [0] Keluar ------------------------" << endl;
            cout << " ---------------------------------------------------" << endl << endl;
            cout << " |PILIHAN| : ";
            cin  >> no;

            while (no != 0){
                if (no == 1){
                    system("CLS");
                    printFilm(LF);
                    cout << endl;
                    cout << "                 | Hapus Data Film |                 " << endl;
                    cout << "              --------------------------             " << endl;
                    cout << " --------------------------------------------------- " << endl;
                    cout << " Masukkan nama film yang data nya ingin dihapus : ";
                    cin >> x;
                    cout << endl;
                    deleteelmtrelasiFilm(LR, LF, R, x);
                    deleteElmFilm(LF, F, x);
                    printFilm(LF);
                    system("PAUSE");
                } else if (no == 2){
                    system("CLS");
                    printArtis(LA);
                    cout << "                 | Hapus Data Artis |                " << endl;
                    cout << "              --------------------------             " << endl;
                    cout << " --------------------------------------------------- " << endl;
                    cout << " Masukkan nama artis yang data nya ingin dihapus : ";
                    cin >> x;
                    cout << endl;
                    deleteelmtrelasiArtis(LR, LA, R, x);
                    deleteElmArtis(LA, A, x);
                    printArtis(LA);
                    system("PAUSE");
                } else if (no > 2) {
                    system("CLS");
                    cout << endl;
                    cout << " MAAF. TIDAK ADA PILIHAN UNTUK 2 KEATAS " << endl;
                    system("PAUSE");
                }

                system("CLS");
                cout << endl;
                cout << "                  | Menu Hapus Data |               " << endl;
                cout << "              --------------------------            " << endl;
                cout << " --------------- [1] Hapus Data Film ---------------" << endl;
                cout << " --------------- [2] Hapus Data Artis --------------" << endl;
                cout << " --------------- [0] Keluar ------------------------" << endl;
                cout << " ---------------------------------------------------" << endl << endl;
                cout << " |PILIHAN| : ";
                cin  >> no;

            }
        } else if (no == 4){
            system("CLS");
            cout << endl;
            cout << "                              | Menu Tampil Data |                             " << endl;
            cout << "                           --------------------------                          " << endl;
            cout << " --------------- [1] Tampilkan Keseluruhan Data ------------------------------ " << endl;
            cout << " --------------- [2] Tampilkan Data Aktor dan Aktris Paling Top -------------- " << endl;
            cout << " --------------- [3] Tampilkan Data Film Berdasarkan Nama Artis -------------- " << endl;
            cout << " --------------- [4] Tampilkan Data Artis Berdasarkan Nama Film -------------- " << endl;
            cout << " --------------- [0] Keluar -------------------------------------------------- " << endl;
            cout << " ----------------------------------------------------------------------------- " << endl << endl;
            cout << " |PILIHAN| : ";
            cin  >> no;

            while (no != 0){
                if (no == 1){
                    system("CLS");
                    printRelasi(LR);
                    system("PAUSE");
                } else if (no == 2){
                    system("CLS");
                    jmlhtampil(LR, LA);
                    system("PAUSE");
                } else if (no == 3){
                    system("CLS");
                    printArtis(LA);
                    cout << "----------------------------------" << endl;
                    cout << " Masukkan nama artis : ";
                    cin >> x;
                    tampildatafilmtertentu(LR, x);
                    system("PAUSE");
                } else if (no == 4){
                    system("CLS");
                    printFilm(LF);
                    cout << "----------------------------------" << endl;
                    cout << " Masukkan nama film : ";
                    cin >> x;
                    tampildataartistertentu(LR, x);
                    system("PAUSE");
                } else if (no > 5) {
                    system("CLS");
                    cout << endl;
                    cout << " MAAF. TIDAK ADA PILIHAN UNTUK 5 KEATAS " << endl;
                    system("PAUSE");
                }
                system("CLS");
                cout << endl;
                cout << "                              | Menu Tampil Data |                             " << endl;
                cout << "                           --------------------------                          " << endl;
                cout << " --------------- [1] Tampilkan Keseluruhan Data ------------------------------ " << endl;
                cout << " --------------- [2] Tampilkan Data Aktor dan Aktris Paling Top -------------- " << endl;
                cout << " --------------- [3] Tampilkan Data Film Berdasarkan Nama Artis -------------- " << endl;
                cout << " --------------- [4] Tampilkan Data Artis Berdasarkan Nama Film -------------- " << endl;
                cout << " --------------- [0] Keluar -------------------------------------------------- " << endl;
                cout << " ----------------------------------------------------------------------------- " << endl << endl;
                cout << " |PILIHAN| : ";
                cin  >> no;
            }
        } else if (no > 4) {
            system("CLS");
            cout << endl;
            cout << " MAAF. TIDAK ADA PILIHAN UNTUK 4 KEATAS " << endl;
            system("PAUSE");
        }

        system("CLS");
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
        cout << "                  ^^ SELAMAT DATANG ^^                  " << endl;
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl << endl;

        cout << "            | Pilihan Menu Data Perfilman |             " << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "-------------- [1] | Menambahkan data | ----------------" << endl;
        cout << "-------------- [2] | Mengedit data    | ----------------" << endl;
        cout << "-------------- [3] | Menghapus data   | ----------------" << endl;
        cout << "-------------- [4] | Menampilkan data | ----------------" << endl;
        cout << "--------------------------------------------------------" << endl << endl;
        cout << "|PILIHAN| : ";
        cin  >> no;

    }
}


