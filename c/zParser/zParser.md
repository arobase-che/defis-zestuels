
Faisons une vraie calculette !



Note : cet exercice est inspiré d'un atelier qui fût organiser sur le forum « autres langages ». Vous pouvez aller lire cette discussion et y participer si vous avez quelque chose de nouveau à y ajouter ! Cependant, ce topic comprend plusieurs solutions, dont certaines en langage C. Méfiez-vous ! Je vous conseille d'essayer par vous-mêmes avant de voir comment les autres ont fait. En ayant essayé par vous-mêmes, vous repérerez où sont les difficultés, et vous profiterez d'autant mieux de la lecture de ce topic.

C'est parti !

Introduction



Savez-vous ce qu'est un parser ? Il s'agit d'un bout de code dont le but est d'analyser une chaîne de caractères afin d'en dégager la structure. Par exemple, si je vous donne la chaîne `3+2*(4-3)`, un parser pourrait la transformer en arbre, comme ceci :


```plain
Arbre :
    +
  /   \
3       *
      /   \
    2       -
          /   \
        4       3
```



Bien entendu, les parsers peuvent servir à beaucoup de choses, depuis l'analyse d'expressions mathématiques simples jusqu'à l'analyse de codes sources. Le parsing est la première étape qu'effectue votre compilateur de C favori pour produire un exécutable. Il s'agit de l'étape permettant « comprendre » le code. :)

Les parsers sont des outils très utiles qui vous serviront très probablement à un moment donné. Cependant, cet exercice traitera uniquement d'expressions mathématiques, je vais donc me focaliser là-dessus.

L'arbre correspondant à l'expression du premier exemple pourrait être représenté par la structure suivante :
```c
/* Un nœud de l'arbre peut être soit un opérateur (+,-,/,*), soit
   un nombre. On prévoit une énumération pour pouvoir rajouter des cas. */
enum type
{
    OPERATEUR,
    NOMBRE
};
typedef enum type type_e;
 
/* La structure qui contient les informations d'un nœud. L'arbre
   tout entier sera représenté par le nœud racine. */
struct arbre
{
    type_e        type;   /* Opérateur ou nombre ? */
    int           valeur; /* Valeur du nombre/code ascii de l'opérateur. */
    struct arbre *gauche; /* Pointeur vers le sous-arbre gauche. */
    struct arbre *droit;  /* Idem avec le sous-arbre droit. */
};
typedef struct arbre arbre_s;
/* Bien entendu, dans le cas d'un nombre, les deux pointeurs valent NULL. */
```


Une fois que l'arbre a été construit, nous pouvons le manipuler, par exemple pour calculer la valeur de l'expression mathématique.

Pourquoi s'embêter à construire l'arbre ? Ne pouvons-nous pas calculer la valeur au fur et à mesure de l'analyse ?



C'est juste, mais en procédant ainsi, on perd en flexibilité. Et si notre but n'était pas simplement de calculer la valeur, mais de transcrire la formule dans une autre notation ? Ou encore, si la formule comporte des variables dont nous ne connaîtrons la valeur que plus tard, comment faire ? Nous pourrions aussi imaginer calculer la dérivée d'une fonction dont on connaîtrait la formule, etc.

Comme vous le voyez, les possibilités sont nombreuses ! Nous nous servirons de cet analyseur dans d'autres exercices, plus tard. Il sera alors important de disposer de l'arbre, plutôt que de tout calculer directement. ;)

### Consignes 


Écrivez un programme qui :

    1. lit une expression mathématique sur l'entrée standard ;
    2. l'analyse pour en construire l'arbre ;
    3. calcule la valeur.


L'expression mathématique tiendra sur une seule ligne et ne fera pas plus de 200 caractères, en comptant le '\n' et le '\0' terminaux.

La nature des expressions, autrement dit le « langage » dans lequel les formules seront données, dépend du niveau de difficulté choisi.

### Objectifs 

 + Chercher par soi-même sur Internet.
 + Découvrir ce qu'est un parser, comment ça marche.
 + Implémenter un algorithme connu.
 + Manipuler les chaînes de caractères.

### Énoncé

##### Niveau 1


