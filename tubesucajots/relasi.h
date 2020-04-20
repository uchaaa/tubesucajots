#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "pelem.h"
#include "artis.h"
#include <iostream>

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
adrR cariRelasi(listRelasi L, string u);

#endif // RELASI_H_INCLUDED
