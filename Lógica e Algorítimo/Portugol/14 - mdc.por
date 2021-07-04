programa
{
	inteiro num1, num2, maior menor, i;
	funcao inicio()
	{
		escreva("primeiro numero")
		leia(num1)
		escreva("segundo numero")
		leia(num2)

		se(num1>num2)entao
		maior:=num1
		menor:=num2
		senao
		maior:=num2
		menor:=num1
		fimse
		enquanto (maior mod menor<>0)faca
		i:=menor
		menor:=maior mod menor
		maior:=i
		fimenquanto

		escreva("O mdc eh ", menor)
	}
}			//mdc
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 385; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */