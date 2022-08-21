/*1-Selecionar nome das pessoas que tenham salário definido.*/
select pessoa.nome
from pessoa
where pessoa.salario is not null;

/*2-Selecionar nome e salário das pessoas que tenham Silva como parte do nome e recebem mais do que 1000 reais. Ordenar o resultado por salário.*/
select pessoa.nome, pessoa.salario
from pessoa
where pessoa.nome like '%silva%'
and pessoa.salario > 1000
order by pessoa.salario asc;

/*3-Selecionar todos os dados de pessoas e seus endereços.*/
select * 
from pessoa right join endereco
on pessoa.codPessoa = endereco.codPessoa;

/*4-Selecionar todos os dados de pessoas e seus endereços. Pessoas sem endereço também devem ser mostradas.*/
select * 
from pessoa left join endereco
on pessoa.codPessoa = endereco.codPessoa;

/*5-Selecionar quantas pessoas trabalham em cada projeto, identificando o projeto correspondente à quantidade.*/
select count(pessoa.nome) numPessoas, projeto.nomeProj
from projeto inner join participacao inner join pessoa
on projeto.codProj = participacao.codProj
and participacao.codPessoa = pessoa.codPessoa
group by projeto.nomeProj;

/*6-Exibir o número de projetos onde revisores atuem.*/
select count(projeto.nomeProj) revisoresAtuam
from categoria inner join pessoa inner join participacao inner join projeto
on categoria.codCateg = pessoa.codCateg
and pessoa.codPessoa = participacao.codPessoa
and participacao.codProj = projeto.codProj
and categoria.nomeCateg = 'Revisor'
group by categoria.nomeCateg;

/*7-Selecionar nomes de categorias juntamente com a quantidade de pessoas que atuam na categoria.*/
select categoria.nomeCateg, count(pessoa.nome) atuam
from categoria inner join pessoa
on categoria.codCateg = pessoa.codCateg
group by categoria.nomeCateg;

/*8-Selecionar nomes de pessoas de Bagé que atuaram como líderes de projetos.*/
select distinct pessoa.nome
from participacao inner join endereco inner join pessoa
on pessoa.codPessoa = endereco.codPessoa
and endereco.cidade = 'Bagé'
and pessoa.codPessoa = participacao.codPessoa
and participacao.funcao = 'Lider';

/*9-Exibir o número de pessoas de Bagé que já atuaram em pelo menos algum projeto.*/
select count(distinct pessoa.nome) numPessoas
from participacao inner join endereco inner join pessoa
on pessoa.codPessoa = endereco.codPessoa
and endereco.cidade = 'Bagé'
and pessoa.codPessoa = participacao.codPessoa
group by pessoa.nome;

/*10-Selecionar cidades e o número de pessoas daquela cidade que já atuaram em projetos em posições que não fossem de Líder.*/
select endereco.cidade, count(pessoa.nome) numPessoas
 from endereco inner join pessoa inner join participacao
 on endereco.codPessoa = pessoa.codPessoa
 and pessoa.codPessoa = participacao.codPessoa
 and participacao.funcao <> 'Lider'
 group by endereco.cidade;
