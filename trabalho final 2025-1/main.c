#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tartaruga.h"
#include "vilao.h"
#include "arsenal.h"
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "arvore_vilao.h"
#include "missao.h"

#define TAM_DESCRICAO_RELATORIO 200

Lista *lista_tartarugas = NULL;
NoArvoreVilao *arvore_viloes = NULL;
FilaArsenal *arsenal = NULL;
Pilha *diario_bordo = NULL;
NoMissao *fila_missoes = NULL;

void menu_tartaruga() {
    char nome[50];
    char arma_favorita[50];
    int nivel;
    printf("\nNome da tartaruga: ");
    scanf(" %[^\n]", nome);
    printf("Nivel (1 a 10): ");
    scanf("%d", &nivel);
    printf("Arma favorita: ");
    scanf(" %[^\n]", arma_favorita);

    Tartaruga *t = cria_tartaruga(nome, DISPONIVEL, nivel, arma_favorita);
    lista_tartarugas = insere_final(lista_tartarugas, t);

    printf("Tartaruga adicionada!\n");
}

void menu_vilao() {
    char nome[50], ponto[50];
    int nivel;
    printf("\nNome do vilao: ");
    scanf(" %[^\n]", nome);
    printf("Nivel habilidade (1 a 10): ");
    scanf("%d", &nivel);
    printf("Ponto fraco: ");
    scanf(" %[^\n]", ponto);

    Vilao *v = cria_vilao(nome, nivel, ponto);
    arvore_viloes = inserir_vilao(arvore_viloes, v);

    printf("Vilao adicionado!\n");
}

void menu_remover_vilao() {
    char nome[50];
    printf("\nNome do vilao a ser removido: ");
    scanf(" %[^\n]", nome);

    NoArvoreVilao* vilao_existente = buscar_vilao(arvore_viloes, nome);
    if (vilao_existente == NULL) {
        printf("Vilao '%s' nao encontrado.\n", nome);
    } else {
        arvore_viloes = remover_vilao(arvore_viloes, nome);
        printf("Vilao '%s' removido com sucesso!\n", nome);
    }
}

void menu_arsenal() {
    char nome[50];
    int custo, atk, def, tipo;
    printf("\nNome do equipamento: ");
    scanf(" %[^\n]", nome);
    printf("Custo: ");
    scanf("%d", &custo);
    printf("Bonus ataque: ");
    scanf("%d", &atk);
    printf("Bonus defesa: ");
    scanf("%d", &def);
    printf("Tipo (0: ARMA, 1: ARMADURA, 2: ITEM_CURA, 3: OUTRO): ");
    scanf("%d", &tipo);

    Equipamento *e = cria_equipamento(nome, custo, atk, def, tipo);
    enfileirar(arsenal, e);

    printf("Equipamento adicionado com sucesso!\n");
}

void menu_missao() {
    char desc[100], local[100];
    int nivel, recompensa;
    printf("\nDescricao: ");
    scanf(" %[^\n]", desc);
    printf("Local: ");
    scanf(" %[^\n]", local);
    printf("Nivel de ameaca (1 a 10): ");
    scanf("%d", &nivel);
    printf("Recompensa: ");
    scanf("%d", &recompensa);

    Missao *m = cria_missao(desc, local, ATIVA, nivel, recompensa);
    fila_missoes = inserir_missao_prioridade(fila_missoes, m);

    printf("Missao adicionada com sucesso!\n");
}

Tartaruga* buscar_tartaruga_por_nome(Lista* lista, const char* nome) {
    Lista* p = lista;
    while (p != NULL) {
        Tartaruga* t = (Tartaruga*)p->dado;
        if (strcmp(nome, nome_tartaruga(t)) == 0) {
            return t;
        }
        p = p->prox;
    }
    return NULL;
}

