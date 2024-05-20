#include "column.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

COLUMN *create_column(char *title) {
    COLUMN *colonne = (COLUMN *)malloc(sizeof(COLUMN));
    if (colonne == NULL){
        return NULL;
    }
    colonne->titre = strdup(title);
    colonne->taille_phy = 0;
    colonne->taille_log = 0;
    colonne->donnee = NULL;
    return colonne;
}

int insert_value(COLUMN* col, int value) { /*Fonction pour insérer une valeur dans la colonne*/
    int NewTaillePhysique = col->taille_phy;
    if (col->taille_phy == 0) { /*Si la taille physique est égal à 0, on crée un tableau*/
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

void delete_column(COLUMN **col) {
    free((*col)->donnee);
    (*col)->donnee = NULL;
    free(*col);
    *col = NULL;
}


void print_col(COLUMN* col){
    int i;
    for (i = 0; i < col->taille_log; i++){
        printf("[%d] %d\n",i,col->donnee[i]);
    }
}

int nb_occ_x(COLUMN* col, int x) {
    int i, occurrence = 0;
    for (i = 0; i < col->taille_log; i++) {
        if (x == col->donnee[i]) {
            occurrence += 1;
        }
    }
    return occurrence;
}

int pos_x(COLUMN* col, int x) {
    int valeur_position_x;
    valeur_position_x = col->donnee[x];
    return valeur_position_x;
}

int nb_sup_x(COLUMN*col, int x) {
    int nombre_superieur_x = 0, i;
    for (i = 0; i < col->taille_log; i++) {
        if (x < col->donnee[i]) {
            nombre_superieur_x += 1;
        }
    }
    return nombre_superieur_x;
}

int nb_inf_x(COLUMN*col, int x) {
    int nombre_inferieur_x = 0, i;
    for (i = 0; i < col->taille_log; i++) {
        if (x > col->donnee[i]) {
            nombre_inferieur_x += 1;
        }
    }
    return nombre_inferieur_x;
}

int nb_egal_x(COLUMN *col, int x) {
    int nombre_egal_x = 0;
    for(int i = 0; i < col->taille_log; i++) {
        if (x == col->donnee[i]){
            nombre_egal_x += 1;
        }
    }
    return nombre_egal_x;
}

//Partie 2

COLUMN_CHAR *create_column_char(ENUM_TYPE type, char *title_c){
    COLUMN_CHAR *colonne_c = (COLUMN_CHAR *)malloc(sizeof(COLUMN_CHAR));
    if (colonne_c == NULL){
        return NULL;
    }
    colonne_c->title_c = title_c;
    colonne_c->column_type = type;
    colonne_c->data = NULL;
    colonne_c->max_size = 0;
    colonne_c->size = 0;
    colonne_c->index = NULL;
    return colonne_c;
}

/*int insert_value_c(COLUMN_CHAR *col, void *value_2){
    int NewTaillePhysique_c = col->max_size;
    if (col->max_size == NULL || col->max_size == 0) { //Si la max_size est null ou = 0, on créer un tableau
        col->data = (COLUMN_CHAR *)malloc(REALOC_SIZE*sizeof(COLUMN_CHAR));
        if (col->data == NULL) {
            return 0;   //On retourne 0 si on a pas pu créer de tableau car il n'y avait pas assez de stockage
        }
        col->data[0] = value_2; //Insérer la valeur
        col->size++; //Ajouter 1 à size
        col->max_size = REALOC_SIZE;
        return 1;
    }
    if (col->size == col->max_size) { //S'il n'y a plus de place dans le tableau
        NewTaillePhysique_c += REALOC_SIZE; //On ajoute REALOC_SIZE (=256 cases)
        int *new_p_2 = (char *)realloc(col->data, NewTaillePhysique_c* sizeof(char));
        if (new_p_2 == NULL) {
            return 0;
        }
        col->data = new_p_2;
        col->data[col->size] = value_2; //Ajouter valeur à l'indice size
        col->size++;
        col->max_size = NewTaillePhysique_c;
        return 1;
    }
    //after checking memory
    switch(col->column_type){
        case INT:
            col->data[col->size] = (int*) malloc (sizeof(int));
            *((int*)col->data[col->size])= *((int*)value_2);
            break;
        case CHAR:
            col->data[col->size] = (char*) malloc (sizeof(char));
            *((char*)col->data[col->size])= *((char*)value_2);
            break;
        case FLOAT:
            col->data[col->size] = (float*) malloc (sizeof(float));
            *((float*)col->data[col->size])= *((float*)value_2);
            break;
        case UINT:
            col->data[col->size] = (unsigned int*) malloc(sizeof(unsigned int));
            *((unsigned int*)col->data[col->size])= *((unsigned int*)value_2);
            break;
        case DOUBLE:
            col->data[col->size]= (double*) malloc(sizeof(double));
            *((double*)col->data[col->size])= *((double*)value_2);
            break;
        case STRING:
            col->data[col->size]= malloc(strlen((char*)value_2));
            strcpy((char*)col->data[col->size],(char*)value_2);
            break;
        case STRUCTURE:
            col->data[col->size]= malloc(sizeof(struct column));
            memcpy(col->data[col->size],value_2, sizeof(struct column));
            break;
        case NULLVAL:
            break;
    }
    ...
    col->size++;
    ...
}

//S'il y a assez de place dans le tableau pour insérer la valeur à l'indice taille_log
    else { // col->taille_log < col->taille_phy
        col->data[col->size] = value_2;
        col->size++;
        return 1;
    }
}


void delete_column_c(COLUMN **col){
    free((*col)->donnee);
    free((*col)->titre);
    free(*col);
    *col = NULL;
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
    insert_value_c();
    switch(col->column_type){
        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case CHAR:
            snprintf(str,size,"%c", *((char*)col.data[i]));
            break;
        case UINT:
            snprintf(str,size,"%d", *((unsigned int*)col.data[i]));
            break;
        case FLOAT:
            snprintf(str,size,"%lf",*((float*)col.data[i]));
    }

}
*/