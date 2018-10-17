# Chiffres romains

Auteur: [Nanoc](https://openclassrooms.com/fr/membres/nanoc-64301)  
[Source](https://openclassrooms.com/forum/sujet/exercices-venez-vous-entrainer-41065?page=32#message-3438816)


Vous connaissez certainement les chiffres romains et vous savez certainement que lorsqu'on n'a pas l'habitude de les utiliser, lire ou écrire un de ces nombres peut être fastidieux. 

L'exerice de ce mois va justement résoudre ce problème en vous permettant de réaliser un traducteur chiffres arabes <-> chiffres romains.

## Que sont les chiffres romains ?

Les romains utilisaient un système différent du notre pour représenter les chiffres. Ils utilisaient les principes suivants:

Les règles à utiliser varient selon les sources. Pour cet exercice, on prendra les règles précisées ci-dessous.


On utilise les symboles suivants:

```
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
```

### Règles

1. On arrange ensuite les symboles dans l'ordre décroissant pour former un nombre qui sera lu en additionnant chacune des symboles.  
Par exemple 26 peut s'écrire comme `XXVI` ou `XXIIIIII` ou encore `XVVVI`. La première version étant préférée car utilisant moins de symboles. 

2. On peut utilise des soustractions en plaçant un (et uniquement un) symbole de petite valeur juste avant un symbole de plus grande valeur. Le résultat de cette manipulation est alors la différence entre le symbole le plus grand et le plus petit.  
Exemple: `IV` = 5-1 = 4 ou bien `CIX` = 100 + 10 - 1 = 109.

3. La soustraction ne peut se faire qu'avec les symboles suivants:
    * `I` devant `V` ou `X`
    * `X` devant `L` ou `C`
    * `C` devant `D` ou `M`
Ceci implique que 49 n'est pas `IL` mais `XLIX`.

4. Il n'y a pas de nombres plus grands que 4999 dans ce système, ni de nombres plus petits que 1. 

5. On utilise toujours la combinaison de symboles la plus courte.  
Donc `XXVI` au lieu de `XVVVI`, mais `XLIX` au lieu de `IL` sinon on viole la règle 3.


## L'exercice


### Niveau 1

Comme vous pouvez vous en douter, votre programme devra "traduire" un nombre entier en chiffre romain (valide) et afficher le résultat dans la console.
Il devra également pouvoir traduire les chiffres romains sous forme de strings en nombres entiers.

Si un nombre est non-valide, le programme devra afficher un message d'erreur.

```
Entrez un nombre romain: XXVII
Votre nombre est: 27
Entrez un chiffre romain: DDXI
Votre chiffre est non-valide
...
```

### Niveau 2

Si le nombre romain entré par l'utilisateur est non-valide, votre programme devra indiquer quelle règle est violée et proposer (si possible) une correction.

```
Entrez un nombre romain: XXXXI
Votre chiffre est non-valide. Il viole la règle 5: On peut l'écrire de manière plus courte.
Le résultat serait: XLI
Ce qui donne en chiffres arabes: 41
```
