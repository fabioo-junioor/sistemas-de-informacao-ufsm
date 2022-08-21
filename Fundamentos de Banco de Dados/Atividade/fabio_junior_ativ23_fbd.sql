/*1-Exibir os ids de líderes de projetos. Só deve ser exibido um líder se todos seus projetos tiveram mais do que 2 alocações.*/
select idlider from projeto
where idproj in 
(select idproj
from alocacao
having count(idproj) > 2);

/*2-Exibir nomes de líderes de projetos e os nomes de seus projetos. Só deve ser exibido um líder se todos seus projetos tiveram mais do que 2 alocações.*/
select projeto.nome, func.nome
from projeto,func
where idproj in 
	(select idproj
	from alocacao
	having count(idproj) > 2)
and projeto.idlider = func.idfunc;

/*3-Selecionar os nomes de projetos em que nenhum dos funcionários alocados ganhe menos do que 5.000.*/
select projeto.nome
from projeto
where projeto.idProj in 
	(select alocacao.idProj
	from func natural join remuneracao natural join alocacao 
   	 where remuneracao.valor > 5000);

/*4-Exibir a média de salário dos funcionários que lideraram projetos com custo maior do que 25.000.*/
select avg(func.salario) media
from func
where func.idFunc in 
	(select projeto.idLider
	from  projeto 
   	where projeto.custo > 25000);

/*5-Exibir nomes de funcionários que receberam o maior valor a título de gratificações.*/
select func.nome 
from func natural join remuneracao
where func.idFunc in  
	(select remuneracao.idFunc
	from remuneracao
	where remuneracao.remun like '%gratificacao%')
and remuneracao.valor = 
	(select max(remuneracao.valor)
	from remuneracao
	where remuneracao.remun like '%gratificacao%');

/*6-Mostrar nomes de funcionários que são chefes ou diretores.*/
select func.nome
from func
where func.idFunc in 
	(select func.idChefe from func)
or func.idFunc in 
	(select depto.idDiretor
	from depto);
