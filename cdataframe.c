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
    cdf->colonnes = (COLUMN **) malloc(nombre_col * sizeof(COLUMN));
    return cdf;
}

void print_cdata(CDataframe *cdf){
    for(int i = 0; i<cdf->nbr_colonnes;i++){
        print_col(cdf->colonnes[i]);
        printf("\n");
    }
}

/*
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
}*/

void ajout_col(CDataframe *cdf, COLUMN *col){
    cdf->colonnes = realloc(cdf->colonnes,(cdf->nbr_colonnes + 1)* sizeof(COLUMN));
    cdf->colonnes[(cdf->nbr_colonnes)++] = col;
}

void delete_col(CDataframe *cdf, char *title){
    int a = 0;
    for (int i = 0; i < cdf->nbr_colonnes; i++){
        if (cdf->colonnes[i]->titre == title){
            a = i;
            break;
        }
    }
    delete_column(&(cdf->colonnes[a]));

    for (int i = a;i < cdf->nbr_colonnes - 1; i++){
        cdf->colonnes[i] = cdf->colonnes[i+1];
    }
    cdf->colonnes = realloc(cdf->colonnes,(cdf->nbr_colonnes - 1) * sizeof(COLUMN));
    cdf->nbr_colonnes--;
}

int val_exist(CDataframe *cdf,int val){
    for (int i = 0; i < cdf->nbr_colonnes;i++){
        if (nb_occ_x(cdf->colonnes[i],val) > 0) {
            return 1;
        }
    }
    return 0;
}

void print_title(CDataframe *cdf){
    for (int i = 0; i < cdf->nbr_colonnes;i++) {
        printf("Le titre de la colonne %d est: %s\n",i,cdf->colonnes[i]->titre);
    }
}

void nbr_lig(CDataframe *cdf){
    printf("Le nombre de ligne est de %d\n",cdf->nbr_lignes);
}

void nbr_col(CDataframe *cdf){
    printf("Le nombre de colonne est de %d\n",cdf->nbr_colonnes);
}

int val_egal_x(CDataframe *cdf,int x){
    int occ = 0;
    for (int i = 0; i < cdf->nbr_colonnes;i++){
        occ += nb_occ_x(cdf->colonnes[i],x);
    }
    return occ;
}

int val_sup_x(CDataframe *cdf,int x){
    int val_supe_x = 0;
    for (int i = 0; i < cdf->nbr_colonnes;i++){
        val_supe_x += nb_sup_x(cdf->colonnes[i],x);
    }
    return val_supe_x;
}

int val_inf_x(CDataframe *cdf, int x){
    int val_infe_x = 0;
    for (int i = 0; i < cdf->nbr_colonnes;i++){
        val_infe_x += nb_inf_x(cdf->colonnes[i],x);
    }
    return val_infe_x;
}