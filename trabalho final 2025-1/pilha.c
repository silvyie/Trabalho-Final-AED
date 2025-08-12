#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct no_pilha {
    RelatorioMissao* relatorio;
    struct no_pilha* prox;
};

struct pilha {
    NoPilha* topo;
};

Pilha* criar_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) p->topo = NULL;
    return p;
}

void empilhar(Pilha* p, RelatorioMissao* relatorio) {
    if (p == NULL || relatorio == NULL) return;

    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo == NULL) return;

    RelatorioMissao* copia = malloc(sizeof(RelatorioMissao));
    if (copia == NULL) {
        free(novo);
        return;
    }
    strncpy(copia->descricao, relatorio->descricao, TAM_DESCRICAO - 1);
    copia->descricao[TAM_DESCRICAO - 1] = '\0'; 

    copia->resultado = relatorio->resultado;
    copia->num_feridos = relatorio->num_feridos;

    novo->relatorio = copia;
    novo->prox = p->topo;
    p->topo = novo;
}

void imprimir_pilha(Pilha* p) {
    if (p == NULL) return;
    NoPilha* atual = p->topo;
    while (atual != NULL) {
        printf("Missao concluida: %s\n", atual->relatorio->descricao);
        printf("Resultado: ");
        switch (atual->relatorio->resultado) {
            case VITORIA_PERFEITA: 
                printf("Vitoria Perfeita!\n"); 
                break;
            case VITORIA_CUSTO: 
                printf("Vitoria com Custo (%d ferido(s)).\n", atual->relatorio->num_feridos); 
                break;
            case DERROTA: 
                printf("Derrota (%d ferido(s)).\n", atual->relatorio->num_feridos); 
                break;
        }
        atual = atual->prox;
    }
}

void liberar_pilha(Pilha* p) {
    if (p == NULL) return;
    NoPilha* atual = p->topo;
    while (atual != NULL) {
        NoPilha* temp = atual;
        atual = atual->prox;
        free(temp->relatorio);
        free(temp);
    }
    free(p);
}