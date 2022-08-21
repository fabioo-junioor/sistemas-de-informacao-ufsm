/*1-Exibir salário de cada pessoa comissionada, considerando as comissões que elas recebem.*/
select distinct pessoa.salario
from pessoa 
where pessoa.codPessoa in 
	(select participacao.codPessoa 
   	 from participacao 
   	 where participacao.comissao > 0);

/*2-Exibir nomes de projetos que não possuam funcionários que ganhem menos do que 1000 reais.*/
select nomeProj 
from projeto
where codProj not in
	(select codProj
	from pessoa natural join participacao
	where salario < 1000);

/*3-Exibir os nomes de projetos que não tenham funcionários auditores alocados.*/
select nomeProj 
from projeto
where codProj not in
	(select codProj
	from pessoa natural join participacao
	where codCateg in
		(select codCateg from categoria
		where nomeCateg like 'Auditor'));

/*4-Exibir funcionários que participaram de todos os projetos.*/
select pessoa.nome
from pessoa natural join participacao
having count(participacao.codPessoa) >= all
	(select count(participacao.codPessoa) 
	from participacao natural join projeto
	group by participacao.codPessoa);

/*5-Exibir pessoas que ganhem mais do que o chefe.*/
select a.nome, a.salario 
from pessoa a inner join pessoa b
where a.codChefe in 
	(select b.codPessoa 
  	  from pessoa 
    	where a.salario > b.salario);

/*6-Exibir os nomes de projetos que tenham o maior número de participantes.*/
select nomeProj
from projeto natural join participacao
group by nomeProj
having count(distinct codPessoa) >= all
	(select count(distinct codPessoa)
	from participacao part, projeto p
   	 where part.codProj = p.codProj);
