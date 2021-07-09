/*
Escreva um programa em Prolog para resolver o seguinte problema de lógica: Angela, Bernardo e Carla 
são crianças premiadas em um show de talentos infantis. Suas idades são 5, 7 e 8 anos. 
Uma das crianças ganhou o 1o Lugar. A menina que ganhou o 2o Lugar é 3 anos mais velha que Angela. 
A criança que ganhou o 3o Lugar tem 7 anos.

A solução do problema deverá reunir todos os dados informados e deduzidos sobre as crianças. 
Seu programa deverá ter uma regra solucao(X) que permita obter a solução do problema na variável X.
*/


/*
 * comentado pq nao cheguei a uma solução.
 * 
solucao(X) :- colocacao = [_,_,_], [_,(carla,_),_] = colocacao,
    							   [_,(_,I),_] = colocacao,
    							   [_,_,(_,7)] = colocacao,
    							   I is I + 3.
*/