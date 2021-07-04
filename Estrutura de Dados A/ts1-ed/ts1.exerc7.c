/*Considere uma lista l1 simplesmente encadeada de valores inteiros. Faça uma função que receba l1 já preenchida
e retorne uma nova lista l2, contendo os valores de l1 ordenados em ordem crescente. A função deve ter o seguinte
protótipo: Lista* cria_ordenado (Lista* l1); qualquer função auxiliar utilizada na sua solução deve ser apresentada.
Ao final, imprima as duas listas.*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

struct lista{
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista *lst_cria(void){
    return NULL;
}

Lista *lst_insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    l = novo;
    return novo;
}

Lista* insere_num(Lista* l, int i){
    Lista *novo, *ant, *p;
    ant = NULL;
    p = l;
    while(p!=NULL && p->info<i){
        ant = p;
        p = p->prox;
    }
    novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    if(ant==NULL){
        novo->prox = l;
        l = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

Lista* cria_ordenado(Lista* l){
    Lista *l2, *p;
    l2 = lst_cria();
    for(p=l; p!=NULL; p=p->prox){
        l2 = insere_num(l2, p->info);
    }
    return l2;
}

void lst_imprime(Lista* l){
    Lista* p;
    for(p=l; p!=NULL; p=p->prox){
        printf("--%d\n\n", p->info);
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

int main(void){
    Lista* l1;
    Lista* l2;
    l1 = lst_cria();

    l1 = lst_insere(l1, 8);
    l1 = lst_insere(l1, 2);
    l1 = lst_insere(l1, 5);
    l1 = lst_insere(l1, 3);
    l1 = lst_insere(l1, 4);
	printf("Normal\n");
    lst_imprime(l1);
    printf("\n");
    l2 = cria_ordenado(l1);
    printf("Alterada\n");
    lst_imprime(l2);
    free_list(l1);
    free_list(l2);
    system("pause");

    return 0;
}
