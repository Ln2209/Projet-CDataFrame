#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

COLUMN *create_column(char *title) {
    COLUMN *colonne = (COLUMN *)malloc(sizeof(COLUMN));
    if (colonne == NULL){
        return NULL;
    }
    colonne->titre = title;
    colonne->taille_phy = 0;
    colonne->taille_log = 0;
    colonne->donnee = NULL;
    return colonne;
}

int insert_value(COLUMN* col, int value) { /*Fonction pour insérer une valeur dans la colonne*/
    int NewTaillePhysique = col->taille_phy;
    if (col->taille_phy == NULL || col->taille_phy == 0) { /*Si la taille physique est null ou = 0, on créer un tableau*/
        col->donnee = (COLUMN *)malloc(REALOC_SIZE*sizeof(COLUMN));
        if (col->donnee == NULL) {
            return 0;   /*On retourne 0 si on a pas pu créer de tableau car il n'y avait pas assez de stockage*/
        }
        col->donnee[0] = value; /*Insérer la valeur*/
        col->taille_log++; /*Ajouter 1 à la taille logique*/
        col->taille_phy = REALOC_SIZE;
        return 1;
    }
    if (col->taille_log == col->taille_phy) { /*S'il n'y a plus de place dans le tableau*/
        NewTaillePhysique += REALOC_SIZE; /*On ajoute REALOC_SIZE (=256 cases)*/
        int *new_p = (int *)realloc(col->donnee, NewTaillePhysique* sizeof(int));
        if (new_p == NULL) {
            return 0;
        }
        col->donnee = new_p;
        col->donnee[col->taille_log] = value; /*Ajouter valeur à l'indice taille_log*/
        col->taille_log++;
        col->taille_phy = NewTaillePhysique;
        return 1;
    }
    /*S'il y a assez de place dans le tableau pour insérer la valeur à l'indice taille_log*/
    else { /* col->taille_log < col->taille_phy */
        col->donnee[col->taille_log] = value;
        col->taille_log++;
        return 1;
    }
}

int delete_column(COLUMN **col) {
    free((*col)->titre);
    free((*col)->donnee);
    return 0;
}

void print_col(COLUMN* col){
    int i;
    for (i = 0; i < col->taille_log; i++){
        printf("[%d] %d\n",i,col->donnee[i]);
    }
}
