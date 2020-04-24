#include "relasi.h"

adrR createElmR(adrfilm P, adrartis Q){
    adrR j = new elmRelasi;

    nextR(j) = NIL;
    infoRfilm(j) = P;
    infoRartis(j) = Q;

    return j;
}

void createListRelasi(listRelasi &L){
    firstR(L) = NIL;
    lastR(L) = NIL;
}

void insertlastRelasi(listRelasi &L, adrR R){
    if (firstR(L) == NIL && lastR(L) == NIL){
        firstR(L) = R;
        lastR(L) = R;
    } else{
        nextR(lastR(L)) = R;
        lastR(L) = R;
    }
}

void inputrelasi(listRelasi &lr,listFilm lp,listArtis lc){
    adrfilm p;
    adrartis q;
    adrR r;
    string film,artis;

    printFilm(lp);
    cout << " Masukkan nama Film yang ingin dihubungkan : ";
    cin >> film;
    cout << endl;
    p = caridataFilm(lp,film);

    if (p != NIL) {
        system("CLS");
        printArtis(lc);
        cout << endl;
        cout << " Masukkan nama Artis yang ingin dihubungkan : ";
        cin  >> artis;
        q = caridataArtis(lc,artis);

        if (q != NIL) {
            r = createElmR(p,q);
            insertlastRelasi(lr,r);
            cout << endl;
            cout << " ----------------- Berhasil Diinput! ---------------- " << endl;
            cout << " ---------------------------------------------------- " << endl << endl;
        } else {
            system("CLS");
            cout << "data artis tidak ada !!" << endl;
        }
    } else {
            system("CLS");
            cout << "data film tidak ada !!" << endl;
            system("PAUSE");
        }
        system("PAUSE");
}
void deleteelmtrelasiFilm(listRelasi &l,listFilm lp,adrR &p,string film){
    adrR q,r;

    if (firstR(l) == NIL && lastR(l) == NIL) {
        cout << endl;
        cout << " ----------------- Data kosong ------------------ " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
        p = NIL;
    } else {
        q = firstR(l);
        while (q != NIL) {
            if (infofilm(infoRfilm(q)).film == film && firstR(l) == q ) {
                p = q;
                q = nextR(q);
                firstR(l) = q;
                nextR(p) = NIL;
                infoRfilm(p) = NIL;
                infoRartis(p) = NIL;
            } else if (infofilm(infoRfilm(q)).film == film && lastR(l) == q){
                p = q;
                q = NIL;
                r = firstR(l);
                while (nextR(r) != p) {
                    r = nextR(r);
                }
                lastR(l) = r;
                nextR(r) = NIL;
                infoRfilm(p) = NIL;
                infoRartis(p) = NIL;
            } else if (infofilm(infoRfilm(q)).film == film && nextR(firstR(l)) == NIL) {
                p = q;
                q = NIL;
                firstR(l) = NIL;
                lastR(l) = NIL;
                infoRfilm(p) = NIL;
                infoRartis(p) = NIL;

            } else if (infofilm(infoRfilm(q)).film == film && nextR(r) == q) {
                p = q;
                q = nextR(q);
                nextR(r) = q;
                infoRfilm(p) = NIL;
                nextR(p) = NIL;
                infoRartis(p) = NIL;
            } else {
                r = q;
                q = nextR(q);
            }
        }

    }
}

void deleteelmtrelasiArtis(listRelasi &l,listArtis lc,adrR &p,string film){
    adrR q,r;

    if (firstR(l) == NIL && lastR(l) == NIL) {
        cout << endl;
        cout << " ----------------- Data kosong ------------------ " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
        p = NIL;
    } else {
        q = firstR(l);
        while (q != NIL) {
            if (infoartis(infoRartis(q)).nama == film && firstR(l) == q ) {
                p = q;
                q = nextR(q);
                firstR(l) = q;
                nextR(p) = NIL;
                infoRfilm(p) = NIL;
                infoRartis(p) = NIL;
            } else if (infoartis(infoRartis(q)).nama == film && lastR(l) == q){
                p = q;
                q = NIL;
                r = firstR(l);
                while (nextR(r) != p) {
                    r = nextR(r);
                }
                lastR(l) = r;
                nextR(r) = NIL;
                infoRfilm(p) = NIL;
                infoRartis(p) = NIL;
            } else if (infoartis(infoRartis(q)).nama == film && nextR(firstR(l)) == NIL) {
                p = q;
                q = NIL;
                firstR(l) = NIL;
                lastR(l) = NIL;
                infoRfilm(p) = NIL;
                infoRartis(p) = NIL;

            } else if (infoartis(infoRartis(q)).nama == film && nextR(r) == q) {
                p = q;
                q = nextR(q);
                nextR(r) = q;
                infoRfilm(p) = NIL;
                nextR(p) = NIL;
                infoRartis(p) = NIL;
            } else {
                r = q;
                q = nextR(q);
            }
        }

    }
}
void tampildatafilmtertentu(listRelasi l,string film){
    adrR p;

    if (firstR(l) == NIL) {
        cout << endl;
        cout << " ----------------- Data kosong ------------------ " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    } else {
            p = firstR(l);
            cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl;
            cout << " :::            FILM YANG DIPERANKAN              ::: " << endl;
            cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl << endl;
            while (p != NIL) {
                if (infoartis(infoRartis(p)).nama == film){
                    cout << " ---------------------------------------------------- " << endl;
                    cout << " Film           : " << infofilm(infoRfilm(p)).film << endl;
                    cout << " Genre          : " << infofilm(infoRfilm(p)).genre << endl;
                    cout << " Sutradara      : " << infofilm(infoRfilm(p)).sutradara << endl;
                    cout << " Budget         : " << infofilm(infoRfilm(p)).budget << endl;
                    cout << " ---------------------------------------------------- " << endl;
                }
                p = nextR(p);
                cout << endl;
            }
            cout << endl;
    }
}

void tampildataartistertentu(listRelasi l,string artis){
    adrR p;

    if (firstR(l) == NIL) {
        cout << endl;
        cout << " ----------------- Data kosong ------------------ " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    } else {
            p = firstR(l);
            cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl;
            cout << " :::               DIBINTANGI OLEH                ::: " << endl;
            cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl << endl;
            while (p != NIL) {
                if (infofilm(infoRfilm(p)).film == artis) {
                    cout << " ---------------------------------------------------- " << endl;
                    cout << " Nama artis   : "<<infoartis(infoRartis(p)).nama<<endl;
                    cout << " Aktor/Aktris : "<<infoartis(infoRartis(p)).aktor<<endl;
                    cout << " ---------------------------------------------------- " << endl;
                }
                p = nextR(p);
                cout << endl;
            }
            cout << endl;
    }
}

void jmlhtampil (listRelasi L,listArtis lc ){
    adrR P;
    adrartis Q;
    int i,banyak;

    i = 0;
    banyak = 0;

    if (firstR(L) == NIL && firstartis(lc) == NIL) {
        cout << endl;
        cout << " ----------------- Data kosong ------------------ " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    } else{
        // mengisi data default dari jumlah tampil mnjdi 0 //
        Q = firstartis(lc);
        while (Q != NIL){
            infoartis(Q).jumlahtampil = 0;
            Q = nextartis(Q);
        }
        // ketika menghitung banyak yg trlibat di suatu film tertentu//
        P = firstR(L);
        while (P != NIL){
            Q = infoRartis(P);
            infoartis(Q).jumlahtampil = infoartis(Q).jumlahtampil + 1;
            P = nextR(P);
        }
        // mengecek nilai maksimum jumlah tampil //
        Q = firstartis(lc);
        while (Q != NIL){
            if (infoartis(Q).jumlahtampil > banyak){
                banyak = infoartis(Q).jumlahtampil;
            }
            Q = nextartis(Q);
        }
        Q = firstartis(lc);
        cout << " ++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
        cout << " +++++++++++      ARTIS PALING TOP      +++++++++++++ " << endl;
        cout << " ++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl << endl;
        while (Q != NIL){
            if (infoartis(Q).jumlahtampil == banyak){
                cout << " Nama     : " << infoartis(Q).nama << endl;
                cout << " Kategori : " << infoartis(Q).aktor << endl;
                cout << " Telah membingtangi " << infoartis(Q).jumlahtampil << " film " << endl << endl;
                cout << " ++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl << endl;
            }
            Q = nextartis(Q);
        }
    }


}

void printRelasi(listRelasi L){
    adrR P;
    int i = 0;

    if (firstR(L) == NIL) {
        cout << endl;
        cout << " ----------------- Data kosong ------------------ " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    } else {
        P = firstR(L);
        cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl;
        cout << " :::             DATA PEMERAN TERBARU             ::: " << endl;
        cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl << endl;
        while (P != NIL){
            i = i + 1;
            cout << " ---------------------------------------------------- " << endl;
            cout << " " << i << ". Film         : " << infofilm(infoRfilm(P)).film << endl;
            cout << "    Genre        : " << infofilm(infoRfilm(P)).genre << endl;
            cout << "    Nama Pemeran : " << infoartis(infoRartis(P)).nama<< endl;
            cout << "    Aktor/Aktris : " << infoartis(infoRartis(P)).aktor<< endl;
            cout << "    Sutradara    : " << infofilm(infoRfilm(P)).sutradara << endl;
            cout << "    Budget       : " << infofilm(infoRfilm(P)).budget << endl;
            P = nextR(P);
            cout << " ---------------------------------------------------- " << endl;
        }
    }
}

