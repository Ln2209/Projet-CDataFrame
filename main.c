#include "liste.h"
#include <stdio.h>

int main() {
    COLUMN *mycol_int = create_column("My column int");

    insert_value(mycol_int,32);
    insert_value(mycol_int,1);
    insert_value(mycol_int,2);
 //   if (InsertVal == 1) {
   //     printf("Value added successfully to my column\n");
   // } else {
     //   printf("Error adding value to my column\n");
    //}
    print_col(mycol_int);

    COLUMN_CHAR *mycol_c = create_column_char(CHAR,"My column char");
    char a = 'A',b = 'B';
    insert_value_c(mycol_c,&a);
    insert_value_c(mycol_c,NULL);
    insert_value_c(mycol_c,&b);


}