/*Considere uma lista simplesmente encadeada L representando uma seqüência de caracteres. Construa uma função
em C para imprimir a seqüência de caracteres da lista L na ordem inversa. Ex: Para a lista L = {A,E,I,O,U}, a função
deve imprimir “UOIEA”. Não é permitido alterar a lista original. Qualquer função adicional que por ventura seja
utilizada na sua solução também deve ser codificada.*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

struct lista{
    char info;
    struct lista* prox
};
typedef struct lista Lista;

Lista *lst_insere(Lista* l, char i){
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
        printf("--%c\n\n", p->info);
    }
}
void imprime_invertida(Lista* l){
    Lista* p = l;
    if(p != NULL){
        imprime_invertida(p->prox);
        printf("--%c\n\n", p->info);
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
    l = lst_insere(l, 'u');
    l = lst_insere(l, 'o');
    l = lst_insere(l, 'i');
    l = lst_insere(l, 'e');
    l = lst_insere(l, 'a');
    printf("Normal\n");
    lst_imprime(l);
    printf("\n");
	printf("Alterada\n");
    imprime_invertida(l);
    free_list(l);
    system("pause");

    return 0;
}
