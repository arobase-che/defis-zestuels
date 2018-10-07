# Un calculateur de masse molaire #

Aujourd'hui l'exercice sera de réaliser un **calculateur de masse molaire**. Cette notion de chimie n'est abordée qu'en classe de seconde générale, mais vous devriez vous en sortir même si vous êtes au collège, du moment que vous avez une bonne connaissance des molécules et des atomes.

Pour les non-initiés donc, il faut savoir que chaque atome a ce qu'on appelle une [masse molaire atomique](https://fr.wikipedia.org/wiki/Masse_molaire). Pour faire court, il s'agit de la masse que pèse une mole de cet atome. Chaque molécule a une masse molaire moléculaire, que l'on obtient en faisant la somme de tous les masses molaires atomiques des atomes qui la composent.

L’unité de la masse molaire est le <math>g.mol^-^1</math>.

## Consignes ##

Le but de l'exercice est donc de réaliser un programme qui calcule la masse molaire d'une molécule entrée par l'utilisateur, et ce grâce à un fichier texte contenant certains atomes et leur masse molaire atomique correspondante.

```sh
Entrez une molécule :
--> CO2
 
La masse molaire de cette molécule est 44.0090 g.mol-1
```

Je vous propose de commencer à travailler avec ce petit fichier texte, il sera amplement suffisant pour faire des tests et pour couvrir un bon nombre de molécules.

```text
C 12.011
O 15.999
H 1.0079
He 4.0026
Li 6.941
Cl 35.453
Na 22.989
Br 79.904
N 14.006
```

## Reconnaître un atome ##

Vous pouvez remarquer que les symboles de certains atomes prennent un caractère et d'autres deux. Quand notre programme aura à analyser l'atome de chlore (Cl), par exemple, il ne faudra pas qu'il l'interprette comme un atome de carbone (C), et un atome l (inconnu au bataillon).

## Énoncé ##
### Niveau 1 ###

Faire un programme qui gère uniquement une liste d'atomes de symbole n'ayant qu'un caractère, écrits les uns à la suite des autres.

```sh
Entrez une molécule :
--> COO
 
La masse molaire de cette molécule est 44.0090 g.mol-1
```

### Niveau 2 ###

Cette fois, votre programme devra gérer les atomes dont le symbole fait plusieurs caractères.

```sh
Entrez une molécule :
--> NaCl
 
La masse molaire de cette molécule est 58.442000 g.mol-1
```

### Niveau 3 ###

Votre programme devra gérer les coefficients.

```sh
Entrez une molécule :
--> CO2
 
La masse molaire de cette molécule est 44.0090 g.mol-1
```

### Niveau 4 ###

Votre programme devra gérer les groupes qui se répètent plusieurs fois.

```sh
Entrez une molécule :
--> (CH4)2
 
La masse molaire de cette molécule est 32.085200 g.mol-1
```
