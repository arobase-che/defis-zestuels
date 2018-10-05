############################################################################
############################################################################
##########   A RETRAVAILLER  ###############################################
############################################################################
############################################################################


**La factorielle et ses analogues**

Traitement de grands nombres et récursivité


En mathématiques, la **factorielle** d'un entier naturel n, notée $n!$ est le produit des nombres entiers strictement positifs inférieurs ou égaux à n. Mais saviez-vous qu'il existe des fonctions analogues à la factorielle ? Primorielle, multifactorielles, hyperfactorielle, superfactorielle, sous-factorielle etc, la famille est grande ; je vous propose aujourd'hui d'en découvrir quelques unes, pythonniquement bien sûr.  

### La factorielle

#### Rappel


<table>

<thead>

<tr>

<th>Factorielle</th>

<th>Expression</th>

<th>Resultat</th>

</tr>

</thead>

<tbody>

<tr>

<td><math>\(1!\)</math></td>

<td><math>\(1\)</math></td>

<td><math>\(1\)</math></td>

</tr>

<tr>

<td><math>\(2!\)</math></td>

<td><math>\(1 \times 2\)</math></td>

<td><math>\(2\)</math></td>

</tr>

<tr>

<td><math>\(3!\)</math></td>

<td><math>\(1 \times 2 \times 3\)</math></td>

<td><math>\(6\)</math></td>

</tr>

<tr>

<td><math>\(...\)</math></td>

<td><math>\(...\)</math></td>

<td><math>\(...\)</math></td>

</tr>

</tbody>

</table>


Soit $n$ un entier naturel. Sa factorielle est formellement définie par :  
$n! = \prod_{i=1}^{n} = 1 \times 2 \times 3 \times ... \times (n-1) \times n$
Par convention :  
$0! = 1$  

#### Commençons en douceur

› Exercice № 1 : Créez une fonction `fac(n)` qui renvoi la factorielle de $n$ Le but étant de faire un code concis et —relativement— rapide  

### Superfactorielle

#### Définition

<div>

<table>

<thead>

<tr>

<th>Factorielle</th>

<th>Expression</th>

<th>Resultat</th>

</tr>

</thead>

<tbody>

<tr>

<td><math>\(1\$\\)</math></td>

<td><math>\(1\)</math></td>

<td><math>\(1\)</math></td>

</tr>

<tr>

<td><math>\(2\$\\)</math></td>

<td><math>\(2^2\)</math></td>

<td><math>\(6\)</math></td>

</tr>

<tr>

<td><math>\(3\$\\)</math></td>

<td><math>\(6^{6^{6^{6^{6^6}}}}\)</math></td>

<td><math>\(8.02\times 10^{6050}\)</math></td>

</tr>

<tr>

<td><math>\(...\)</math></td>

<td><math>\(...\)</math></td>

<td><math>\(...\)</math></td>

</tr>

</tbody>

</table>

</div>

On peut définir la superfactorielle de n, notée <math>\(n\$\\)</math> ($ étant un signe factoriel ! portant un S superposé) comme :  

$n$\equiv \begin{matrix} \underbrace{ n!^{{n!}^{{\cdot}^{{\cdot}^{{\cdot}^{n!}}}}}} \\ n! \end{matrix}$ 

Ainsi, on a pour $3\$\$ :
$3\$= 6^{6^{6^{6^{6^6}}}} \!= 8.02\times 10^{6050}$  

#### Codons enfin

› Exercice № 2 : Créez une fonction `superfac(n)` qui renvoi la superfactorielle de $n$.  

Si vous implantez la formule sans réfléchir, ça ne marchera pas : **Vous ne pouvez *pas* utiliser de moyens "conventionnels" pour résoudre ce problème.** Trouver un autre moyen qui ne nécessite pas de traiter *directement* de très grand nombre

Bonne chance !  

Texte extrait des articles Wikipédia [Factorielle](https://fr.wikipedia.org/wiki/Factorielle) et [Analogues de la factorielle](https://fr.wikipedia.org/wiki/Analogues_de_la_factorielle)