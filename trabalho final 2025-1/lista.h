#ifndef LISTA_H
#define LISTA_H

typedef struct lista {
    void *dado;
    struct lista *prox;
} Lista;

Lista *cria_lista();

Lista *insere_final(Lista *l, void *dado);

void imprime_lista(Lista* l, void (*funcao_imprime_dado)(void*));

void libera_lista(Lista* l, void (*funcao_libera_dado)(void*));

int lista_vazia(Lista* l);

#endif