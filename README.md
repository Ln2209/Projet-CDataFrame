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
### Partie I : Un CDataFrame d'entiers
- La fonction **COLUMN *create_column(char* title)** permet de créer dynamiquement une colonne vide à partir d'un titre de type char. Cette fonction est de type "COLUMN", qui est le nom de la structure qu'on a créé. Dans cette structure, elle contient le titre, la taille logique, la taille physique et les données.
- La fonction __int insert_value(COLUMN* col, int value)__ permet d'insérer une valeur dans une colonne. Avant d'insérer, il faut vérifier la disponibilité de la taille physique.
- La fonction __int delete_column(COLUMN **col)__ permet de libérer la mémoire qui a été allouée par son tableau de données et à elle-même.
- La fonction __void print_col(COLUMN* col)__ permet d'afficher le contenu de la colonne et le numéro de chaque ligne, c'est-à-dire, l'indice de la case dans laquelle se trouve la valeur à afficher.
- La fonction __int nb_occ_x(COLUMN* col, int x)__ permet d'afficher le nombre d'occurrence d'une valeur *x*.
- La fonction __int pos_x(COLUMN* col, int x)__ permet d'afficher la valeur qui se trouve à la position *x*.
- La fonction __int nb_sup_x(COLUMN*col, int x)__ permet d'afficher le nombre de valeur(s) qui sont supérieures à la valeur *x*.
- La fonction __int nb_inf_x(COLUMN*col, int x)__ permet d'afficher le nombre de valeur(s) qui sont inférieures à la valeur *x*.
- La fonction __int nb_egal_x(COLUMN*col, int x)__ permet d'afficher le nombre de valeur(s) qui sont égales à *x*.
Nous avons notamment créer un menu pour que l'utilisateur puisse choisir ce qu'il aimerait afficher.
