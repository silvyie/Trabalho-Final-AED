#ifndef VILAO_H
#define VILAO_H

typedef struct vilao Vilao;

Vilao *cria_vilao(const char *nome, int nivel_habilidade, const char *ponto_fraco);

char *nome_vilao(Vilao *v);

int nivel_habilidade_vilao(Vilao *v);

char *ponto_fraco(Vilao *v);

void modifica_nivel_habilidade(Vilao *v, int novo_nivel);

void modifica_ponto_fraco(Vilao *v, const char *novo_ponto_fraco);

void libera_vilao(Vilao *v);

#endif