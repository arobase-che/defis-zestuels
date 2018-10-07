# Des sudokus en folie !

Salut,

Aujourd'hui, nous voyons un exercice archi-classique.

## Mise en situation

Il n'est plus besoin de présenter le célèbre jeu de Sudoku.
Nous allons créer un programme en console capable de résoudre des grilles de Sudoku, en utilisant des méthodes de plus en plus évoluées.

## Énoncé

Votre programme lira, sur l'entrée standard, une grille incomplète de Sudoku 9×9. Les chiffres sont écrits tels quels, et les cases blanches sont représentées par des espaces.

Exemple :

```
1.3456789789.23456456789.233456789.29.23456786789.234556789.23423456789.89.234567
```

Vous devez alors afficher le même sudoku, complété (si la solution existe).

Exemple :

```
123456789789123456456789123345678912912345678678912345567891234234567891891234567
```

Les sudokus auront tous une taille 9×9. Vous pouvez donc raisonnablement utiliser un brute-force. Il existe des algorithmes plus fins pour la résolution, utilisez la méthode que vous sentez le mieux ! :)

### Niveau 1

Pour le niveau le plus simple, contentez-vous de résoudre la grille de la façon qui vous plaît le mieux. Un simple brute-force suffit. :)

### Niveau 2

Ici, nous allons un peu corser les choses. Le but sera maintenant de résoudre le sudoku par une méthode plus efficace, impliquant le backtracking. Yoch, membre habitué de ce forum, a écrit un tutoriel à ce sujet. Le but est donc de lire et comprendre la méthode, mais pas les codes sources. Le but est de les récrire vous-mêmes, sans lire ce qui existe déjà.

Vous pouvez également vous renseigner au sujet du backtracking sur Wikipédia, ou partout ailleurs sur le web. :)

### Niveau 3

Pour ce dernier niveau, il vous est demandé de faire une résolution pas à pas. À chaque étape, vous devez remplir une seule case libre de la grille, en expliquant pourquoi. Votre explication n'a cependant pas besoin d'être très détaillée. ;)

## Conclusion

Les Sudokus ont déjà fait l'objet de nombreux exercices, mais j'ose espérer que certains d'entre vous ne l'auront jamais codé. :)

Bon courage à tous !