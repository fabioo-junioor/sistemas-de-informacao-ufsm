/*Faça um programa que permita ao usuário entrar com uma matriz 20 x 20 de números inteiros. Em seguida,
preencha um vetor com a soma dos valores de cada coluna da matriz e mostre na tela esse vetor. Por exemplo, a
matriz 3x3
5 -8 1
1 2 1
25 10 7
vai gerar um vetor, onde cada posição é a soma das colunas da matriz. A primeira posição será 31, pois 5 + 1 + 25
resulta em 31, e assim por diante:
Vetor: 31 4 9*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

int **aloca_matriz(int m, int n){
    int i, **mat;
    mat = (int**)malloc(m*sizeof(int*));
	for(i=0; i<m; i++){
		mat[i] = (int*)malloc(n*sizeof(int));
	}
	if(mat==NULL){
		printf("\n Erro alocacao");
		system("pause");
		exit(1);
	}
	return mat;
}

int *aloca_vetor(int n){
    int *vet;
    vet = (int*)malloc(n*sizeof(int));
    if(vet==NULL){
		printf("\n Erro alocacao");
		system("pause");
		exit(1);
	}
	return vet;
}

void preenche_matriz(int m, int n, int **mat){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("Informe o numero? ");
            scanf("%d", &mat[i][j]);
        }
    }
}

void soma_coluna(int m, int n, int **mat, int *vet){
    int i, j;
    for(i=0; i<m; i++){
        vet[i]=0;
        for(j=0; j<n; j++){
            vet[i] += mat[j][i];
        }
        printf("\n");
    }
}

void imprime_vetor(int n, int *vet){
    int i;
    for(i=0; i<n; i++){
        printf("%d  ", vet[i]);
    }
}

void free_matriz(int m, int **mat){
    int i;
    for(i=0; i<m; i++){
        free(mat[i]);
    }
    free(mat);
}

void free_vetor(int n, int *vet){
    int i;
    for(i=0; i<n; i++){
        free(vet[i]);
    }
    free(vet);
}

int main(){
    int **matriz, *vetor;
	int m=20, n=20;

    matriz = aloca_matriz(m, n);
    vetor = aloca_vetor(n);
    preenche_matriz(m, n, matriz);
    soma_coluna(m, n, matriz, vetor);
    imprime_vetor(n, vetor);
    free_matriz(m, matriz);
    free_vetor(n, vetor);
    return 0;

}
