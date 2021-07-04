/*Considere que você armazenou os diferentes valores observados em um experimento de física em um vetor de
números reais (do tipo float). Para melhorar a precisão dos seus dados, você deve eliminar o maior e o menor valor
dentre todas as medições. Por exemplo, para o vetor (1.2, 1.3, 0.9, 1.5, 1.4, 1,6), o terceiro elemento deveria ser
retirado por ser o de menor valor, e também o sexto por ser o de maior valor. Escreva um programa em C que leia
um vetor vet de n números reais positivos distintos, correspondendo às medições, e gere e imprima um novo vetor,
de tamanho n-2, sem os elementos do vetor original que têm o maior e o menor valor. Considere que os valores
digitados estão entre 0 e 10. Obs: o valor de n é informado pelo usuário.*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
typedef struct{
    float menor;
    float maior;
    int pos_men;
    int pos_mai;
} num;
num Num;

float *aloca_vetor2(int m){
    float *vet2;
    vet2 = (float*)malloc(m*sizeof(float));
    if(vet2==NULL){
		printf("\n Erro alocacao vetor 2");
		system("pause");
		exit(1);
	}
	return vet2;
}

float *aloca_vetor1(int m){
    float *vet1;
    vet1 = (float*)malloc(m*sizeof(float));
    if(vet1==NULL){
		printf("\n Erro alocacao vetor 1");
		system("pause");
		exit(1);
	}
	return vet1;
}

void preenche_vetor1(int m, float *vet1){
    int i;
    printf("Numeros maiores/iguais a '0' e menores/iguais a '10'\n");
    for(i=0; i<m; i++){
        printf("Informe o numero: ");
        scanf("%f", &vet1[i]);
    }
}

void verifica_menor(int m, float *vet1){
    int i;
    float menor;
    Num.menor = 10;
    for(i=0; i<m; i++){
        menor = vet1[i];
        if(menor<Num.menor){
            Num.menor = menor;
            Num.pos_men = i;
        }
        menor = 0;
    }
}

void verifica_maior(int m, float *vet1){
    int i;
    float maior;
    for(i=0; i<m; i++){
        maior = vet1[i];
        if(maior>Num.maior){
            Num.maior = maior;
            Num.pos_mai = i;
        }
    }
}

void preenche_vetor2(int m, float *vet1, float *vet2){
    int i, j=0;
    for(i=0; i<m; i++){
        if(i!=Num.pos_men && i!=Num.pos_mai){
            vet2[j]=vet1[i];
            j++;
        }
    }
}

void imprime_vetor1(int m, float *vet1){
    int i;
    for(i=0; i<m; i++){
        printf("%.2f  ", vet1[i]);
    }
    printf("\n");
}

void imprime_vetor2(int m, float *vet2){
    int i;
    for(i=0; i<(m-2); i++){
        printf("%.2f  ", vet2[i]);
    }
}

void free_vetor1(float *vet1){
    free(vet1);
}

void free_vetor2(float *vet2){
    free(vet2);
}

int main(){
    float *vetor1, *vetor2;
	int m;

    printf("Quantos valores sao? ");
    scanf("%d", &m);

    vetor1 = aloca_vetor1(m);
    vetor2 = aloca_vetor2((m-2));
    preenche_vetor1(m, vetor1);
    imprime_vetor1(m, vetor1);
    verifica_menor(m, vetor1);
    verifica_maior(m, vetor1);
    preenche_vetor2(m, vetor1, vetor2);
    imprime_vetor2(m, vetor2);
    free_vetor1(vetor1);
    free_vetor2(vetor2);
    return 0;

}