Dans ce niveau, les formules vous sont données en (notation polonaise inversée)[https://fr.wikipedia.org/wiki/Notation_polonaise_invers%C3%A9e]. C'est un nom technique, mais il n'y a rien de compliqué ; si vous savez parler comme maître Yoda, vous connaissez déjà. Au lieu d'avoir des opérations de la forme « 3+2 », elles sont de la forme « 3 2 + ». Ainsi,

```plain
(3+2)*5/4
```

s'écrit en notation polonaise inverséee :
```plain
3 2 + 5 * 4 /
```

Les règles pour comprendre une formule écrite à l'aide de cette notation sont les suivantes. Prenez une pile, initialement vide, et lisez les symboles (nombre ou opérateur) un par un. Pour chaque symbole :

 - s'il s'agit d'un nombre, ajoutez-le au sommet de la pile ;
 - s'il s'agit d'un opérateur, dépilez deux nombres, appliquez-leur l'opération, empilez le résultat.


Cette notation a pour caractéristique particulière qu'elle est facile à parser. Comme vous avez pu le constater sur l'exemple, il n'y a jamais besoin de parenthèses avec cette notation : les expressions sont non-ambiguës ! Nous n'avons pas non-plus besoin de priorité des opérateurs, puisque les opérations apparaissent dans l'ordre où elles sont effectuées.

Voilà, vous avez toutes les clés en main pour réussir le niveau 1. Vous pouvez gérer les opérateurs que vous voulez, mais au moins +, -, *, et ^ (puissance).

Bonne chance ! :)

**Bonus** : toutes les formules données en notation polonaise inversée peuvent être écrites de façon à ce que tous les opérateurs soient à la fin. Par exemple,

```plain
3 2 + 5 * 4 /
```
peut s'écrire :
```plain
4 5 2 3 + * /
```

#### Niveau 2


Pour le niveau 2, nous allons parser une expression mathématique de « tous les jours ».

Cette fois-ci, ce ne sera pas aussi simple, d'une part car il s'agit d'un langage plus compliqué, d'autre part car je vous guiderai moins. :)

Je vais vous donner le langage que vous avez à parser sous la forme d'une [grammaire formelle](https://fr.wikipedia.org/wiki/Grammaire_formelle). Elle rentre dans la catégorie des [grammaires algébriques](https://fr.wikipedia.org/wiki/Grammaire_alg%C3%A9brique), qui peuvent être reconnues grâce à un [automate à pile](https://fr.wikipedia.org/wiki/Automate_%C3%A0_pile).



```shell
E -> (E)
E -> E+E
E -> E-E
E -> E*E
E -> E/E
E -> N
N -> n'importe quel entier positif
```



Cette grammaire est donnée par un ensemble de *règles* ; ici, E signifie « Expression » et N « nombre ». La première règle se lit comme suit : « une expression peut être formée d'un symbole '(', suivi d'une expression, suivi du symbole ')' ». La deuxième règle se lit : « une expression peut être formée d'une expression suivie du symbole '+', suivi d'une autre expression ». Et ainsi de suite...

Une approche naïve est de tenter d'appliquer ces règles l'une après l'autre. Par exemple, pour la deuxième règle, on cherche un symbole « + » dans la chaîne, puis on analyse ce qui se trouve à gauche et à droite dudit symbole. Si on ne trouve aucun symbole « + », on essaie le symbole « - », puis « * », etc. Il est alors simple de construire l'arbre au fur et à mesure. La gestion des parenthèses et alors un poil délicate, mais l'idée reste la même. :)

Une autre méthode consiste en utiliser un algorithme d'analyse connu. Un bon exemple est [l'analyse LR](https://fr.wikipedia.org/wiki/Analyse_LR), sur laquelle vous pouvez trouver de nombreuses informations sur le Web. Notez qu'il vous faudra peut-être modifier la grammaire pour l'adapter à l'algorithme que vous vous proposer d'utiliser. On peut en effet effectuer certaines transformations sur la grammaire sans pour autant en changer le sens. En outre, certains algorithmes demandent des grammaires écrites sous une forme bien précise. Je ne vous en dit pas plus, je vous laisse vous débrouiller. :)

Le mot d'ordre pour le niveau 2 est : n'hésitez pas à chercher sur le Web. Je ne parle pas de copier/coller des codes tout faits, bien entendu, mais plutôt de chercher quelles techniques et quels algorithmes existent, puis de tenter de les implémenter. N'oubliez pas que le forum est là pour vous aider !

Bon courage à tous ! ;)

*Bonus* : plutôt que de calculer la valeur de l'expression mathématique, pourquoi ne pas la traduire en notation polonaise inversée ?

#### Niveau 3

Le but est maintenant de rajouter une nouvelle fonctionnalité à votre parser. Il doit comprendre les variables, dont le nom sera constitué d'une unique lettre en minsucule.

Vous devez donc modifier votre programme du niveau 2 pour qu'il liste une expression mathématique comprenant des variables. Il devra ensuite demander la valeur de chacune des variables apparaissant dans l'expression, puis afficher le résultat du calcul.

### Conclusion


Bon courage à tous ! :)
GuilOooo

