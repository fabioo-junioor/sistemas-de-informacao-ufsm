#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "identidade.h"

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

Identidade preenche_lista(int m, int **mat){	
	Identidade p;
	int i=0, j=0, aux=0;
	
	p.v = (int*)malloc(m*sizeof(int));
	p.ordem = m;
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			if(i==j){
				p.v[aux] = mat[i][j];
				aux++;
			}
		}
	}
	
	return p;
}

int verifica_matriz_identidade(int **mat, int m){
	int i=0, j=0, vl=1;
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			if(i==j){
				if(mat[i][j]!=1){
					printf("\nO elemento [%d] referente a linha [%d] coluna [%d] viola a regra 'todos da diagonal = 1'\n", mat[i][j], i, j);
					vl = 0;
				}
			}
				
		}
	}
	return vl;
}

int verifica_matriz_resto(int **mat, int m){
	int i=0, j=0, vl=1;
	for(i=0; i<m; i++){
		for(j=0; j<m; j++){
			if(i!=j){
				if(mat[i][j]!=0){
					printf("\nO elemento [%d] referente a linha [%d] coluna [%d] viola a regra 'demais elementos = 0'\n", mat[i][j], i, j);
					vl = 0;
					
				}
			}
		}
	}
	return vl;
}
void imprimir_identidade(Identidade id, int m){
	int i=0;	
	printf("Ordem-> [%d] ", id.ordem);
	printf("Diagonal-> ");
	for(i=0; i<m; i++){
		printf("[%d]", id.v[i]);
	}
	printf("\n");
}

void free_matriz(int m, int **mat){
    int i=0;
    for(i=0; i<m; i++){
        free(mat[i]);
    }
    free(mat);
}
