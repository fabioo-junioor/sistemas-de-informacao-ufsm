#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "diagonal.h"

int main() {
	int **mat, tam=0, sair=1, op=0, valida_diagonal=0;
	Diagonal di;
	
	printf("Qual o tamanho da matriz? ");
	scanf("%d", &tam);
	
	mat = aloca_matriz(tam);
	preenche_matriz(tam, mat);	
	valida_diagonal = verifica_matriz_diagonal(mat, tam);
	
	if(valida_diagonal){
		di = preenche_lista(di, tam, mat);
		while(sair){
			int lin=0, col=0;
			printf("----------------------------------------------\n");
			printf("1 - Imprimir diagonal/ordem da matriz!\n");
			printf("----------------------------------------------\n");
			printf("2 - Consultar valor da matriz!\n");
			printf("----------------------------------------------\n");
			printf("10 - Sair!\n");
			printf("----------------------------------------------\n");
			scanf("%d", &op);
			printf("\n");
			switch(op){
				case 1:
					imprimir_diagonal(di, tam);
					break;
					
				case 2:
					printf("Informe a linha? ");
					scanf("%d", &lin);
					printf("Informe a coluna? ");
					scanf("%d", &col);
					imprime_matriz_pos(di, lin, col, tam);
					break;
					
				case 10:
					sair = 0;
					break;
					
				default:
					printf("Valor invalido!\n");
					
			}
			printf("\n");
			
		}		
	}else{
		printf("\nNao eh uma matriz diagonal\n");
		
	}	
	
	free_matriz(tam, mat);
	system("PAUSE");
	return 0;
	
}
