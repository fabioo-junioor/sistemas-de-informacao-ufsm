programa
{
	inteiro cont, totalgraos, somagraos;
	funcao inicio()
	{
		cont:= 0
		totalgraos:= 1
		somagraos:= 0
           para cont de 1 ate <= 64 passo 1 faca
                 se (cont > 1) entao
                  //multiplica totalgraos x 2
                  totalgraos:= totalgraos*2
                  //soma o totalgraos e acumula com o somagraos
                  somagraos:= somagraos+totalgraos
                  fimse
                  escreval("Quadro do xadrez ", cont, " tem ", totalgraos, "Grãos.")
                  //acumula contador até chegar 64 para o looping para
                  cont<- cont+1
           fimpara
	escreva("Serão pagos ", somagraos, " grãos.")
}
}		//graos monge
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 700; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */