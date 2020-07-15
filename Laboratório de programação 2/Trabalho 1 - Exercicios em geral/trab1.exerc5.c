/*Em uma pesquisa de campo, uma editora solicitou os seguintes dados para os entrevistados: sexo, idade
e quantidade de livros que leu no ano de 2019. Faça um programa que leia os dados de 500 usuários.
Depois, calcule e imprima:
a) A quantidade total de livros lidos pelos entrevistados menores de 10 anos.
b) A quantidade de mulheres que leu 5 livros ou mais.
Deve ser usada a seguinte struct:
struct usuario
{
char sexo;
int idade;
int qtdade;
};
typedef struct usuario Usuario;
Os dados devem ser armazenados em um vetor de usuários.
O programa deve ser estruturado nas seguintes funções:

void leVetor (int tamanho, Usuario* vet); //esta funcao recebe o tamanho do vetor e o endereço do primeiro
elemento do vetor; e preenche o vetor com dados digitados pelo usuário

int calculaQtidadeLivros (int tamanho, Usuario* vet); // esta função recebe o tamanho do vetor e o
endereco do primeiro elemento do vetor; calcula a quantidade total de livros lidos pelos entrevistados
menores de 10 anos, e retorna esta quantidade para o main

int calculaQtidadeMulheres (int tamanho, Usuario* vet); // esta função recebe o tamanho do vetor e o
endereco do primeiro elemento do vetor; calcula a quantidade de mulheres que leu 5 livros ou mais, e
retorna esta quantidade para o main.
Ao final, o main mostra na tela as duas quantidades calculadas.*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define tam 500

typedef struct{
	char sexo[1];
	int idade;
	int qtdade;
} usuario;
usuario Usuario;

void inicializa(int tamanho, usuario* vet){
	int j;
	for(j=0; j<tamanho; j++){
		vet[j].qtdade = 0;
		vet[j].idade = 0;
		strcpy(vet[j].sexo, "NULL");
	}
}
void leVetor(int tamanho, usuario* vet){
	int i;
	for(i=0; i<tamanho; i++){
		printf("Qual sexo do entrevistado [m/f]: ");
		scanf("%s", vet[i].sexo);
		printf("Qual idade do entrevistado: ");
		scanf("%d", &vet[i].idade);
		printf("Quantidade de livros lidos: ");
		scanf("%d", &vet[i].qtdade);
	}
}
int calculaQuantidadeLivros(int tamanho, usuario* vet){
	int i, qtdd=0;
	for(i=0; i<tamanho; i++){
		if((vet[i].idade < 10) && ((vet[i].sexo[0] == 'f') || (vet[i].sexo[0] == 'm'))){
			qtdd = qtdd + vet[i].qtdade;
		}
	}
	printf ("\n%d eh o total de livros lidos por menores de 10 anos \n", qtdd);
}
int calculaQuantidadeMulheres(int tamanho, usuario* vet){
	int i, qtd=0;
	for(i=0; i<tamanho; i++){
		if((vet[i].sexo[0] == 'f') && (vet[i].qtdade >=5)){
			qtd++;
		}
	}
	printf ("%d eh a quantidade de mulheres que leram 5 livros ou mais \n", qtd);
}
int main(){
	int vet[tam];
	leVetor(tam, vet);
	calculaQuantidadeLivros(tam, vet);
	calculaQuantidadeMulheres(tam,vet);
}
