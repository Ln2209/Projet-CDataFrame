#include "liste.h"

int main() {
    COLUMN *mycol = create_column("My column");

    int val = 5, InsertVal;
    InsertVal = insert_value(mycol, val);
    if (InsertVal == 1) {
        printf("Value added successfully to my column\n");
    } else {
        printf("Error adding value to my column\n");
    }

    return 0;
}