#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

COLUMN *create_column(char *title) {
    COLUMN *colonne = NULL;
    return colonne;
}

int delete_column(COLUMN **col){
    free((*col)->titre);
    free((*col)->donnee);
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){

}