#include "column.h"
#include "cdataframe.h"
#include <stdio.h>

int main() {

    // Présentation des fonctionnalités
    /*int restart, functionality,menu;
    printf("Choisir entre menu 1 et menu 2?");
    scanf("%d",&menu);
    if (menu == 1) {
        printf("Voici les fonctionnalites dont nous disposons pour le moment: ");
        printf("\n 1 - Creer un CDataFrame Vide Creer une colonne");
        printf("\n 2 - Remplissage du CDataFrame à partir des saisies utilisateurs Inserer un nombre de valeur saisie et verifier si chaque valeur a bien ete ajoute");
        printf("\n 3 - Afficher la colonne");
        printf("\n 4 - Supprimer la colonne");
        printf("\n 5 - Afficher le nombre d'occurrence d'une valeur choisi par l'utilisateur");
        printf("\n 6 - Afficher la valeur a l'emplacement d'une valeur choisi par l'utilisateur");
        printf("\n 7 - Afficher le nombre de valeur superieure(s) a une valeur choisi par l'utilisateur");
        printf("\n 8 - Afficher le nombre de valeur(s) inferieure(s) a une valeur choisi par l'utilisateur");
        printf("\n 9 - Afficher le nombre de valeur(s) egal a une valeur choisi par l'utilisateur");

        // Choix des fonctionalités
        int NbCases;
        char titrecolonne[100];
        int i, nombre_valeur_insere, val, insertion_valeur;
        int nombre_occurrence, x;
        int val_position_x;
        int nombre_superieur_x;
        int nombre_inferieur_x;
        int nombre_egal_x;
        printf("\nPour acceder aux fonctionnalites, veuillez ecrire les numeros auxquels elles correspondent");
        restart = 1;
        while (restart == 1) {
            printf("\nA quelle fonctionnalite voulez-vous acceder ? ");
            scanf(" %d", &functionality);
            if (functionality == 1) {
                create_column(titrecolonne);
                printf("La colonne a ete cree avec succes !");
            }
            if (functionality == 2) {
                printf("Comment voulez-vous appeler la colonne ?");
                scanf(" %s", &titrecolonne);
                create_column(titrecolonne);
                printf("La premiere colonne %s a bien ete creer\n", titrecolonne);
                printf("Combien de valeur voulez-vous inserer ? ");
                scanf("%d", &nombre_valeur_insere);
                for (i = 0; i < nombre_valeur_insere; i++) {
                    printf("\nEntrez la valeur:");
                    scanf("%d", &val);
                    insertion_valeur = insert_value(titrecolonne, val);
                    if (insertion_valeur == 1) {
                        printf("Value added successfully to my column\n");
                    } else {
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
                printf("Pour quelle emplacement voulez-vous connaitre la valeur ?");
                scanf("%d", &x);
                val_position_x = pos_x(titrecolonne, x);
                printf("\nLa valeur a la position de %d est %d", x, val_position_x);
            }
            if (functionality == 7) {
                printf("Pour quelle valeur voulez-vous connaitre le nombre de valeur(s) superieur(s)?");
                scanf("%d", &x);
                nombre_superieur_x = nb_sup_x(titrecolonne, x);
                printf("\nIl y a %d valeur(s) superieur(s) a %d", nombre_superieur_x, x);
            }
            if (functionality == 8) {
                printf("Pour quelle valeur voulez-vous connaitre le nombre de valeur(s) inferieur(s)?");
                scanf("%d", &x);
                nombre_inferieur_x = nb_inf_x(titrecolonne, x);
                printf("\nIl y a %d valeur(s) qui est inferieur(s) a %d", nombre_inferieur_x, x);
            }
            if (functionality == 9) {
                printf("Pour quelle valeur voulez-vous connaitre le nombre de valeur(s) egal?");
                scanf("%d", &x);
                nombre_egal_x = nb_egal_x(titrecolonne, x);
                printf("Il y a %d valeur(s) qui est egal a %d", nombre_egal_x, x);
            }
            printf("\nSouhaitez-vous utiliser une autre fonctionnalite ?");
            printf("\n0 - Non");
            printf("\n1 - Oui\n");
            scanf("%d", &restart);
        }
    } */
    int valeurs[3][3] = {{1,4,5},{5,9,24},{43,6,89}};
    int val,x;
    CDataframe *cdf = CreationCDataFrameVide(2,3);

    COLUMN *col = create_column("Bubble");

    COLUMN *col1 = create_column("Jungle");

    COLUMN *col2 = create_column("Juju");

    col->donnee = valeurs[0];
    col->taille_log = 3;
    col1->donnee = valeurs[1];
    col1->taille_log = 3;
    col2->donnee = valeurs[2];
    col2->taille_log = 3;


    cdf->colonnes[0] = col;
    cdf->colonnes[1] = col1;

    cdf->nbr_lignes = 3;
    ajout_col(cdf,col2);

    //delete_col(cdf,"Bubble");
    printf("Entrez val : ");
    scanf("%d",&val);

    if (val_exist(cdf,val) == 1) {
        printf("Vrai\n");
    }
    else {
        printf("Faux\n");
    }
    print_title(cdf);
    nbr_lig(cdf);
    nbr_col(cdf);

    printf("Entrez une valeur pour chercher l'occurrence : ");
    scanf("%d",&x);
    printf("Occurrence = %d\n", val_egal_x(cdf,x));

    printf("Entrez une valeur pour chercher le nombre de valeur superieure : ");
    scanf("%d",&x);
    printf("nombre de valeur superieure = %d\n", val_sup_x(cdf,x));


    printf("Entrez une valeur pour chercher le nombre de valeur inferieure : ");
    scanf("%d",&x);
    printf("nombre de valeur inferieure = %d\n", val_inf_x(cdf,x));
    print_cdata(cdf);
        /*printf("\nA quelle fonctionnalite voulez-vous acceder ? ");
        scanf(" %d", &functionality);
        CDataframe *cdf = CreationCDataFrameVide(nbr_col, 0);
        if (cdf == NULL) {
            printf("Erreur lors de la création du dataframe.\n");
            return 0;
        }
        else{
            printf("Succes");
        }
        ajout_ligne(cdf, valeurs);
        printf("CDataframe cree avec %d colonne(s) et %d ligne(s):\n", cdf->nbr_colonnes, cdf->nbr_lignes);
        for (int i = 0; i < cdf->nbr_colonnes; i++) {
            printf("Colonne [%d]: ", i);
            for (int j = 0; j < cdf->colonnes[i].taille_log; j++) {
                printf("%d ", cdf->colonnes[i].donnee[j]);
            }
            printf("\n");
        }
        }



        int indice_a_supp = 0;
        int ind = supp_ligne(cdf, indice_a_supp);
        if (ind == 0) {
            printf("Valeur bien supprimee");
        } else {
            printf("Erreur");
            return -1;
        }
    } */
    /*COLUMN_CHAR *mycol_c = create_column_char(CHAR,"My column char");
    char a = 'A',b = 'B';
    insert_value_c(mycol_c,&a);
    insert_value_c(mycol_c,NULL);
    insert_value_c(mycol_c,&b);*/
    return 0;
}