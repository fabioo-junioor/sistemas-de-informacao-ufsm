/*
1. Defina um predicado recursivo isPositive(L) que deverá ser verdadeiro se a lista L tiver apenas elementos positivos.
Exemplo de uso:
   ?- isPositive([1,-2,3,4]).
   false.
2. Defina um predicado recursivo filterEven(L1,L2) de modo que L2 seja uma lista
só com os elementos pares contidos em L1.
?- filterEven([1,3],L).
L = [].
?- filterEven([0,1,2,3],L).
L = [0, 2] 
3. Defina um predicado recursivo ziplus(L1,L2,L3), 
de forma que cada elemento da lista L3 seja a soma dos elementos de L1 e L2 na mesma posição. Exemplo:
?- ziplus([1,2,3],[5,5,5],L). 
L = [6, 7, 8].
*/

isPositive([]).
isPositive([H|T]) :- H > 0, isPositive(T).
isPositive([H|_]) :- H =< 0, false.

filterEven([],[]).
filterEven([H|T],L) :- mod(H,2) =:= 0 , L = [H|T1], filterEven(T,T1).
filterEven([H|T],L) :- mod(H,2) =\= 0, filterEven(T,L).

ziplus([],[],[]).
ziplus([H1|T1],[H2|T2],L) :- H3 is H1 + H2, ziplus(T1,T2,L2), L = [H3|L2].