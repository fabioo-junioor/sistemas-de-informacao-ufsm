programa
{
	caracter: nome_pais_1, nome_pais_2, nome_pais_3;
	inteiro: ouro_pais_1, ouro_pais_2, ouro_pais_3;
 	inteiro: prata_pais_1, prata_pais_2, prata_pais_3;
 	inteiro: bronze_pais_1, bronze_pais_2, bronze_pais_3;
 	inteiro: total_pais_1, total_pais_2, total_pais_3;
	
	funcao inicio()
	{
	leia (nome_pais_1, ouro_pais_1, prata_pais_1, bronze_pais_1);
 	leia (nome_pais_2, ouro_pais_2, prata_pais_2, bronze_pais_2);
 	leia (nome_pais_3, ouro_pais_3, prata_pais_3, bronze_pais_3);

 	total_pais_1 = (ouro_pais_1 * 3) + (prata_pais_1 * 2) + (bronze_pais_1 * 1);
 	total_pais_2 = (ouro_pais_2 * 3) + (prata_pais_2 * 2) + (bronze_pais_2 * 1);
 	total_pais_3 = (ouro_pais_3 * 3) + (prata_pais_3 * 2) + (bronze_pais_3 * 1);
	escreva ("Classificação: ");

	se ((total_pais_1 > total_pais_2) e (total_pais_1 > total_pais_3)) entao
	escreva ("1º Lugar: ", nome_pais_1, " - Medalhas: ", total_pais_1);
 	se (total_pais_2 > total_pais_3) entao
 	inicio
 	escreva ("2º Lugar: ", nome_pais_2, " - Medalhas: ", total_pais_2);
	escreva ("3º Lugar: ", nome_pais_3, " - Medalhas: ", total_pais_3);
	fim;
	senao
	inicio
	escreva ("2º Lugar: ", nome_pais_3, " - Medalhas: ", total_pais_3);
	escreva ("3º Lugar: ", nome_pais_2, " - Medalhas: ", total_pais_2);
	fim;
	fimse;
	fimse;
	se ((total_pais_2 > total_pais_1) e (total_pais_2 > total_pais_3)) entao
	escreva ("1º Lugar: ", nome_pais_2, " - Medalhas: ", total_pais_2);
	se (total_pais_1 > total_pais_3) entao
	inicio
	escreva ("2º Lugar: ", nome_pais_1, " - Medalhas: ", total_pais_1);
	escreva ("3º Lugar: ", nome_pais_3, " - Medalhas: ", total_pais_3);
	fim;
	senao
	escreva ("2º Lugar: ", nome_pais_3, " - Medalhas: ", total_pais_3);
	escreva ("3º Lugar: ", nome_pais_1, " - Medalhas: ", total_pais_1);
	fim;
	fimse;
	fimse;
	se ((total_pais_3 > total_pais_1) e (total_pais_3 > total_pais_2)) entao
	escreva ("1º Lugar: ", nome_pais_3, " - Medalhas: ", total_pais_3);
	se (total_pais_1 > total_pais_2) entao
	inicio
	escreva ("2º Lugar: ", nome_pais_1, " - Medalhas: ", total_pais_1);
	escreva ("3º Lugar: ", nome_pais_2, " - Medalhas: ", total_pais_2);
	fim;
	senao
	inicio
	escreva ("2º Lugar: ", nome_pais_2, " - Medalhas: ", total_pais_2);
	escreva ("3º Lugar: ", nome_pais_1, " - Medalhas: ", total_pais_1);
	fim;
	fimse;			//olimpica
	fimse;
	fim.
	}
	
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 2283; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */