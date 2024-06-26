#ifndef PROJET_C_COLUMN_H
#define PROJET_C_COLUMN_H
#define REALOC_SIZE 256

typedef struct {
    char *titre;
    int taille_phy;
    int taille_log;
    int *donnee;
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int nb_occ_x(COLUMN*col, int x);
int pos_x(COLUMN*col, int x);
int nb_sup_x(COLUMN*col, int x);
int nb_inf_x(COLUMN*col, int x);
int nb_egal_x(COLUMN*col, int x);

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

struct column {
    char *title_c;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};

typedef struct column COLUMN_CHAR;

COLUMN_CHAR *create_column_char(ENUM_TYPE type, char *title_c);

int insert_value_c(COLUMN_CHAR *col, void *value_c);
void delete_column_c(COLUMN **col);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

#endif //PROJET_C_COLUMN_H