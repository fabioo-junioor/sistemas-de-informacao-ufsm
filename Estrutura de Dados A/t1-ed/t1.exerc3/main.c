#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "identidade.h"

int main(){
	int **mat, tam=0, valida_id=0, valida_res=0, sair=1, op=0;
	Identidade id;
	
	printf("Qual o tamanho da matriz? ");
	scanf("%d", &tam);
	
	mat = aloca_matriz(tam);
	preenche_matriz(tam, mat);	
	
	valida_id = verifica_matriz_identidade(mat, tam);
	valida_res = verifica_matriz_resto(mat, tam);
	
	if((valida_id)&&(valida_res)){
		id = preenche_lista(tam, mat);
		while(sair){
			printf("----------------------------------------------\n");
			printf("1 - Imprimir matriz!\n");
			printf("----------------------------------------------\n");
			printf("10 - Sair!\n");
			printf("----------------------------------------------\n");
			scanf("%d", &op);
			printf("\n");
			switch(op){
				case 1:
					imprimir_identidade(id, tam);
					break;
				
				case 10:
					sair = 0;
					break;
				
				default:
					printf("Valor invalido\n");
				
			}
		printf("\n\n");
		
		}
	}else{
		printf("\nNao eh matriz identidade!\n\n");
		
	}
	
	free_matriz(tam, mat);
	system("PAUSE");
	return 0;
}
