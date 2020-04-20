#include "relasi.h"
#include "pelem.h"
#include "artis.h"

adrR createElmR(adrfilm P, adrartis Q){

}

void createListRelasi(listRelasi &L){
    firstR(R) = NIL;
    lastR(R) = NIL;
}

void insertlastRelasi(listRelasi &L, adrR R){
    if (firstR(L) == NIL && lastR(L) == NIL){
        firstR(L) = R;
        lastR(L) = R;
        nextR(R) = firstR(L);
    } else{
        nextR(lastR(L)) = R;
        nextfilm(R) = firstR(L);
        lastfilm(L) = R;
    }
}
}

void printRelasi(listRelasi L){

}

adrR cariRelasi(listRelasi L, string u){
    adrfilm Q;

    Q = firstR(L);
    while (Q != lastR(L) && infofilm(Q).film != u){
        Q = nextR(Q);
    }
    if (infofilm(Q).film == u){
        return Q;
    } else{
        return NIL;
    }
}
