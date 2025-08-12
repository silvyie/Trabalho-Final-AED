#ifndef PILHA_H
#define PILHA_H

#define TAM_DESCRICAO 200 

typedef enum {
    VITORIA_PERFEITA,
    VITORIA_CUSTO,
    DERROTA
} ResultadoMissao;

typedef struct relatorio_missao {
    char descricao[TAM_DESCRICAO];
    ResultadoMissao resultado;
    int num_feridos;
} RelatorioMissao;

typedef struct no_pilha NoPilha;

typedef struct pilha Pilha;

Pilha* criar_pilha();
void empilhar(Pilha* p, RelatorioMissao* relatorio);
void imprimir_pilha(Pilha* p);
void liberar_pilha(Pilha* p);

#endif