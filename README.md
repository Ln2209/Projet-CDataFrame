# Projet CDataFrame
Voici le lien pour se diriger vers le github : https://github.com/Ln2209/Projet-CDataFrame.git

Bonjour et bienvenue dans notre README ! Ici, on explique comment le code marche et la fonctionnalité de chaque fonction. Ce projet se fait en binôme et notre binôme est composée de : 
- CHEN Irène
- LI Hélène

Nous sommes en première année de Prépa Math Plus (PMP) chez l'EFREI et on nous a donné comme projet au deuxième semestre : **Projet CDataFrame**.
Ce projet a pour but de créer un DataFrame en langage C. Un DataFrame est une structure qui organise les données en tables bidimensionnelles (matrice) de lignes et
de colonnes, similaire à une feuille de calcul. Nous allons donc expliquer la fonctionnalité chaque fonction de notre code. Tout d'abord, le projet est séparé en 
3 parties. La première partie consiste à créer un CDataFrame d'entiers, la deuxieme partie est similaire à la première partie mais avec quelques fonctions en plus, et enfin la troisième partie est d'avoir un CDataFrame complet. 

Voici les explications de la première partie : 
## Partie I : Un CDataFrame d'entiers
- La fonction **COLUMN *create_column(char* title)** permet de créer dynamiquement une colonne vide à partir d'un titre de type char. Cette fonction est de type "COLUMN", qui est le nom de la structure qu'on a créé. Dans cette structure, elle contient le titre, la taille logique, la taille physique et les données.
- La fonction __int insert_value(COLUMN* col, int value)__ permet d'insérer une valeur dans une colonne. Avant d'insérer, il faut vérifier la disponibilité de la taille physique.
- La fonction __int delete_column(COLUMN **col)__ permet de libérer la mémoire qui a été allouée par son tableau de données et à elle-même.
- La fonction __void print_col(COLUMN* col)__ permet d'afficher le contenu de la colonne et le numéro de chaque ligne, c'est-à-dire, l'indice de la case dans laquelle se trouve la valeur à afficher.
- La fonction __int nb_occ_x(COLUMN* col, int x)__ permet d'afficher le nombre d'occurrence d'une valeur *x*.
- La fonction __int pos_x(COLUMN* col, int x)__ permet d'afficher la valeur qui se trouve à la position *x*.
- La fonction __int nb_sup_x(COLUMN*col, int x)__ permet d'afficher le nombre de valeur(s) qui sont supérieures à la valeur *x*.
- La fonction __int nb_inf_x(COLUMN*col, int x)__ permet d'afficher le nombre de valeur(s) qui sont inférieures à la valeur *x*.
- La fonction __int nb_egal_x(COLUMN*col, int x)__ permet d'afficher le nombre de valeur(s) qui sont égales à *x*.

#### Les fonctions ci-dessus sont pour une seule colonne. Les fonctions ci-dessous auront pour but de créer un CDataFrame d'entiers.

- La fonction __CDataframe *CreationCDataFrameVide(int nombre_col, int nombre_lig)__ permet de créer un CDataFrame vide.
- La fonction __void print_cdata(CDataframe *cdf)__ permet d'afficher tout le CDataFrame.
- La fonction __void ajout_col(CDataframe *cdf, COLUMN *col)__ permet d'ajouter une colonne dans le CDataFrame.
- La fonction __void delete_col(CDataframe *cdf, char *title)__ permet de supprimer une colonne dans le CDataFrame.
- La fonction __int val_exist(CDataframe *cdf,int val)__ permet de savoir si la valeur existe ou non dans le CDataFrame (ou s'il apparaît au moins une fois).
- La fonction __void print_title(CDataframe *cdf)__ permet d'afficher le titre de chaque colonne du CDataFrame.
- La fonction __void nbr_lig(CDataframe *cdf)__ permet d'afficher le nombre de ligne du CDataFrame.
- La fonction __void nbr_col(CDataframe *cdf)__ permet d'afficher le nombre de colonne du CDataFrame.
- La fonction __int val_egal_x(CDataframe *cdf, int x)__ permet de parcourir tout le CDataFrame et d'afficher le nombre de cellules contenant la même valeur que l'utilisateur va entrer (on peut le comprendre comme l'occurrence).
- La fonction __int val_sup_x(CDataframe *cdf, int x)__ permet de parcourir tout le CDataFrame et d'afficher le nombre de cellules contenant une valeur supérieure à la valeur que l'utilisateur va entrer.
- La fonction __int val_inf_x(CDataframe *cdf, int x)__ permet de parcourir tout le CDataFrame et d'afficher le nombre de cellules contenant une valeur inférieure à la valeur que l'utilisateur va entrer.

#### Nous avons notamment créer un menu pour que l'utilisateur puisse choisir ce qu'il aimerait afficher.

## Partie I : Un CDataFrame presque parfait

Pour cette partie, nous n'avons pas pu beaucoup avancer en raison d'une manque de compréhension et notamment en manque de temps. On a pu réussir quelques fonctions mais qui n'interéagit pas avec l'utilisateur.
Le but de cette deuxième partie du projet est d'amélioré le CDataFrame précédent. 

- La fonction __COLUMN_CHAR *create_column_char(ENUM_TYPE type, char *title_c)__ permet de créer une colonne d'un type et d'un titre donnés en paramètre.
