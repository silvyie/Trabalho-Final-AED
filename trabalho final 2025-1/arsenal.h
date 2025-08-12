#ifndef ARSENAL_H 
#define ARSENAL_H 

typedef enum { 
    ARMA, 
    ARMADURA, 
    ITEM_CURA, 
    OUTRO 
} TipoEquipamento; 

typedef struct arsenal Equipamento; 

Equipamento *cria_equipamento(const char *nome, int custo, int bonus_ataque, int bonus_defesa, TipoEquipamento tipo); 

const char *nome_equipamento(Equipamento *e); 

int custo_equipamento(Equipamento *e); 

int bonus_ataque_equipamento(Equipamento *e); 

int bonus_defesa_equipamento(Equipamento *e); 

TipoEquipamento tipo_equipamento(Equipamento *e); 

void libera_equipamento(Equipamento *e); 

#endif