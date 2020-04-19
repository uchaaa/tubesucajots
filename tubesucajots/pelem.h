#ifndef PELEM_H_INCLUDED
#define PELEM_H_INCLUDED

#include <iostream>
#define infofilm(P) P->infofilm
#define nextfilm(P) P->nextfilm
#define firstfilm(P) P.firstfilm
#define lastfilm(P) P.lastfilm
#define NIL NULL

using namespace std;

struct film{
    string film;
    string genre;
    string sutradara;
    int budget;
};

typedef struct elmFilm *adrfilm;

struct elmFilm{
    film infofilm;
    adrfilm nextfilm;
};

struct listFilm{
    adrfilm firstfilm;
    adrfilm lastfilm;
};

void createListFilm(listFilm L);
void createElmLF(adrfilm &P);
void insertlastFilm(listFilm &L, adrfilm P);
void editFilm(listFilm &L, adrfilm P);
void deletefirstFilm(listFilm &L, adrfilm &P);
void deletelastFilm(listFilm &L, adrfilm &P);
void deleteElmFilm(listFilm &L, adrfilm &P);
adrfilm caridataFilm(listFilm L, string x);
void printFilm(listFilm L);


#endif // PELEM_H_INCLUDED
