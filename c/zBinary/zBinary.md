# zBinary
## Algorithmique, binaire

### Objectif


L'objectif de cet exercice est de réaliser un convertisseur de valeurs en base décimal (10) vers la base binaire (2). L'exo vous entraînera à l'algorithmique et à la compréhension de la base binaire. C'est un très bon exercice et tout ce qu'il vous faut se trouve sur ce site. Cherchez par exemple le tutoriel sur les conversions de bases ou essayer de trouver une autre méthode pour déterminer une valeur binaire. ;)

```shell
dec ? 25
bin : 11001
```

Edit : Le programme ne devra que convertir les entiers positifs sur l'intervalle $[0;+\infty[$ .

Bonne chance ! ;)

shareman

----------------


>!secret Correction de yoch
>
>```c
>#include <stdio.h>
>
>void affichage_base(const unsigned int n, const unsigned int base)
>{
>    if (n >= base)
>        affichage_base(n/base, base);
>    putchar('0'+n%base);
>}
>
>
>int main(void)
>{
>    affichage_base(1000, 8);
>    return 0;
>}
>```
