Bonjour  

Aujourd'hui je vous propose un exercice concernant la **mise en cache** des appels de fonctions. J'explique : quand on appelle une fonction plusieurs fois avec les mêmes arguments, on doit pouvoir retenir le résultat afin de ne pas avoir à le recalculer. Je vous propose de résoudre cela avec des décorateurs.  

Pour tester si votre fonction fonctionne :  

```python
def fibo(n):
    if n <= 1:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)

@cache
def fib(n):
    if n <= 1:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)
```

L'appel de `fibo(32)` doit durer quelques secondes, alors que l'appel de `fib(32)` doit être instantané.  

Attention, cet exercice comporte plusieurs difficultés. Je posterai la solution que je propose d'ici quelques messages (et je ne suis qu'à moitié satisfait de ma solution à un des problèmes, donc si je trouve - seul bien sûr - d'ici là...)  

Le sujet est volontairement assez vague : il ne s'agit pas d'un exercice scolaire rigide, mais d'une proposition d'entraînement. Ça veut dire aussi que vous pouvez extrapoler un peu : le but est d'avoir une discussion intéressante, pas un examen ! En particulier, le rôle des variables globales et des méthodes de classe n'est pas clairement défini. Essayez de réfléchir dessus.  

edit : je suis parvenu à une solution qui me convient beaucoup mieux. Voyons les idées que vous aurez !