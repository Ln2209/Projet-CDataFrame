#include "cdataframe.h"
#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CDataframe *CreationCDataFrameVide(int nombre_col, int nombre_lig) {
    CDataframe *cdf = (CDataframe *) malloc(sizeof(CDataframe));
    if (cdf == NULL){
        return NULL;
    }
    cdf->nbr_colonnes = nombre_col;
    cdf->nbr_lignes = nombre_lig;
    cdf->colonnes = (COLUMN *) malloc(nombre_col * sizeof(COLUMN));
    for (int i = 0; i < nombre_col;i++) {
        cdf->colonnes[i].taille_log = 0;
        cdf->colonnes[i].taille_phy = 0;
        cdf->colonnes[i].donnee = NULL;
        cdf->colonnes[i].titre = NULL;
    }
    return cdf;
}

int ajout_ligne(CDataframe *cdf, int *val){
    for (int i = 0; i < cdf->nbr_colonnes;i++){
        COLUMN *col = &cdf->colonnes[i];
        if (col->taille_log == col->taille_phy){
            int new_taille = col->taille_phy + REALOC_SIZE;
            int *new_donnee = (int *) realloc(col->donnee, new_taille * sizeof(int));
            if (new_donnee == NULL) {
                printf("Erreur");
                return -1;
            }
            col->donnee = new_donnee;
            col->taille_phy = new_taille;
        }
        col->donnee[col->taille_log] = val[i];
        col->taille_log++;
    }
    cdf->nbr_lignes++;
    return 0;
}

int supp_ligne(CDataframe *cdf, int indice){
    for (int i = 0; i < cdf->nbr_colonnes;i++) {
        COLUMN *col = &cdf->colonnes[i];
        if (indice < col->taille_log){
            for (int j = indice; j < col->taille_log; j++){
                col->donnee[j] = col->donnee[j+1];
            }
            col->taille_log--;
            free(&col->donnee[indice]);
        }
    }
    cdf->nbr_lignes--;
    return 0;
}