programa
{
	inteiro n1, n2, c, i, r, resto, aux;
	funcao inicio()
	{
		escreva("Digite o dividendo: ")
  		leia(n1)
 		escreva("Digite o divisor: ")
 		leia(n2)
 		
 		aux := n1
 		enquanto (n1>=0) faca
 			se (n1>=n2) entao
 				c:=c+1
 			fimse
 			n1 := n1-n2
		  fimenquanto
		  se (n1<0) entao
		    r:=n1+n2
		  fimse
		  escreval("Resultado -:",c)
		  escreval("Resto -----:",r)	
	fim.	  
}		//cociente inteiro da divisao
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 428; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */