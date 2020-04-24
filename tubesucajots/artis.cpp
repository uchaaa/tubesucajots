#include "artis.h"

void createListArtis(listArtis &L){
    firstartis(L) = NULL;
    lastartis(L) = NULL;
}
void createElmLA(adrartis &P){
    P = new elmArtis;
    prevartis(P) = NULL;
    nextartis(P) = NULL;

    string nama;
    string aktor;
    cout << endl;
    cout << "                | Tambah Data Artis |                " << endl;
    cout << "              --------------------------             " << endl;
    cout << " --------------------------------------------------- " << endl;
    cout<<" Nama Artis   : ";
    cin>>nama;
    infoartis(P).nama = nama;
    cout<<" Aktor/Aktris : ";
    cin>>aktor;
    infoartis(P).aktor = aktor;
    cout << endl;
    cout << " ---------------- Berhasil Diinput! ---------------- " << endl;
    cout << " --------------------------------------------------- " << endl << endl;
}

void insertfirstArtis(listArtis &L, adrartis P){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        firstartis(L) = P;
        lastartis(L) = P;
    }else{
       prevartis(firstartis(L)) = P;
       nextartis(P) = firstartis(L);
       firstartis(L) = P;
    }
}
void editArtis(listArtis &L, adrartis P){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        cout << endl;
        cout << " ------------- Data artis tidak ada ------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    }else{
        string namaartis;
        cout << endl;
        cout << "                  | Edit Data Film |                 " << endl;
        cout << "              --------------------------             " << endl;
        cout << " --------------------------------------------------- " << endl;
        cout << " Masukkan nama artis yang ingin diedit : ";
        cin>>namaartis;

        adrartis Q;
        Q = caridataArtis(L, namaartis);

        if(Q != NULL){
            string namaartis;
            string aktor;

            cout<<" Nama artis : ";
            cin>>namaartis;
            infoartis(P).nama = namaartis;

            cout<<" Aktor/Aktris : ";
            cin>>aktor;
            infoartis(P).aktor = aktor;
            cout << endl;
            cout << " --------------- Berhasil Diedit! --------------- " << endl;
            cout << " ------------------------------------------------ " << endl << endl;
        }else{
        cout << endl;
        cout << " ---------- Data artis tidak ditemukan ---------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
        }
    }
}
void deletefirstArtis(listArtis &L, adrartis &P){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        cout << endl;
        cout << " ------------ Artis tidak diketahui ------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    }else if(firstartis(L) == lastartis(L)){
        firstartis(L) = NULL;
        lastartis(L) = NULL;
    }else{
        P = firstartis(L);
        firstartis(L) = nextartis(P);
        prevartis(firstartis(L)) = NIL;
        nextartis(P) = NIL;
    }
}
void deletelastArtis(listArtis &L, adrartis &P){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        cout << endl;
        cout << " ------------ Artis tidak diketahui ------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    }else if(firstartis(L) == lastartis(L)){
        firstartis(L) = NULL;
        lastartis(L) = NULL;
    }else{
        P = lastartis(L);
        lastartis(L) = prevartis(P);
        prevartis(P) = NIL;
        nextartis(lastartis(L)) = NIL;
    }
}
void deleteElmArtis(listArtis &L, adrartis &P, string x){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        cout << endl;
        cout << " ---------- Data artis tidak ditemukan ---------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    }else {
        adrartis Q;

        P = caridataArtis(L,x);
        if(P == NULL){
            cout << endl;
            cout << " ---------- Data artis tidak ditemukan ---------- " << endl;
            cout << " ------------------------------------------------ " << endl << endl;
        } else if(P == firstartis(L)){
            deletefirstArtis(L,P);
        } else if(P == lastartis(L)){
            deletelastArtis(L,P);
        } else{
            Q = firstartis(L);
            while(nextartis(Q) != P){
                nextartis(Q) = Q;
            }
            nextartis(Q) = nextartis(P);
            nextartis(P) = NULL;
        }
        cout << endl;
        cout << " -------------- Berhasil Dihapus! --------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    }
}
adrartis caridataArtis(listArtis L, string x){
    adrartis Q;

    Q = firstartis(L);
    while(nextartis(Q) != NIL && infoartis(Q).nama != x){
        Q = nextartis(Q);
    }
    if(infoartis(Q).nama == x){
        return Q;
    }else{
        return NULL;
    }
}
void printArtis(listArtis L){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        cout << endl;
        cout << " ---------------- Data tidak ada ---------------- " << endl;
        cout << " ------------------------------------------------ " << endl << endl;
    }else{
        adrartis P;
        int i = 0;

        P = firstartis(L);
        cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl;
        cout << " :::              DATA ARTIS TERBARU              ::: " << endl;
        cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::: " << endl << endl;

        while(P != lastartis(L)){
            i = i + 1;
            cout << " ---------------------------------------------------- " << endl;
            cout << " " << i << ". Nama Artis     : "<<infoartis(P).nama<<endl;
            cout << "    Aktor/Aktris   : " <<infoartis(P).aktor<<endl;
            P = nextartis(P);
            cout << " ---------------------------------------------------- " << endl;
        }
        i = i + 1;
        cout << " ---------------------------------------------------- " << endl;
        cout << " " << i << ". Nama Artis     : "<<infoartis(P).nama<<endl;
        cout << "    Aktor/Aktris   : " <<infoartis(P).aktor<<endl;
        cout << " ---------------------------------------------------- " << endl << endl;
    }
}
