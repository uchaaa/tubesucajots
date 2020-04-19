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

    cout << "|       INPUT DATA FILM      |" << endl;
    cout << "-------                -------" << endl;
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
    cout << "|   TELAH BERHASIL DIINPUT   |" << endl;
    cout << "------------------------------" << endl;
    cout << " " << endl;
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
        cout << "Data Film tidak ada" << endl;
    } else{
        string namafilm;

        cout << " " << endl;
        cout << " Masukkan nama film yang ingin diedit : ";
        cin >> namafilm;

        adrfilm Q;
        Q = caridataFilm(L, namafilm);

        if (Q != NIL){
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
            cout << "|   TELAH BERHASIL DIEDIT   |" << endl;
            cout << "-----------------------------" << endl;
        } else{
            cout << "Film tidak ditemukan" << endl;
        }
    }
}

void deletefirstFilm(listFilm &L, adrfilm &P){
    if (firstfilm(L) == NIL && lastfilm(L) == NIL){
        cout << "Data Film tidak ada" << endl;
    } else if (nextfilm(firstfilm(L)) == NIL){
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
        cout << "Data Film tidak ada" << endl;
    } else if (nextfilm(firstfilm(L)) == NIL){
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
        cout << "Data Film tidak ada" << endl;
     } else{
        adrfilm Q;
        P = caridataFilm(L, x);
        if (P == NIL){
            cout << "Data Film tidak ditemukan" << endl;
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
        cout << "|    DATA BERHASIL DIHAPUS    |" << endl;
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
        cout << "Data tidak ada" << endl;
    } else{
        adrfilm P;

        P = firstfilm(L);
        while (P != lastfilm(L)){
            cout << " ------------------------------ " << endl;
            cout << " Film           : " << infofilm(P).film << endl;
            cout << " Genre          : " << infofilm(P).genre << endl;
            cout << " Sutradara      : " << infofilm(P).sutradara << endl;
            cout << " Budget         : " << infofilm(P).budget << endl;
            cout << " ------------------------------ " << endl;
            P = nextfilm(P);
        }
        cout << " ------------------------------ " << endl;
        cout << " Film           : " << infofilm(P).film << endl;
        cout << " Genre          : " << infofilm(P).genre << endl;
        cout << " Sutradara      : " << infofilm(P).sutradara << endl;
        cout << " Budget         : " << infofilm(P).budget << endl;
        cout << " ------------------------------ " << endl;
    }
}
