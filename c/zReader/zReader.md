zReader
=======


Lecture et écriture dans les fichiers
---------------------------------

#### Objectif


L'objectif de cet exercice et que vous réalisiez un programme en mode console qui vous permettra d'ouvrir et donc de lire un fichier, de créer un fichier dont on aura le choix de l'extension, et d'écrire dans un fichier. Pour cet exercice, vous devez avoir lu le chapitre de m@teo21 sur la lecture et l'écrite dans les fichiers en C (si vous n'y connaissez encore rien, c'est l'occasion d'apprendre). La manipulation des fichiers est un domaine incontournable en programmation, c'est une opportunité pour vous de vous y préparer dés maintenant. :)


Le programme devra être simple d'utilisation de telle sorte que tout le monde puisse l'utiliser.
On pourrait par exemple imaginez ceci :
```shell
1. Lire un fichier
2. Créer un fichier
3. Écrire dans un fichier
 
Votre choix ? _
```


Bonne chance à vous tous ! ;)

shareman

__________________________


>!secret Correction 
>
>
>```c
>#include <stdlib.h>
>#include <stdio.h>
>#include <string.h>
>
>#define TAILLE 5000
>
>typedef struct fichier
>{
>    FILE* doc;
>    char* chemin;
>} fichier;
>
>void read(fichier*);
>void write(fichier*);
>void creat(fichier*);
>
>void buf(){
>    int c = 0;
>    while ((c = getchar()) != '\n');
>}
>void wait(){
>    printf("\n Appuyez sur entrer pour retourner au menu...");
>    buf();
>}
>void strcle(char* str){
>    char* d = strchr(str, '\n');
>    if (d) *d = '\0';
>    else buf();
>}
>
>int main()
>{
>    fichier monFichier;
>    monFichier.doc = NULL;
>    monFichier.chemin = NULL;
>    char choixSec[2];
>    int choix;
>
>    printf("\n Bienvenue sur zReader - lisez, cr\x82""ez et \x82""crivez dans vos fichiers !\n");
>
>    do{
>        printf("\n 1. Lire"
>               "\n 2. Ecrire"
>               "\n 3. Cr\x82""er"
>               "\n 4. Quitter \n"
>               "\n Votre choix ? ");
>
>        fgets(choixSec,2,stdin); buf();
>        choix = atoi(choixSec);
>
>        if(choix == 1) read(&monFichier);
>        else if(choix == 2) write(&monFichier);
>        else if(choix == 3) creat(&monFichier);
>        else if(choix == 4) break;
>        else printf("\n Mauvaise saisie !\n");
>
>    }while(1);
>
>    return EXIT_SUCCESS;
>}
>
>void read(fichier* monFichier)
>{
>    monFichier->chemin = malloc(TAILLE * sizeof(char));
>    char c[TAILLE];
>
>    printf("\n Entrez le chemin du fichier : ");
>    fgets(monFichier->chemin, TAILLE, stdin);
>    strcle(monFichier->chemin);
>    printf("\n\n");
>
>    if(monFichier->doc = fopen(monFichier->chemin,"r"))
>    {
>        printf(" Contenu du fichier : \n\n");
>        while (fgets(c,TAILLE,monFichier->doc) != NULL)
>        printf(c);
>        fclose(monFichier->doc);
>    }
>    else
>    {
>        printf(" Le fichier n'existe pas ! \n");
>    }
>    free(monFichier->chemin);
>    wait();
>}
>
>void write(fichier* monFichier)
>{
>    monFichier->chemin = malloc(TAILLE * sizeof(char));
>    char inputInFile[TAILLE*3];
>
>    printf("\n Entrez le chemin du fichier (si invalide, le fichier sera cr\x82""e) : ");
>    fgets(monFichier->chemin, TAILLE, stdin);
>    strcle(monFichier->chemin);
>    printf("\n\n");
>
>    monFichier->doc = fopen(monFichier->chemin,"w");
>    printf(" Saisie dans le fichier (pour fermer, tapez \"f.close\") : \n\n");
>    while(fgets(inputInFile,TAILLE*3,stdin))
>    {
>        if (strstr(inputInFile,"f.close"))
>            break;
>        fputs(inputInFile,monFichier->doc);
>    }
>    fclose(monFichier->doc);
>    free(monFichier->chemin);
>    printf("\n Contenu enregistr\x82"".");
>    wait();
>}
>
>void creat(fichier* monFichier)
>{
>    char path[TAILLE];
>    char ext[30];
>
>    printf("\n\n Nom du fichier (extension non-incluse) : ");
>    fgets(path,TAILLE,stdin);
>    strcle(path);
>    printf("\n Extension du fichier : ");
>    fgets(ext,30,stdin);
>    strcle(ext);
>
>    strcat(path,".");
>    strcat(path,ext);
>
>    monFichier->doc = fopen(path,"w");
>    fclose(monFichier->doc);
>    printf("\n Fichier cr\x82""e avec succ\x8a""s \n\n");
>}
>```
>





