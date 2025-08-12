#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vilao.h"

#define TAM_NOME_VILAO 50
#define TAM_PONTO_FRACO 50

struct vilao {
    char nome[TAM_NOME_VILAO];
    int nivel_habilidade;
    char ponto_fraco[TAM_PONTO_FRACO];
};

Vilao *cria_vilao(const char *nome, int nivel_habilidade, const char *ponto_fraco){
    Vilao *novo_vilao = (Vilao*)malloc(sizeof(Vilao));

    if(novo_vilao == NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    strncpy(novo_vilao->nome, nome, sizeof(novo_vilao->nome) -1);
    novo_vilao->nome[sizeof(novo_vilao->nome) -1] = '\0';

    novo_vilao->nivel_habilidade = nivel_habilidade;

    strncpy(novo_vilao->ponto_fraco, ponto_fraco, sizeof(novo_vilao->ponto_fraco) -1);
    novo_vilao->ponto_fraco[sizeof(novo_vilao->ponto_fraco) -1] = '\0';

    return novo_vilao;
}

char *nome_vilao(Vilao *v){
    if(v == NULL){
        return NULL;
    }

    return v->nome;
}

int nivel_habilidade_vilao(Vilao *v){
    if(v == NULL){
        return 1;
    }

    return v->nivel_habilidade;
}

char *ponto_fraco(Vilao *v){
    if(v == NULL){
        return NULL;
    }

    return v->ponto_fraco;
}

void modifica_nivel_habilidade(Vilao *v, int novo_nivel){
    if(v != NULL && novo_nivel >= 1 && novo_nivel <= 10){
        v->nivel_habilidade = novo_nivel;
    }
}

void modifica_ponto_fraco(Vilao *v, const char *novo_ponto_fraco){
    if(v == NULL){
        return;
    }
    
    strncpy(v->ponto_fraco, novo_ponto_fraco, sizeof(v->ponto_fraco) -1);
    v->ponto_fraco[sizeof(v->ponto_fraco) -1] = '\0';
}

void libera_vilao(Vilao *v){
    if(v != NULL){
        free(v);
    }
}
