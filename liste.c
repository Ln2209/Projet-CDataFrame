#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

COLUMN *create_column(char *title) {
    COLUMN *colonne = (COLUMN *) malloc(sizeof(COLUMN));
    if (colonne == NULL){
        return NULL;
    }
    return colonne;
}

int delete_column(COLUMN **col) {
    free((*col)->titre);
    free((*col)->donnee);
    return 0;
}

void print_col(COLUMN* col){

}
