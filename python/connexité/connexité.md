Salut !  

Aujourd'hui je vous propose un exercice de niveau intermédiaire ayant trait au traitement d'images. N'ayez pas peur si vous n'en avez jamais fait, aucune connaissance dans ce domaine n'est requise pour mener cette tâche à bien : vous n'aurez besoin que de quelques neurones à cramer. ! :p  

### Images binaires et composantes connexes

Prenons par exemple le tableau suivant:  

    00000000000000000000
    00111000000000000000
    00011100000011101000
    01111100000111011100
    01100000000011111100
    11000000000111111110
    00001111000111111100
    00111111100011111100
    00000111000000110000
    00000000000000000000

On va considérer que ce tableau est une *image binaire* : les pixels dont la valeur est égale à 0 font partie du fond, et ceux dont la valeur est 1 font partie d'un objet.  

On fait l'hypothèse que si deux pixels de valeur 1 sont **connexes**, alors ils font partie d'un seul et même objet.  

[[q]]
| Connexes ? Ça veut dire quoi ?! o_O

Grosso-modo, cela veut dire qu'ils « se touchent ».  
On peut définir 2 sortes de connexité :  

-   La **4-connexité** : deux pixels sont 4-connexes s'ils se suivent sur la même ligne ou la même colonne. Dans le petit tableau ci-dessous, les paires de pixels connexes sont : (A,B), (A,C), (A,D) et (A,E). **A et F ne sont pas 4-connexes**.
-   La **8-connexité** : deux pixels sont 8-connexes s'ils se suivent verticalement, horizontalement ou en diagonale. Dans l'exemple ci-dessous, A et F sont 8-connexes.


    0 B 0
    C A D
    0 E F

**Pour cet exercice, nous considérons que deux pixels sont connexes s'ils sont 4-connexes.**  

On appelle une *composante connexe* de l'image, un ensemble de pixels tels que, si l'on prend 2 pixels quelconques dans cet ensemble, il est possible de trouver un chemin 4-connexe qui les relie. En gros, une composante connexe est une tache. ! ;)  

Dans l'image ci-dessous, nous avons 2 composantes 4-connexes.  

    00000
    01100
    00011
    00011

### Votre mission, si vous l'acceptez...

Le but de cet exercice est de **trouver combien d'objets différents se trouvent sur une image binaire**.  
Cela revient donc à compter le nombre de composantes 4-connexes de l'image.  

Pour l'image du tout début de cet énoncé, votre code doit trouver 3 composantes connexes.  
Vous avez le choix de représenter l'image dans votre programme de la manière que vous voulez, et d'utiliser toutes les bibliothèques que vous voulez, mais le plus sympa serait de trouver et d'implémenter un algorithme adéquat. ! :p

#### Indices

Si jamais vous planchez sur un algorithme pour résoudre ce problème, voici une petite piste :  


Le plus simple, pour compter les objets, est de les "colorier", et de compter le nombre de couleurs que vous avez utilisées...


Bon courage !!