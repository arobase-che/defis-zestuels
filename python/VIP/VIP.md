Salut !  

Je vous propose aujourd'hui de résoudre un problème algorithmique en Python, très largement inspiré d'un chapitre de l'excellent livre *Pearls of Functional Algorithm Design* de Richard Bird.  

### Formulation du problème

Vous assistez à une soirée où sont présentes un certain nombre de personnes.  

#### La classe Person

Une personne se caractérise par son nom, ainsi que la liste des noms des personnes qu'elle connaît. Elle dispose d'une méthode `knows`, permettant de savoir si elle connaît la personne qui lui est passée en paramètre :  

`a.knows(b)` retourne :  

*   `True` si la personne `a` connaît la personne `b`,
*   `False` si `a` ne connaît pas `b`.

La relation `knows` n'est pas symétrique : une personne `a` peut tout à fait connaitre une personne `b` alors que `b` ne connaît pas `a`.  

Voici le code de la classe `Person`  


```python
class Person(object):
    def __init__(self, name):
        self.name = name
        self._known = []

    def knows(self, other):
        return other.name in self._known

    def __str__(self):
        return str(self.name)

    def __repr__(self):
        return repr(self.name)
```

#### Faites entrer les VIP

Parmi les gens qui assistent à la soirée, vous avez un certain nombre (strictement positif) de VIP.  
Voici les propriétés des VIP :  

-   Un VIP ne connaît que les autres VIP, il ne connait pas de gens ordinaires. (On appelle cela une "clique" en théorie des graphes)
-   Un VIP est connu de **tout le monde**,

Ainsi, vous avez dans cette soirée un groupe de VIP qui se connaissent tous entre eux, qui sont connus de tout le monde, mais qui ne connaissent personne en dehors de leur groupe.  

#### Votre mission, si vous l'acceptez

Le but de cet exercice, est de rechercher, étant donnée la liste de toutes les personnes assistant à cette soirée, cette clique de VIP.  

Voici une fonction qui crée une liste d'invités pour tester votre algorithme :  

```python
from random import shuffle, randrange, sample

def mk_problem():
    # Création de la clique de VIP (j'avais pas d'inspiration pour les
    # célébrités, et comme je suis en train d'écouter du jazz...)
    c_names = ["Louis Armstrong", "Oscar Peterson", "Billie Holiday", 
               "Ella Fitzgerald", "Paul Desmond", "Chet Baker",
               "Dave Brubeck", "Niels E.H. Pedersen", "John Pass",
               "Quincy Jones"]
    c_clique = [Person(n) for n in c_names]

    # Les VIP se connaissent tous entre eux
    for c in c_clique:
        c._known = c_names

    # Création d'un certain nombre de gens ordinaires
    n_names = ["Toto", "Titi", "Tata", "Tutu", "Bibi", "Coco", "Papi", "Tati",
            "Dede", "Dudu", "Bobo"]

    normal_people = [Person(n) for n in n_names]

    # Les gens normaux connaissent tous les VIP
    # ainsi qu'un certain nombre d'autres gens normaux (choisis au hasard).
    for n in normal_people:
        n._known = c_names + sample(n_names, randrange(len(n_names)))

    # On mélange le tout
    party = normal_people + c_clique
    shuffle(party)

    return party
```

Votre mission est donc de créer une fonction `find_vip` qui prend en argument la liste des personnes assistant à la soirée (dans l'exemple : le retour de la fonction `mk_problem`, et retourne la liste des VIP de cette soirée).  

Le but de cet exercice est de trouver un algorithme efficace permettant de résoudre ce problème (en formulant l'hypothèse qu'il y a une et une seule clique de VIP à cette soirée) **en ne se servant que de la méthode `knows`**. L'algorithme naïf est en $O(nk)$ en termes d'utilisation de l'opérateur `knows` avec $n$ le nombre de personnes assistant à la soirée et $k$ le nombre de VIP. Il est possible de faire BEAUCOUP mieux que ça. Une première amélioration de l'algorithme naïf (tenant compte des contraintes sur les VIP) est en $O(n^2)$, et il existe une solution linéaire (en $O(n)$) à ce problème.  ;)   

Voici une seconde fonction de test (python 2 ET 3), permettant de tester les performances de votre fonction avec possibilité de dimensionner le problème :  

 -   total est le nombre total d'invités à la soirée.
 -   vips est le nombre de vips (< total).
 -   <span>functions est la liste des fonctions à tester.

```python
from __future__ import print_function
from random import shuffle, sample, randrange
from time import time

def test_function(total, vips, functions):
    print("Building list of {0} vips and {1} normal people".format(vips
            , total - vips))

    vip_names = set(range(vips))
    normal_names = set(range(vips, total))

    vip = [Person(c) for c in vip_names]
    normal = [Person(p) for p in normal_names]

    for v in vip:
        v._known = vip_names

    for p in normal:
        p._known = vip_names.union(sample(normal_names, randrange(vips)))

    party = vip + normal
    shuffle(party)

    for fn in functions:
        print("Running '{0}' :\t".format(fn.__name__), end=" ")
        start = time()
        result = fn(party)
        end = time()
        print("[{0:.6f}s]".format(end-start), end= " ")

        result.sort(key=lambda p:p.name)
        print("OK" if result == vip else "FAIL!")
```

Bon courage !  

Je posterai une première solution en $O(n^2)$ dans 24h si personne n'a le courage d'essayer d'ici-là.