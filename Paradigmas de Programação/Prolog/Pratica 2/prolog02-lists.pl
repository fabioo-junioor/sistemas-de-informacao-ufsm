/*
1. Defina um predicado ao_lado(X, Y, L) para determinar se X está imediatamente ao lado de Y na lista L. 
Neste caso, X pode estar imediatamente à esquerda OU à direita de Y. 
Você pode usar o predicado nextto, só vai precisar usá-lo 2 vezes.

2. Defina um predicado um_entre(X, Y, L) para determinar se os elementos X e Y da lista L 
estão separados por exatamente um elemento. Você pode usar o predicado nextto. 
Abaixo estão exemplos de consultas com o predicado um_entre:

?- um_entre(b,c,[a,b,c,d]).
false.
?- um_entre(b,d,[a,b,c,d]).
true .
?- um_entre(a,d,[a,b,c,d]).
false.
*/

ao_lado(X, Y, L) :- nextto(X, Y, L); nextto(Y, X, L).
um_entre(X, Y, L) :- nextto(X, K, L), nextto(K, Y, L).