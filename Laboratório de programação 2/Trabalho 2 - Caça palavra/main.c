#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "caca-palavra.h"

int main(int argc, char *argv[]) {
	char **matriz;
	char palavra[20];
	int m=0, n=0, op=0, sair=1;
	
	printf("Quantas linhas: ");
	scanf("%d", &m);
	printf("Quantas colunas: ");
	scanf("%d", &n);	
	matriz = aloca_matriz(m, n);
	preenche_matriz(m, n, matriz);
	
	while(sair){
		imprime_matriz(m, n, matriz);
		printf("\n");
		printf("-----------------------------------------\n");
		printf("1 - Procurar palavra!\n");
		printf("-----------------------------------------\n");
		printf("2 - Novo sorteio da matriz!\n");
		printf("-----------------------------------------\n");
		printf("10 - Sair!\n");
		printf("-----------------------------------------\n");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				printf("Informe a palavra: ");
				scanf(" %[^\n]", palavra);
				verificar_matriz(matriz, palavra, m, n);
				break;
			
			case 2:
				printf("Quantas linhas: ");
				scanf("%d", &m);
				printf("Quantas colunas: ");
				scanf("%d", &n);
				
				printf("\n# Nova matriz #\n");
				preenche_matriz(m, n, matriz);
				break;
				
			case 10:
				sair = 0;
				break;
				
			default:
				printf("Valor incorreto!\n");
				break;
				
		}		
		printf("\n");
		
	}	
	
	free_palavra(palavra);
	free_matriz(m, matriz);
	
	system("PAUSE");
	return 0;
	
}
