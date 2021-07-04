programa
{
	inteiro idade;
	funcao inicio()
	{
		escreva("idade ")
		leia(idade)

		se(idade < 16 e idade > 0){
			escreva("ainda nao vota ")
		}senao se(idade >= 16 e idade < 18){
			escreva("voto facultativo ")
		}senao se(idade >=18  e idade <= 65){
			escreva("voto obrigatorio ")
		}senao se(idade > 65){
			escreva("voto facultativo")
		}
	}
}		// classe eleitoral
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 370; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */