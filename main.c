#include "liste.h"
#include <stdio.h>

int main() {
    COLUMN *mycol = create_column("My column");

    insert_value(mycol,32);
    insert_value(mycol,1);
    insert_value(mycol,2);
 //   if (InsertVal == 1) {
   //     printf("Value added successfully to my column\n");
   // } else {
     //   printf("Error adding value to my column\n");
    //}
    print_col(mycol);

}