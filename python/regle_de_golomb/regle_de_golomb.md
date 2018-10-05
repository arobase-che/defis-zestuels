Bonjour,  

Voici un exo pour s'entrainer avec Python. ! :)  

### Présentation

En mathématiques, une **règle de Golomb** est une règle, munie de marques à des positions entières, telle que deux paires de marques ne soient jamais à la même distance ; en d'autres termes, chaque couple de marques mesure une longueur différente des autres.  

**Exemple de règle** (source: Wikipédia) : 

![Image utilisateur](https://user.oc-static.com/files/327001_328000/327930.png)

Quelques définitions :  

-   l'**ordre** d'une règle de Golomb signifie le nombre de marques présentes. La règle ci-dessus est d'*ordre* 4.
-   la **longueur** d'une règle de Golomb représente l’écart maximal entre 2 de ses marques. (par convention, la règle commence à zéro, donc c'est la valeur de la plus haute marque). La *longueur* de la règle ci-dessus vaut 6.
-   une règle de Golomb est dite **optimale** si sa *longueur* est la longueur minimale pour son *ordre*. La règle ci-dessus est *optimale*.
-   une règle de Golomb est dite **parfaite** si elle permet de mesurer toutes les longueurs entre 1 et n (n = *longueur*). La règle ci-dessus est aussi *parfaite*.

La recherche s’intéresse beaucoup à ces règles, notamment du fait qu'il est très difficile de vérifier qu'une règle un peu grande est optimale. C'est l'un des objets du projet de calcul distribué **distributed.net** ([page du projet](https://www.distributed.net/OGR)). Pour vous faire une idée, le dernier résultat en date est la longueur d'une règle d'ordre 26... Mais rassurez vous, nous ne ferons que des choses abordables en terme de temps de calcul. ! ;)  

Pour avoir plus d'informations, ou si vous ne comprenez pas quelque chose, vous pouvez consulter la page [Wikipédia](https://fr.wikipedia.org/wiki/R%C3%A8gle_de_Golomb).  

### Ce que vous devez faire :

#### Exercice 1 (niveau facile) :

Coder une fonction qui prends une règle candidate en entrée (même format que sur l'image), et retourne un tuple de booléens (Valide, Parfaite).  

#### Exercice 2 (niveau moyen) :

Réaliser une fonction prenant en paramètre un ordre et une longueur, et retournant toutes les règles de Golomb trouvées pour ces paramètres.