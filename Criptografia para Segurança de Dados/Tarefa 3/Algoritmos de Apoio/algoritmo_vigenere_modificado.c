#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

#define TAM_MATRIX 27
#define TAM_TEXTO 1000
#define TAM_CHAVE 1

	//Função para calcular `a^m mod n`
int compute(int a, int m, int n);
	//Função para fazer a chamada de outras funçoes
int sorteia_chave();
	//Cria uma nova chave incrementando a antiga de 10 em 10, ateh o intervalo de 97 - 122
int sorteia_nova_chave(int chave);
	//Preenche os vetores com '%' para tirar o lixo de memoria
void inicializa_vetores(char vetor[], int tamanho);
	//Imprime os vetores
void mostrar_vetores(char vetor[], int tamanho);
	//Imprime a matrix
void mostrar_matrix(char vigenere_matrix[TAM_MATRIX][TAM_MATRIX]);
	//Extende a chave ateh ficar do tamanho do texto informado pelo usuario
void extender_chave(char chave[], char chave_extendida[TAM_TEXTO],
					char texto_cifrado[TAM_TEXTO], char texto[TAM_TEXTO],
					char texto_decifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
					int tam_texto, int tam_chave, int sec);
	//texto_cifrado = texto + chave_extendida
void cifrador_texto(char texto[TAM_TEXTO], char chave_extendida[TAM_TEXTO],
					char texto_cifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
					int tam_texto);
	//texto_decifrado = texto_cifrado + chave_extendida
void descifrador_texto(char texto[TAM_TEXTO], char chave_extendida[TAM_CHAVE],
						char texto_cifrado[TAM_TEXTO],char matrix[TAM_MATRIX][TAM_MATRIX],
                		int tam_texto);
    //Função sem ainda utilizção
void manipula_espacos_vetor(char texto[], char texto_cifrado[], int tamanho);

int main (){	
    int cif_ou_dec = 1;
    char key_letra[TAM_CHAVE];    
    char texto[TAM_TEXTO];
    char texto_cifrado[TAM_TEXTO];
    char texto_decifrado[TAM_TEXTO];
    char chave_extendida[TAM_TEXTO];
    inicializa_vetores(texto_cifrado, TAM_TEXTO);
    inicializa_vetores(chave_extendida, TAM_TEXTO);
    inicializa_vetores(texto_cifrado, TAM_TEXTO);
    inicializa_vetores(texto_decifrado, TAM_TEXTO);
    inicializa_vetores(texto, TAM_TEXTO);
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
 
 		
	key_letra[0] = sorteia_chave();
	    
    printf("INFORME UM TEXTO DE ATE [%d] CARACTERES!!\n", (TAM_TEXTO-10));
	printf("LETRAS MINUSCULAS!!\n");
	scanf("%[^\n]", texto);
	getchar();
		
	
	extender_chave(key_letra, chave_extendida, texto_cifrado, texto,
					texto_decifrado, vigenere_matrix,
					strlen(texto), strlen(key_letra), cif_ou_dec);
	
    
    printf("TEXTO DO USUARIO: ");
    mostrar_vetores(texto, TAM_TEXTO);
    printf("CHAVE: %c\n", key_letra[0]);
    printf("CHAVE EXTENDIDA:  ");
    mostrar_vetores(chave_extendida, TAM_TEXTO);
    printf("TEXTO CIFRADO:  ");
	mostrar_vetores(texto_cifrado, TAM_TEXTO);
    printf("TEXTO DECIFRADO:  ");
	mostrar_vetores(texto_decifrado, TAM_TEXTO);
	
    return 0;
    
}

