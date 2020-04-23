#include "pelem.h"
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

    while (no != 0) {
        if (no == 1) {
            system("CLS");
            cout << "              | Menu Penambahan Data |             " << endl;
            cout << "             --------------------------            " << endl;
            cout << "---------- [1] Menambahkan Data Artis -------------" << endl;
            cout << "---------- [2] Menambahkan Data Film --------------" << endl;
            cout << "---------- [3] Menambahkan Data Pemeran Film ------" << endl;
            cout << "---------------------------------------------------" << endl << endl;
            cout << "|PILIHAN| : ";
            cin  >> no;

            while (no != 0) {
                if (no == 1) {
                    system("CLS");
                    createListArtis(LA);
                    insertfirstArtis(LA, A);
                    system("CLS");
                    printArtis(LA);
                    cout << endl;
                    system("PAUSE");
                } else if (no == 2){
                    system("CLS");
                    createListFilm(LF);
                    insertlastFilm(LF, F);
                    system("CLS");
                    printFilm(LF);
                    cout << endl;
                    system("PAUSE");
                }
            }
            createlementdosen(AD);
            insertlastdosen(LD,AD);
            system("CLS");
            tampildatadosen(LD);
            cout << endl;
            system("PAUSE");
        } else if (no == 2) {
            system("CLS");
            cout << endl;
            alokasimahasiswa(AM);
            insertfirstmahasiswa(LM,AM);
            system("CLS");
            printdatamahasiswa(LM);
            system("PAUSE");
        } else if (no == 3) {
            system("CLS");
            inputrelasi(LR,LD,LM);
            cout << endl;
            system("CLS");
            printListRelasi(LR);
            system("PAUSE");
        } else if (no == 4) {
            system("CLS");
            tampildatadosen(LD);
            cout << endl;
            editdatadosen(LD,AD);
            cout << endl;
            tampildatadosen(LD);
            system("PAUSE");
        } else if (no > 4) {
            system("CLS");
            cout << "tidak ada pilihan selain 11 ke atas !!" << endl;
            system("PAUSE");
        }



    /** createListFilm(L);
    createElmLF(P);
    insertlastFilm(L, P);
    system("CLS");
    createElmLF(P);
    insertlastFilm(L, P);
    system("CLS");
    createElmLF(P);
    insertlastFilm(L, P);
    system("CLS");
    printFilm(L);
    editFilm(L, P);
    printFilm(L);
    cout << "Data yang ingin dihapus : ";
    cin >> x;
    deleteElmFilm(L, P, x);
    printFilm(L);

    return 0; **/
}

