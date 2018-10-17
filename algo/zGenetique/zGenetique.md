# La recherche en génétique

[Exercice](https://openclassrooms.com/forum/sujet/fait-defis-9-la-recherche-en-genetique-17658#message-6949924) proposé initialement par [GuilOooo](https://openclassrooms.com/fr/membres/guiloooo-44436).

Thèmes : chaînes de caractères, recherche de motifs.

## Mise en situation

La recherche en génétique progresse chaque jour. Elle a déjà donné d'excellents résultats, et continue d'être active. Seulement, la quantité d'informations contenue dans un brin d'ADN est simplement énorme... Il est donc logique de la traiter par ordinateur !

Les séquences ADN peuvent être représentées par un alphabet de quatre lettres : A, T, G ,C. Pour connaître la signification de ces lettres, je vous invite à consulter la [page wikipédia concernant l'ADN](https://fr.wikipedia.org/wiki/Acide_d%C3%A9soxyribonucl%C3%A9ique). Une opération courante dans le domaine est la recherche d'un gène (qui sera ici une séquence de lettres) dans une séquence ADN bien plus grande.

Nous allons donc coder un programme capable de retrouver une sous-chaîne dans un texte !

## Énoncé

Écrivez un programme qui lit un gène sur la première ligne, une séquence ADN sur la deuxième, puis qui donne la position où démarre le gène dans la séquence.

Exemple :
```
ATGC
ATTGGCCTATGCGGA
```

En sortie :
```
9
```

### Niveau 1

Écrivez le programme de recherche en utilisant l'algorithme le plus simple. Bien entendu, il est interdit de recourir à une fonction de la bibliothèque standard faisant déjà le travail, le but est que vous le fassiez vous-même. :)

### Niveau 2

Améliorez votre programme de recherche pour qu'il utilise l'algorithme de Rabin-Karp. 

L'idée est la suivante : nous allons représenter chaque lettre par un chiffre. Par exemple, A=0, T=1, G=2 et C=3. Nous pouvons alors écrire un gène, tel que ATGC, comme un nombre entier, qui vaut 123.

Pour chercher le gène, il suffit de prendre les 4 premiers caractères de la séquence, d'opérer la même conversion, puis de comparer les résultats. Il nous faut ensuite convertir les caractères 2 à 5 de la séquence, et comparer à nouveau... Mais, lorsque nous avons converti les caractères 1 à 4 tout à l'heure, nous avons en particulier converti les caractères 2 à 4 en entiers ! N'y a-t-il pas moyen d'en profiter ?

Reprenons l'exemple précédent pour nous fixer les idées. Au premier tour, de boucle, la situation était :

```
0123
0112GCCTATGCGGA
```

Comme 123 et 112 sont différents, le gène n'est pas en position 1. Nous nous décalons donc d'une case dans la séquence :

```	
_0123
A1122CCTATGCGGA
```

Donc, sachant que la séquence actuelle vaut 0112, et que le prochain caractère sera associé au nombre « 2 », comment en déduire que le prochain entier à comparer sera 1122 ?

### Niveau 3

Le code précédent constitue une bonne amélioration de la recherche naïve codée au niveau 1. Cependant, nous sommes limités par la taille des entiers que nous pouvons manipuler ! En fonction du langage, nous serons limités soit par le type natif (int ou long) soit par les performances si on peut utiliser des entiers de taille arbitraire.

Une solution à ce problème est d'utiliser un hash. L'idée est la suivante : nous allons appliquer un modulo au gène et au bloc à tester. Notez que ceci ne modifie en rien l'astuce du niveau 2 : elle fonctionne toujours. :)

En revanche, lorsque nous trouverons deux nombres égaux, nous ne seront plus complètement sûrs que les gènes correspondants le sont bien aussi, du fait du modulo. Il devient donc nécessaire de faire une comparaison textuelle en cas d'égalité. Par contre, si les deux nombres trouvés sont différents, les deux séquences sont nécessairement différentes, et il n'y a plus besoin de test (ce qui est un peu l'intérêt quand même).

## Conclusion

À l'issue de cet exercice, nous avons implémenté un algorithme efficace de recherche de sous-chaînes, qui évite « souvent » les comparaisons inutiles.

Il existe encore de nombreuses autres méthodes pour pour rechercher efficacement une sous-chaîne dans une chaîne. Vous avez de quoi vous amuser encore longtemps... :diable:

Bon courage ! :)

