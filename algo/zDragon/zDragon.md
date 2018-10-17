# Dessinez la courbe du dragon

Auteur: [yoch](https://zestedesavoir.com/membres/voir/yoch/)  
[Source](https://openclassrooms.com/forum/sujet/fait-defis-6-dessinez-la-courbe-du-dragon-77056)

## Les fractales

Vous avez peut-être déjà entendu parler des [figures fractales](https://fr.wikipedia.org/wiki/Fractale) : ce sont des structures ayant la particularité de présenter certaines auto-similarités à toutes les échelles.

Ces figures intéressent à la fois mathématiciens et informaticiens.
Aussi, par exemple, vous pouvez trouver sur le SdZ un tutoriel pour expliquer comment créer une des fractales les plus célèbres : l'ensemble de Mandelbrot, ainsi qu'un autre tutoriel abordant certains aspects mathématiques des fractales.

Il existe tout un tas de types de fractales, et aussi (évidement ;) ) divers de moyens d'en générer. Si vous êtes curieux, vous pouvez aller faire un tour sur cette [page Wikipédia](https://fr.wikipedia.org/wiki/Liste_de_fractales_par_dimension_de_Hausdorff), où sont recensés un bon nombre de fractales, ou encore lire ce dossier sur la question [ici](https://www.futura-sciences.com/sciences/dossiers/mathematiques-fractales-curiosite-mathematique-234/).


## La courbe du dragon

![Exemple de courbe du dragon (Source: Wikipédia)](https://upload.wikimedia.org/wikipedia/commons/8/87/Auto-similarity_dragon_curve.svg)

La courbe du dragon est une très jolie image fractale, que l'on peut obtenir notamment de deux façons :

- En utilisant une grammaire de construction, appelée [**L-System**](https://fr.wikipedia.org/wiki/L-Syst%C3%A8me).
- En utilisant un système de fonctions itérées, communément appelé [**IFS**](https://fr.wikipedia.org/wiki/Syst%C3%A8me_de_fonctions_it%C3%A9r%C3%A9es).

Ces deux méthodes sont extrêmement riches, et permettent de réaliser de très nombreuses images fractales. Pensez à vous documenter convenablement dessus. Aussi, n'hésitez pas si vous le sentez à rendre votre code un peu plus générique pour tracer d'autres images.

Liens vers un document pour appréhender les IFS (
[#1](http://mathenjeans.free.fr/amej/edition/actes/actes94/94pge083.htm),
[#2](http://mathenjeans.free.fr/amej/edition/actes/actes94/94pge087.htm),
[#3](http://mathenjeans.free.fr/amej/edition/actes/actes94/94pge093.htm)
).


## Consignes

Votre mission, si vous l'acceptez, sera d'écrire un programme graphique permettant de tracer la courbe du dragon.
N’hésitez pas à innover et sortir des sentiers battus, si vous le désirez.


### Prérequis

Vous devez maitriser un minimum la programmation graphique, et disposer de deux primitives : tracé de point et/ou tracé de ligne.


### Objectifs

- Comprendre une documentation.
- Maitriser la récursivité.
- Créer un programme graphique.


## Énoncé

### Niveau 1

Créer un programme permettant de tracer et visualiser la courbe du dragon à partir de ce *L-System* :

- angle 90°
- graine `FX`
- règles :
    * `X -> X+YF+`
    * `Y -> −FX−Y`

Ce qui se traduit simplement comme suit: Partir d'un segment de base; puis en suivant la courbe, remplacer chaque segment par deux segments à angle droit en effectuant une rotation de 45° alternativement à droite puis à gauche (source: Wikipédia).


### Niveau 2

Créer un programme permettant de tracer et visualiser la courbe du dragon à partir de l'ensemble limite de l'*IFS* suivant (sur le plan complexe) :

- $f_1(z) = \frac{(1+i)z}{2}$
- $f_2(z) = 1 - \frac{(1-i)z}{2}$

Si vous ne connaissez pas les nombres complexes, vous pouvez remplacer ces deux fonctions par ces expressions analytiques (sur un repère orthonormé) : 

- $\left\{\begin{matrix}x' = \frac{x-y}{2}\\y' = \frac{x+y}{2}\end{matrix}\right.$
- $\left\{\begin{matrix}x' = 1 - \frac{x+y}{2}\\y' = 1 - \frac{x-y}{2}\end{matrix}\right.$
