#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "arsenal.h" 

#define TAM_NOME_EQUIPAMENTO 100 

struct arsenal { 
    char nome[TAM_NOME_EQUIPAMENTO]; 
    int custo; 
    int bonus_ataque; 
    int bonus_defesa; 
    TipoEquipamento tipo; 
}; 

Equipamento *cria_equipamento(const char *nome, int custo, int bonus_ataque, int bonus_defesa, TipoEquipamento tipo){ 
    Equipamento *novo_arsenal = (Equipamento*)malloc(sizeof(Equipamento)); 

    if(novo_arsenal == NULL){ 
        printf("Erro ao alocar memoria\n"); 
        return NULL; 
    } 

    strncpy(novo_arsenal->nome, nome, sizeof(novo_arsenal->nome) -1); 
    novo_arsenal->nome[sizeof(novo_arsenal->nome) -1] = '\0'; 

    novo_arsenal->custo = custo; 
    novo_arsenal->bonus_ataque = bonus_ataque; 
    novo_arsenal->bonus_defesa = bonus_defesa; 
    novo_arsenal->tipo = tipo; 

    return novo_arsenal; 
} 

const char *nome_equipamento(Equipamento *e){ 
    if(e == NULL){ 
        return NULL; 
    } 
    return e->nome; 
} 

int custo_equipamento(Equipamento *e){ 
    if(e == NULL){ 
        return 1; 
    }
    return e->custo; 
} 

int bonus_ataque_equipamento(Equipamento *e){ 
    if(e == NULL){ 
        return 1; 
    } 
    return e->bonus_ataque; 
} 

int bonus_defesa_equipamento(Equipamento *e){ 
    if(e == NULL){ 
        return 1; 
    } 
    return e->bonus_defesa; 
} 

TipoEquipamento tipo_equipamento(Equipamento *e){ 
    if(e == NULL){ 
        return OUTRO; 
    } 
    return e->tipo; 
} 

void libera_equipamento(Equipamento *e) { 
    if (e != NULL) { 
        free(e); 
    }
}

