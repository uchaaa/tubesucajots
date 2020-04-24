#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "pelem.h"
#include "artis.h"
#include <iostream>
#include <stdlib.h>

#define infoRfilm(R) R->infoRfilm
#define infoRartis(R) R->infoRartis
#define nextR(R) R->nextR
#define firstR(R) R.firstR
#define lastR(R) R.lastR
#define NIL NULL

using namespace std;

typedef struct elmRelasi *adrR;

struct listRelasi{
    adrR firstR;
    adrR lastR;
};

struct elmRelasi{
    adrR nextR;
    adrfilm infoRfilm;
    adrartis infoRartis;
};

adrR createElmR(adrfilm P, adrartis Q);
void createListRelasi(listRelasi &L);
void insertlastRelasi(listRelasi &L, adrR R);
void printRelasi(listRelasi L);
void inputrelasi(listRelasi &lr,listFilm lp,listArtis lc);
void deleteelmtrelasiFilm(listRelasi &l,listFilm lp,adrR &p,string film);
void deleteelmtrelasi(listRelasi &l,adrR &p,string artis,string film);
void deleteelmtrelasiArtis(listRelasi &l,listArtis lc,adrR &p,string film);
void tampildatafilmtertentu(listRelasi l,string film);
void tampildataartistertentu(listRelasi l,string artis);
void jmlhtampil (listRelasi L,listArtis lc );
adrR cariRelasi(listRelasi L, string u);

#endif // RELASI_H_INCLUDED
