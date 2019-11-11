# Push_swap
*Ce projet à pour but de trier des données sur une pile, avec un set d’instructions limité, en le moins de coups possibles.*

Les instructions possibles sont: 
* ra: Effectue une rotation de la pile A
* rb: Effectue une rotation de la pile B
* rr: Effectue une rotation de la pile A et de la pile B
* rra: Effectue une rotation inverse de la pile A
* rrb: Effectue une rotation inverse de la pile B
* rrr: Effectue une rotation inverse de la pile A et de la pile B
* sa: Swap les deux premiers éléments de la pile A
* sb: Swap les deux premiers éléments de la pile B
* ss: Swap les deux premiers éléments de la pile A et de la pile B
* pa: Push le premier élément de la pile B sur la pile A
* pa: Push le premier élément de la pile A sur la pile B

Mon algorithme est dans un permier temps un dérivé d'un quicksort mais possède pour pivot la médiane ou une fraction de la médiane
de sorte à toujours diviser la pile d'une manière optimal, puis un tri par insertion quand il s'agit de reformer la pile A.
En foncction du nombre d'instructions (moins de 200) l'élément le plus grand reste en permanence en haut de la pile B de sorte que
les éléments les plus petit soient au centre de la pile B et que les éléments les plus grands soient aux extérimités,
ce qui forme une sorte de sablier.

Cette stratégie à pour but de minimiser l'accés aux éléments les plus grands quand la pile A est reconstruite,
mais celle-ci n'a pas d'interet, voir augmente le nombre d'instructions, pour un nombre d'éléments supérieur à 200.

A noter que toutes les instructions de rotation inverse ne sont jamais calculé pendant l'algorithme mais en post-traitement
afin de ne pas encombrer l'algorithme avec deux sens de rotation.
