/*Considerando as seguintes declarações de uma lista encadeada:
struct lista {
char nome[81];
char matricula[8];
float p1;
float p2;
float p3;
struct lista* prox;
};
typedef struct lista Lista;
para representar o cadastro de alunos de uma disciplina, implemente uma função que insira um novo nó em uma lista
encadeada definida pela estrutura acima. O novo nó deve ser inserido na lista de tal forma que os nós da lista
encadeada estejam sempre em ordem crescente de média, onde a média do aluno é calculada pela fórmula
(p1+p2+p3)/3. Essa função deve obedecer ao protótipo:
Lista* insere_ord (Lista* l, char* nome, char* matricula, float p1, float p2, float p3);
Ao final, toda a lista deve ser impressa.*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

struct lista{
    char nome[81];
    char matricula[8];
    float p1;
    float p2;
    float p3;
    struct lista* prox;
};
typedef struct lista Lista;

typedef struct{
    float media;
}salva;
salva Salva;

Lista *cria_lista(void){
    return NULL;
}

char *aloca_vetor(int m){
    char *vet;
    vet = (char*)malloc(m*sizeof(char));
    if(vet==NULL){
		printf("\n Erro alocacao vetor ");
		system("pause");
		exit(1);
	}
	return vet;
}

int calcula(float p1, float p2, float p3){
    float media = 0;

    media = (p1+p2+p3)/3;

    return media;
}

Lista* insere_ord(Lista* l, char *nome, char *matricula, float p1, float p2, float p3){
    Lista *novo, *ant, *p;
    ant = NULL;
    p = l;
    float media;
    media = calcula(p1, p2, p3);
    while(p!=NULL && Salva.media<media){
        ant = p;
        p = p->prox;
    }
    novo = (Lista*)malloc(sizeof(Lista));
    strcpy(novo->nome, nome);
    strcpy(novo->matricula, matricula);

    novo->p1 = p1;
    novo->p2 = p2;
    novo->p3 = p3;
    Salva.media = media;
    if(ant==NULL){
        novo->prox = l;
        l = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

void imprime(Lista *l){
    Lista* p;
    p = l;
    while(p!=NULL){
        printf("Nome: %s\n", p->nome);
        printf("Matricula: %s\n", p->matricula);
        printf("P1: %.2lf\n", p->p1);
        printf("P2: %.2lf\n", p->p2);
        printf("P3: %.2lf\n\n", p->p3);
        p = p->prox;
    }
}

Lista* free_list(Lista* l){
    Lista *p;
    p = l;
    while(p!=NULL){
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

void free_vetor(char *vet){
    free(vet);
}

int main(void){
    Lista* l;
    char *nome, *matricula;
    float nota1=0, nota2=0, nota3=0;
    bool op=0;
    l = cria_lista();

    while(op!=1){
        nome = aloca_vetor(81);
        matricula = aloca_vetor(8);

        printf("informe o nome: ");
        scanf("%s", nome);
        printf("informe matricula: ");
        scanf("%s", matricula);
        printf("Informe a nota 1: ");
        scanf("%f", &nota1);
        printf("Informe a nota 2: ");
        scanf("%f", &nota2);
        printf("Informe a nota 3: ");
        scanf("%f", &nota3);

        l = insere_ord(l, nome, matricula, nota1, nota2, nota3);

        printf("\nCadastrar outro aluno? 0-SIM 1-NAO : ");
        scanf("%d", &op);
        printf("\n");

        free_vetor(nome);
        free_vetor(matricula);
    }

    imprime(l);
    printf("\n\n");
    free_vetor(nome);
    free_vetor(matricula);
    free_list(l);
    system("pause");

    return 0;
}

