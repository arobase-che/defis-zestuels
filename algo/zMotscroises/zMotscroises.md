# Solveur de mots croisés

Vous savez certainement jouer aux mots croisés ;) 

Souvenez vous la frustration lorsque on se retrouve bloqués avec un mot vraiment difficile. Nous allons donc utiliser la programmation pour nous aider.


## Objectif

Nous allons nous servir d'un dictionnaire de mots, pour chercher facilement tous les mots correspondants à une structure donnée. Ensuite, pour effectuer une recherche, l'utilisateur devra fournir une chaine spécialement formatée : chaque mot inconnu sera remplacé par un `_`.

### exemple

```
>>> Entrez le motif à rechercher : z_s_e
['zeste']
```

## Votre mission

1. Charger les mots d'un dictionnaire depuis un fichier.
2. Proposer à l'utilisateur de rechercher des mots.
3. Effectuer la recherche et afficher les résultats.

[Dictionnaire de 336 531 mots (4 Mo)](../mots-fr-accents.txt) (source: http://www.pallier.org/liste-de-mots-francais.html)

### Piste de travail

Pour la recherche de motif, je suggère d'utiliser les expressions régulières de votre langage favori. Bien sur, vous pouvez aussi faire autrement, si vous le désirez.
