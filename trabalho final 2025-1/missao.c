#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "missao.h"

#define TAM_DESCRICAO_MISSAO 200
#define TAM_LOCAL_MISSAO 50

struct missao {
    char descricao[TAM_DESCRICAO_MISSAO];
    char local[TAM_LOCAL_MISSAO];
    StatusMissao status;
    int nivel_ameaca;
    int recompensa;
};

Missao *cria_missao(const char *descricao, const char *local, StatusMissao status, int nivel_ameaca, int recompensa) {
    Missao *nova = (Missao *)malloc(sizeof(Missao));
    if (!nova) return NULL;

    strncpy(nova->descricao, descricao, TAM_DESCRICAO_MISSAO);
    nova->descricao[TAM_DESCRICAO_MISSAO - 1] = '\0';
    strncpy(nova->local, local, TAM_LOCAL_MISSAO);
    nova->local[TAM_LOCAL_MISSAO - 1] = '\0'; 
    nova->status = status;
    nova->nivel_ameaca = nivel_ameaca;
    nova->recompensa = recompensa;

    return nova;
}

char *descricao_missao(const Missao *m) {
    if (!m) return NULL;
    return (char *)m->descricao;
}

char *local_missao(const Missao *m) {
    if (!m) return NULL;
    return (char *)m->local;
}

StatusMissao status_missao(Missao *m) {
    if (!m) return ATIVA;
    return m->status;
}

int nivel_ameaca_missao(Missao *m) {
    if (!m) return 0;
    return m->nivel_ameaca;
}

int recompensa_missao(Missao *m) {
    if (!m) return 0;
    return m->recompensa;
}

void modifica_status_missao(Missao *m, StatusMissao novo_status) {
    if (m) m->status = novo_status;
}

void libera_missao(Missao *m) {
    if (m){
        free(m);
    }
}

NoMissao *inserir_missao_prioridade(NoMissao *fila, Missao *m) {
    NoMissao *novo = malloc(sizeof(NoMissao));
    if (!novo) return fila;

    novo->dados = m;
    novo->prox = NULL;

    if (fila == NULL || m->nivel_ameaca > fila->dados->nivel_ameaca) {
        novo->prox = fila;
        return novo;
    }

    NoMissao *anterior = NULL, *atual = fila;
    while (atual && m->nivel_ameaca <= atual->dados->nivel_ameaca) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior) {
      anterior->prox = novo;
    }
    novo->prox = atual;

    return fila;
}

NoMissao *remover_missao(NoMissao *fila) {
    if (fila == NULL) return NULL;

    NoMissao *temp = fila;
    fila = fila->prox;
    libera_missao(temp->dados);
    free(temp);
    return fila;
}

void imprimir_fila_missoes(NoMissao *fila) {
    NoMissao *p = fila;
    printf("\n=== Missoes Prioritarias ===\n");
    while (p != NULL) {
        printf("- [%d] %s (%s), Recompensa: %d\n",
               p->dados->nivel_ameaca,
               p->dados->descricao,
               p->dados->local,
               p->dados->recompensa);
        p = p->prox;
    }
}

void liberar_fila_missoes(NoMissao *fila) {
    while (fila != NULL) {
        NoMissao *temp = fila;
        fila = fila->prox;
        libera_missao(temp->dados);
        free(temp);
    }
}