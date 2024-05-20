#include "column.h"
#include "cdataframe.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int restart, functionality1, functionality2;
    // Présentation des fonctionnalités
    printf("Bienvenue dans le CDataFrame");
    printf("\nVous devez d'abord choisir comment entre creer et remplir un CDataFrame");
    printf("\n1. Alimentation");
    printf("\n 1 - Creation et remplissage d'un CDataFrame a partir de saisies utilisateurs");
    printf("\n 2 - Creation et remplissage d'un CDataFrame en dur");
    printf("\nEnsuite vous aurez acces aux sous-fonctionnalites ci-dessous: ");
    printf("\n2.Affichage");
    printf("\n 1 - Afficher tout le CDataFrame");
    printf("\n3. Operation usuelles");
    printf("\n 2 - Ajouter une ligne de valeurs au CDataFrame");
    printf("\n 3 - Supprimer une ligne de valeurs du CDataFrame");
    printf("\n 4 - Ajouter une colonne au CDataFrame");
    printf("\n 5 - Supprimer une colonne du CDataFrame");
    printf("\n 6 - Renommer le titre d'une colonne du CDataFrame");
    printf("\n 7 - Vérifier l'existence d'une valeur (recherche) dans le CDataFrame");
    printf("\n 8 - Afficher les noms des colonnes");
    printf("\n4. Analyse et statistiques");
    printf("\n 9 - Afficher le nombre de lignes");
    printf("\n 10 - Afficher le nombre de colonnes");
    printf("\n 11 - Nombre de cellules contenant une valeur egale a x");
    printf("\n 12 - Nombre de cellules contenant une valeur superieure a x ");
    printf("\n 13 - Nombre de cellules contenant une valeur inferieure a x");
    printf("\nPour acceder aux fonctionnalites, veuillez ecrire le numero correspondant");
    printf("\n");
    printf("\nComment voulez-vous creer votre CDataFrame ?\n");
    scanf("%d", &functionality1);

//CDATAFRAME UTILISATEUR
    restart = 1;
    if (functionality1 == 1) {
        int nb_col, nb_lig, x;
        int val_taille;
        int l_val[val_taille];
        char titre_col[255];
        int nom_col_verif;
        printf("Combien voulez-vous de colonne(s) ? ");
        scanf("%d", &nb_col);
        printf("Combien voulez-vous de ligne(s) ? ");
        scanf("%d", &nb_lig);
        CDataframe *cdf = CreationCDataFrameVide(nb_col, nb_lig);
        printf("Votre CDataFrame avec %d colonne(s) et %d ligne(s) a bien ete cree", cdf->nbr_colonnes,
               cdf->nbr_lignes);
        COLUMN **col = (COLUMN **) malloc(nb_col * sizeof(COLUMN *));
        printf("\nVeuillez entrer le nom des colonnes\n");
        for (int i = 0; i < nb_col; i++) {
            printf("colonne %d: ", i);
            scanf(" %s", &titre_col);
            col[i] = create_column(titre_col);
            cdf->colonnes[i] = col[i];
        }
        printf("Le nom de chaque colonne a bien ete sauvegarde");
        printf("L'ajout de valeur n'est pas encore disponible");

//SOUS FONCTIONNALITE
        while (restart == 1) {
            printf("\nVeuillez a present choisir la sous-fonctionnalite qui vous plaira:\n");
            scanf("%d", &functionality2);
//print le CDataFrame
            if (functionality2 == 1) {
                print_cdata(cdf);
            }
//Ajout ligne de valeurs
            if (functionality2 == 2) {
                printf("La fonction est en commentaire car elle ne fonctionne pas");
            }
//Suppression ligne de valeurs
            if (functionality2 == 3) {
                printf("La fonction est en commentaire car elle ne fonctionne pas");
            }
//Ajout colonne
            if (functionality2 == 4) {
                nb_col += 1;
                printf("Comment voulez-vous appeler votre nouvelle colonne ?");
                scanf(" %s", &titre_col);
                for (int i = 0; i <= nb_col; i++) {
                    if (i == nb_col) {
                        col[i] = create_column(titre_col);
                        ajout_col(cdf, col[i]);
                        cdf->colonnes[i] = col[i];
                    }
                }
                printf("\nVotre nouvelle colonne a bien ete creee");
            }
//Suppression colonne
            if (functionality2 == 5) {
                printf("\nLa fonction existe, cependant, elle ne fonctionne pas");
            }
//Renommer une colonne
            if (functionality2 == 6) {
                printf("\nLa fonction n'existe pas");
            }
//Existence
            if (functionality2 == 7) {
                if (val_exist(cdf,x) == 1) {
                    printf("Elle existe\n");
                }
                else {
                    printf("Elle n'existe pas\n");
                }
            }
//Afficher titre colonne
            if (functionality2 == 8) {
                print_title(cdf);
            }
//Afficher nombre ligne
            if (functionality2 == 9) {
                nbr_lig(cdf);
            }
//Afficher nombre colonne
            if (functionality2 == 10) {
                nbr_col(cdf);
            }
//Occurrence
            if (functionality2 == 11) {
                printf("Entrez une valeur pour chercher l'occurrence : ");
                scanf("%d",&x);
                printf("Occurrence = %d\n", val_egal_x(cdf,x));
            }
//Supérieur
            if (functionality2 == 12) {
                printf("Entrez une valeur pour chercher le nombre de valeur superieure : ");
                scanf("%d",&x);
                printf("nombre de valeur superieure = %d\n", val_sup_x(cdf,x));
            }
//Inférieur
            if (functionality2 == 13) {
                printf("Entrez une valeur pour chercher le nombre de valeur inferieure : ");
                scanf("%d",&x);
                printf("nombre de valeur inferieure = %d\n", val_inf_x(cdf,x));
            }

            //RESTART
            //Restart ?
            printf("\nSouhaitez-vous utiliser une autre fonctionnalite ?");
            printf("\n0 - Non");
            printf("\n1 - Oui\n");
            scanf("%d", &restart);
        }
    }

