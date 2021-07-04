programa
{
		inteiro num, cont, a, b, c, d, f, g;
		real a1, b1, c1, d1, f1, g1;
	funcao inicio()
	{
		escreva("1 para o candidato A ")
		escreva("2 para o candidato B ")
		escreva("3 para o candidato C ")
		escreva("4 para o candidato D ")
		escreva("5 para nulo ")
		escreva("6 para o branco ")
		escreva("0 para finalizar ")

		enquanto(num<>0) faca
			leia(num)
			cont:=cont+1
			se(num=1)entao
			a:=a+1
			senao se(num=2)entao
			b:=b+1
			senao se(num=3)entao
			c:=c+1
			senao se(num=4)entao
			d:=d+1
			senao se(num=5)entao
			f:=f+1
			senao se(num=6)entao
			g:=g+1
			senao
			escreva("digito incorreto")
			fimse
		fimenquanto

		a1:=a*100/cont
   		b1:=b*100/cont                               
    		c1:=c*100/cont
    		d1:=d*100/cont
    		e1:=f*100/cont
    		f1:=g*100/cont	

    		escreva("candidato a recebeu ",a,"votos, ",a1,"% do total ")
    		escreva("candidato b recebeu ",b,"votos, ",b1,"% do total ")
    		escreva("candidato a recebeu ",c,"votos, ",c1,"% do total ")
    		escreva("candidato a recebeu ",d,"votos, ",d1,"% do total ")
    		escreva("votos nulos ",f,"votos, ",f1,"% do total ")
    		escreva("votos brancos ",g,"votos, ",g1,"% do total ")
    		escreva("total de votos ",cont)
    		fim.
	}
}			//votos
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1249; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */