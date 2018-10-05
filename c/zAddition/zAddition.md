# zAddition
## Matrice, pure algorithmique
### Objectif


L'objectif de zAddition est tout simple (ou pas) : Coder une fonction qui concatène deux matrices. Pour rappel : une matrice est un tableau à deux dimensions. Pour cet exercice, ne vous embêtez pas avec le type des données : prenez des int. ;) Une concaténation est une "fusion", c'est à dire que l'on réunit les deux matrices en une seule et ce grace à la fonction que vous allez devoir coder.
En gros, vous devez réussir à coder un algorithme faisant ceci :
Image utilisateur

La dimension 1 (M) devra être la même pour chaque matrice. La dimension 2 de la matrice finale sera la somme des dimensions 2 des deux matrices d'entrée. Pour vérifier que l'algorithme fonctionne, on affichera le résultat :

```shell
Matrice 1 :
9 6 1 0
2 8 3 4
8 7 5 5
 
Matrice 2 :
6 1 9 7 1 5
3 7 5 3 8 0
4 8 9 2 3 6
 
Fusion en cours...
 
Matrice 3 :
9 6 1 0 6 1 9 7 1 5
2 8 3 4 3 7 5 3 8 0
8 7 5 5 4 8 9 2 3 6
```

Vous vous organisez comme vous voulez. Pour la structure de votre programme, il devra contenir un main (avec l'affichage des différentes matrices puis de la matrice résultant de la concaténation) et une ou plusieurs fonction(s) pour la concaténation. Pour les matrices, ce que je vous conseille, c'est de créer les trois dans le main, avec les dimensions toutes calculées puis de les envoyer à la fonction. La correction de cette exercice sera donnée dans deux semaines environ. ^^
Je dis : Bonne chance !

crys (alias shareman)

--------------

>!secret Correction
>
>
>
>
> ### L'algorithme
>
>
>La concaténation de matrices est une chose relativement simple, courante mais qui mérite réflexion, surtout quand on débute en programmation. Supposons que je dispose de deux matrices $M1$ et $M2$ que l'on peut schématiser sous cette forme pour plus de compréhension :
>
>$M1=⎜1 8 5 2 9 6 3 0 7 4 1 8⎟$ et $M2=⎜5 2 9 6 3 0 7 4 1 ⎟$
>
>Nous aimerions les concaténer afin d'obtenir une nouvelle matrice $M3$ :
>
>$M3=⎜185296307418529630741⎟$
>
>Le nombre de colonnes de $M3$ est égal à la somme du nombre de colonnes de $M1$ et $M2$ et le nombre de lignes de $M3$ est égal au nombre de lignes de $M1$ qui est aussi égal au nombre de lignes de $M2$.
>
>Notez le contenu de $M3$, c'est comme si nous avions 'collé' $M2$ à droite de $M1$. Maintenant réfléchissons ! Pour parvenir à un tel résultat, il faut commencer par parcourir la première ligne de $M1$ et une fois arrivé au bout, on enchaîne sur $M2$ tout en copiant les valeurs récupérées à la suite dans la première ligne de $M3$. Dés qu'on arrive à la fin de la première ligne de $M2$, on refait exactement de même en recommençant sur la deuxième ligne de $M1$, en enchaînant sur la deuxième ligne de $M2$ tout en copiant les valeurs récupérées dans la deuxième ligne de $M3$, et ainsi de suite, jusqu'à ce qu'on arrive au bout de la dernière ligne de $M2$.
>
>Simple, non ? ^^
>
>### Le code
>
> Le fichier main.c :
>```c
>#include <stdio.h>
>#include <stdlib.h>
>#include <time.h>
>
>#include "main.h"
>
>int main(int argc, char **argv)
>{
>        matrice_t mat1, mat2, matc;
>
>        srand(time(NULL));
>
>        if(argc < 4)
>        {       // L'utilisateur a lancé la console sans l'invite de commande ou a voulu faire le malin
>                fprintf(stderr, "Usage : %s <nb_row> <nb_col1> <nb_col2>\n", argv[0]);
>                exit(EXIT_FAILURE);
>        }
>// On récupère les arguments du main :
>        mat1.nb_row = mat2.nb_row = atoi(argv[1]);
>        mat1.nb_col = atoi(argv[2]);
>        mat2.nb_col = atoi(argv[3]);
>
>
>// On envoie mat1 et mat2 à init pour les remplir de valeurs pseudo-aléatoires :
>        init(&mat1);
>        init(&mat2);
>// L'algorithme est appliqué :
>        zaddition(&mat1, &mat2, &matc);
>// On affiche le tout :
>        printf("Matrice 1 :\n\n");
>        affiche(&mat1);
>        printf("\nMatrice 2 :\n\n");
>        affiche(&mat2);
>        printf("\nMatrice résultant de la concaténation :\n\n");
>        affiche(&matc);
>
>        liberer(&mat1);
>        liberer(&mat2);
>        liberer(&matc);
>
>        return 0;
>}
>
>void init(matrice_t *mat)
>{
>        size_t i = 0, j = 0;
>
>        mat->val = malloc(mat->nb_row * sizeof(int *)); Allocation pour les lignes
>
>        for(i = 0; i < mat->nb_row; i++)
>        {
>                mat->val[i] = malloc(mat->nb_col * sizeof(int)); // Allocation pour les colonnes
>                for(j = 0; j < mat->nb_col; j++)
>                        mat->val[i][j] = rand() % 10; // nombre pseudo-aléatoire entre 0 et 10
>        }
>}
>
>void affiche(matrice_t *mat)
>{
>        size_t i, j;
>
>        for(i = 0; i < mat->nb_row; i++)
>        {
>                for(j = 0; j < mat->nb_col; j++)
>                        printf("%d ", mat->val[i][j]);
>                putchar('\n');
>        }
>}
>
>void zaddition(matrice_t *mat1, matrice_t *mat2, matrice_t *mat)
>{
>        size_t i, j;
>
>        mat->nb_row = mat1->nb_row;
>        mat->nb_col = mat1->nb_col + mat2->nb_col;
>
>        mat->val = malloc(mat->nb_row * sizeof(int *));
>
>        for(i = 0; i < mat->nb_row; i++)
>                mat->val[i] = malloc(mat->nb_col * sizeof(int));
>
>        for(i = 0; i < mat->nb_row; i++)
>                for(j = 0; j < mat->nb_col; j++)
>                        if(j < mat1->nb_col)
>                                mat->val[i][j] = mat1->val[i][j];
>                        else
>                                mat->val[i][j] = mat2->val[i][j - mat1->nb_col];
>}
>
>void liberer(matrice_t* mat)
>{
>    size_t i;
>    for(i = 0; i < mat->nb_row; i++)
>        free(mat->val[i]);
>    free(mat->val);
>}
>```
>
> Le fichier main.h :
>```c
>#ifndef H_MAIN
>#define H_MAIN
>
>typedef struct
>{
>        int **val;
>        size_t nb_row;
>        size_t nb_col;
>} matrice_t;
>
>void init(matrice_t *mat);
>
>void affiche(matrice_t *mat);
>
>void zaddition(matrice_t *mat1, matrice_t *mat2, matrice_t *mat);
>
>void liberer(matrice_t* mat);
>
>#endif
>```


