/*1- Selecionar nome e salário das pessoas cujo salário fique entre 500 e 1000 reais.*/
select pessoa.nome, pessoa.salario
from pessoa
where pessoa.salario > 500 
and pessoa.salario < 1000;

/*2-Exibir número de pessoas que tenham Silva como parte do nome ou que recebam menos de 1000 reais.*/
select count(pessoa.nome) silvaOuMenos1000r
from pessoa
where pessoa.nome like '%silva%'
or pessoa.salario < 1000;

/*3-Selecionar quantas pessoas trabalham no Projeto de código 1.*/
select count(pessoa.nome) qtdPessoas
from pessoa inner join participacao inner join projeto
on pessoa.codPessoa = participacao.codPessoa
and participacao.codProj = projeto.codProj
and projeto.codProj = 1;

/*4-Selecionar quantas pessoas trabalham no Projeto chamado Projeto 1.*/
select count(pessoa.nome) qtdPessoas
from pessoa inner join participacao inner join projeto
on pessoa.codPessoa = participacao.codPessoa
and participacao.codProj = projeto.codProj
and projeto.nomeProj = 'projeto 1';

/*5-Para cada cidade, exibir o maior salário pago.*/
select endereco.cidade, max(pessoa.salario) maiorSalario
from endereco inner join pessoa
on endereco.codPessoa = pessoa.codPessoa
group by endereco.cidade;

/*6-Exibir quantas vezes cada função em projetos foi desempenhada.*/
select participacao.funcao, count(participacao.funcao) participacao
from participacao
group by participacao.funcao;

/*7-Selecionar nome da pessoa, projeto onde atua e sua função. Mostrar também pessoas que não atuem em nenhum projeto.*/
select pessoa.nome, projeto.nomeProj, participacao.funcao
from projeto right outer join pessoa left outer join participacao
on pessoa.codPessoa = participacao.codPessoa
on projeto.codProj = participacao.codProj;

/*8-Exibir o custo de cada projeto, ou seja, o valor de comissão pago por projeto.*/
select projeto.nomeProj, sum(participacao.comissao) comissaoPorProj
from projeto inner join participacao
on projeto.codProj = participacao.codProj
where participacao.comissao is not null
group by projeto.nomeProj;

/*9-Exibir o salário e número de pessoas que o recebem, apenas para valores que são pagos a mais de uma pessoa.*/
select pessoa.salario, count(pessoa.nome)
from pessoa
group by pessoa.salario
having count(pessoa.nome) > 1;

/*10-Exibir nomes de pessoas que ganhem mais do que o chefe.*/
select a.nome, a.salario
from pessoa a inner join pessoa b
on a.codChefe = b.codPessoa
where a.salario > b.salario;
