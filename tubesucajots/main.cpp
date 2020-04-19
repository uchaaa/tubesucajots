#include "pelem.h"

int main(){
    listFilm L;
    adrfilm P;
    string x;

    createListFilm(L);
    createElmLF(P);
    insertlastFilm(L, P);
    createElmLF(P);
    insertlastFilm(L, P);
    printFilm(L);
    editFilm(L, P);
    printFilm(L);
    cout << "Data yang ingin dihapus";
    cin >> x;
    deleteElmFilm(L, P, x);
    printFilm(L);

    return 0;
}

