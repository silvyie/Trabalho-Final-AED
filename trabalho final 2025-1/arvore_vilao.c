#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_vilao.h"
#include "vilao.h"

struct no_arvore_vilao {
    Vilao* vilao;
    NoArvoreVilao* esq;
    NoArvoreVilao* dir;
};

NoArvoreVilao* inserir_vilao(NoArvoreVilao* raiz, Vilao* v) {
    if (raiz == NULL) {
        NoArvoreVilao* novo = (NoArvoreVilao*)malloc(sizeof(NoArvoreVilao));
        novo->vilao = v;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    if (nivel_habilidade_vilao(v) < nivel_habilidade_vilao(raiz->vilao)) {
        raiz->esq = inserir_vilao(raiz->esq, v);
    } else {
        raiz->dir = inserir_vilao(raiz->dir, v);
    }

    return raiz;
}

NoArvoreVilao* encontrar_maximo(NoArvoreVilao* no) {
    while (no && no->dir != NULL) {
        no = no->dir;
    }
    return no;
}

NoArvoreVilao* buscar_vilao(NoArvoreVilao* raiz, const char* nome_procurado) { 
    if (raiz == NULL) {
        return NULL;
    }

    if (strcmp(nome_procurado, nome_vilao(raiz->vilao)) == 0) {
        return raiz;
    }

    NoArvoreVilao* encontrado = buscar_vilao(raiz->esq, nome_procurado);
    if (encontrado != NULL) {
        return encontrado;
    }

    return buscar_vilao(raiz->dir, nome_procurado);
}

NoArvoreVilao* remover_no_por_ponteiro(NoArvoreVilao* raiz, NoArvoreVilao* no_remover) { 
    if (raiz == NULL) return NULL;

    if (raiz == no_remover) {
        if (raiz->esq == NULL) {
            NoArvoreVilao* temp = raiz->dir;
            libera_vilao(raiz->vilao);
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            NoArvoreVilao* temp = raiz->esq;
            libera_vilao(raiz->vilao);
            free(raiz);
            return temp;
        }

        NoArvoreVilao* temp = encontrar_maximo(raiz->esq);
        libera_vilao(raiz->vilao);
        raiz->vilao = cria_vilao(nome_vilao(temp->vilao), nivel_habilidade_vilao(temp->vilao), ponto_fraco(temp->vilao));
        raiz->esq = remover_no_por_ponteiro(raiz->esq, temp);
        return raiz;
    }

    raiz->esq = remover_no_por_ponteiro(raiz->esq, no_remover);
    raiz->dir = remover_no_por_ponteiro(raiz->dir, no_remover);
    return raiz;
}

NoArvoreVilao* remover_vilao(NoArvoreVilao* raiz, const char* nome_procurado) { 
    if (raiz == NULL) return NULL;

    if (strcmp(nome_procurado, nome_vilao(raiz->vilao)) == 0) {
        return remover_no_por_ponteiro(raiz, raiz);
    }

    raiz->esq = remover_vilao(raiz->esq, nome_procurado);
    raiz->dir = remover_vilao(raiz->dir, nome_procurado);

    return raiz;
}


void imprimir_viloes_ordem(NoArvoreVilao* raiz) {
    if (raiz == NULL) return;
    imprimir_viloes_ordem(raiz->esq);
    printf("Vilao: %s | Nivel: %d | Ponto Fraco: %s\n",
        nome_vilao(raiz->vilao),
        nivel_habilidade_vilao(raiz->vilao),
        ponto_fraco(raiz->vilao));
    imprimir_viloes_ordem(raiz->dir);
}

void liberar_arvore_vilao(NoArvoreVilao* raiz) {
    if (raiz == NULL) return;
    liberar_arvore_vilao(raiz->esq);
    liberar_arvore_vilao(raiz->dir);
    libera_vilao(raiz->vilao);
    free(raiz);
}
