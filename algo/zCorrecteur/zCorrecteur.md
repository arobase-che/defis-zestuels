# Un correcteur orthographique efficace


Nous allons programmer un correcteur orthographique. Il existe de nombreuses techniques pour y parvenir, nous en explorerons quelques unes au cours des trois niveaux que cet exercice propose. :)

Un correcteur orthographique, pour nous, sera un programme qui diposera d'un dictionnaire (liste de mots) et d'une entrée (chaîne de caractères arbitraire). Le correcteur vérifie que chaque mot de l'entrée est bien dans le dictionnaire. Les mots sont définis comme les séquences de caractères alphabétiques (minuscules ou majuscules), séparés par tout autre caractère (ponctuation, espaces, etc).


## Énoncé

Écrivez un programme de correction orthographique. Le dictionnaire sera stocké dans un fichier externe, et l'entrée sera l'entrée standard. La liste des mots incorrects rencontrés sera affichée sur la sortie standard.

### Niveau 1

Pour ce niveau, le dictionnaire sera donné sous forme d'un fichier texte, avec un mot par ligne. Allez, au boulot ! :)

### Niveau 2

Essayons un peu plus corsé. Notre correcteur actuel fonctionne correctement (enfin, il devrait ^^ ) mais n'est pas très rapide. En outre, le dictionnaire peut prendre une place assez conséquente...

Les [filtres de bloom](https://fr.wikipedia.org/wiki/Filtre_de_Bloom) peuvent nous aider à résoudre ce problème. L'idée est la suivante : nous allons trouver un certain nombre de fonctions de hachage, qui, à chaque chaîne de caractère, renvoie un nombre entre 0 et 100. Pour cet exemple, nous coderons quatre fonctions de hachage différentes.

Notre dictionnaire prendra alors la forme d'un tableau de 100 bits, qui sera initialisé à 00000000...000. Pour ajouter le mot « ciboulette », nous le faisons passer par les fonctions de hachage ; imaginons que nous obtenions les résultats 23, 27, 48 et 62. Il suffit alors de mettre les bits numéros 23, 27, 48 et 62 à « 1 » dans notre tableau.

Pour tester si un mot donné est dans le dico, il suffit de le faire passer par les fonctions de hachage, et de vérifier que les bits correspondants sont bien à 1 dans le filtre.

La particularité du filtre de bloom est qu'**il peut se tromper** ! En effet, 100, 1000 ou même 1 000 000 bits d'information ne permettent pas de stocker un dictionnaire de la langue française complètement. Il arrive donc qu'un mot ait des hashs dont les bits sont tous activés par d'autres mots.

Dans la pratique, ce n'est cependant pas très grave. En effet, en prenant un filtre plus grand et en choisissant correctement le nombre et le code des fonctions de hachage, on peut minimiser la probabilité d'erreur (qu'on appelle un « faux positif »). Le choix de ces paramètres est quelque peu délicat ; nous ferons au plus simple ici.

Votre mission est donc de modifier votre correcteur orthographique pour qu'il utilise un filtre de bloom. N'oubliez pas la possibilité de stocker le filtre dans un fichier. Vous aurez aussi besoin d'un moyen de créer le filtre à partir d'une liste de mots !

#### Quelle fonction de hachage choisir ?

Il y en a plein ! Une chaîne de caractères est basiquement une suite de nombre. Il suffit d'effectuer une opération sur ces nombres, par exemple la somme, le produit, ou je ne sais quoi encore, puis d'appliquer un modulo. Dans notre exemple, le résultat devra subir un modulo 100.

Quelques idées :

- somme des codes ascii de chaque caractère ;
- produit des codes ascii de chaque caractère ;
- concaténation des codes (par exemple, 13 37 65 42 donnera 13037065042) ;
- somme des codes ascii élevés au carré ;
- puissance successive des codes ascii ;
- xor (ou exclusif) des codes ascii....

Ce ne sont pas les possibilités qui manquent ! N'oubliez pas le modulo 100 à la fin. :)

### Niveau 3

Dans ce niveau, nous allons faire quelque chose de légèrement différent.

Imaginons que nous ayons détecté un mot erroné. Nous voulons allons fournir quelques suggestions pour la bonne orthographe de ce mot.

Vous allez donc écrire un programme qui, étant donné un mot, trouve le mot du dictionnaire le plus proche de celui-ci. Bien évidemment, il faudra travailler sur le dictionnaire in extenso, un filtre de bloom ne vous permettra pas de récupérer cette information. :)

Toute la difficulté est donc de calculer la « distance » entre deux mots. Voici plusieurs idées possibles :

- calculer la longueur du plus grand préfixe commun ;
- calculer le nombre de lettres qui diffèrent dans le mot ;
- calculer le nombre d'opérations (insertion/suppression/substitution) minimal nécessaires pour passer d'un mot à l'autre.

À vous de choisir celle que vous préférez. Il vous faut ensuite trouver le(s) mot(s) du dico dont la distance à votre mot est la plus petite, et les afficher.


## Conclusion

Vous pourrez bien entendu réutiliser toutes ces techniques dans d'autre contexte qu'un correcteur orthographique.

Amusez-vous bien ! :)
GuilOooo