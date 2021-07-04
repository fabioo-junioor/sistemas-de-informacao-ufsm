/*Faça um programa em C que leia uma matriz 5x5 com o valor do salário de 25 pessoas. Ao final, mostre:
a. A média salarial
b. A qtidade de pessoas que ganham acima da média salarial
Exemplos de funções que se espera que o aluno implemente para esta questão: alocar a matriz, preencher a matriz,
imprimir a matriz, encontrar a média salarial, encontrar a qtidade de pessoas que ganham acima da média salarial,
liberar matriz, etc*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

float **aloca_matriz(int m, int n){
    int i;
    float **mat;
    mat = (float**)malloc(m*sizeof(float*));
	for(i=0; i<m; i++){
		mat[i] = (float*)malloc(n*sizeof(float));
	}
	if(mat==NULL){
		printf("\n Erro alocacao");
		system("pause");
		exit(1);
	}
	return mat;
}

void preenche_matriz(int m, int n, float **mat){
    int i, j, aux=1;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("Salario da pessoa numero %d? ", aux);
            scanf("%f", &mat[i][j]);
            aux++;
        }
    }
}

int media_salarial(int m, int n, float **mat){
    int i, j;
    float media=0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            media = media+mat[i][j];
        }
    }
    media = media/(m*n);

    return media;
}
void acima_media(int m, int n, float **mat, float media){
    int cont=0, i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(mat[i][j]>media){
                cont++;
            }
        }
    }
    printf("\nMedia salarial %.2f\n", media);
    printf("%d Eh a quantidade de pessoas que ganham acima da media salarias", cont);
}

void free_matriz(int m, float **mat){
    int i;
    for(i=0; i<m; i++){
        free(mat[i]);
    }
    free(mat);
}

int main(){
    float **matriz, media;
	int m=5, n=5;

    matriz = aloca_matriz(m, n);
    preenche_matriz(m, n, matriz);
    media = media_salarial(m, n, matriz);
    acima_media(m, n, matriz, media);
    free_matriz(m, matriz);
    return 0;
}
