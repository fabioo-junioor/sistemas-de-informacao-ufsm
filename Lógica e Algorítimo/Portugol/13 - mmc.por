programa
{
	inteiro x, y, mmc;
	funcao inicio()
	{
		escreva ("Digite dois números ");
   leia (x,y);
   
       para a de 2 a 9 passo 1 faca
           inicio
           a=1
           se (x mod a = 0)
              inicio
              a=1
              mmc = mmc*a;
              x = x/a;
              fim;
          fimse;
          se (y mod a = 0)
              inicio
              se a <> 1
              mmc = mmc*a;
              y = y/a;
          fimse;
       fimse;
   fim;
 escreva("o mmc entre o números é ");
fim.
	}
}		//mmc
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 543; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */