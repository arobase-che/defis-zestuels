Bonjour,
Je vous propose un exercice que j'ai eu à l'université et que j'ai trouvé assez intéressant.
Il s'agit de lire un calcul en [notation polonaise](https://fr.wikipedia.org/wiki/Notations_infix%C3%A9e%2C_pr%C3%A9fix%C3%A9e%2C_polonaise_et_postfix%C3%A9e) (notation préfixée), de créer un arbre binaire et d'afficher différents résultats à partir de celui-ci.

Les connaissances requises sont :

   - [Arbe binaire](http://sdz.tdct.org/sdz/calcul-d-une-expression-mathematique.html)
   - [Récursivité](http://sdz.tdct.org/sdz/la-recursivite-1.html)


Le tutoriel sur les arbres binaires est explicité en OCaml et celui sur la récursivité en PHP et OCaml, mais le raisonnement reste le même.

Le programme à créer devra lire un calcul du type:

$−×/15−7+113+2+11$

et afficher un résultat comprenant :

 -  La pronfondeur maximale de l'arbre (en prenant 1 pour la profondeur du sommet)
 -  La valeur maximale dans l'opération (ici 15 donc)
 -  Le nombre de noeuds dans l'arbre
 -  Le résultat du calcul
 -  Le calcul en notation polonaise avec toutes les parenthèses
 -  Le calcul en notation infixée avec toutes les parenthèses
 -  Le calcul en notation infixée avec seulement les parenthèses nécessaires
 -  Un diagramme de l'arbre utilisé
 -  Toutes les étapes du calcul



Le résultat devra donc ressembler à ça :

````console
Enter a calculation in prefix notation
- x / 15 - 7 + 1 1 3 + 2 + 1 1
 
Maximum depth:  6
Number of nodes:  15
Maximum value:  15
 
Result =  5
 
Prefix notation with brackets: 
(- (x (/ 15 (- 7 (+ 1 1))) 3) (+ 2 (+ 1 1)))
 
Infix notation with all brackets: 
(((15 / (7 - (1 + 1))) x 3) - (2 + (1 + 1)))
Infix notation with only necessary brackets: 
15 / (7 - (1 + 1)) x 3 - (2 + 1 + 1)
 
Diagram:
+-(-)
   +-(x)
   |  +-(/)
   |  |  +- 15
   |  |  +-(-)
   |  |     +- 7
   |  |     +-(+)
   |  |        +- 1
   |  |        +- 1
   |  +- 3
   +-(+)
      +- 2
      +-(+)
         +- 1
         +- 1
 
 
Order of operations:
   15 / (7 - (1 + 1)) x 3 - (2 + 1 + 1)
 = 15 / (7 - 2) x 3 - (2 + 1 + 1)
 = 15 / 5 x 3 - (2 + 1 + 1)
 = 3 x 3 - (2 + 1 + 1)
 = 9 - (2 + 1 + 1)
 = 9 - (2 + 2)
 = 9 - 4
 = 5
 ````
 
 

Le but de l'exercice étant en particulier de s'entrainer sur l'utilisation des arbres binaires et de la récursivité pour les parcourir, je ne pense pas que la gestion des exceptions et erreurs, ainsi que la précision du calcul soient une priorité ici.

Je posterai ma solution dans quelques jours, bien que ça ne soit à mon avis vraiment pas la meilleure, pour laisser les personnes qui le souhaitent la chercher par eux-mêmes.

Si vous avez des questions, n'hésitez pas, je ferai de mon mieux pour y répondre.
Je suis aussi ouvert à toutes remarques, tant que celles-ci sont un tant soit peu constructives.
