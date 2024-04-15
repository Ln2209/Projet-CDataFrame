#include "liste.h"
#include <stdio.h>

int main() {
    COLUMN *colonne = create_column("Entier");
    delete_column(&colonne);
    return 0;
}