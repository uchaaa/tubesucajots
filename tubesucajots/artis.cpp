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

    cout<<"-------------- Input Data Artis --------------"<<endl;
    cout<<endl;
    cout<<"Nama Artis: ";
    cin>>nama;
    infoartis(P).nama = nama;

    cout<<"Aktor/Aktris: ";
    cin>>aktor;
    infoartis(P).aktor = aktor;
    cout<<endl;
    cout<<"-------------- Data Berhasil Diinput --------------"<<endl;
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
        cout<<"Data artis tdk ada"<<endl;
    }else{
        string namaartis;

        cout<<"Masukkan nama artis yang ingin diedit: ";
        cin>>namaartis;

        adrartis Q;
        Q = caridataArtis(L, namaartis);

        if(Q != NULL){
            string namaartis;
            string aktor;

            cout<<"Nama artis: ";
            cin>>namaartis;
            infoartis(P).nama = namaartis;

            cout<<"Aktor/Aktris: ";
            cin>>aktor;
            infoartis(P).aktor = aktor;

            cout<<"Berhasil diedit"<<endl;
        }else{
            cout<<"Artis tidak ditemukan"<<endl;
        }
    }
}
void deletefirstArtis(listArtis &L, adrartis &P){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        cout<<"Artis tidak diketahui"<<endl;
    }else if(firstartis(L) == lastartis(L)){
        firstartis(L) = NULL;
        lastartis(L) = NULL;
    }else{
        P = firstartis(L);
        nextartis(P) = NULL;
        prevartis(nextartis(P)) = NULL;
        firstartis(L) = nextartis(P);
    }
}
void deletelastArtis(listArtis &L, adrartis &P){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        cout<<"Artis tidak diketahui"<<endl;
    }else if(firstartis(L) == lastartis(L)){
        firstartis(L) = NULL;
        lastartis(L) = NULL;
    }else{
        P = lastartis(L);
        prevartis(P) = NULL;
        nextartis(prevartis(P)) = NULL;
        lastartis(L) = prevartis(P);
    }
}
void deleteElmArtis(listArtis &L, adrartis &P, string x){
    if(firstartis(L) == NULL && lastartis(L) == NULL){
        cout<<"Artis tidak ditemukan"<<endl;
    }else {
        adrartis Q;

        P = caridataArtis(L,x);
        if(P == NULL){
            cout<<"Data artis tidak ditemukan"<<endl;
        }else if(P == firstartis(L)){
            deletefirstArtis(L,P);
        }else if(P == lastartis(L)){
            deletelastArtis(L,P);
        }else{
            Q = firstartis(L);
            while(nextartis(Q) != P){
                nextartis(Q) = Q;
            }
            nextartis(Q) = nextartis(P);
            nextartis(P) = NULL;
        }
        cout<<"Data berhasil dihapus"<<endl;
    }
}
adrartis caridataArtis(listArtis L, string x){
    adrartis Q;

    Q = firstartis(L);
    while(Q != lastartis(L) && infoartis(Q).nama != x){
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
        cout<<"Data tidak ada"<<endl;
    }else{
        adrartis P;

        P = firstartis(L);
        while(P != lastartis(L)){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"Nama artis   : "<<infoartis(P).nama<<endl;
            cout<<"Aktor/Aktris : "<<infoartis(P).aktor<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            P = nextartis(P);
        }
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"Nama artis   : "<<infoartis(P).nama<<endl;
        cout<<"Aktor/Aktris : "<<infoartis(P).aktor<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
}
