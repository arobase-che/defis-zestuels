# zStrstat
## Chaines de caractères


### Objectif


Le but de l'exercice est de comptabiliser le nombre d'occurences de chaque caractère alphanumérique (lettres majuscules et minuscules, chiffre) dans une phrase donnée, phrase ne comportant aucun accent. Tout autre caractère ne devra pas être pris en compte.

### Entrée du programme


Je propose trois alternatives pour récupérer cette phrase, choisissez celle qui vous convient le mieux. Vous pouvez en coder une seule, comme vous pouvez coder les trois, je vous demanderai simplement de m'indiquer en commentaire d'en-tête à votre code source réponse de m'indiquer votre choix. Dans l'ordre de difficulté :

1/ La phrase est notée en "dur" dans le programme, dans ce cas la phrase sera contenue dans une chaîne de caractères classique en C.

2/ La phrase sera demandée à l'utilisateur dans la console, avec une interface du style :

```shell
Veuillez entrer votre phrase :
Je suis une phrase de test.
```



3/ La phrase sera contenue dans un fichier texte dans lequel il faudra aller récupérer la phrase qui devra tenir sur une seule ligne.

BONUS : si certains souhaitent aller un peu plus loin, je peux leur suggérer, s'ils choisissent la 3e option, de ne plus se limiter à une phrase mais à un texte tenant sur plusieurs lignes.

### Sortie du programme


En sortie, le programme devra afficher, dans la console, chaque caractère apparu avec le nombre d'occurences correspondant.

Un exemple :
```shell
Statistiques pour la phrase "Je suis une chaine" :
a : 1
c : 1
e : 3
h : 1
i : 2
j : 1
n : 2
s : 2
u : 2
```

**BONUS** : les plus motivés pourront aller écrire les statistiques (complètes ou non, c'est-à-dire avec affichage des lettres non apparues) obtenues dans un fichier texte. Ou encore faire un affichage sous forme d'histogramme à barre horizontales ou verticales... Faites-vous plaisir, ça c'est pour le fun, vu que le but de l'exercice est juste de compter les occurences. Le reste, c'est à vous de voir... ;)

### Traitement de la chaine


On ne tiendra pas compte de la casse, ainsi les majuscules et les minuscules ne seront pas distinguées dans le résultat final.


Eusebus

PS: Ce qui est marqué en "BONUS" n'est pas l'objectif de l'exercice. Ce sont simplement des pistes pour ceux qui veulent s'amuser un peu et pratiquer d'autres choses, mais l'exercice en lui-même ne réside pas dans ces lignes-là. :)

-----------------


>!secret Correction
>Niveau 1 :
>```c
>#include <stdio.h>
>#include <ctype.h>
>
>#define LEN 36
>
>int main(void)
>{
>        const char str[] = "Ceci est une chaine de test.";
>        const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyz";
>        int stat[LEN] = { 0 };
>        size_t i, j;
>
>        for (i = 0; str[i] != '\0'; i++)
>        {
>                int found = 0;
>                char c = tolower(str[i]);
>
>                for(j = 0; j < LEN && !found; j++)
>                        if(c == alphanum[j])
>                        {
>                                found = 1;
>                                stat[j]++;
>                        }
>        }
>
>        printf("Statistiques pour la chaine \"%s\" :\n", str);
>
>        for(i = 0; i < LEN; i++)
>                if(stat[i] != 0)
>                        printf("%c : %d\n", alphanum[i], stat[i]);
>
>    putchar('\n');
>        puts("**FIN**");
>
>        return 0;
>}
>```
>
>Niveau 2:
>```c
>#include <stdio.h>
>#include <ctype.h>
>
>int main(void)
>{
>    int c, i, freqs[256] = {0};
>
>    while ((c = tolower(getchar())) != '\n')
>        if (isalnum(c))
>            freqs[c]++;
>
>    for (i = 0; i < 256; ++i)
>        if (freqs[i] > 0)
>            printf("'%c'\t%d\n", i, freqs[i]);
>
>    return 0;
>}
>```
>
>```c
>#include <stdio.h>
>#include <stdlib.h>
>#include <ctype.h>
>
>#define LEN 36
>
>int main(void)
>{
>        const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyz";
>        int stat[LEN] = { 0 };
>        char c;
>        size_t i, j;
>        FILE *fp = fopen("bla.txt", "r");
>
>        if(fp == NULL)
>        {
>                perror("fopen()");
>                exit(EXIT_FAILURE);
>        }
>
>        while((c = tolower(fgetc(fp))) != EOF)
>        {
>                int found = 0;
>
>                for(j = 0; j < LEN && !found; j++)
>                        if(c == alphanum[j])
>                        {
>                                found = 1;
>                                stat[j]++;
>                        }
>        }
>
>        printf("Statistiques :\n");
>
>        for(i = 0; i < LEN; i++)
>                if(stat[i] != 0)
>                        printf("%c : %d\n", alphanum[i], stat[i]);
>
>        putchar('\n');
>        puts("**FIN**");
>        fclose(fp);
>
>        return 0;
>}
>```
>
