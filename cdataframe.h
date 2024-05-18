#include "column.h"

#ifndef PROJET_CDATAFRAME_CDATAFRAME_H
#define PROJET_CDATAFRAME_CDATAFRAME_H


typedef struct {
    COLUMN *colonnes;
    int nbr_colonnes;
    int nbr_lignes;
} CDataframe;

CDataframe *CreationCDataFrameVide(int, int);
int ajout_ligne(CDataframe*, int*);
int supp_ligne(CDataframe *, int );


#endif //PROJET_CDATAFRAME_CDATAFRAME_H
