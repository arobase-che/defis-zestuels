

# zMath
## algorithmique, pile

### Objectif


L'objectif de cet exercice est de réaliser un calculateur d'expressions sous la forme NPI (notation polonaise inverse) en vous servant des piles. Vous devez donc vous imaginer un algorithme qui permettrait d'évaluer un calcul en NPI en retournant le résultat. Il existe un tutoriel non-officiel sur ce site traitant des piles (structure de données), vous allez devoir le lire pour mener à bien cet exercice. ;)
Mais voyons cela de plus près !

#### La notation polonaise inverse


Qu'est-ce que cette notation ? En réalité, c'est tout simple, la NPI est une notation de calculs mathématiques sous une autre forme que celle que nous avons l'habitude d'utiliser. Dans cette notation, il n'existe pas de parenthèses. Pour vous expliquer concrètement de quoi il s'agit, voici une expression mathématique simple écrite ordinairement que je vais ensuite convertir en utilisant la NPI :

$4∗(3+5)−2$

Exprimé en NPI, on obient : $35+4∗2−$

Comment ai-je fait ? En réalité, le but de la NPI est de pouvoir lire le calcul à partir du début puis, dés que l'on rencontre un opérateur ($+,−,∗,/,\^$), on applique ce dernier au deux derniers nombres lus ! Vous comprenez un peu mieux le précédent calcul j'espère. On commence par lire 3 puis 5, ensuite, on tombe sur l'opérateur '+'. On va donc additionner 3 et 5 et considérer le résultat, pour la suite, comme une valeur précédemment lue. Voici donc en détail les opérations effectuées :

Calcul NPI : $35+4∗2−$
$3+5=8$
$8∗4=32$
$32−2=30$ !

#### Pourquoi utiliser les piles ?


La pile est une structure de données que la majorité des programmeurs considère comme adaptée à l'évaluation d'expressions mathématiques en NPI. La principe de la pile et de pouvoir facilement ajouter des valeurs au sommet de la pile et de les récupérer en temps voulu à partir du sommet (LIFO : last in, first out). Imaginons que nous avons un calcul NPI à lire, nous allons lire l'expression et pour chaque nombre rencontré, nous allons l'ajouter au sommet de la pile (opération couramment nommée 'push'). Dés que l'on rencontre un opérateur, on récupère les deux dernières valeurs lues en les retirant de la pile ('pop') et en ajoutant à la pile la valeur qui résulte du calcul de ses deux valeurs par l'opérateur.

En gros, pour ceux qui se sentent à l'aise, on aurait aussi pu écrire $4∗(3+5)−2$ de cette manière :

$435+∗2−$
ou : $2435+∗−$

#### Un exemple concret


À présent, je vais vous montrer ce que doit pouvoir réaliser votre algorithme en utilisant les piles. Supposons que je veuille résoudre le calcul $435+∗2−$, l'algorithme sera :

```plain
La pile est vide
On reçoit la chaîne
   Lecture de 4 : la pile contient [4]
   Lecture de 3 : la pile contient [4,3]
   Lecture de 5 : la pile contient [4,3,5]
   Lecture de l'opérateur + :
      On récupère 3 et 5 : la pile contient [4]
      On applique l'opérateur + à 3 et 5, on obtient 8
      On ajoute 8 à la pile : la pile contient [4,8]
   Lecture de l'opérateur * :
      On récupère 4 et 8 : la pile est vide
      On applique l'opérateur * à 4 et 8, on obtient 32
      On ajoute 32 à la pile : la pile contient [32]
   Lecture de 2 : la pile contient [32,2]
   Lecture de l'opérateur - :
      On récupère 32 et 2 : la pile est vide
      On applique l'opérateur - à 32 et 2, on obtient 30
      On ajoute 30 à la pile : la pile contient [30]
Fin d'itération sur la chaîne
Renvoie de la valeur stocké dans la pile : Renvoie de 30
Résultat du calcul : 30
```



#### Où récupérer le calcul ? Quelles valeurs autorisées ?


Pour la première question, je vous laisse le choix : soit vous récupérez l'expression mathématique en NPI à partir d'un fichier et vous afficher le résultat en console, soit on demande à l'utilisateur d'entrer cette expression directement par le clavier lors de l'exécution du programme. Pour la dernière question, utiliser seulement les chiffres dans vos calculs et non les nombres à plus d'un chiffre. Pour lire un nombre dans une chaîne, c'est déjà un algorithme tout à part (pas très dur mais faites juste ce qui est demandé), tandis que récupérer un chiffre est très simple (on n'a même pas à réfléchir) et vous aurez tout le temps pour vous concentrer sur l'algorithme de lecture d'expressions en NPI, ce qui est le but de l'exercice.

Un exemple de programme pourrait être :

```shell
Saisissez le calcul NPI : 3 2 + 4 * 6 / 2 -
Résultat : 1
```

(Notez que les espaces entre les caractères ne sont pas nécessaires si vous manipulez uniquement les chiffres).

Pour les plus férus d'algorithmique, vous êtes libres d'implémenter la lecture et la récupération de nombre à plus d'un chiffre ! ^^

Merci pour votre (future) participation !
crys (alias shareman)

-----------

>!secret Correction
>
>```c
>#include <stdio.h>
>#include <stdlib.h>
>
>
>int zMath(const char* calcul, size_t taille)
>{
>    int i, temp1, temp2, final;
>    Pile* ma_pile = NULL;
>    i = temp1 = temp2 = final = 0;
>
>    for(; i < taille; i++)
>    {
>        if(calcul[i] >= '0' && calcul[i] <= '9') // si c'est un chiffre...
>            pile_push(&ma_pile,calcul[i]-'0');
>        // '-0' permet de "convertir" l'information numérique d'un caractère en "vrai" chiffre
>        else if(calcul[i] == '*')
>        { // multiplication
>            temp1 = pile_pop(&ma_pile);
>            temp2 = pile_pop(&ma_pile);
>            pile_push(&ma_pile, temp2*temp1);
>        }
>        else if(calcul[i] == '/')
>        { // division
>            temp1 = pile_pop(&ma_pile);
>            temp2 = pile_pop(&ma_pile);
>            pile_push(&ma_pile, temp2/temp1);
>        }
>        else if(calcul[i] == '+')
>        { // addition
>            temp1 = pile_pop(&ma_pile);
>            temp2 = pile_pop(&ma_pile);
>            pile_push(&ma_pile, temp2+temp1);
>        }
>        else if(calcul[i] == '-')
>        { // soustraction
>            temp1 = pile_pop(&ma_pile);
>            temp2 = pile_pop(&ma_pile);
>            pile_push(&ma_pile, temp2-temp1);
>        }
>        else // caractère invalide
>            printf(" Erreur : %c n'est pas considéré comme un caractere valide ! \n", calcul[i]);
>    }
>    final = pile_pop(&ma_pile);
>    pile_clear(&ma_pile); // au cas où ...
>    return final;
>}
>int main(void)
>{
>    char saisie[200];
>    int i;
>    printf("Votre calcul NPI : ");
>    fgets(saisie,200,stdin); // saisie
>
>    for(i = 0; i<200; i++)
>    {
>        if(saisie[i] == '\n') // là où l'utilisateur a appuyé sur entrer...
>        { // ...on marque juste la fin de chaîne pour pouvoir utiliser strlen
>            saisie[i] = '\0';
>            break;
>        }
>    }
>
>    printf("Résultat : %i", zMath(saisie,strlen(saisie)));
>    return 0;
>}
>```
>
