#ifndef PROJET_C_LISTE_H
#define PROJET_C_LISTE_H
#define REALOC_SIZE 256

typedef struct {
    char *titre;
    int taille_phy;
    int taille_log;
    int *donnee;
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
int delete_column(COLUMN **col);
void print_col(COLUMN* col);
int nb_occ_x(COLUMN*col, int x);
int pos_x(COLUMN*col, int x);
int nb_sup_x(COLUMN*col, int x);
int nb_inf_x(COLUMN*col, int x);
int nb_egal_x(COLUMN*col, int x);

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

typedef struct {
    COLUMN colonnes;
} CDataframe;

#endif //PROJET_C_LISTE_H