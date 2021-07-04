/*Faça um programa em C que leia uma matriz de números reais de tamanho 100x12. Esta matriz armazena o peso
de 100 pessoas (linhas) ao longo de 12 meses (colunas). Ao final, calcule e imprima:
a. A média de peso de cada pessoa ao longo dos 12 meses
b. A pessoa (número da linha) que mais perdeu peso (considerando o peso no primeiro e no último mês)*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

typedef struct{
    int menor_peso;
    int linha;
} peso;
peso Peso;

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
            printf("Informe o peso da pessoa %d no mes %d? ", (i+1), (j+1));
            scanf("%d", &mat[i][j]);
        }
    }
}

void media_peso(int m, int n, int **mat, int *vet){
    int i, j, k=0, media=0;
    for(i=0; i<m; i++){
        media=0;
        for(j=0; j<n; j++){
            media += mat[i][j];
        }
        vet[k] = (media/n);
        k++;
    }
}

void imprime_vetor(int m, int *vet){
    int i, pessoa=1;
    for(i=0; i<m; i++){
        printf("Pessoa %d media de peso %d \n", pessoa, vet[i]);
        pessoa++;
    }
}

void mais_peso(int m, int n, int **mat){
    int i, j, pes_final;
    for(i=0; i<m; i++){
        pes_final = 0;
        for(j=0; j<n; j++){
            pes_final = mat[i][0] - mat[i][11];
            if(pes_final>Peso.menor_peso){
                Peso.menor_peso = pes_final;
                Peso.linha = i;
            }
        }
    }
    printf("\nA pessoa da linha %d perdeu mais peso %dkg\n", Peso.linha, Peso.menor_peso);
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
	int m=100, n=12;

    matriz = aloca_matriz(m, n);
    vetor = aloca_vetor(m);
    preenche_matriz(m, n, matriz);
    media_peso(m, n, matriz, vetor);
    imprime_vetor(m, vetor);
    mais_peso(m, n, matriz);
    free_matriz(m, matriz);
    free_vetor(n, vetor);
    return 0;

}
