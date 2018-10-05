#############################################
####### L'exercice de base est un peu moche
#############################################
#############################################

A la demande générale, voilà le tetris ...  
Je ne suis vraiment pas doué pour expliquer les choses, je vais faire de mon mieux, je suis ouvert à toutes suggestions.  
Je pars du principe que tout le monde connais le jeu.  

Il y a 36 façons de coder un tetris. Je vais essayer de vous expliquer ma façon de faire; je ne sais pas si c'est la meilleure ou la pire, mais elle fonctionne.  
Comme ça fait assez longtemps que j'en ai pas coder un, je vais tout reprendre depuis la page blanche.  

c'est partie:  

1. **observation du jeu:**  
    soit un objet qui chute dans un tableau, il est mobile et répond au clavier, il interagit avec le décor car il ne peut occuper une place déjà prise.  
    sa vitesse de chute est constante, et répond donc à une temporisation.  
    il y a donc 3 facteurs qui agissent de l'objet:  
    
    + l'évènement clavier (gauche, droite, bas et rotation)  
    + l'évènement temps (fait chuter à intervals réguliers)  
    + le décor (empêche le déplacement)  

    l'objet n'occupe que des espaces vides.  
    si on considère l'objet comme un élément coloré, il ne peut occuper qu'un espace 'noir'.  
    si on considère l'objet comme une densité égale à 1, il ne peut occuper qu'un espace de 'densité 0'.  
    il y a donc une notion binaire ...  

    on peut donc définir un tableau et un objet comme ceci:  
    les '1' ne pouvant occuper le place d'autres '1', il suffit de limiter le tableau avec des '1' pour empêcher l'objet d'en sortir.  

	```plain
       tableau                   objet
       100000000001                000000000000
       100000000001                000001000000
       100000000001                000011100000
       100000000001                000000000000
       100000000001
       100000000001
       100000000001           autre objet
       100000000001                000000000000
       100000000001                000010000000
       100000000001                000011100000
       100000000001                000000000000
       100000000001
       100000000001
       100000000001
       100000000001
       111111111111
	```

    et là ça semble évident, chaque ligne du tableau et des objets peut être codée sur un entier.

