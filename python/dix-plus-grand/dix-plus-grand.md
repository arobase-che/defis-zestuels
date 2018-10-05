Bonjour,  

Je vous propose de résoudre ce petit problème (pas bien dur) :  

**Nous devons trouver les dix plus grands nombres dans un iterable sans faire appel à la fonction sort() ou sorted().**  

En pratique, cet algo peut se révéler très utile, par exemple dans le cas ou il y a énormément de valeurs à filtrer (fichier de log par exemple), car ce ne sera pas forcément évident de tout stocker en mémoire pour trier (on parle de complexité mémoire)...  

Donc pour simuler ce contexte, je vous propose d'utiliser un générateur, comme ceci :  

```python
from random import randint

# génère n entiers compris entre a et b
def gen(n, a, b):
    for i in range(n):
        yield randint(a, b)

# ou bien, pour ceux qui préfèrent les 'one-liner'
gen = lambda n, a, b: (randint(a,b) for i in range(n))
```

Ensuite, nous allons créer une fonction `dix_maxi()`, et l'appeler comme ceci :  

```python
dix_maxi(gen(n, start, stop))
```

Cette fonction doit nous renvoyer une liste (ou ce que vous voulez) contenant les dix plus grands nombres générés. Les nombres retournés ne doivent pas forcément être ordonnés, faites ce que vous voulez de ce coté là.  

Dans un second temps, vous devez essayer de rendre votre fonction générique, afin de pouvoir renvoyer les N éléments maximums. Essayez de faire en sorte que votre fonction soit un minimum performante même avec de grandes valeurs de N.  

**Astuce :**

[[s]]
| Certains modules de la lib standard peuvent vous aider (je ne dis pas lesquels, ce serait trop facile)



**PS :** prière de mettre les réponses en secret, pour que tout le monde puisse réfléchir.  

**[edit] :** *Ajout de la possibilité de faire une fonction générique, ainsi qu'un petit mot sur la complexité.*