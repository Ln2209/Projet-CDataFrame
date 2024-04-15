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

int delete_column(COLUMN **col);

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

typedef struct {
    COLUMN colonnes;
} CDataframe;


#endif //PROJET_C_LISTE_H
