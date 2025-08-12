#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "tartaruga.h" 

#define TAM_NOME_TARTARUGA 50 
#define TAM_ARMA_FAVORITA 50 

struct tartaruga { 
    char nome[TAM_NOME_TARTARUGA]; 
    StatusTartaruga status; 
    int nivel; 
    char arma_favorita[TAM_ARMA_FAVORITA]; 
}; 

Tartaruga *cria_tartaruga(const char *nome, StatusTartaruga status, int nivel, const char* arma_favorita){ 
    Tartaruga *nova_tartaruga = (Tartaruga*)malloc(sizeof(Tartaruga)); 

    if(nova_tartaruga == NULL){ 
        printf("Erro ao alocar memoria\n"); 
        return NULL; 
    } 

    strncpy(nova_tartaruga->nome, nome, sizeof(nova_tartaruga->nome) -1); 
    nova_tartaruga->nome[sizeof(nova_tartaruga->nome) -1] = '\0'; 
    strncpy(nova_tartaruga->arma_favorita, arma_favorita, sizeof(nova_tartaruga->arma_favorita) -1); 
    nova_tartaruga->arma_favorita[sizeof(nova_tartaruga->arma_favorita) -1] = '\0'; 
    nova_tartaruga->status = status; 
    nova_tartaruga->nivel = nivel; 

    return nova_tartaruga; 
} 

char *nome_tartaruga(Tartaruga *t){ 
    if(t == NULL){ 
        return NULL; 
} 
    return t->nome; 
} 

StatusTartaruga status_tartaruga(Tartaruga *t){ 
    if(t == NULL){ 
    return DISPONIVEL; 
} 
    return t->status; 
} 

int nivel_tartaruga(Tartaruga *t){ 
    if(t == NULL){ 
    return 1; 
} 
    return t->nivel; 
} 

void modifica_status(Tartaruga* t, StatusTartaruga novo_status_tartaruga){ 
    if(t != NULL){ 
     t->status = novo_status_tartaruga; 
    } 
} 

void modifica_nivel(Tartaruga *t, int novo_nivel_tartaruga){ 
    if (t != NULL && novo_nivel_tartaruga >= 1 && novo_nivel_tartaruga <= 10) { 
        t->nivel = novo_nivel_tartaruga; 
    } 
} 

void aumenta_nivel(Tartaruga* t, int incremento){ 
    if(t != NULL){ 
        t->nivel += incremento; 

        if(t->nivel > 10){ 
            t->nivel = 10; 
        }else if(t->nivel < 1){ 
            t->nivel = 1; 
        } 
    } 
} 

void imprime_tartaruga(void *dado) { 
    Tartaruga *t = (Tartaruga *)dado; 
    if (t == NULL) return; 

    char *status_str; 
    switch (status_tartaruga(t)) { 
        case DISPONIVEL: status_str = "DISPONIVEL"; break; 
        case EM_MISSAO: status_str = "EM_MISSAO"; break; 
        case FERIDO: status_str = "FERIDO"; break; 
        default: status_str = "DESCONHECIDO"; break; 
    } 
      
    printf("Nome: %s | Nivel: %d | Status: %s\n", 
           nome_tartaruga(t), nivel_tartaruga(t), status_str); 
} 

char *arma_favorita(Tartaruga *t){ 
    if (t == NULL){ 
        return NULL; 
    } 
    return t->arma_favorita; 
} 

void libera_tartaruga(Tartaruga* t){ 
    if(t != NULL){ 
        free(t); 
    } 
}