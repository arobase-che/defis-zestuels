# zTri
## Récupération des secondes système, comparatif de tris

### Objectif


L'objectif de cet exercice est de réaliser un comparatif de différents algorithmes de tri en O(n²). Pour cela, vous devez savoir comment récupérer les secondes système (time.h) et connaître quelques algorithmes de tri en O(n²). En voici trois :

 + Le tri à bulles
 + Le tri par sélection
 + Le tri par insertion

On peut par exemple avoir :

```shell
Combien d'éléments voulez-vous trier ? 50000
Tri par insertion en cours ... 12 secondes
Tri par sélection en cours ... 8 secondes
Tri à bulles en cours ........ 15 secondes
```

Et pourquoi pas faire un petit classement à la fin. :) \\
Le but est bien sur que vous essayez d'implémenter les algorithmes de tris par vous-même et il serait aussi bien de compter le nombre de comparaisons/échanges pour chaque algo. ;)

Bonne chance ! ;) 

shareman

--------------


>!secret Correction
>
>```c
>#include <stdio.h>
>#include <time.h>
>#include <stdlib.h>
> 
>void tri_bulles(int* tab, size_t taille)
>{
>    unsigned short tab_en_ordre = 0; // booléen
>    unsigned i;
>    int temp;
>    while(!tab_en_ordre) // ou while(tab_en_ordre==0)
>    {
>        tab_en_ordre = 1;
>        for(i=0 ; i < taille-1 ; i++)
>        {
>            if(tab[i] > tab[i+1]) // comparaison des éléments adjascents
>            {   // échange :
>                temp = tab[i];
>                tab[i] = tab[i+1];
>                tab[i+1] = temp;
>                tab_en_ordre = 0;
>            }
>        }
>        taille--;
>    }
>}
> 
>void tri_selection(int* tab, size_t taille)
>{
>    unsigned fin = taille-1, i, plus_grand;
>    int temp;
>    while(fin > 0) // Tant que la zone de travail n'est pas nulle
>    {
>        plus_grand = 0;
>        for(i = 1 ; i <= fin ; i++)
>        {   // trouver le plus grand nombre :
>            if(tab[i] > tab[plus_grand])
>                plus_grand = i;
>        } // échange :
>        temp = tab[fin];
>        tab[fin] = tab[plus_grand];
>        tab[plus_grand] = temp;
>        fin--;
>    }
>}
> 
>void tri_insertion(int* tab, size_t taille)
>{
>    unsigned i, j;
>    int element_a_inserer, temp;
>    for(i = 1; i < taille; i++)
>    { // [boucle d'itération sur le tableau]
>        element_a_inserer = tab[i];
>        for(j = 0; j < i; j++)
>        {  // [boucle d'insertion]
>            if (element_a_inserer < tab[j])
>            {   // échange :
>                temp = element_a_inserer;
>                element_a_inserer = tab[j];
>                tab[j] = temp;
>            }
>        }
>        tab[i] = element_a_inserer;
>    }
>}
> 
>void charger_tableau(int* sauvegarde, int* tab, size_t taille)
>{
>    unsigned i;
>    for(i=0 ; i<taille ; i++)
>        tab[i] = sauvegarde[i];
>}
> 
>int hasard(int min, int max) // fonction de Natim pour les nombres aléatoires
>{
>    return (int)(min+((float)rand()/RAND_MAX*(max-min+1)));
>}
> 
>int main(void)
>{
>   srand(time(NULL));
> 
>   int* tab = NULL;
>   int* sauvegarde = NULL;
>   int taille;
>   unsigned i;
>   clock_t t1, t2; // Pour le chrono
> 
>   printf(" [zTri] Comparatif de tris \n\n"
>          " Choisissez une taille pour le tableau a trier : ");
>   scanf("%d",&taille);
>   getchar(); // avaler le '\n'
> 
>   tab = malloc(sizeof(int)*taille);
>   sauvegarde = malloc(sizeof(int)*taille);
>   /* On crée un tableau de sauvegarde pour qu'un tri suivant un autre
>      n'ai pas affaire à un tableau trié mais le même qu'au début
>      du programme */
> 
>   if(tab == NULL || sauvegarde == NULL)
>        return 1; // au cas où les malloc échouent
> 
>   for(i=0 ; i<taille ; i++)
>       sauvegarde[i] = tab[i] = hasard(0,taille+5000);
> 
>///////////////////////////////////////////////////////////////
>   printf("\n Tri a bulles en cours... ");
>   t1 = clock();
>   tri_bulles(tab,taille);
>   t2 = clock();
>   printf(" %.3lf secondes \n", (double)(t2-t1)/CLOCKS_PER_SEC);
>   charger_tableau(sauvegarde,tab,taille);
>///////////////////////////////////////////////////////////////
>   printf("\n Tri par selection en cours... ");
>   t1 = clock();
>   tri_selection(tab,taille);
>   t2 = clock();
>   printf(" %.3lf secondes \n", (double)(t2-t1)/CLOCKS_PER_SEC);
>   charger_tableau(sauvegarde,tab,taille);
>///////////////////////////////////////////////////////////////
>    printf("\n Tri par insertion en cours... ");
>   t1 = clock();
>   tri_insertion(tab,taille);
>   t2 = clock();
>   printf(" %.3lf secondes \n\n", (double)(t2-t1)/CLOCKS_PER_SEC);
>///////////////////////////////////////////////////////////////
> 
>   free(tab);
>   free(sauvegarde);
> 
>   printf(" Appuyez sur entrer pour quitter...");
>   getchar();
>   return 0;
>}
>```

