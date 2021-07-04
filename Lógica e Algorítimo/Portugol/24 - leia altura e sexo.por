programa
{
	caracter sexo;
	inteiro soma_alt_m, maior, menor, qtd_mulher, qtd_homens, i;
	funcao inicio()
	{
		qtd_homens := 0
		qtd_mulheres := 0
		soma_alt_m := 0
		para i de 1 ate 50 faca
		leia (sexo)
		leia (altura)
		se (sexo = "M") entao
		qtd_homens <- qtd_homens +1
		senao
		qtd_mulheres := qtd_mulheres + 1
		soma_alt_m := soma_alt_m + altura
		fimse
		se i = 1) entao
		maior := altura
		menor := altura
		senao
		se (menor > altura) entao
		menor := altura
		fimse
		se (maior < altura) entao
		maior := altura
		fimse
		fimse
		fimpara
		escreval ("Menor: ", manor)
		escreval ("Maior: ", maior)
		escreval ("Altura média das mulheres: ", soma_alt_m/ qtd_mulheres)
		escreval ("Quantidade de homens: ", qtd_homens)
		escreval ("Quantidade de mulheres: ", qtd_mulheres)
		fim.
	}
}			//leia altura e sexo
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 817; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */