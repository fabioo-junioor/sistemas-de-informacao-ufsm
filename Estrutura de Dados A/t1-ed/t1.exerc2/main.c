#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "esparsa.h"

int main() {
	int **mat, qtd=0, sair=1, op=0, lin=0, col=0;
	Esparsa *es;	
	
	printf("Quantas linha tem a matriz? ");
	scanf("%d", &lin);
	printf("Quantas colunas tem a matriz? ");
	scanf("%d", &col);
	printf("\n");
	
	mat = aloca_matriz(lin, col);
	zerar_matriz(mat, lin, col);	
	preenche_matriz(mat, lin, col);
	
	es = cria_esparsa(lin, col);
	verifica_matriz(mat, lin, col, es);
	
		
	while(sair){
		int linha=0, coluna=0;
		printf("----------------------------------------------\n");
		printf("1 - Consultar valor da matriz!\n");
		printf("----------------------------------------------\n");
		printf("2 - Somatorio de uma determinada linha!\n");
		printf("----------------------------------------------\n");
		printf("3 - Percentual de valores nao nulos na matriz!\n");
		printf("----------------------------------------------\n");
		printf("4 - Imprimir matriz esparsa!\n");
		printf("----------------------------------------------\n");
		printf("10 - Sair!\n");
		printf("----------------------------------------------\n");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				printf("Informe a linha: ");
				scanf("%d", &linha);
				printf("Informe a coluna: ");
				scanf("%d", &coluna);
				imprime_matriz_pos(linha, coluna, es);
				break;
				
			case 2:
				printf("Informe a linha: ");
				scanf("%d", &linha);
				somatorio_matriz(linha, es);
				break;
				
			case 3:
				qtd = percentual_nao_nulos(es);
				calcula_percentual(qtd, lin, col);
				break;
			
			case 4:	
				imprimir_esparsa(es);
				break;
				
			case 10:
				sair = 0;
				break;
				
			default:
				printf("Valor invalido\n");
				
		}
		printf("\n");
		
	}	
	
	free_matriz(lin, mat);	
	esparsa_free(es);
	system("PAUSE");
	return 0;
}
