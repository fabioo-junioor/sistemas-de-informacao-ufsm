/*1-Mostrar nomes de filmes e dos estúdios que os produziram.*/
select filme.nome, estudio.nome 
from filme, estudio, producao
where filme.id = producao.filme_id and estudio.id = producao.estudio_id;

/*2-Retornar nomes dos filmes produzidos pelo estúdio Disney.*/
select filme.nome 
from filme, estudio, producao
where filme.id = producao.filme_id 
and estudio.id = producao.estudio_id 
and estudio.nome = 'Disney';

/*3-Selecionar avaliador, rank, filme, ano, diretor, e-mail e arrecadação dos filmes, ordenados pelo rank.*/
select avaliador.nome, rank.rank, filme.nome, filme.ano, diretor.nome, diretor.email,
filme.arrecadacao
from avaliador, rank, filme, diretor
where filme.diretor = diretor.id
and rank.filme_id = filme.id
order by rank.rank asc;

/*4-Selecionar nomes de estúdios e número de filmes que cada um produziu. Ordenar pela contagem.*/
select estudio.nome, count(filme.nome) num_filmes 
from estudio, producao, filme
where estudio.id = producao.estudio_id 
and filme.id = producao.filme_id
group by estudio.nome
order by num_filmes;

/*5-Exibir nomes de estúdios e arrecadação somada de todos seus filmes. Ordenar pela arrecadação.*/
select estudio.nome, sum(filme.arrecadacao) soma_arrecadacao 
from estudio, filme, producao
where estudio.id = producao.estudio_id
and filme.id = producao.filme_id
group by estudio.nome
order by soma_arrecadacao desc;

/*6-Exibir estúdio e arrecadação média de seus filmes. Ordenar pela arrecadação.*/
select estudio.nome, avg(filme.arrecadacao) media
from estudio, filme, producao
where estudio.id = producao.estudio_id
and filme.id = producao.filme_id
group by estudio.nome
order by media desc;

/*7-Mostrar nomes de diretores e número de filmes que dirigiram que tenham ficado entre as três primeiras colocações.*/
select diretor.nome, count(filme.nome) num_filmes
from diretor, filme, rank
where diretor.id = filme.diretor 
and filme.id = rank.filme_id 
and rank.rank <= 3
group by diretor.nome;

/*8-Exibir a maior e a menor arrecadação de cada diretor.*/
select diretor.nome, max(filme.arrecadacao) maior_arrecadacao, min(filme.arrecadacao) menor_arrecadacao
from diretor, filme
where diretor.id = filme.diretor
group by diretor.nome;

/*9-Exibir o maior e o menor ranking de cada diretor.*/
select diretor.nome, max(rank.rank) maior_rank, min(rank.rank) menor_rank
from diretor, rank, filme
where diretor.id = filme.diretor and rank.filme_id = filme.id
group by diretor.nome;

/*10-Para cada diretor, exibir o maior e o menor ranking e a maior e a menor arrecadação.*/
select diretor.nome, max(rank.rank) maior_rank, min(rank.rank) menor_rank, 
max(filme.arrecadacao) maior_arrecadacao, min(filme.arrecadacao) menor_arrecadacao
from diretor, rank, filme
where diretor.id = filme.diretor
and filme.id = rank.filme_id
group by diretor.nome;
