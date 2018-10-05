# Un téléchargement bien ennuyeux



Bonjour à tous !

Non non, cet exercice ne concernera pas le réseau. :)

## Mise en situation



La situation est la suivante : vous disposez d'une liste de villes, reliées entre elles par des câbles réseau. Si deux villes sont reliées, vous pouvez envoyer des de méga-octets de l'une à l'autre. Mais attention aux quotas ! France télécom, le propriétaire des câbles, vous impose une limite sur le nombre maximal de méga-octets qui peuvent circuler sur chacune des lignes.

Vous souhaitez faire un backup des données qui se situent sur votre serveur, dans l'une des villes, vers un centre de backup, qui est bien entendu éloigné. Vous devez donc trouver comment faire passer les données dans les différents câbles afin d'en rapatrier un maximum !

Exemple de situation.

```plain
Liste des villes : Paris, Marseille, Lyon, Toulouse, Nice, Nantes, Strasbourg, Montpellier.
 
Liste des câbles :
Paris Lyon 20 Mo
Paris Strasbourg 20 Mo
Paris Nantes 20 Mo
Paris Lille 25 Mo
Paris Toulouse 5 Mo
Strasbourg Lyon 10 Mo
Lyon Marseille 30 Mo
Marseille Montpellier 30 Mo
Montpellier Toulouse 30 Mo
Toulouse Nantes 30 Mo
Nantes Lille 10 Mo
Lille Strasbourg 35 Mo
 
Envoyer depuis TOULOUSE vers STRASBOURG.
```

*Une solution possible pour cette carte est :*

```plain
On peut envoyer au mieux 65 Mo.
Il faut découper les données en cinq paquets de 5 Mo, 10 Mo, 10 Mo, 20 Mo, 20 Mo.
Les répartir comme ceci :

(10 Mo) Toulouse -> Montpellier -> Marseille -> Lyon -> Strasbourg (10 Mo)
/* Le câble Lyon -> Strasbourg est maintenant saturé, on passe par Paris */

(20 Mo) Toulouse -> Montpellier -> Marseille -> Lyon -> Paris -> Strasbourg (20 Mo)
 /* Le câble Toulouse -> Montpellier est maintenant saturé, on passe par Paris */

(5 Mo) Toulouse -> Paris -> Lille -> Strasbourg (5 Mo)
/* Le câble Toulouse -> Paris est maintenant saturé, on passe par Nantes */

(20 Mo) Toulouse -> Nantes -> Paris -> Lille -> Strasbourg (20 Mo)
/* Le câble Nantes -> Paris est maintenant saturé, on passe par Lille */

(10 Mo) Toulouse -> Nantes -> Lille -> Strasbourg (10 Mo)
/* Le câble Toulouse -> Nantes est saturé, plus aucun câble ne part de Toulouse. */
```


Il se trouve que tous les câbles de la carte sont occupés à fond, nous ne pouvons donc pas faire mieux !

### Énoncé


Écrivez un programme qui, étant donné une liste de villes, une liste de câbles, un point de départ et un point d'arrivée, vous donne la meilleure solution pour transférer un maximum de données.

#### Niveau 1



L'utilisateur entre le nombre de villes sur une ligne, puis entre les valeurs des câbles sous forme de tableau à deux dimensions. Vient ensuite le numéro de la ville de départ, puis celui de la ville d'arrivée. Par exemple, pour la situation précédente :

```shell
8
0  25 20 20 5  20 0  0
25 0  35 0  0  10 0  0
20 35 0  10 0  0  0  0
20 10 0  0  0  0  30 0
5  0  0  0  0  30 0  30
20 10 0  0  30 0  0  0
0  0  0  30 0  0  0  30
0  0  0  0  30 0  30 0
5 3
```



Dans l'ordre des lignes et des colonnes : Paris Lille Strasbourg Lyon Toulouse Nantes Marseille Montpellier.

La sortie doit être la quantité maximale de données qui a pu être transférée :
```shell
65
```


#### Niveau 2

Cette fois-ci, l'entrée est la même, mais les noms des villes sont indiqués avant la matrice, séparés par des espaces.
Exemple :
```shell
8
Paris Lille Strasbourg Lyon Toulouse Nantes Marseille Montpellier
0  25 20 20 5  20 0  0
25 0  35 0  0  10 0  0
20 35 0  10 0  0  0  0
20 10 0  0  0  0  30 0
5  0  0  0  0  30 0  30
20 10 0  0  30 0  0  0
0  0  0  30 0  0  0  30
0  0  0  0  30 0  30 0
```

 Et la sortie doit être la liste des chemins empruntés :
```shell
Toulouse -> Montpellier -> Marseille -> Lyon -> Strasbourg 10 Mo
Toulouse -> Montpellier -> Marseille -> Lyon -> Paris -> Strasbourg 20 Mo
Toulouse -> Paris -> Lille -> Strasbourg 5 Mo
Toulouse -> Nantes -> Paris -> Lille -> Strasbourg 20 Mo
Toulouse -> Nantes -> Lille -> Strasbourg 10 Mo
Total : 65 Mo
```



#### Niveau 3

Dans ce niveau, l'entrée et la sortie sont les mêmes qu'au niveau 2.

Simplement, votre mission, si vous l'acceptez, est de développer un programme rapide, capable de traiter en un temps raisonnable des cartes bien plus denses.

Pour cela, plutôt que de faire un brute-force sur les possibilités - ou tout autre algorithme de votre inv
