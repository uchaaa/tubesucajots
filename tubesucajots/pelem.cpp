#include "pelem.h"

void createListFilm(listFilm &L){
    firstfilm(L) = NIL;
    lastfilm(L) = NIL;
}

void createElmLF(adrfilm &P){
    P = new elmFilm;

    nextfilm(P) = NIL;
    string film;
    string genre;
    string sutradara;
    int budget;
    cout << endl;
    cout << "                 | Tambah Data Film |                " << endl;
    cout << "              --------------------------             " << endl;
    cout << " --------------------------------------------------- " << endl;
    cout << " Film      : ";
    cin >> film;
    infofilm(P).film = film;
    cout << " Genre     : ";
    cin >> genre;
    infofilm(P).genre = genre;
    cout << " Sutradara : ";
    cin >> sutradara;
    infofilm(P).sutradara = sutradara;
    cout << " Budget    : ";
    cin >> budget;
    infofilm(P).budget = budget;
    cout << endl;
    cout << " ---------------- Berhasil Diinput! ---------------- " << endl;
    cout << " --------------------------------------------------- " << endl << endl;
}

void insertlastFilm(listFilm &L, adrfilm P){
    if (firstfilm(L) == NIL && lastfilm(L) == NIL){
        firstfilm(L) = P;
        lastfilm(L) = P;
        nextfilm(P) = firstfilm(L);
    } else{
        nextfilm(lastfilm(L)) = P;
        nextfilm(P) = firstfilm(L);
        lastfilm(L) = P;
    }
}

void editFilm(listFilm &L, adrfilm P){
    if (firstfilm(L) == NIL && lastfilm(L) == NIL){
        cout << endl;
        cout << " -------------- Data film tidak ada ------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    } else{
        string namafilm;
        cout << endl;
        cout << "                  | Edit Data Film |                 " << endl;
        cout << "              --------------------------             " << endl;
        cout << " --------------------------------------------------- " << endl;
        cout << " Masukkan nama film yang ingin diedit : ";
        cin >> namafilm;

        P = caridataFilm(L, namafilm);

        if (P != NIL){
            string film;
            string genre;
            string sutradara;
            int budget;

            cout << " Film      : ";
            cin >> film;
            infofilm(P).film = film;
            cout << " Genre     : ";
            cin >> genre;
            infofilm(P).genre = genre;
            cout << " Sutradara : ";
            cin >> sutradara;
            infofilm(P).sutradara = sutradara;
            cout << " Budget    : ";
            cin >> budget;
            infofilm(P).budget = budget;
            cout << endl;
            cout << " --------------- Berhasil Diedit! --------------- " << endl;
            cout << " ------------------------------------------------ " << endl << endl;
        } else{
            cout << "Film tidak ditemukan" << endl;
        }
    }
}

void deletefirstFilm(listFilm &L, adrfilm &P){
    if (firstfilm(L) == NIL && lastfilm(L) == NIL){
        cout << endl;
        cout << " -------------- Data film tidak ada ------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    } else if (nextfilm(firstfilm(L)) == firstfilm(L)){
        firstfilm(L) = NIL;
        lastfilm(L) = NIL;
        nextfilm(P) = NIL;
    } else{
        P = firstfilm(L);
        firstfilm(L) = nextfilm(P);
        nextfilm(lastfilm(L)) = firstfilm(L);
        nextfilm(P) = NIL;
    }
}

void deletelastFilm(listFilm &L, adrfilm &P){
    if (firstfilm(L) == NIL && lastfilm(L) == NIL){
        cout << endl;
        cout << " -------------- Data film tidak ada ------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    } else if (nextfilm(firstfilm(L)) == firstfilm(L)){
        firstfilm(L) = NIL;
        lastfilm(L) = NIL;
        nextfilm(P) = NIL;
    } else{
        P = lastfilm(L);
        adrfilm Q = firstfilm(L);

        while (nextfilm(Q) != P){
            Q = nextfilm(Q);
        }
        lastfilm(L) = Q;
        nextfilm(Q) = firstfilm(L);
        nextfilm(P) = NIL;
    }
}

void deleteElmFilm(listFilm &L, adrfilm &P, string x){
     if (firstfilm(L) == NIL && lastfilm(L) == NIL){
        cout << endl;
        cout << " -------------- Data film tidak ada ------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
     } else{
        adrfilm Q;
        P = caridataFilm(L, x);
        if (P == NIL){
            cout << endl;
        cout << " ----------- Data film tidak ditemukan ---------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
        } else if (P == firstfilm(L)){
            deletefirstFilm(L, P);
        } else if (P == lastfilm(L)){
            deletelastFilm(L, P);
        } else{
            Q = firstfilm(L);
            while (nextfilm(Q) != P){
                nextfilm(Q) = Q;
            }
            nextfilm(Q) = nextfilm(P);
            nextfilm(P) = NIL;
        }
        cout << endl;
        cout << " -------------- Berhasil Dihapus! --------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
     }
}

adrfilm caridataFilm(listFilm L, string x){
    adrfilm Q;

    Q = firstfilm(L);
    while (Q != lastfilm(L) && infofilm(Q).film != x){
        Q = nextfilm(Q);
    }
    if (infofilm(Q).film == x){
        return Q;
    } else{
        return NIL;
    }
}

void printFilm(listFilm L){
    if (firstfilm(L) == NIL && lastfilm(L) == NIL){
        cout << endl;
        cout << " -------------- Data film tidak ada ------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    } else{
        adrfilm P;
        int i = 0;

        P = firstfilm(L);
        cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl;
        cout << " :::              DATA FILM TERBARU               ::: " << endl;
        cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl << endl;
        while (P != lastfilm(L)){
            i = i + 1;
            cout << " ---------------------------------------------------- " << endl;
            cout << " " << i << ". Film           : " << infofilm(P).film << endl;
            cout << "    Genre          : " << infofilm(P).genre << endl;
            cout << "    Sutradara      : " << infofilm(P).sutradara << endl;
            cout << "    Budget         : " << infofilm(P).budget << endl;
            P = nextfilm(P);
            cout << " ---------------------------------------------------- " << endl;
        }

        i = i + 1;
        cout << " ---------------------------------------------------- " << endl;
        cout << " " << i << ". Film           : " << infofilm(P).film << endl;
        cout << "    Genre          : " << infofilm(P).genre << endl;
        cout << "    Sutradara      : " << infofilm(P).sutradara << endl;
        cout << "    Budget         : " << infofilm(P).budget << endl;
        cout << " ---------------------------------------------------- " << endl << endl;
    }
}
