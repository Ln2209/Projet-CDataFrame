#include "column.h"

#ifndef PROJET_CDATAFRAME_CDATAFRAME_H
#define PROJET_CDATAFRAME_CDATAFRAME_H


typedef struct {
    COLUMN **colonnes;
    int nbr_colonnes;
    int nbr_lignes;
} CDataframe;

CDataframe *CreationCDataFrameVide(int, int);
void print_cdata(CDataframe *);
void ajout_col(CDataframe *, COLUMN *);
int val_exist(CDataframe*, int);
void print_title(CDataframe*);
void nbr_lig(CDataframe*);
void nbr_col(CDataframe *);
int val_egal_x(CDataframe *,int);
int val_sup_x(CDataframe*,int);
int val_inf_x(CDataframe*,int);
void delete_col(CDataframe *cdf, char*);
int ajout_ligne(CDataframe*, int*);
int supp_ligne(CDataframe *, int );


#endif //PROJET_CDATAFRAME_CDATAFRAME_H