//CDATAFRAME EN DUR
    if (functionality1 == 2) {
        int nb_col = 3;
        int nb_lig = 3;
        int x;
        //printf("Creation d'un CDataFrame avec 3 colonnes et 3 lignes");
        CDataframe *cdf = CreationCDataFrameVide(nb_col,nb_lig);
        //printf("\nCDataFrame cree avec succes");
        //printf("\nLa premier colonne s'appelle colonne 0, la deuxième colonne 1 et la troisième colonne 2");
        COLUMN *col = create_column("colonne 0");
        cdf->colonnes[0] = col;
        COLUMN *col1 = create_column("colonne 1");
        cdf->colonnes[1] = col1;
        COLUMN *col2 = create_column("colonne 2");
        cdf->colonnes[2] = col2;
        //printf("\nRemplissage du CDataFrame");
        int valeurs[3][3] = {{1,4,5},{5,9,24},{43,6,89}};
        //printf("\nLes valeurs 1, 4 et 5 pour la col0");
        col->donnee = valeurs[0];
        col->taille_log = 3;
        //printf("\nLes valeurs 5, 9 et 24 pour la col1");
        col1->donnee = valeurs[1];
        col1->taille_log = 3;
        //printf("\nLes valeurs 43, 6 et 29 pour la col2");
        col2->donnee = valeurs[2];
        col2->taille_log = 3;
        //printf("\nLes valeurs ont bien ete ajoutees");
        //SOUS FONCTIONNALITE
        while (restart == 1) {
            printf("\nVeuillez a present choisir la sous-fonctionnalite qui vous plaira:\n");
            scanf("%d", &functionality2);
//print le CDataFrame
            if (functionality2 == 1) {
                print_cdata(cdf);
            }
//Ajout ligne de valeurs
            if (functionality2 == 2) {
                printf("\nLa fonction est en commentaire car elle ne fonctionne pas");
            }
//Suppression ligne de valeurs
            if (functionality2 == 3) {
                printf("La fonction est en commentaire car elle ne fonctionne pas");
            }
//Ajout colonne
            if (functionality2 == 4) {
                nb_col += 1;
                char titre_col[255] = "COLONNE 3";
                COLUMN *col3 = create_column(titre_col);
                cdf->colonnes[3] = col3;
                ajout_col(cdf, col3);
                printf("\nNouvelle colonne %s ajoutee", titre_col);
            }
//Suppression colonne
            if (functionality2 == 5) {
                printf("\nLa fonction existe, cependant, elle ne fonctionne pas");
            }
//Renommer une colonne
            if (functionality2 == 6) {
                printf("\nLa fonction n'existe pas");
            }
//Existence
            if (functionality2 == 7) {
                printf("Entrez une valeur pour chercher si elle existe: ");
                scanf("%d",&x);
                if (val_exist(cdf,x) == 1) {
                    printf("Oui, %d existe bien\n", x);
                }
                else {
                    printf("Non, %d n'existe bien\n", x);
                }
            }
//Afficher titre colonne
            if (functionality2 == 8) {
                print_title(cdf);
            }
//Afficher nombre ligne
            if (functionality2 == 9) {
                nbr_lig(cdf);
            }
//Afficher nombre colonne
            if (functionality2 == 10) {
                nbr_col(cdf);
            }
//Occurrence
            if (functionality2 == 11) {
                printf("Entrez une valeur pour chercher l'occurrence : ");
                scanf("%d",&x);
                printf("Occurrence = %d\n", val_egal_x(cdf,x));
            }
//Supérieur
            if (functionality2 == 12) {
                printf("Entrez une valeur pour chercher le nombre de valeur superieure : ");
                scanf("%d",&x);
                printf("Nombre de valeur superieure a %d : %d\n",x, val_sup_x(cdf,x));
            }
//Inférieur
            if (functionality2 == 13) {
                printf("Entrez une valeur pour chercher le nombre de valeur inferieure : ");
                scanf("%d",&x);
                printf("Nombre de valeur inferieure a %d : %d\n",x, val_inf_x(cdf,x));
            }

            //RESTART
            //Restart ?
            printf("\nSouhaitez-vous utiliser une autre fonctionnalite ?");
            printf("\n0 - Non");
            printf("\n1 - Oui\n");
            scanf("%d", &restart);
        }
    }
    return 0;
    }