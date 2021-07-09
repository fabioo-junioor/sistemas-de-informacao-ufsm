/*
1. Defina um predicado recursivo incN(L1,N,L2), de forma que L2 seja uma lista com todos os elementos de L1 
somados à constante N.
2. Defina um predicado recursivo hasN(L,N) que seja verdadeiro se L for uma lista de N elementos.
3. Defina um predicado recursivo countdown(N,L), de forma que L seja uma lista com os números [N, N-1, N-2, .., 1],
sendo N um número positivo. Exemplo:
?- countdown(7,L).
L = [7, 6, 5, 4, 3, 2, 1].
4. Defina um predicado recursivo nRandoms(N,L), de forma que L seja uma lista com N números gerados aleatoriamente,
conforme os exemplos abaixo:
?- nRandoms(3,L).
L = [60, 92, 28].

?- nRandoms(6,L).
L = [12, 81, 46, 19, 81, 21].

?- nRandoms(0,L).
L = [].
*/

incN([], _, []).
incN([H|T], N, [H2|T2]) :- incN(T, N, T2), H2 is H + N.

hasN([],0).
hasN([_|T], N) :- hasN(T, K), N is K +1.

countdown(0,[]).
countdown(N,[H|T]) :- H is N, K is N -1, countdown(K,T),!.

nRandoms(0,[]).
nRandoms(N,[H|T]) :- random(1,50,H), K is N -1, nRandoms(K,T),!.