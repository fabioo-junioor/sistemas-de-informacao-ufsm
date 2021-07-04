/*Dada uma lista simplesmente encadeada conforme definida a seguir:
struct lista{
int info;
struct lista* prox;
};
typedef struct lista Lista;
Faça uma função que receba uma lista qualquer e remova todos os elementos repetidos que por ventura existirem
nesta lista, mantendo apenas a primeira ocorrência de cada elemento.
Exemplo de lista original: 1 2 5 1 2 7 3 3 Exemplo de lista após remoção: 1 2 5 7 3
A função deve ter o protótipo: Lista* remove_repetidos (Lista* l);
Ao final, imprima a lista alterada.*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

struct lista{
    int info;
    struct lista* prox
};
typedef struct lista Lista;

Lista *lst_insere(Lista* l, int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    l = novo;
    return novo;
}

Lista *lst_cria(void){
    return NULL;
}

void lst_imprime(Lista* l){
    Lista* p;
    for(p=l; p!=NULL; p=p->prox){
        printf("--%d\n\n", p->info);
    }
}

Lista* remove_repetidos(Lista* l){
    Lista *ant, *p, *z;
    p = l;
    z = l;

    if(p==NULL){
        return l;
    }else{
        while(p!=NULL){
            z = p->prox;
            while(z!=NULL && z->info!=p->info){
                    ant = z;
                    z = z->prox;
            }
                if(z==NULL){
                    p = p->prox;
                }else{
                    ant->prox = z->prox;
                    Lista* aux = z;
                    z = z->prox;
                    free(aux);
            }
        }
        return l;
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
    Lista* l;
    l = lst_cria();
    l = lst_insere(l, 8);
    l = lst_insere(l, 2);
    l = lst_insere(l, 5);
    l = lst_insere(l, 3);
    l = lst_insere(l, 4);
    l = lst_insere(l, 3);
    l = lst_insere(l, 2);
    printf("Normal\n");
    lst_imprime(l);
    printf("\n");
    l = remove_repetidos(l);
    printf("Alterada\n");
	lst_imprime(l);
    free_list(l);
    system("pause");

    return 0;
}
