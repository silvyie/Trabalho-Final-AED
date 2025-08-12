#ifndef MISSAO_H
#define MISSAO_H

typedef enum {
    ATIVA,
    CONCLUIDA,
    FALHA
} StatusMissao;

typedef struct missao Missao;

typedef struct no_missao {
    Missao *dados;
    struct no_missao *prox;
} NoMissao;

Missao *cria_missao(const char *descricao, const char *local, StatusMissao status, int nivel_ameaca, int recompensa);

char *descricao_missao(const Missao *m);
char *local_missao(const Missao *m);
StatusMissao status_missao(Missao *m);
int nivel_ameaca_missao(Missao *m);
int recompensa_missao(Missao *m);
void modifica_status_missao(Missao *m, StatusMissao novo_status);

void libera_missao(Missao *m);

NoMissao *inserir_missao_prioridade(NoMissao *fila, Missao *m);
NoMissao *remover_missao(NoMissao *fila);
void imprimir_fila_missoes(NoMissao *fila);
void liberar_fila_missoes(NoMissao *fila);

#endif