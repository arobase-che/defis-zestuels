# ... et des lettres

Auteur: [Nanoc](https://openclassrooms.com/fr/membres/nanoc-64301)  
[Source](https://openclassrooms.com/forum/sujet/exercices-venez-vous-entrainer-41065?page=24#message-2973867)

## Introduction

Vous connaissez très certainement le célèbre jeu télévisé "Des chiffres et des lettres". Ce que je vous propose ce mois est de coder un programme qui résoud l'autre partie du jeu, "Le mot le plus long".

Les règles du jeu sont simples mais le jeu est assez difficile. On tire au hasard 9 lettres et on cherche un mot français (orthographié correctement) écrits avec ces 9 lettres. Si on ne trouve pas de mots de 9 lettres, on cherche en 8 lettres et ainsi de suite.

Le tirage des lettres, se passe de la manière suivante. On demande au joueur si il désire une consonne ou une voyelle et on lui donne une lettre au hasard selon son choix et on recommence pour les 8 autres. Le règlement impose qu'il y ait au minimum 2 voyelles. (`Y` est une voyelle)

## L'exercice

Votre programme devra tirer au hasard des lettres selon les règles définies au-dessus.
Il devra ensuite chercher la meilleure solution possible à partir du dictionnaire suivant:

[Dictionnaire de 328 578 mots (3.5 Mo)](../mots-fr-sans-accents.txt) (source: http://documents.epfl.ch/users/m/ms/mschalle/www/liste_finale.txt)

et l'afficher à l'écran. Si il y a plusieurs solutions, libre à vous de les afficher toutes ou non.

Ce qui donne par exemple :

```
Tirage : S I N U S A M O R
Solutions possibles en 9 lettres :
MARSOUINS
SOUS-MARIN
```

Remarque concernant le dictionnaire: Le dico contient des verbes conjugués ainsi que des pluriels. Il est donc suffisament complet. Il ne contient que des caractères sans majuscules, sans accents et sans cédilles. 

Votre programme devra fonctionner avec le dictionnaire situé dans le même dossier que l'exécutable et ne pas nécessiter d'autres fichiers que celui fourni.
