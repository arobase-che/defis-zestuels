Amis zéros pythonniens, je vous salue !  

Étant donné que cela fait bien longtemps que l'on a pas vu un topic d'exo sur ce forum. Me voici aujourd'hui avec un petit sujet de difficulté intermédiaire (voire avancée), pour vous faire creuser vos méninges et éventuellement en découvrir plus sur le fonctionnement de votre langage préféré.  

Autant le dire tout de suite, cet exercice va surtout vous faire travailler sur les décorateurs.  
Pour ceux qui n'auraient pas encore apprivoisé ces sales bêtes, vous pourrez vous diriger vers le [chapitre sur les décorateurs](https://zestedesavoir.com/tutoriels/954/notions-de-python-avancees/2-functions/3-decorators/) du tutoriel Python officiel, et, si vous voulez approfondir la notion de décoration, (parce qu'un peu de pub ne fait jamais de mal) vous trouverez un peu de lecture supplémentaire avec mon mini-tuto sur [le pattern Decorator en Python](http://sdz.tdct.org/sdz/le-pattern-decorator-en-python.html).  

### Objectif

L'objectif de cet exercice est de créer un décorateur qui va vous aider à visualiser ce qui se passe à l'exécution de votre programme. Grosso-modo, il va servir à afficher le déroulement du programme en termes d'appels de fonctions.  

Ceci peut s'avérer être une aide visuelle extrêmement utile lorsque vous maintenez un gros programme et que vous avez du mal, au bout d'un moment, à visualiser ce qui se passe réellement à l'intérieur, simplement en lisant le code. ! ;)  

### Exemple

Imaginons le petit programme suivant (qui n'a strictement aucun intérêt en lui-même, m'enfin...), comprenant des appels de fonctions imbriqués.  

```python
def addition(a, b):
    return a + b

def fonction1(a, b):
    c = addition(a, b)
    return a * b + c

def fonction2(a, b):
    c = addition(a, b)
    d = fonction1(a, b)
    return addition(c, d)

fonction2(b=2, a=3)
```

Le but ultime de cet exercice est de créer un décorateur que l'on pourrait appliquer à ces 3 fonctions pour que lorsque l'on exécute le programme, celui-ci décrive son propre déroulement dans la console, comme ceci :  

```console
> fonction2(a=3, b=2)
  > addition(3, 2)
  < 5
  > fonction1(3, 2)
    > addition(3, 2)
    < 5
  < 11
  > addition(5, 11)
  < 16
< 16
```

Bien évidemment, **il est absolument interdit** de tricher en modifiant le corps des fonctions : la seule chose que vous avez le droit de faire est de leur appliquer un décorateur ! Rassurez-vous cependant, j'ai décomposé cet exercice en plusieurs étapes, de manière à ce que vous ne soyez pas perdus dès le départ ! ;)   

### Énoncé

**1/ Créez un décorateur qui affiche ">" avant d'exécuter la fonction décorée, puis "<" après son exécution.**  

#### Exemple

```python
def decor(fonction):
    # ...
    # le code de votre décorateur ici
    pass

@decor
def addition(a, b):
    return a + b

addition(2, b=3)
```

Résultat :  

```plain
>
<
```

**2/ Modifiez ce décorateur pour qu'il affiche le nom de la fonction appelée avant son exécution, puis son résultat après son exécution, comme ceci :**  

```plain
> addition
< 5
```

Indice : regardez du côté de l'attribut `__name__`... Eh oui, une fonction est un objet ! Souvenez-vous-en, ça va vous servir plus tard.  

**3/ Modifiez ce décorateur pour qu'il affiche les arguments de la fonction appelée.**  

```plain
> addition(2, b=3)
< 5
```

Indice : vous n'êtes pas encore à l'aise avec la notation `"*args, **kwargs"` ? C'est le moment de vous y coller ! :p  

**4/ Modifiez ce décorateur pour gérer l'indentation.**  

Lorsqu'une fonction est appelée à l'intérieur d'une autre fonction, les informations de la fonction appelée sont indentées par rapport à celles de la fonction appelante.  

Indice : Il va falloir vous creuser un peu la tête, mais souvenez-vous qu'une fonction est un objet, qu'un décorateur est une fonction, et que Python accepte que l'on ajoute "à chaud" des attributs sur presque n'importe quel objet. ! ;)

**5/ Question subsidiaire : essayez maintenant de faire en sorte que votre décorateur prenne en argument la taille des indentations.**  

Par exemple, que l'on puisse indenter 2 espaces par 2 espaces, 4 par 4, ... tout cela au choix :  

```python
@decor(4) # l'indentation sera de 4 espaces
def addition(a, b):
    return a + b
```

Indice : « Yo dawg ! I heard u like function decorators, so I put a function decorator in ur function so u can return ur decorator while u decorate ur function !! » :lol:

Si la question 5 est subsidiaire, c'est simplement parce que son intérêt est purement de vous faire créer un niveau de décoration plus élevé, "pour la beauté du geste". Nous y reviendrons lorsque l'on corrigera cet exercice, mais c'est loin d'être la méthode la plus "intelligente" (dans le sens "simple à utiliser") pour gérer la taille des indentations.  

Sur ce, je vous souhaîte un bon courage, et j'attends vos participations avec impatience !