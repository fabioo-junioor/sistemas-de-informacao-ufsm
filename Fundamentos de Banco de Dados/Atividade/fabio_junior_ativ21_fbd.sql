/*1-Exibir pessoas que não trabalharam em nenhum projeto.*/
select pessoa.nome
from pessoa
where not exists 
(select * from participacao 
	where pessoa.codPessoa = participacao.codPessoa);

/*2-Exibir pessoas que tenham alguma comissão em projetos superior ao salário de pelo menos um funcionário.*/
select pessoa.nome
from participacao inner join pessoa
on participacao.codPessoa = pessoa.codPessoa
where participacao.comissao > SOME 
	(select pessoa.salario from pessoa)
group by pessoa.nome;

/*3-Exibir nomes de pessoas que atuaram em projetos na função de liderança e não são gerentes.*/
select pessoa.nome
from pessoa
where pessoa.codPessoa in 
	(select participacao.codPessoa 
	from participacao 
    where participacao.funcao = 'Lider')
and pessoa.codCateg not in 
	(select categoria.codCateg 
	from categoria 
    where categoria.nomeCateg = 'gerente');

/*4- Exibir pessoas que tenham alguma comissão em projetos superior ao salário de qualquer funcionário.*/
select pessoa.nome
from participacao inner join pessoa
on participacao.codPessoa = pessoa.codPessoa
where participacao.comissao > ALL 
	(select pessoa.salario from pessoa)
group by pessoa.nome;

/*5-Exibir o maior número de participantes de projetos.*/
select count(participacao.codProj) maiorNum
from participacao
where participacao.codPessoa in 
	(select pessoa.codPessoa from pessoa)
group by participacao.codProj
having count(participacao.codProj) >= all 
	(select count(participacao.codProj) 
    from participacao, pessoa
	where participacao.codPessoa = pessoa.codPessoa 
    group by participacao.codProj);

/*6-Exibir a soma dos salários dos funcionários que não trabalharam em nenhum projeto.*/
select sum(pessoa.salario) somaSalarios
from pessoa
where pessoa.codPessoa not in 
	(select participacao.codPessoa from participacao);
