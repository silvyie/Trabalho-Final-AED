#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "fila.h" 
#include "arsenal.h" 

typedef struct no_fila { 
    Equipamento* equipamento; 
    struct no_fila* prox; 
} NoFila; 

struct fila_arsenal { 
    NoFila* ini; 
    NoFila* fim; 
}; 

FilaArsenal* criar_fila() { 
    FilaArsenal* f = (FilaArsenal*)malloc(sizeof(FilaArsenal)); 
    if (f != NULL) { 
        f->ini = NULL; 
        f->fim = NULL; 
    } 
    return f; 
} 

void enfileirar(FilaArsenal* f, Equipamento* e) { 
    if (f == NULL) return; 
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila)); 
    if (novo == NULL) return; 
    novo->equipamento = e; 
    novo->prox = NULL; 
    if (f->fim != NULL) { 
        f->fim->prox = novo; 
    } else { 
        f->ini = novo; 
    } 
    f->fim = novo; 
} 

void imprimir_fila(FilaArsenal* f) { 
    if (f == NULL) return; 
    NoFila* atual = f->ini; 
    while (atual != NULL) { 
        Equipamento* e = atual->equipamento; 
          
        char* tipo_str; 

        switch (tipo_equipamento(e)) { 
            case ARMA: tipo_str = "ARMA"; break; 
            case ARMADURA: tipo_str = "ARMADURA"; break; 
            case ITEM_CURA: tipo_str = "ITEM_CURA"; break; 
            case OUTRO: tipo_str = "OUTRO"; break; 
            default: tipo_str = "DESCONHECIDO"; break; 
        } 
        printf("Equipamento: %s | Tipo: %s | Custo: %d | Ataque: %d | Defesa: %d\n", 
            nome_equipamento(e), tipo_str, custo_equipamento(e), 
            bonus_ataque_equipamento(e), bonus_defesa_equipamento(e)); 
          
        atual = atual->prox; 
    } 
} 

void liberar_fila(FilaArsenal* f) { 
    if (f == NULL) return; 
    NoFila* atual = f->ini; 
    while (atual != NULL) { 
        NoFila* temp = atual; 
        atual = atual->prox; 
        libera_equipamento(temp->equipamento); 
        free(temp); 
    } 
    free(f); 
}