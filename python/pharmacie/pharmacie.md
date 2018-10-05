Bonjour,

Je présente un exercice que j'ai travaillé en Java lors d'un MOOC. Il est adapté dans notre cas à notre langage préféré, le python...

**Objectif** : Ecrire un programme orienté objets qui permet de gérer une pharmacie.

La pharmacie gère des clients et des médicaments. Un client est caractérisé par un nom et un crédit. Le crédit représente la somme que ce client doit à la pharmacie. Le crédit peut être négatif si le client a versé plus d'argent que le montant. Un médicament est caractérisé par un nom (chaîne de caractères), un prix (nombre) et un stock (entier). Les méthodes à compléter auront les caractéristiques suivantes:

`affichage(...)` permet d'afficher les clients et leurs crédits respectifs ainsi que les médicaments et leurs stocks respectifs.

`approvisionnement(..)` permet d'approvisionner le stock d'un médicament. Le nom du médicament à approvisionner ainsi que la quantité à ajouter au stock doivent être lus depuis le terminal. Lorsque le nom du médicament est introduit, il faut vérifier qu'il s'agit bien d'un nom connu dans la liste des médicaments de la pharmacie. Le programme doit boucler jusqu'à introduction d'un nom correct. Cette procédure de vérification sera prise en charge par la méthode `lireMedicament(..)` décrite plus bas.

`achat(..)` permet de traiter un achat fait par un client. l'achat porte sur un médicament donné dans une quantité donnée. Pour cette transaction le client paie un certain prix. Une opération d'achat aura pour effet de déduire la quantité achetée du stock du médicaments correspondant et d'augmenter le crédit du client (d'un montant équivalent au montant de l'achat moins la somme payée).  
Les noms du client et du médicament doivent être lus depuis le terminal. Le programme doit boucler jusqu'à introduction de noms connus aussi bien pour les clients que les médicament. Ces procédures de vérification seront prises en charge par les méthodes `lireClient` et `lireMedicament` (voir plus bas). La quantité achetée et le montant payé sont aussi lus depuis le terminal. Ils seront supposés corrects.

`quitter(..)` affiche le message "programme terminé!".

Vous définirez une méthode auxiliaire `lireClient(..)` prenant comme paramètre un liste de clients. Elle permettra de lire le nom d'un client depuis le terminal et de vérifier si ce client existe dans la liste des clients. Dans ce cas le client sera retourné. Cette méthode doit boucler jusqu'à ce qu'un client soit trouvé. Elle sera utilisée par la méthode `achat(..)`. Une méthode similaire, `lireMedicament(..)` sera fournie pour les médicaments. Elle sera utilisée par les méthodes `achat(..)` et `approvisionnement(..)`.

**Vous êtes libre de définir, en plus de ces méthodes, toutes celles que vous jugerez nécessaires.**

Le programme sera exécuté et donnera ce genre de résultat

````console
1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
2
Nom du medicament?:
Aspiron
Donner la Quantite :
2

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
3
Affichage des stocks
Stock du medicament Aspiron :7
Stock du medicament Rhinoplexil :5
Affichage des credits
Credit du client Malfichu :0.0
Credit du client Palichon :0.0

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
1
Nom du client?:
Malfichu
Nom du medicament?:
Aspiron
quel est le montant du paiement?
30.0
quelle est la quantite achetee?
3

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
3
Affichage des stocks
Stock du medicament Aspiron :4
Stock du medicament Rhinoplexil :5
Affichage des credits
Credit du client Malfichu :31.199999999999996
Credit du client Palichon :0.0

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
1
Nom du client?:
Palichon
Nom du medicament?:
Aspiron
quel est le montant du paiement?
5
quelle est la quantite achetee?
5
Achat Impossible. Quantite insuffisante

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
3
Affichage des stocks
Stock du medicament Aspiron :4
Stock du medicament Rhinoplexil :5
Affichage des credits
Credit du client Malfichu :31.199999999999996
Credit du client Palichon :0.0

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
1
Nom du client?:
Palichon
Nom du medicament?:
Rhinoplexil
quel est le montant du paiement?
200
quelle est la quantite achetee?
5

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
3
Affichage des stocks
Stock du medicament Aspiron :4
Stock du medicament Rhinoplexil :0
Affichage des credits
Credit du client Malfichu :31.199999999999996
Credit du client Palichon :-104.25

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
1
Nom du client?:
Febril
Client inconnu. Veuilliez recommencer
Malfichu
Nom du medicament?:
Placebo
Medicament inconnu. Veuilliez recommencer
Aspiron
quel est le montant du paiement?
2
quelle est la quantite achetee?
1

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
3
Affichage des stocks
Stock du medicament Aspiron :3
Stock du medicament Rhinoplexil :0
Affichage des credits
Credit du client Malfichu :49.599999999999994
Credit du client Palichon :-104.25

1 : Achat de medicament
2 : Approvisionnement en  medicaments
3 : Etats des stocks et des credits
4 : Quitter
4
Programme termine!
````

Voici la composition simplifiée du programme principal

```python
def menu():
print("""1 : Achat de medicament
2 : Approvisionnement en medicaments
3 : Etats des stocks et des credits
4 : Quitter""")

while True:
try:
choix = int(input("Entrez votre choix: "))
if choix in range(1, 5):
break
except ValueError:
continue

return choix

Malfichu = Client("Malfichu",0.0)
Palichon = Client("Palichon",0.0)

Aspiron = Medicament("Aspiron", 20.40, 5)
Rhinoplexil = Medicament("Rhinoplexil", 19.15, 5)

clients = [Malfichu, Palichon]
medicaments = [Aspiron, Rhinoplexil]

while True:

choix = menu()

if choix == 1:
achat(clients, medicaments)
elif choix == 2:
approvisionnement(medicaments)
elif choix == 3:
affichage(clients, medicaments)
else:
break

quitter()
```

Amusez-vous bien ;)