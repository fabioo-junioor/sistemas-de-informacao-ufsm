/*1-Exibir os anos e nomes de filmes lançados a partir de 2014. Renomeie a coluna ano para ‘lancamento’.*/
select nome, ano lancamento 
from filme 
where ano > 2014;

/*2-Selecionar os anos de lançamento de filmes (sem repeti-los).*/
select distinct ano 
from filme;

/*3-Selecionar todos dados de filmes, em ordem ascendente de arrecadação.*/
select * 
from filme 
order by arrecadacao asc;

/*4-Selecionar o número de filmes lançados por ano.*/
select ano, count(ano) 
from filme 
group by ano;

/*5-Exibir nomes de filmes e de seus diretores.*/
select filme.nome, diretor.nome 
from filme, diretor 
where filme.diretor = diretor.id;

/*6-Selecionar nomes de filmes dirigidos por Steven Spielberg.*/
select filme.nome from filme, diretor
where filme.diretor = diretor.id and diretor.nome = 'Steven Spielberg';

/*7-Retornar nomes de diretores juntamente com o número de filmes que cada um produziu.*/
select diretor.nome, count(filme.diretor) 
from diretor, filme
where diretor.id = filme.diretor 
group by diretor.nome;

/*8-Para cada diretor, retornar o ano em que teve o primeiro filme lançado.*/
select diretor.nome, min(filme.ano) 
from filme, diretor
where filme.diretor = diretor.id
group by diretor.nome;

/*9-Para cada diretor, mostrar a diferença entre a sua maior e menor arrecadação.*/
select diretor.nome, (max(filme.arrecadacao)-min(filme.arrecadacao)) diferenca
from diretor, filme
where diretor.id = filme.diretor
group by diretor.nome;

/*10-Selecionar rank, filme, ano, diretor, e-mail e arrecadação dos filmes, ordenados pelo rank.*/
select rank.rank, filme.nome, filme.ano, diretor.nome, diretor.email, filme.arrecadacao
from rank, filme, diretor
where filme.diretor = diretor.id
and rank.filme_id = filme.id
order by rank.rank asc;