#ifndef TARTARUGA_H
#define TARTARUGA_H

typedef enum {
    DISPONIVEL,
    EM_MISSAO,
    FERIDO
} StatusTartaruga;

typedef struct tartaruga Tartaruga;

Tartaruga *cria_tartaruga(const char *nome, StatusTartaruga status, int nivel, const char *arma_favorita);

char *nome_tartaruga(Tartaruga *t);

StatusTartaruga status_tartaruga(Tartaruga *t);

int nivel_tartaruga(Tartaruga *t);

void modifica_status(Tartaruga *t, StatusTartaruga novo_status_tartaruga);

void modifica_nivel(Tartaruga *t, int novo_nivel_tartaruga);

void aumenta_nivel(Tartaruga *t, int incremento);

void imprime_tartaruga(void *dado);

void libera_tartaruga(Tartaruga* t);

#endif