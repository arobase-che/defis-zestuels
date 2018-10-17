# Des chiffres ...

Auteur: [Nanoc](https://openclassrooms.com/fr/membres/nanoc-64301)  
[Source](https://openclassrooms.com/forum/sujet/exercices-venez-vous-entrainer-41065?page=21#message-2866746)

## Introduction

Vous connaissez très certainement le célèbre jeu télévisé "Des chiffres et des lettres". Ce que je vous propose ce mois est de coder un programme qui résoud la partie "Le compte est bon" du jeu.

Les règles du jeu sont très simple. On prends un nombre entier au hasard entre 100 et 999 (compris). On tire également au hasard 6 nombres dans la liste {1,2,3,4,5,6,7,8,9,10,25,50,75,100} (on peut tirer plusieurs fois le meme). 
Le but du jeu est alors d'atteindre le résultat en combinant les 6 chiffres tirés avec les 4 opérations élémentaires (+,-,*,/) et autant de parenthèses que nécessaire. On est pas obligé d'utiliser tous les nombres.
Si on arrive pas à obtenir le résultat, alors on cherche à atteindre le nombre le plus proche.


# L'exercice

## Niveau 1

Votre programme devra tirer un nombre au hasard ainsi que 6 autre nombres conformément aux règle spécifiées ci-dessus. Il devra ensuite chercher le moyen d'arriver au résultat en combinant les opérations élémentaires.
Il devra finalement présenter le calcul à faire pour y arriver. 

Par exemple:

```
Nombre à atteindre: 660
Nombres choisis: 1,2,10,10,3,8
Recherche de solution....
On arrive au résultat en faisant : (2*3)*(10+1)*10
```

## Niveau 2

Quand on propose un tirage, on est pas assuré qu'on puisse bien atteindre le résultat souhaité, ce qui n'est pas pratique pour les gens qui jouent. 
Le but est ici d'écrire un programme qui donne un tirage (résultat + les 6 nombres) qui assure qu'on puisse atteindre le résultat.

Votre programme ne doit pas utiliser la force brute qui consiste à essayer des combinaisons jusqu'à ce qu'on trouve une qui corresponde à ce que l'on veut.
