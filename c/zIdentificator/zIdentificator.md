
# zIdentificator

Dans le langage C, on utilise des noms pour définir des variables, des fonctions, des structures, les tags des structures, etc. Les caractères qui constituent ces noms ne doivent pas être choisis sans précaution. Par exemple, les noms dans les déclarations suivantes sont valides :

```c
int toto42, toto_42, _toto, _42toto_, goto_toto;
```

mais ceux-ci ne le sont pas :
```c
int 42_toto, __toto, to-to, _Toto;
```

et celui-là non plus :

```c
int goto;
````


Un nom de variable dans le jargon ça se dit un **identificateur**.

### Objectif

Je vous propose donc d'écrire un code C qui soit capable de dire oui ou non si une chaîne de caractères est un identificateur valide du langage C [les règles précises sont rappelées ci-dessous].


### Prototype

Plus précisément, vous devez écrire une fonction zIdentificator dont le prototype sera à votre guise :

ou bien `int zIdentificator(char *id)`
ou bien (moins simple) `int zIdentificator(const char *id)`

et qui renverra

```plain
1 si la chaîne id désigne un identificateur valide et
0 dans le cas contraire.
```

On aura besoin d'un tableau de chaînes représentant les mots-clés du langage C (liste rappelée ci-dessous). Ce tableau sera déclaré, avec un "scope" laissé à votre choix, de la façon suivante :

```c
const char *motsClefs[] = {
  "auto",
  "break",
/* etc.*/
}
```

Test et affichage

Il faudra insérer la fonction zIdentificator dans un programme complet contenant une batterie de tests.


Les chaînes de test seront placées directement dans le code source (de préférence dans un tableau de chaînes statiques) et non pas capturées via une fonction d'entrée comme scanf ou fgets (autrement dit, vous êtes priés de laisser le bling-bling au vestiaire ;) ).



Un test produira un affichage du genre suivant
```shell
toto       : 1
```

ou encore
``shell
__toto       : 0
```

### Identificateurs valides : règles

**Rappel** -- Un identificateur valide du langage C est une suite non vide de caractères parmi

 - les 26 caractères alphabétiques minuscules
 - les 26 caractères alphabétiques majuscules
 - les 10 chiffres décimaux
 - le caractère souligné : "_"


Un identificateur valide est soumis à chacune des 3 contraintes suivantes :

1. il ne commence pas par un chiffre
(par exemple 42toto est interdit)

2. ses deux premiers caractères NE devront(*) PAS être de l'une de deux formes suivantes
 1. _ suivi de _
 1. _ suivi d'un caractère majuscule.
    (par exemple __toto ou _Toto devront être évités)
1. il est différent de n'importe lequel des 37 mots-clés du langage C99 dont voici la liste :

```plain
auto
break
case
char
const
continue
default
do
double
else
enum
extern
float
for
goto
if
inline
int
long
register
restrict
return
short
signed
sizeof
static
struct
switch
typedef
union
unsigned
void
volatile
while
_Bool
_Complex
_Imaginary
```


Il est a noté que l'exercice suit la norme du langage C. Les compilateurs comme gcc on l'habitude d'être un peu plus souple et peuvent accepter des variables comme "__todo".


Bonne chance !

candide


------------


>!secret Correction
>
> Par yoch
>
>```c
>#include <stdio.h>
>#include <stdlib.h>
>#include <string.h>
>#include <ctype.h>
>
>const char *C_idents[] = {
>   "auto", "break", "case", "char", "const", "continue", "default",
>   "do", "double", "else", "enum", "extern", "float", "for", "goto",
>   "if", "inline", "int", "long", "register", "restrict", "return",
>   "short", "signed", "sizeof", "static", "struct", "switch",
>   "typedef", "union", "unsigned", "void", "volatile", "while",
>   "_Bool", "_Complex", "_Imaginary", NULL
>};
>
>int is_C_word (char *ident)
>{
>   int i;
>   for (i = 0; C_idents[i] != NULL; i++)
>   {
>      if (!strcmp (ident, C_idents[i]))
>         return 1;
>   }
>   return 0;
>}
>
>int zIdentificator (char *ident)
>{
>   if (ident[0] == 0 || is_C_word (ident)
>       || (ident[0] == '_' && ident[1] == '_') || isdigit (ident[0])
>       || (ident[0] == '_' && isupper (ident[1])))
>      return 0;
>
>   for (; *ident; ident++)
>   {
>      if (!isalnum (*ident) && *ident != '_')
>         return 0;
>   }
>
>   return 1;
>}
>
>int main (void)
>{
>
>   char *id[] =
>      { "a", "toto42", "toto_42", "_toto", "_42toto_", "goto_toto", "42_toto",
>      "__toto", "to-to", "_Toto", "", NULL
>   };
>   int i;
>   for (i = 0; id[i] != NULL; i++)
>   {
>      printf ("%s = %d\n", id[i], zIdentificator (id[i]));
>   }
>   return EXIT_SUCCESS;
>}
>```