void menu_iniciar_missao() {  
    if (fila_missoes == NULL) { 
        printf("\nNenhuma missao disponivel.\n"); 
        return; 
    } 

    if (lista_tartarugas == NULL || lista_vazia(lista_tartarugas)) { 
        printf("\nNenhuma tartaruga disponivel para missao.\n"); 
        return; 
    } 

    Missao* missao_atual = fila_missoes->dados; 

    printf("\n=== PREPARACAO DA MISSAO ===\n"); 
    printf("Missao: %s (Nivel: %d)\n", descricao_missao(missao_atual), nivel_ameaca_missao(missao_atual)); 
    printf("Tartarugas disponiveis:\n"); 
    imprime_lista(lista_tartarugas, (void (*)(void*))imprime_tartaruga); 

    Lista* equipe = cria_lista(); 
    char nome_tartaruga_equipe[50]; 
    int num_membros = 0; 

    printf("\nSelecione a equipe (digite 'fim' para terminar):\n"); 
    while (num_membros < 4) { 
        printf("Nome da tartaruga (disponivel): "); 
        scanf(" %[^\n]", nome_tartaruga_equipe); 

        if (strcmp(nome_tartaruga_equipe, "fim") == 0) { 
            break; 
        } 

        Tartaruga* t = buscar_tartaruga_por_nome(lista_tartarugas, nome_tartaruga_equipe); 
        if (t != NULL && status_tartaruga(t) == DISPONIVEL) { 
            equipe = insere_final(equipe, t); 
            modifica_status(t, EM_MISSAO); 
            num_membros++; 
            printf("Tartaruga '%s' adicionada a equipe.\n", nome_tartaruga_equipe); 
        } else { 
            printf("Tartaruga nao encontrada ou indisponivel. Tente novamente.\n"); 
        } 
    } 

    if (num_membros == 0) { 
        printf("Nenhuma tartaruga foi selecionada. Missao cancelada.\n"); 
        libera_lista(equipe, NULL); 
        return; 
    } 

    printf("\n... Iniciando missao e batalha ...\n"); 

    double forca_equipe = 0.0; 
    Lista* p_equipe = equipe; 
    while (p_equipe != NULL) { 
        Tartaruga* t = (Tartaruga*)p_equipe->dado; 
        forca_equipe += nivel_tartaruga(t); 
        p_equipe = p_equipe->prox; 
    } 
    forca_equipe /= num_membros; 

    int nivel_desafio = nivel_ameaca_missao(missao_atual); 
    double sorte = (double)(rand() % 5) - 2; 
    double caos_mutante = (double)rand() / RAND_MAX; 
    double resultado_final = forca_equipe - nivel_desafio + sorte - caos_mutante; 

    printf("\n=== RESULTADO DA BATALHA ===\n"); 
    printf("Forca da Equipe: %.2f\n", forca_equipe); 
    printf("Nivel de Desafio: %d\n", nivel_desafio); 
    printf("Resultado Final: %.2f\n", resultado_final); 
      
    RelatorioMissao* relatorio = (RelatorioMissao*)malloc(sizeof(RelatorioMissao)); 
    if (relatorio == NULL) { 
        printf("Erro ao alocar memoria para relatorio\n"); 
        libera_lista(equipe, NULL); 
        return; 
    } 
    strncpy(relatorio->descricao, descricao_missao(missao_atual), TAM_DESCRICAO_RELATORIO - 1); 
    relatorio->descricao[TAM_DESCRICAO_RELATORIO - 1] = '\0'; 
      
    if (resultado_final > 3.0) { 
        printf("Vitoria Perfeita!\n"); 
        relatorio->resultado = VITORIA_PERFEITA; 
        relatorio->num_feridos = 0; 

        p_equipe = equipe; 
        while (p_equipe != NULL) { 
            Tartaruga* t = (Tartaruga*)p_equipe->dado; 
            modifica_status(t, DISPONIVEL); 
            aumenta_nivel(t, 1); 
            p_equipe = p_equipe->prox; 
        } 

        fila_missoes = remover_missao(fila_missoes); 

    } else if (resultado_final >= 0.0) { 
        printf("Vitoria com Custo!\n"); 
        relatorio->resultado = VITORIA_CUSTO; 
        relatorio->num_feridos = 1; 

        int tartaruga_ferida_idx = rand() % num_membros; 
        p_equipe = equipe; 
        for (int i = 0; i < tartaruga_ferida_idx; i++) { 
            p_equipe = p_equipe->prox; 
        } 
        Tartaruga* t_ferida = (Tartaruga*)p_equipe->dado; 
        modifica_status(t_ferida, FERIDO); 
        printf("A tartaruga %s se feriu e esta indisponivel.\n", nome_tartaruga(t_ferida)); 

        p_equipe = equipe; 
        while (p_equipe != NULL) { 
            Tartaruga* t = (Tartaruga*)p_equipe->dado; 
            if (t != t_ferida) { 
                modifica_status(t, DISPONIVEL); 
            } 
            p_equipe = p_equipe->prox; 
        } 

        fila_missoes = remover_missao(fila_missoes); 

    } else { 
        printf("Derrota!\n"); 
        relatorio->resultado = DERROTA; 
        relatorio->num_feridos = num_membros; 

        p_equipe = equipe; 
        while (p_equipe != NULL) { 
            Tartaruga* t = (Tartaruga*)p_equipe->dado; 
            modifica_status(t, FERIDO); 
            p_equipe = p_equipe->prox; 
        } 

        fila_missoes = remover_missao(fila_missoes); 
    } 

    if (diario_bordo == NULL) { 
        diario_bordo = criar_pilha(); 
        if (diario_bordo == NULL) { 
            printf("Erro ao criar pilha diario_bordo\n"); 
            free(relatorio); 
            libera_lista(equipe, NULL); 
            return; 
        } 
    } 

    printf("Empilhando relatorio: %s\n", relatorio->descricao); 
    empilhar(diario_bordo, relatorio); 
      
    free(relatorio); 
    libera_lista(equipe, (void (*)(void*))libera_tartaruga); 
}

void menu_diario() {
    printf("\n=== Diario de Bordo ===\n");
    imprimir_pilha(diario_bordo);
}

void imprimir_opcoes() {
    printf("\n=== CENTRAL DE COMANDO ===\n");
    printf("1 - Adicionar Tartaruga\n");
    printf("2 - Adicionar Vilao\n");
    printf("3 - Adicionar Missao\n");
    printf("4 - Adicionar Equipamento ao Arsenal\n");
    printf("5 - Iniciar Missao\n");
    printf("6 - Consultar Diario de Bordo\n");
    printf("7 - Listar Tartarugas\n");
    printf("8 - Listar Viloes (em ordem)\n");
    printf("9 - Listar Arsenal\n");
    printf("10 - Listar Missoes Pendentes\n");
    printf("11 - Remover Vilao\n");
    printf("0 - Sair\n");
}

int main() {
    int opcao;

    srand(time(NULL));

    lista_tartarugas = cria_lista();
    arvore_viloes = NULL;
    arsenal = criar_fila();
    diario_bordo = criar_pilha();
    if (diario_bordo == NULL) {
        printf("Erro ao criar pilha diario_bordo\n");
        exit(1);
    }
    fila_missoes = NULL;

    do {
        imprimir_opcoes();
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: menu_tartaruga(); break;
            case 2: menu_vilao(); break;
            case 3: menu_missao(); break;
            case 4: menu_arsenal(); break;
            case 5: menu_iniciar_missao(); break;
            case 6: menu_diario(); break;
            case 7: printf("=== Lista de Tartarugas ===\n"); imprime_lista(lista_tartarugas, (void (*)(void*))imprime_tartaruga); break;
            case 8: printf("=== Viloes em Ordem ===\n"); imprimir_viloes_ordem(arvore_viloes); break;
            case 9: printf("=== Arsenal ===\n"); imprimir_fila(arsenal); break;
            case 10: printf("=== Fila de Missoes ===\n"); imprimir_fila_missoes(fila_missoes); break;
            case 11: menu_remover_vilao(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    libera_lista(lista_tartarugas, (void (*)(void*))libera_tartaruga);
    liberar_arvore_vilao(arvore_viloes);
    liberar_fila(arsenal);
    liberar_pilha(diario_bordo);
    liberar_fila_missoes(fila_missoes);

    return 0;
}