1. **opérateurs logiques et numériques:**  
    -comment savoir si un objet n'empiète pas sur un espace déjà occupé?
    on sait que:  
    un '0' peut occuper la place d'un '0'  
    un '0' peut occuper la place d'un '1'  
    un '1' peut occuper la place d'un '0'  
    mais  
    un '1' ne peut occuper la place d'un '1'  

    ce schéma correspond à un 'ET NON' logique.  

    -comment l'objet se déplace à gauche ou à droite?  
    c'est simple, il suffit de déplacer les '1'.  
    si la ligne 2 d'un objet est codée '0000011000' soit 24 en décimal  
    24 multiplié par 2 donne 48, soit '0000110000' en binaire  
    et 24 divisé par 2 donne 12, soit '0000001100' en binaire  

    les '1' semblent s'être déplacés ...  
    en appliquant ceci aux 4 lignes de l'objet, tout l'objet se déplace.  

    c'est pour cela que l'objet à la même largeur que le tableau, car 'supperposé' à celui-ci, opérateurs logiques et numériques s'appliqueront plus facilement.  

    -ok, et la rotation alors?  
    de même que l'on code l'objet en forme de 'L' sur 4 int (ou des bin ou hex, c'est vous qui voyez),  
    on code ses 4 phases de rotation ainsi:  
    (les chiffres sont bidons)  
    objet_en_forme_de_L = (45,26,96,12) , (57,84,32,79) , (84,23,15,47) , (63,35,29,21)  
    un index pointe l'objet en cours; il suffit de le décrémenter pour créer la rotation.

1. **problèmes et solutions ...**  
    pb:  
    admettons que le jeu sur déroule avec l'objet_en_forme_de_L[2]  
    si je déplace celui-ci complètement à droite, au prochaine cycle où il sera utilisé, il apparaitra à droite et non plus au milieu du tableau...  
    sl:   
    on utilise une copie de l'objet_en_forme_de_L[2] que l'on pourra manipuler.  

    <span>pb:</span>  
    l'objet_en_forme_de_L[2] est complètement à droite du tableau  
    si j'applique une rotation, l'objet_en_forme_de_L[1] sera, lui, au milieu du tableau ...  
    <span>sl:</span>  
    on utilise une copie de l'objet_en_forme_de_L pour palier au 1er problème, et, au lieu de déplacer que l'objet indexé, on déplace tout le groupe.

4. **les évènements:**  

    1.- **clavier**  

        les 4 touches 'arrow' sont utilisées.  
        l'objet se déplace à gauche, droite et bas tant que les touches 'left','right' et 'down' sont maintenues enfoncées,  
        mais ne 'tourne' qu'à l'enfoncement de la touche 'up'.  
        pygame met à disposition plusieurs outils pour gérer le clavier ...  
        <span>Exercice: 
        écrivez un 'mainloop' qui réagit de la façon expliquée ci-dessus; vérifiez le fonctionnement en 'printant' la touche enfoncée ('left','right','up' et 'down')  

        ```python
        from pygame import *

        screen = display.set_mode((200,200))

        key.set_repeat(50,50)

        k_up_is_up = False

        while True:
            ev = event.wait()
            if ev.type == QUIT: exit()
            elif ev.type == KEYDOWN:
                if ev.key == K_DOWN: print 'down'
                elif ev.key == K_LEFT: print 'left'
                elif ev.key == K_RIGHT: print 'right'
                elif ev.key == K_UP and not k_up_is_up:
                    print 'up'
                    k_up_is_up = True
            elif ev.type == KEYUP and ev.key == K_UP: k_up_is_up = False
        ```

    1. **temps**  

        l'objet chute de lui-même à vitesse constante(par cycle),ce qui signifie qu'il répond à un timing; non bloquant évidement...  
        la encore pygame dispose de plusieurs solutions pour gérer le temps.  
        Exercice:  
        modifiez le 'mainloop' de façon à ce que soit 'printé' 'down' toutes les 500ms.  

        ```python
        from pygame import *

        screen = display.set_mode((200,200))

        key.set_repeat(50,50)
        time.set_timer(KEYDOWN,500)
        #ici l'astuce est de simuler l'appuie d'une touche
        #time.set_timer() poste un evenement a interval regulier
        #mais il n'est pas possible de specifier des attributs
        #ainsi l'evenement KEYDOWN aura un attribut key egal a 0
        #0 ne correspondant a aucune touche du clavier il n'y a pas de conflict

        k_up_is_up = False

        while True:
            ev = event.wait()
            if ev.type == QUIT: exit()
            elif ev.type == KEYDOWN:
                if not ev.key or ev.key== K_DOWN: print 'down'
                elif ev.key == K_LEFT: print 'left'
                elif ev.key == K_RIGHT: print 'right'
                elif ev.key == K_UP and not k_up_is_up:
                    print 'up'
                    k_up_is_up = True
            elif ev.type == KEYUP and ev.key == K_UP: k_up_is_up = False
        ```

1. **interaction objet/décor: **  
    algo du jeu (un parmis d'autre :p): 
    il est simple ...  
    soit un tableau vide.  
    tant que le tableau ne déborde pas d'objets:  
    un nouvel objet est généré et fait sa vie d'objet. Il vit jusqu'à ce qu'il ne puisse plus chuter.  
    si l'objet fraîchement généré ne peut chuter au moins 1 fois, c'est que le tableau déborde.  

    <span>cycle de jeu:</span>  
    un cycle est le temps de vie d'un objet.  
    au début d'un cycle, l'objet apparait hors champs, au dessus du tableau visible. Comme il ne peut pas survivre dans le vide sidérale du out of range,  
    il est nécessaire que le tableau s'étende de façon à contenir l'objet.  
    un tableau visible fait 10 x 20 cases:  

    en rouge la parie visible  

    100000000001 <---ligne 0  
    100000000001 <---ligne 1  
    10000<span>1</span>000001  
    1000<span>111</span>00001  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    1<span>0000000000</span>1  
    111111111111  

    puis il chute, se pose et meurt.  
    en mourrant il se pétrifie et fait partie du décor.  
    la encore la magie des opérateurs logiques opère...  
    si 100000000001 est un élément du décor  
    et 000111000000 est un élément de l'objet  
    **1**0000000000**1** **OU**(logigue) 000<span>111</span>000000 donne **1**00<span>111</span>00000**1** comme nouvelle valeur à l'élément du décor.  
    (étant donné que deux '1' ne peuvent se chevaucher, ça marhe aussi avec le 'OU EXCLUSIF')  

    un nouveau cycle est généré ...  

    interactions:

    <span>Exercice:</span>  
    1-écrivez une fonction qui teste si un objet peut descendre d'une ligne où pas.  
    il faut donc au préalable définir un tableau et au moins un objet dans une phase de rotation.  
    démarrez de la ligne 0 du tableau et laisser, via le 'mainloop', chuter l'objet qui ne devra pas dépasse le bas du tableau.  
    pour vérifiez le fonctionnement, ecriver une fonction qui affiche en console un truc de ce genre ...  
    ![Image utilisateur](http://joel-murielle.perso.sfr.fr/tetristerm.png)  

    2-pour empêcher l'objet de sortir du tableau on y a collé des bordures; ça vous l'aviez compris.  
    modifiez la fonction test() et 'mainloop' pour tenir compte du déplacement lattéral de l'oblet.  

    3-modifiez la fonction test() et 'mainloop' pour tenir compte de la rotation de l'objet.  

    4-modifiez 'mainloop' pour générer des objets tant que le tableau ne déborde pas ...  

    5-et pour finir, vous l'avez devinez ... (j'abrège car j'en ai marre ![:p](../../bundles/tinymce/vendor/tiny_mce/plugins/emotions/img/langue.png) )  
    modifiez 'mainloop' pour supprimer les 'lignes pleines' et insérer des lignes vides.  

```python
from pygame import *
    from random import choice

    empty_ligne = 2049
    all_set = 4095
    tableau = [empty_ligne]*24+[all_set]

    objet = (
    ((0, 0, 8, 14), (0, 12, 8, 8), (0, 0, 14, 2), (0, 4, 4, 12)),
    ((0, 0, 4, 14), (0, 4, 6, 4), (0, 0, 14, 4), (0, 2, 6, 2)),
    ((0, 0, 6, 12), (0, 4, 6, 2), (0, 0, 6, 12), (0, 4, 6, 2)),
    ((0, 0, 12, 6), (0, 2, 6, 4), (0, 0, 12, 6), (0, 2, 6, 4)),
    ((0, 0, 2, 14), (0, 4, 4, 6), (0, 0, 14, 2), (0, 6, 4, 4)),
    ((0, 0, 6, 6), (0, 0, 6, 6), (0, 0, 6, 6), (0, 0, 6, 6)),
    ((0, 0, 0, 15), (4, 4, 4, 4), (0, 0, 0, 15), (2, 2, 2, 2))
    )

    screen = display.set_mode((200,400))
    key.set_repeat(50,50)
    time.set_timer(KEYDOWN,500)

    k_up_is_up = False

    test = lambda shift,down,rotation: not any([int(i*shift)&tableau[e] for e,i in enumerate(obj[(one+rotation)%4],ligne+down)])

    def affiche():
        t = tableau[:]
        for i in range(4): t[ligne+i] = t[ligne+i]|obj[one][i]    
        for i in t[4:]:
            for j in bin(i)[2:]: print 'X' if int(j) else ' ',
            print

    ligne = 1
    while ligne:
        ligne = 0
        obj = choice(objet)[:]
        one = choice((0,1,2,3))
        while True:
            ev = event.wait()
            if ev.type == KEYDOWN:
                if not ev.key or ev.key== K_DOWN:
                    if test(1,1,0): ligne+=1
                    else:
                        for e,i in enumerate(obj[one],ligne):
                            tableau[e] = tableau[e]|i
                            if tableau[e] == all_set:
                                del(tableau[e])
                                tableau.insert(0,empty_ligne)
                        break
                elif ev.key == K_LEFT:
                    if test(2,0,0): obj = [[j<<1 for j in i]for i in obj]
                elif ev.key == K_RIGHT:
                    if test(0.5,0,0): obj = [[j>>1 for j in i]for i in obj]
                elif ev.key == K_UP and not k_up_is_up:
                    k_up_is_up = True
                    if test(1,0,1): one = (one+1)%4
            elif ev.type == KEYUP and ev.key == K_UP: k_up_is_up = False
            elif ev.type == QUIT: exit()
            affiche()
```

Prochaine étape ... le rendu.