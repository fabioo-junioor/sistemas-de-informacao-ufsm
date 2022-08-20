/*
Quebrando a cifra de Vigenere com chave menor que a mensagem.

Etapa 1- Faça um programa que permita a cifragem/decifragem
de uma mensagem usando o algoritmo de Vigenere com uma chave dada.
Etapa 2- O ciphertext abaixo foi cifrado com Vigenere e uma chave de um único caracter.
Encontre a chave usada e decifre a mensagem.
(Use o código da atividade anterior para ajudá-lo a verificar se a chave foi encontrada)
Ciphertext: MXOXYBKPSLZBZLKPBDRFRABZFCOXOXJBKPXDBJ
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

#define TAM_CIFRA 38
#define TAM_MATRIX 27
#define TAM_NOVO_TEXTO 110
#define TAM_NOVA_CHAVE 110
#define TAM_NOVA_CIFRA 110

void mostrar_matrix(char vigenere_matrix[TAM_MATRIX][TAM_MATRIX]){
	int i, j;
	printf("MATRIX \n");
	for(i=0; i<26; i++){
		for(j=0; j<TAM_MATRIX; j++){
			printf("%c ", vigenere_matrix[i][j]);

		}
		printf("\n");

	}
	printf("\n\n");

}
void mostrar_cifra(char cifra[TAM_CIFRA]){
	int i;
	printf("CIPHERTEXT \n");
	for(i=0; i<TAM_CIFRA; i++){
		printf("%c", cifra[i]);

	}
	printf("\n\n");

}
void inicializa_vetores(char vetor[TAM_NOVO_TEXTO]){
	int i=0;
	for(i=0; i<TAM_NOVO_TEXTO; i++){
		vetor[i] = '%';

	}
}
void mostrar_vetores(char vetor[TAM_NOVO_TEXTO]){
	int i;
	for(i=0; i<TAM_NOVO_TEXTO; i++){
		if(vetor[i] != '%'){
			printf("%c", vetor[i]);

		}
	}
	printf("\n");

}
void analisa_ciphertext(char vigenere[TAM_MATRIX][TAM_MATRIX], char cifra[TAM_CIFRA]){
	int i=1, j=1, cont=0;
	while(i < TAM_MATRIX){
		printf("Cifra -> [%c]  Saida -> ", vigenere[i][0]);
		while(j < TAM_MATRIX){
			if(cifra[cont] == vigenere[i][j]){
				printf("%c", vigenere[0][j]);
				j=1;
				cont++;

			} else {
				j++;

			}
		}
		if(cont >= TAM_CIFRA){
			i++;
			cont = 0;
			j=1;
			printf("\n");

		}
	}
}
void cifrador_texto(char texto[TAM_NOVO_TEXTO], char chave_extendida[TAM_NOVO_TEXTO],
					char saida[TAM_NOVO_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
					int tam_texto){
	int i=0, j=0, aux=0, aux_i=0, aux_j=0;
	while(aux < tam_texto){
		for(i=0; i<TAM_MATRIX; i++){
			for(j=0; j<TAM_MATRIX; j++){
				if(matrix[0][j] == texto[aux]){
					aux_j = j;
					i = TAM_MATRIX;
					j = TAM_MATRIX;

				}
			}
		}
		for(i=0; i<TAM_MATRIX; i++){
			for(j=0; j<TAM_MATRIX; j++){
				if(matrix[i][0] == chave_extendida[aux]){
					aux_i = i;
					i = TAM_MATRIX;
					j = TAM_MATRIX;
					aux++;

				}
			}
		}
		saida[aux-1] =  matrix[aux_i][aux_j];

	}
}
void descifrador_texto(char texto[TAM_NOVO_TEXTO], char chave[TAM_NOVA_CHAVE],
                char saida[TAM_NOVO_TEXTO],char matrix[TAM_MATRIX][TAM_MATRIX],
                int tam_texto){
    int i=0, j=0, aux=0, aux_i=0, aux_j=0;    
    while(aux < tam_texto){
        aux_i = 0;
        aux_j = 0;
        for(i=0; i<TAM_MATRIX; i++){
            for(j=1; j<TAM_MATRIX; j++){
                if(matrix[i][0] == chave[aux]){
                    aux_i = i;
                    i = TAM_MATRIX;
                    j = TAM_MATRIX;
                    
                }
            }
        }
        for(i=1; i<TAM_MATRIX; i++){
            for(j=1; j<TAM_MATRIX; j++){
                if(matrix[aux_i][j] == texto[aux]){
                    aux_j = j;
                    i = TAM_MATRIX;
                    j = TAM_MATRIX;
                    aux++;
                    
                }
            }
        }
        saida[aux-1] =  matrix[0][aux_j];
        
    }
}
void extender_chave(char chave[TAM_NOVA_CHAVE], char chave_extendida[TAM_NOVO_TEXTO],
					char saida[TAM_NOVA_CIFRA], char texto[TAM_NOVO_TEXTO],
					char matrix[TAM_MATRIX][TAM_MATRIX],
					int tam_texto, int tam_chave, int sec){
	int i=0, aux=0, j=0;
	while(aux < tam_texto){
		if(i < tam_chave){
			chave_extendida[j] = chave[i];
			j++;
			i++;
			aux++;

		} else {
			i=0;

		}
	}
	if(sec == 4){
		cifrador_texto(texto, chave_extendida, saida, matrix, tam_texto);
			
	}else{
		descifrador_texto(texto, chave_extendida, saida, matrix, tam_texto);	
		
	}
}
int main(){
	int valor_case = 0, fim = 1;

	char nova_chave[TAM_NOVA_CHAVE];
	char novo_texto[TAM_NOVO_TEXTO];
	char chave_extendida[TAM_NOVO_TEXTO];
	char nova_saida_cifra[TAM_NOVA_CIFRA];

	char cifra[TAM_CIFRA] = {"mxoxybkpslzbzlkpbdrfrabzfcoxoxjbkpxdbj"};
	char vigenere_matrix [TAM_MATRIX][TAM_MATRIX] = {
		{' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
		{'a', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
		{'b', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'},
		{'c', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'},
		{'d', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
		{'e', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
		{'f', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e'},
		{'g', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
		{'h', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
		{'i', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
		{'j', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
		{'k', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
		{'l', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
		{'m', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
		{'n', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
		{'o', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
		{'p', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'},
		{'q', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
		{'r', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},
		{'s', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
		{'t', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'},
		{'u', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'},
		{'v', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
		{'w', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
		{'x', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'},
		{'y', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
		{'z', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}};

	inicializa_vetores(novo_texto);
	inicializa_vetores(nova_chave);
	inicializa_vetores(nova_saida_cifra);

	while(fim != 0){
		printf("#####################################################\n");
		printf("[0] - FINALIZAR PROGRAMA!!\n");
		printf("[1] - IMPRIMIR A MATRIX DE VIGENERE!!\n");
		printf("[2] - IMPRIMIR CIPHERTEXT DA TAREFA 2!!\n");
		printf("[3] - DECIFRAR CIPHERTEXT DA TAREFA 2!!\n");
		printf("[4] - CIFRAR NOVO TEXTO INFORMADO PELO USUARIO!!\n");
		printf("[5] - DECIFRAR NOVO TEXTO INFORMADO PELO USUARIO!!\n");
		printf("[6] - IMPRIMIR VETORES!!\n");
		printf("#####################################################\n");
		scanf("%d", &valor_case);
		printf("\n");

		switch(valor_case){
			case 0:
				fim = 0;
				printf("SAINDO...\n");
				break;

			case 1:
				mostrar_matrix(vigenere_matrix);
				break;

			case 2:
				mostrar_cifra(cifra);
				break;

			case 3:
				analisa_ciphertext(vigenere_matrix, cifra);
				break;

			case 4:
				printf("INFORME UM TEXTO DE ATE [%d] CARACTERES!!\n", (TAM_NOVO_TEXTO-10));
				printf("LETRAS MINUSCULAS E SEM ESPACOS ENTRE AS PALAVRAS!!\n");
				scanf("%s", novo_texto);
				printf("INFORME UMA CHAVE MENOR QUE [%d] CARACTERES!!\n", strlen(novo_texto));
				scanf("%s", nova_chave);

				if(strlen(novo_texto) < strlen(nova_chave)){
					printf("CHAVE MAIOR QUE TEXTO\n");
					fim = 0;

				} else {
					extender_chave(nova_chave, chave_extendida,
									nova_saida_cifra, novo_texto,
									vigenere_matrix,
									strlen(novo_texto),
									strlen(nova_chave), valor_case);
					printf("\nESCOLHA A OPCAO [6]\n");

				}
				break;

			case 5:
			    printf("INFORME UM TEXTO CIFRADO DE ATE [%d] CARACTERES!!\n", (TAM_NOVO_TEXTO-10));
				printf("LETRAS MINUSCULAS E SEM ESPACOS ENTRE AS PALAVRAS!!\n");
				scanf("%s", novo_texto);
				printf("INFORME A CHAVE USADA PARA CRIPTOGRAFAR A CIFRA ANTERIOR!\n");
				scanf("%s", nova_chave);

				if(strlen(novo_texto) < strlen(nova_chave)){
					printf("CHAVE MAIOR QUE TEXTO\n");
					fim = 0;

				} else {
					extender_chave(nova_chave, chave_extendida,
									nova_saida_cifra, novo_texto,
									vigenere_matrix,
									strlen(novo_texto),
									strlen(nova_chave), valor_case);
					printf("\nESCOLHA A OPCAO [6]\n");

				}
			    break;

            case 6:
                printf("TEXTO INFORMADO PELO USUARIO\n");
				mostrar_vetores(novo_texto);
				printf("\nCHAVE INFORMADA PELO USUARIO\n");
				mostrar_vetores(nova_chave);
				printf("\nCIFRAGEM/DECIFRAGEM COMPLETO\n");
				mostrar_vetores(nova_saida_cifra);
				break;
				
			default:
				printf("VALOR INVALIDO\n");

		}
		printf("\n");

	}
	getch();
	return 0;

}
