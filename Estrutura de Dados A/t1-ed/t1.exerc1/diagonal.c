#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "diagonal.h"

int **aloca_matriz(int m){
	int i, **mat;
	mat = (int**)malloc(m*sizeof(int*));
	for(i=0; i<m; i++){
		mat[i] = (int*)malloc(m*sizeof(int));
	}
	if(mat==NULL){
		printf("\n Erro alocacao");
		system("pause");
		exit(1);
	}
	return mat;
}

void preenche_matriz(int m, int **mat){
	int i=0, j=0;
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			printf("Informe o valor na posicao [%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}

Diagonal preenche_lista(Diagonal di, int m, int **mat){	
	int i=0, j=0, aux=0;
	
	di.v = (int*)malloc(m*sizeof(int));	
	di.ordem = m;	
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			if(i==j){
				di.v[aux] = mat[i][j];
				aux++;
			}
		}
	}
	
	return di;
}

void imprimir_diagonal(Diagonal di, int m){
	int i=0;	
	printf("Ordem da matriz-> [%d]\n", di.ordem);
	printf("Diagonal da matriz-> ");
	for(i=0; i<m; i++){
		printf("[%d] ", di.v[i]);
	}
	printf("\n\n");
}

void imprime_matriz_pos(Diagonal di, int lin, int col, int tam){
	int i=0, aux=0;		
	if(lin==col){
		printf("Valor [%d]\n", di.v[lin]);
		
	}else{
		printf("\nValor nullo nao salvo na stuct!\n");
		
	}	
}

int verifica_matriz_diagonal(int **mat, int m){
	int i=0, j=0, vl=1;
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			if(i!=j){
				if(mat[i][j]!=0){
					return 0;					
				}
			}
		}
	}
	return 1;
}

void free_matriz(int m, int **mat){
    int i=0;
    for(i=0; i<m; i++){
        free(mat[i]);
    }
    free(mat);
}
