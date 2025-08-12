#ifndef FILA_H 
#define FILA_H 

#include "arsenal.h" 

typedef struct fila_arsenal FilaArsenal; 

FilaArsenal* criar_fila(); 
void enfileirar(FilaArsenal* f, Equipamento* e); 
void imprimir_fila(FilaArsenal* f); 
void liberar_fila(FilaArsenal* f); 

#endif