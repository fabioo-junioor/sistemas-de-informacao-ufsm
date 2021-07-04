/*Faça um programa que leia uma matriz de 50 linhas e 3 colunas contendo as seguintes informações sobre alunos
de uma disciplina, sendo todas as informações do tipo float:
c. Primeira coluna: média das provas
d. Segunda coluna: média dos trabalhos
e. Terceira coluna: nota final
Considere que o número da linha corresponde ao número de matrícula do aluno (aluno 0, aluno 1, etc). Elabore
um programa que:
i. Leia as duas primeiras informações de cada aluno
ii. Calcule e preencha a nota final como sendo a soma da média das provas e da média dos
trabalhos
iii. Imprima a média aritmética das notas finais*/

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

void preenche_matriz(int m, int n, int **mat){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(j==0||j==1){
            printf("Informe as medias das provas e trabalhos do aluno %d ? ", (i+1));
            scanf("%d", &mat[i][j]);
            }else{
                mat[i][2]=0;
            }
        }
    }
}

void media_final(int m, int n, int **mat){
    int i, j, media;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(j==2){
                mat[i][j]=mat[i][0]+mat[i][1];
            }
        }
    }
}

void imprime_matriz(int m, int n, int **mat){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(j==2){
            printf("A media final do aluno %d eh %d", (i+1), mat[i][j]);
            }
        }
        printf("\n");
    }
}

void free_matriz(int m, int **mat){
    int i;
    for(i=0; i<m; i++){
        free(mat[i]);
    }
    free(mat);
}

int main(){
    int **matriz;
	int m=50, n=3;

    matriz = aloca_matriz(m, n);
    preenche_matriz(m, n, matriz);
    media_final(m, n, matriz);
    imprime_matriz(m, n, matriz);
    free_matriz(m, matriz);
    return 0;

}
