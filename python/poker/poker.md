Bonjour  

Petit exercice sympa inspiré d'un [exercice](https://projecteuler.net/index.php?section=problems&id=54) du projet Euler.  

#### Énoncé

L'exercice est à résoudre en Python et est composé des deux questions suivantes.  

---------------------------------------------------------------------------------------------------  
1. On vous donne au Poker une main de 5 cartes et le programme doit identifier la nature de la main parmi les neuf combinaisons possibles (quinte, carré, etc, cf. la liste ci-dessous).  

2. On vous donne deux mains de 5 cartes issues d'un même jeu de 52 cartes et le programme doit dire quelle est la main qui gagne (ou s'il y a égalité, ce qui est possible). Attention, je ne donnerai pas toutes les règles de gain d'une main sur une autre, se référer à l'[article correspondant](https://fr.wikipedia.org/wiki/Main_au_poker) de wikipedia pour les détails manquants.  
---------------------------------------------------------------------------------------------------  

####   Rappels

Au poker, chaque joueur reçoit 5 cartes qui forment ce qu'on appelle une [main](https://fr.wikipedia.org/wiki/Main_au_poker). Les différentes mains se répartissent en 9 combinaisons, par ordre décroissant de valeur :  


1. Quinte  
2. Carré  
3. Full  
4. Couleur  
5. Suite  
6. Brelan  
7. Double paire  
8. Paire  
9. Carte haute

Attention, bien que cette règle ne soit pas universellement admise, dans le cas de cartes consécutives, l'As a une situation particulière : il peut être supérieur au Roi mais aussi représenter la carte 1 et donc être la carte la plus faible du jeu.  

Pour savoir qui l'emporte de deux mains de même niveau (par exemple deux brelans), on regarde «la» carte la plus forte (voir les détails dans l'article de Wikipedia ci-dessus).  

#### Détails

-   Vous êtes libre de noter les rangs des cartes comme vous le souhaitez. Je suggère 1 pour As, R pour Roi, 7 pour la carte 7, etc.
-   Pour les couleurs, je suggère  
    `p = pique, c= cœur, k = carreau, t = trèfle`
-   Par conséquent, avec les notations ci-dessus, un valet de pique se notera Vp. Mais je répète, vous pouvez utiliser une notation plus adaptée à Python, par exemple un tuple `('V', 'p')`
-   Il est souhaitable que ce soient des fonctions (ou à la rigueur des méthodes si vous tenez à écrire votre code avec des classes) qui exécutent chacune des taches des questions 1 et 2.
-   Pour la génération d'une main, c'est sans importance,  
    +   ou bien vous écrivez vous-même une main dans le code,
    +   ou bien vous demandez à l'utilisateur d'entrer une main, genre  
        `Rp 5t Dc Rt 5c`
    +   ou bien vous écrivez un générateur aléatoire de mains.  
    La première forme a ma préférence.
-   Dans votre solution, veuillez préciser quelle version de Python vous utilisez (tout le monde n'utilise pas la version 3 de Python !)