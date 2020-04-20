#ifndef ARTIS_H_INCLUDED
#define ARTIS_H_INCLUDED

#include <iostream>
#define infoartis(P) P->infoartis
#define nextartis(P) P->nextartis
#define prevartis(P) P->prevartis
#define firstartis(P) P.firstartis
#define lastartis(P) P.lastartis
#define NIL NULL

using namespace std;

struct artis{
    string nama;
    string aktor;
};

typedef struct elmArtis *adrartis;

struct elmArtis{
    artis infoartis;
    adrartis nextartis;
    adrartis prevartis;
};

struct listArtis{
    adrartis firstartis;
    adrartis lastartis;
};

void createListArtis(listArtis L);
void createElmLA(adrartis &P);
void insertfirstArtis(listArtis &L, adrartis P);
void editArtis(listArtis &L, adrartis P);
void deletefirstArtis(listArtis &L, adrartis &P);
void deletelastArtis(listArtis &L, adrartis &P);
void deleteElmArtis(listArtis &L, adrartis &P, string x);
adrartis caridataArtis(listArtis L, string x);
void printArtis(listArtis L);


#endif // ARTIS_H_INCLUDED

