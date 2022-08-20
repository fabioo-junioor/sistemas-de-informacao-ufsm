/*
Nesta tarefa de programação, você deverá implementar o método básico de análise de frequência para quebrar cifras de substituição monoalfabética.
Seu programa (ou conjunto de programas) deverá ser capaz de:
- Criar uma tabela de frequência a partir de um arquivo de texto puro, e armazenar esta tabela.
- Usar a(s) tabela(s) para comparação e quebra de uma cifra.
- Implementar alguma forma de detecção de texto para auxiliar na automatização da tarefa de quebra de cifra.

Exemplo: Teste seu código na cifra de substituição monoalfabética simples abaixo.
CIFRA: HQKQWTFLCGETRTEGROYOEGXQDTFLQUTDLTEKTZQ
Observações:
- Trabalho poderá ser feito individualmente ou em duplas.
- Seu código não precisa ser capaz de quebrar completamente a cifra, mas oferecer ao menos uma quebra superior a 50% da chave (alfabeto usado).
- Seu trabalho será testado em máquina com SO Linux, usando o compilador gcc e bibliotecas padrão. Se desejar usar outra linguagem de programação, consulte-me.
*/
// Fabio Correa Costa Junior - 201921050

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#define TAM 26

	//struct para salvar textos aleatórios
struct dados_letra{
	char letra[1];
	double quantidade;
	double porcentagem;
	bool existe;
	double desvio_padrao;
	
};

	//struct para salvar cifra
struct dados_cifra{
	char letra[1];
	double quantidade;
	double porcentagem;
	bool existe;
	bool descifrada;
	char letra_descifrada[1];
	double desvio_padrao;
	
};

	//função que verifica a maior ocorrencia "de cada" letra do texto.
	//retorna a letra com maior ocorrencia e dps é setada com false.
char menor_ocorrencia_letra_texto(struct dados_letra *dados){
	double menor=1;
	int i, j=0;
	char letra[1];
	
	for(i=0; i<TAM; i++){
		if((dados[i].desvio_padrao <= menor) && (dados[i].existe == true)){
			menor = dados[i].desvio_padrao;				
			letra[0] = dados[i].letra[0];
			//printf("--%c\n", letra[0]);
			
		}
	}
	//printf("--%c\n", letra[0]);
	for(j=0; j<TAM; j++){
		if((dados[j].letra[0] == letra[0]) && (dados[j].existe == true)){
			dados[j].existe = false;
			
		}
	}
	return letra[0];
	
}

	//função que verifica a maior ocorrencia "de cada" letra da cifra.
	//retorna a letra com maior ocorrencia e dps é setada com false.
char menor_ocorrencia_letra_cifra(struct dados_cifra *cifra){
	double menor=1;
	int i, j;
	char letra[1];
	
	for(i=0; i<TAM; i++){
		if((cifra[i].desvio_padrao <= menor) && (cifra[i].existe == true)){
			menor = cifra[i].desvio_padrao;				
			letra[0] = cifra[i].letra[0];
			
		}
	}
	//printf("--%c\n", letra[0]);
	for(j=0; j<TAM; j++){
		if((cifra[j].letra[0] == letra[0]) && (cifra[j].existe == true)){
			cifra[j].existe = false;
			
		}
	}	
	return letra[0];
	
}

	//função que verifica a quantidade de ocorrencia de cada letra no texto.
	//se não existe a letra no vetor -> coloca na proxima celula do vetor
	//se ja existe quantidade += 1.
	//aplicado filtros em alguns caracteres.
void verifica_frequencia_letras_texto(struct dados_letra *dados, char letra){
	int i;
	for(i=0; i<TAM; i++){
		if((dados[i].letra[0] == letra) && (dados[i].existe == true) && (letra != ' ')){
			dados[i].quantidade += 1;
			return;
						
		}else if((dados[i].letra[0] == '%') && 
					(letra != ' ') &&
					(letra != '\n') &&
					(letra != ',') &&
					(letra != '?') &&
					(letra != '>') &&
					(letra != '<') &&
					(letra != '0') &&
					(letra != '1') &&
					(letra != '2') &&
					(letra != '3') &&
					(letra != '4') &&
					(letra != '5') &&
					(letra != '6') &&
					(letra != '7') &&
					(letra != '8') &&
					(letra != '9') &&
					(letra != '.') && 
					(letra != '-') &&
					(letra != ':') &&
					(letra != '$') &&
					(letra != ';') &&
					(letra != '!') &&
					(letra != '[') &&
					(letra != '/') &&
					(letra != '&') &&
					(letra != '(') &&
					(letra != ')') &&
					(letra != '=') &&
					(letra != '+') &&
					(letra != 39)){
			dados[i].letra[0] = letra;
			dados[i].quantidade += 1;
			dados[i].existe = true;
			return;
			
		}
	}
}

	//função que verifica a quantidade de ocorrencia de cada letra na cifra.
	//se não existe a letra no vetor -> coloca na proxima celula do vetor
	//se ja existe quantidade += 1.
	//aplicado filtros em alguns caracteres.
void verifica_frequencia_letras_cifra(struct dados_cifra *cifra, char letra){
	int i;
	for(i=0; i<TAM; i++){
		if((cifra[i].letra[0] == letra) && (cifra[i].existe == true) && (letra != ' ')){
			cifra[i].quantidade += 1;
			return;
						
		}else if((cifra[i].letra[0] == '%') && 
					(letra != ' ') &&
					(letra != '\n') &&
					(letra != ',') &&
					(letra != '?') &&
					(letra != '>') &&
					(letra != '<') &&
					(letra != '0') &&
					(letra != '1') &&
					(letra != '2') &&
					(letra != '3') &&
					(letra != '4') &&
					(letra != '5') &&
					(letra != '6') &&
					(letra != '7') &&
					(letra != '8') &&
					(letra != '9') &&
					(letra != '.') && 
					(letra != '-') &&
					(letra != ':') &&
					(letra != '$') &&
					(letra != ';') &&
					(letra != '!')){
			cifra[i].letra[0] = letra;
			cifra[i].quantidade += 1;
			cifra[i].existe = true;
			return;
			
		}
	}
}

	//função que imprime a tabela(struct) de ocorrencias do texto.
void imprime_struct_texto(struct dados_letra *dados){
	int i;
	printf("----------------------------------\n");
	printf("--TABELA DE FREQUENCIA DO TEXTO--\n");
	for(i=0; i<TAM; i++){
		printf("Letra Texto: %c\n", dados[i].letra[0]);
		printf("Quantidade de Letras: %.0lf\n", dados[i].quantidade);
		printf("Porcentagem: %.5lf\n", dados[i].porcentagem);
		printf("Desvio Padrao: %.10lf\n", dados[i].desvio_padrao);
		//printf("--%s\n", dados[i].existe ? "true" : "false");
		printf("\n");
		
	}	
}

	//função que imprime a tabela(struct) de ocorrencias da cifra.
void imprime_struct_cifra(struct dados_cifra *cifra){
	int i;
	printf("----------------------------------\n");
	printf("--TABELA DE FREQUENCIA DA CIFRA--\n");
	for(i=0; i<TAM; i++){
		if(cifra[i].letra[0] != '%'){		
			printf("Letra Cifrada: %c\n", cifra[i].letra[0]);
			printf("Quantidade de Letras: %.0lf\n", cifra[i].quantidade);
			printf("Porcentagem: %.5lf\n", cifra[i].porcentagem);
			printf("Letra Descifrada: %c\n", toupper(cifra[i].letra_descifrada[0]));
			printf("Desvio Padrao: %.10lf\n", cifra[i].desvio_padrao);
			//printf("--%s\n", cifra[i].existe ? "true" : "false");
			//printf("Descifrado: %s\n", cifra[i].desc ? "true" : "false");
			printf("\n");
			
		}		
	}	
}

	//função que inicializa as duas structs(texto e cifra).
void inicializa_structs(struct dados_letra *dados, struct dados_cifra *cifra){
	int i;
	for(i=0; i<TAM; i++){
		dados[i].letra[0] = '%';
		dados[i].quantidade = 0;
		dados[i].porcentagem = 0;
		dados[i].existe = false;
		dados[i].desvio_padrao = 0;
		
	}
	for(i=0; i<TAM; i++){
		cifra[i].letra[0] = '%';
		cifra[i].quantidade = 0;
		cifra[i].porcentagem = 0;
		cifra[i].letra_descifrada[0] = '%';
		cifra[i].existe = false;
		cifra[i].descifrada = false;
		cifra[i].desvio_padrao = 0;
		
	}
}

	//função que calcula a porcentagem de cada letra -> (texto e cifra).
void calculo_porcentagem(struct dados_letra *dados, struct dados_cifra *cifra){
	int i;
	double total_caracter_texto=0, total_caracter_cifra=0;
	double calc = 0;
	for(i=0; i<TAM; i++){
		total_caracter_texto += dados[i].quantidade;
		
	}
	for(i=0; i<TAM; i++){
		total_caracter_cifra += cifra[i].quantidade;
		
	}
	for(i=0; i<TAM; i++){
		calc = dados[i].quantidade/total_caracter_texto;
		dados[i].porcentagem = calc;
		calc = 0;
		
	}
	calc = 0;
	for(i=0; i<TAM; i++){
		calc = cifra[i].quantidade/total_caracter_cifra;
		cifra[i].porcentagem = calc;
		calc = 0;
		
	}	
}

	//função que faz o calculo do desvio padrao do texto
void calculo_desvio_padrao_texto(struct dados_letra *dados){
	int i, j;
	double dp=0, aux=0, quantidade=0;
	for(i=0; i<TAM; i++){
		quantidade = dados[i].quantidade;
		for(j=0; j<quantidade; j++){
			aux += pow((1-dados[i].porcentagem), 2);
			
		}
		dp = sqrt(aux/dados[i].quantidade);
		//printf("-- %.4f\n", dp);
		dados[i].desvio_padrao = dp;
		dp = 0;
		aux = 0;
		quantidade = 0;
	}
}

	//função que faz o calculo do desvio padrao da cifra
void calculo_desvio_padrao_cifra(struct dados_cifra *cifra){
	int i, j;
	double aux=0, dp=0, quantidade=0;
	for(i=0; i<TAM; i++){
		quantidade = cifra[i].quantidade;
		for(j=0; j<quantidade; j++){
			aux += pow((1-cifra[i].porcentagem), 2);
			
		}
		dp = sqrt(aux/cifra[i].quantidade);
		//printf("-- %.4f\n", dp);
		cifra[i].desvio_padrao = dp;
		dp = 0;
		aux = 0;
		quantidade = 0;
	}
}

	//função que compara as maiores porcentagens de (texto e cifra).
	//a primeira letra em porcentagem da "cifra" é equivalente a primeira letra em porcentagem do "texto".
	//e assim por diante.
void executa_comparacao(struct dados_letra *dados, struct dados_cifra *cifra){
	int i, j;
	char letra_texto[1], letra_cifra[1];
	
	for(i=0; i<TAM; i++){
		letra_cifra[0] = menor_ocorrencia_letra_cifra(cifra);
		letra_texto[0] = menor_ocorrencia_letra_texto(dados);
		//printf("--%c\n", letra_texto[0]);
		for(j=0; j<TAM; j++){
			if((cifra[j].letra[0] == letra_cifra[0]) && (cifra[j].descifrada == false)){
				cifra[j].letra_descifrada[0] = letra_texto[0];
				cifra[j].descifrada = true;
			
			}	
		}		
	}
}

	//função de saida, com a possivel descifração.
	//para cada letra da cifra é mostrada "cifra[i].letra_descifrada[0]".
void saida_descifrada(FILE *texto_cifra, struct dados_cifra *cifra, float taxa){
	char caracter;
	int i;
	texto_cifra = fopen("cifra.txt", "rt");
	printf("\n##########################################################\n\n");
	printf("Letras decifradas em maiusculo / taxa de desvio padrao menor que 0.999 \n");
	printf("Quanto maior a taxa, + letras serao descifradas, porem a precissao sera menor \n\n");	
	printf("Possivel texto descifrado!!\n\n");
	while((caracter=fgetc(texto_cifra)) != EOF){
		for(i=0; i<TAM; i++){
			if((cifra[i].letra[0] == caracter) && (cifra[i].descifrada == true) && (cifra[i].desvio_padrao < taxa)){
				printf("%c", toupper(cifra[i].letra_descifrada[0]));
			
			}else if((cifra[i].letra[0] == caracter) && (cifra[i].descifrada == true) && (cifra[i].desvio_padrao > taxa)){
				printf("%c", caracter);
						
			}	
		}		
	}
	printf("\n\n##########################################################\n\n");
	
}
int main(){
	FILE *texto_aleatorio;
	FILE *texto_cifra;
	//int n=0; 
	double total_caracter_texto=0, total_caracter_cifra=0;
	double taxa_de_busca = 0.920;	//quanto maior a taxa, + letras serao decodificadas, - precissao
	char caracter_texto, caracter_cifra, caracter_desc;
	struct dados_letra dados[TAM];
	struct dados_cifra cifra[TAM];
	
	inicializa_structs(dados, cifra);
	
	texto_aleatorio = fopen("palavras_corpus.txt", "rt");
	if(texto_aleatorio == NULL){
		printf("ERRO no texto aleatorio!\n");
		return;
		
	}
	texto_cifra = fopen("cifra.txt", "rt");
	if(texto_cifra == NULL){
		printf("ERRO no texto cifra!\n");
		return;
		
	}
	while((caracter_texto=fgetc(texto_aleatorio)) != EOF){
		verifica_frequencia_letras_texto(dados, caracter_texto);
		total_caracter_texto++;
		
	}
	while((caracter_cifra=fgetc(texto_cifra)) != EOF){
		verifica_frequencia_letras_cifra(cifra, caracter_cifra);
		total_caracter_cifra++;
		
	}
	
	fclose(texto_aleatorio);
	fclose(texto_cifra);
	
	calculo_porcentagem(dados, cifra);
	
	calculo_desvio_padrao_texto(dados);
	calculo_desvio_padrao_cifra(cifra);
	
	executa_comparacao(dados, cifra);	
	
	imprime_struct_texto(dados);
	imprime_struct_cifra(cifra);
	
	saida_descifrada(texto_cifra, cifra, taxa_de_busca);
	
	return 0;
	
}
