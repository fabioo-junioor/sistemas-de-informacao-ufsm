programa
{
	inteiro base, esp;
	real calculo, contador;
	funcao inicio()
	{
		escreva("informe a base ")
		leia(base)
		escreva("informe o expoente ")
		leia(esp)
		se(esp<0)entao
		escreva("informe expoente positivo ")
		fimse
		se(esp=0)entao
		escreva("A resposta e 1 ")
		senao
		calculo:= -1
		contador:=0
		repita
		contador:=contador+1
		calculo:=calculo*base
		ate(contador=esp)
		escreva("a resposta e ", calculo)
		fimse
	}
}		//exponenciaçao
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 452; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */