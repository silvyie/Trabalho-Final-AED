#ifndef ARVORE_VILAO_H
#define ARVORE_VILAO_H

#include "vilao.h"

typedef struct no_arvore_vilao NoArvoreVilao;

NoArvoreVilao *inserir_vilao(NoArvoreVilao *raiz, Vilao *v);
void imprimir_viloes_ordem(NoArvoreVilao *raiz);
NoArvoreVilao* buscar_vilao(NoArvoreVilao *raiz, const char *nome_vilao);
NoArvoreVilao* remover_no_por_ponteiro(NoArvoreVilao* raiz, NoArvoreVilao* no_remover); 
NoArvoreVilao* remover_vilao(NoArvoreVilao* raiz, const char* nome_procurado); 
void liberar_arvore_vilao(NoArvoreVilao *raiz);

#endif

