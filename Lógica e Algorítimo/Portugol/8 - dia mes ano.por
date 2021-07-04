programa
{
	inteiro dia, mes, ano;
	funcao inicio()
	{
		escreva("informe o dia ")
		leia(dia)
		escreva("informe o mes ")
		leia(mes)
		escreva("informe o ano ")
		leia(ano)

		se(ano > 0){
			escreva("ano valido ")
		}senao{
			escreva("ano invalido ")	
		}
		se (mes > 12 ou mes < 0){
			escreva("mes invalido ")
		}senao{
			escreva("mes valido ")
		}
		se(dia > 31 ou dia < 0){
			escreva("dia invalido ")
		}senao{
			escreva("dia valido ")
		}
	}
}			// dia mes ano
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 472; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */