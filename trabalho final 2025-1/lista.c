#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "tartaruga.h"

Lista *cria_lista() {
    return NULL;
}

Lista *insere_final(Lista *l, void *dado) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo == NULL) return NULL;

    novo->dado = dado;
    novo->prox = NULL;

    if (l == NULL) return novo;

    Lista *p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = novo;
    return l;
}

void imprime_lista(Lista* l, void (*funcao_imprime_dado)(void*)) {
    Lista *p = l;
    while (p != NULL) {
        funcao_imprime_dado(p->dado);
        p = p->prox;
    }
}

void libera_lista(Lista* l, void (*funcao_libera_dado)(void*)) {
    Lista *p;
    while (l != NULL) {
        p = l->prox;
        funcao_libera_dado(l->dado);
        free(l);
        l = p;
    }
}

int lista_vazia(Lista* l) {
    return l == NULL;
}