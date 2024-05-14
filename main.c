#include "column.h"
#include "cdataframe.h"
#include <stdio.h>

int main() {
    /*
    // Présentation des fonctionalités
    int restart, functionality;
    printf("Voici les fonctionnalites dont nous disposons pour le moment: ");
    printf("\n 1 - Creer un CDataFrame Vide Creer une colonne");
    printf("\n 2 - Remplissage du CDataFrame à partir des saisies utilisateurs Inserer un nombre de valeur saisie et verifier si chaque valeur a bien ete ajoute");
    printf("\n 3 - Afficher la colonne");
    printf("\n 4 - Supprimer la colonne");
    printf("\n 5 - Afficher le nombre d'occurrence d'une valeur choisi par l'utilisateur");
    printf("\n 6 - Afficher la valeur a l'emplacement d'une valeur choisi par l'utilisateur");
    printf("\n 7 - Afficher le nombre de valeur superieur a une valeur choisi par l'utilisateur");
    printf("\n 8 - Afficher le nombre de valeur inferieur a une valeur choisi par l'utilisateur");

    // Choix des fonctionalités
    int NbCases;
    char titrecolonne[100];
    int i, nombre_valeur_insere, val, insertion_valeur;
    int nombre_occurrence, x;
    int val_position_x;
    int nombre_supérieur_x;
    int nombre_inférieur_x;
    printf("\nPour acceder aux fonctionnalites, veuillez ecrire les numeros auxquels elles correspondent");
    restart = 1;
    while (restart == 1) {
        printf("\nA quelle fonctionnalite voulez-vous acceder ?");
        scanf(" %d", &functionality);
        if (functionality == 1) {
            printf("Combien de colonne voulez-vous creer dans le CDataFrame ?");
            scanf("%d", &NbCases);
            CreationCDataFrameVide(NbCases);
            printf("Le CDataFrame a ete cree avec succes !");
        }
        if (functionality == 2) {
            for (i = 0; i)
            printf("Comment voulez-vous appeler la colonne ?");
            scanf(" %s", &titrecolonne);
            COLUMN *mycol = create_column(titrecolonne);
            printf("La premiere colonne %s a bien ete creer", titrecolonne);
            printf("Combien de valeur voulez-vous inserer ?");
            scanf("%d", &nombre_valeur_insere);
            for (i = 0; i < nombre_valeur_insere; i++) {
                printf("Entrez la valeur:");
                scanf("%d", &val);
                insertion_valeur = insert_value(titrecolonne, val);
                if (insertion_valeur == 1) {
                    printf("Value added successfully to my column\n");
                }
                else {
                    printf("Error adding value to my column\n");
                }
            }
        }
        if (functionality == 3) {
            printf("Voici l'affichage de la colonne: ");
            print_col(titrecolonne);
        }
        if (functionality == 4) {
            delete_column(titrecolonne);
            printf("Votre colonne a bien ete supprime !");
        }
        if (functionality == 5) {
            printf("Pour quelle valeur voulez-vous connaitre toute(s) le(s) occurrence(s) ?");
            scanf("%d", &x);
            nombre_occurrence = nb_occ_x(titrecolonne, x);
            printf("Il y a %d nombre(s) d'occurrence(s) de %d", nombre_occurrence, x);
        }
        if (functionality == 6) {
            printf("Pour quelle emplacement voulez- vous connaitre la valeur ?");
            scanf("%d", &x);
            val_position_x = pos_x(titrecolonne, x);
            printf("\nLa valeur a la position de %d est %d", x, val_position_x);
        }
        if (functionality == 7) {
            printf("Pour quelle valeur voulez-vous connaitre le nombre de valeur(s) superieur(s) ?");
            scanf("%d", &x);
            nombre_supérieur_x = nb_sup_x(titrecolonne, x);
            printf("\nIl y a %d valeur(s) superieur(s) a %d", nombre_supérieur_x, x);
        }
        if (functionality == 8) {
            printf("Pour quelle valeur voulez-vous connaitre le nombre de valeur(s) inferieur(s) ?");
            scanf("%d", &x);
            nombre_inférieur_x = nb_inf_x(titrecolonne, x);
            printf("\nIl y a %d valeur(s) inferieur(s) a %d", nombre_inférieur_x, x);
        }
        printf("\nSouhaitez-vous utiliser une autre fonctionnalite ?");
        printf("\n0 - Non");
        printf("\n1 - Oui");
        scanf("%d", &restart);
    }
  
     /* COLUMN_CHAR *mycol_c = create_column_char(CHAR,"My column char");
    char a = 'A',b = 'B';
    insert_value_c(mycol_c,&a);
    insert_value_c(mycol_c,NULL);
    insert_value_c(mycol_c,&b);*/
}