int compute(int a, int m, int n){
    int r;
    int y = 1;
 
    while (m > 0)
    {
        r = m % 2;
 
        //exponência rápida
        if (r == 1) {
            y = (y*a) % n;
        }
        a = a*a % n;
        m = m / 2;
        
    } 
    return y;
    
}
int sorteia_chave(){
	int key_letra = 0;
	
	int p = 23;        // módulo
    int g = 5;        //base
 
    int a, b;    // `a` – chave secreta de Alice, `b` – chave secreta de Bob.
    int A, B;    // `A` – chave pública de Alice, `B` – chave pública de Bob
	
	srand(time(NULL)); 	
    
   	a = 1 + rand() % 100000; //escolhe um inteiro secreto para a chave privada de Alice (conhecida apenas por Alice)
    A = compute(g, a, p); //Calcula a chave pública de Alice (Alice enviará `A` para Bob)
    b = 1 + rand() % 100000; //escolha um inteiro secreto para a chave privada de Bob (conhecida apenas por Bob)
    B = compute(g, b, p); //Calcula a chave pública de Bob (Bob enviará `B` para Alice)
    // Alice e Bob trocam suas chaves públicas `A` e `B` entre si 
    // Encontra a chave secreta
    int keyA = compute(B, a, p);
    int keyB = compute(A, b, p);    
    //printf("Alice's secret key is %d\nBob's secret key is %d\n", keyA, keyB);
    
    key_letra = sorteia_nova_chave(keyA);
    
    return key_letra;
	
}
int sorteia_nova_chave(int chave){
	int nova_chave = chave;
	while(1){
    	if(nova_chave <= 96){
    		nova_chave += 10;
    		
		}
		if(nova_chave >= 123){
    		nova_chave -= 10;
    		
		}
		if((nova_chave >= 97) && (nova_chave <= 122)){
    		break;
    		
		}
	}	
	return nova_chave;
		
}
void inicializa_vetores(char vetor[], int tamanho){
	int i=0;
	for(i=0; i<tamanho; i++){
		vetor[i] = '%';

	}		
}
void mostrar_vetores(char vetor[], int tamanho){
	int i;
	for(i=0; i<tamanho; i++){
		if(vetor[i] != '%'){
			printf("%c", vetor[i]);

		}
	}
	printf("\n");

}
void mostrar_matrix(char vigenere_matrix[TAM_MATRIX][TAM_MATRIX]){
	int i, j;
	printf("MATRIX \n");
	for(i=0; i<(TAM_MATRIX-1); i++){
		for(j=0; j<(TAM_MATRIX-1); j++){
			printf("%c ", vigenere_matrix[i][j]);

		}
		printf("\n");

	}
	printf("\n\n");

}
void extender_chave(char chave[TAM_CHAVE], char chave_extendida[TAM_TEXTO],
					char texto_cifrado[TAM_TEXTO], char texto[TAM_TEXTO],
					char texto_decifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
					int tam_texto, int tam_chave, int cif_ou_dec){
	int i=0, aux=0, j=0, cont=0;	
	while(i < tam_texto){
		chave_extendida[i] = chave[0];
		i++;
					
	}		
	
	if(cif_ou_dec == 1){
		//manipula_espacos_vetor(texto, texto_cifrado, tam_texto);
		cifrador_texto(texto, chave_extendida, texto_cifrado, matrix, tam_texto);		
		descifrador_texto(texto_decifrado, chave_extendida, texto_cifrado, matrix, tam_texto);
			
	} else {
		//descifrador_texto(texto_decifrado, chave_extendida, texto_cifrado, matrix, tam_texto);
		printf("DESCIFROU\n");
		
	}
}
void cifrador_texto(char texto[TAM_TEXTO], char chave_extendida[TAM_TEXTO],
					char texto_cifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
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
				if(texto[aux] == 32){
					texto_cifrado[aux] = '#';
					i = 0;
					j = 0;
					aux++;
						
				}
			}
		}
		for(i=0; i<TAM_MATRIX; i++){
			for(j=0; j<TAM_MATRIX; j++){
				if(matrix[i][0] == chave_extendida[aux]){
					aux_i = i;
					i = TAM_MATRIX;
					j = TAM_MATRIX;
					texto_cifrado[aux] = matrix[aux_i][aux_j];
					aux++;

				}
			}
		}
	}
}
void descifrador_texto(char texto[TAM_TEXTO], char chave_extendida[TAM_CHAVE],
                char texto_cifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
                int tam_texto){
    int i=0, j=0, aux=0, aux_i=0, aux_j=0;    
    while(aux < tam_texto){
        aux_i = 0;
        aux_j = 0;
        for(i=0; i<TAM_MATRIX; i++){
            for(j=1; j<TAM_MATRIX; j++){
                if(matrix[i][0] == chave_extendida[aux]){
                    aux_i = i;
                    i = TAM_MATRIX;
                    j = TAM_MATRIX;
                    
                }
            }
        }
        for(i=1; i<TAM_MATRIX; i++){
            for(j=1; j<TAM_MATRIX; j++){
            	if('#' == texto_cifrado[aux]){
					texto[aux] =  ' ';
					aux++;
					
				}
                if(matrix[aux_i][j] == texto_cifrado[aux]){
                    aux_j = j;
                    i = TAM_MATRIX;
                    j = TAM_MATRIX;
                    texto[aux] =  matrix[0][aux_j];
                    aux++;
                    
                }
            }
        }        
    }
}
void manipula_espacos_vetor(char texto[], char texto_cifrado[], int tamanho){
	int i=0;
	for(i=0; i<tamanho; i++){
		if(texto[i] == 32){
			texto_cifrado[i] = '#';
			printf("AQUI %c\n", texto_cifrado[i]);
			
		}
	}
}
