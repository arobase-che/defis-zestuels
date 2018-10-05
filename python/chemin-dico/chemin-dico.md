Salut !

Je vous propose un exercice d'algorithmique assez classique mais pas forcément évident. Comme le programme traite un grand nombre de données, les points à optimiser apparaîtront clairement.

# Principe

Le but est d'écrire un programme qui prend en entrée deux mots et qui retourne un chemin possible permettant de passer de l'un à l'autre en utilisant une chaîne de mots issus du dictionnaire. Pour passer d'un mot à l'autre, la seule opération autorisée est la **substitution d'une lettre**. On peut noter que tous les mots doivent être de la même longueur, ce qui élimine déjà une bonne partie du dictionnaire.

Par exemple, pour passer de `cat` à `dog`, voici une solution possible :

```plain
cat
cot
dot
dog
```

Et pour passer de `code` à `line` :

```plain
code
cone
lone
line
```

Ou encore :

```plain
code
bode
bade
bake
bike
dike
dine
line
```

Bien entendu, plus le mot de départ est long et moins la probabilité qu'il y ait de résultat est grande.

# Aller plus loin

Pour ajouter de la difficulté, vous pourrez vous demander **comment trouver la chaîne la plus courte** et **comment trouver toutes les chaînes possibles**. Je vous conseille de vous renseigner sur les **[graphes](https://zestedesavoir.com/tutoriels/621/algorithmique-pour-lapprenti-programmeur/401_quelques-autres-structures-de-donnees-courantes/2026_arbres/)** et les algorithmes qui permettent de répondre à ce genre de problème plus facilement.

Pensez également à toutes les optimisations que vous pourriez apporter à votre programme : certaines méthodes sont bien plus rapides que d'autres pour déterminer si passer de « cat » à « cot » est une opération valide, par exemple. D'ailleurs, quelle serait la méthode la plus rapide pour trouver tous les mots valides que l'on peut utiliser après un mot donné ?

Vous pouvez aussi vous amuser en changeant les règles de passage d'un mot à l'autre (substitution de 2 lettres, ajout/retrait d'une lettre autorisés, etc.).

# Ressources

**[Liste de 80 000 mots anglais (lien mort)](http://nhrx.org/static/files/brit-a-z.txt)** (750 Ko), version UTF-8 de la [liste originale](http://www.curlewcommunications.co.uk/wordlist.html).

**[Liste de 235 000 mots anglais](https://www.freebsd.org/cgi/cvsweb.cgi/~checkout~/src/share/dict/web2?rev=1.14.8.2;content-type=text%2Fplain)** (2.4 Mo) du projet UNIX — ne contient pas les mots au pluriel.

Voici comment vous pouvez construire votre liste de mots :

```python
# coding: utf-8

words = open('brit-a-z.txt').read().splitlines()
```

Bonne chance à vous, je posterai quelques éléments de réponse plus tard !