/*Faça um programa que leia as aulas ministradas em uma disciplina. Para cada disciplina informada,
considere 5 alunos. Para cada aluno, leia duas notas obtidas pelo aluno na disciplina e o número de aulas
assistidas. A seguir, calcule e mostre a média final deste aluno e verifique se ele foi aprovado ou reprovado
(média >= 6 e mínimo de 75% de frequência para ser aprovado).
Considere as seguintes estruturas:
struct aluno
{
float nota1;
float nota2;
int aulasAssistidas;
float media;
bool status;
};
typedef struct aluno Aluno;
struct disciplina
{
Aluno vet[5];
int aulasMinistradas;
};
typedef struct disciplina Disciplina;*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
	float nota1;
	float nota2;
	int aulasAssistidas;
	float media;
	bool status;
} aluno;
aluno Aluno;

typedef struct{
	aluno vet[5];
	int aulasMinistradas;
} disciplina;
disciplina Disciplina;

void verificar_media(){
	int i, freq=0;
	printf("Disciplina 1\n");
	printf("Aulas ministradas: ");
	scanf("%d", &Disciplina.aulasMinistradas);

	for(i=1; i<=5; i++){
		printf("\nAluno %d \n", i);
		printf("Nota 1: ");
		scanf("%f", &Disciplina.vet[i].nota1);
		printf("Nota 2: ");
		scanf("%f", &Disciplina.vet[i].nota2);
		printf("Aulas assistidas, pelo aluno %d : ", i);
		scanf("%d", &Disciplina.vet[i].aulasAssistidas);

		Aluno.media = (Disciplina.vet[i].nota1 + Disciplina.vet[i].nota2)/2;
		freq = (Disciplina.vet[i].aulasAssistidas*100)/Disciplina.aulasMinistradas;

		if ((Aluno.media>=6)&&(freq>=75)){
                Disciplina.vet[i].status = 1;
		}else{
		    Disciplina.vet[i].status = 0;
		}
	}
}
void imprimir(){
    int i;
    for(i=1; i<=5; i++){
        if(Disciplina.vet[i].status==1){
            printf("\nAluno %d aprovado\n", i);
        }else{
            printf("Aluno %d reprovado\n", i);
        }
    }
}
int main(){
	verificar_media();
	imprimir();
}
