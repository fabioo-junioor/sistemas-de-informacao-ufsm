/*Implemente a função Lista* remove (Lista* l, Lista* tmp)
que remove todos os elementos de l que estão em tmp.
As listas são simplesmente encadeadas de valores char.
Ao final, imprima as duas listas*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

struct lista{
    char info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista *cria_lista(void){
    return NULL;
}
Lista *insere(Lista* l, char i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    l = novo;
    return novo;
}
void imprime(Lista* l){
    Lista* p;
    for(p=l; p!=NULL; p=p->prox){
        printf("--%c\n\n", p->info);
    }
}

Lista *exclui(Lista* l, char i){
    Lista *p, *ant;
    ant = NULL;
    p = l;
    while(p!=NULL && p->info!=i){
        ant = p;
        p = p->prox;
    }
    if(p==NULL){
        return l;
    }
    if(ant==NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

Lista* remover(Lista* l, Lista* tmp){
    Lista *p, *z;
    p = l;
    z = tmp;
	if(l==NULL || z==NULL){
        return l;
	}else{
        for(z=tmp; z!=NULL; z=z->prox){
            for(p=l; p!=NULL; p=p->prox){
                if(z->info==p->info){
                    l = exclui(l, p->info);
                    p = l;
                }
            }
        }
	}

	return l;
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
    Lista* tmp;

    l = cria_lista();
    tmp = cria_lista();

	l = insere(l, 'a');
    l = insere(l, 'b');
    l = insere(l, 'c');
    l = insere(l, 'd');

	tmp = insere(tmp, 'j');
    tmp = insere(tmp, 'c');
    tmp = insere(tmp, 'b');
    tmp = insere(tmp, 'k');
	printf("Normal\n");
    imprime(l);
    printf("\n");
    l = remover(l, tmp);
	printf("Alterada\n");
    imprime(l);
    free_list(l);
    free_list(tmp);
    system("pause");

    return 0;
}
