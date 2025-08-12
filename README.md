# Trabalho-Final-AED

# 🛰 Central de Comando

Trabalho Final da disciplina de AED que simula uma **central de comando** para gerenciar operações:
cadastrar missões,
catalogar vilões,
gerenciar o arsenal,
administrar a equipe de tartarugas.

O sistema foi dividido em módulos, cada um implementando uma estrutura de dados diferente.

---

## Estrutura do Projeto

* **`main.c`**
  Contém o menu principal e chama os submenus de cada módulo: tartarugas, vilões, arsenal e missões.

* **`lista.c` / `lista.h`**
  Lista encadeada para armazenar as tartarugas (membros da equipe).

* **`tartaruga.c` / `tartaruga.h`**
  Estrutura `Tartaruga` e funções de criação, exibição e liberação.

* **`arvore_vilao.c` / `arvore_vilao.h`**
  Árvore binária de busca para armazenar vilões, ordenados pelo nível de ameaça (do menor ao maior).

* **`vilao.c` / `vilao.h`**
  Estrutura `Vilao` e funções de manipulação.

* **`fila.c` / `fila.h`**
  Fila para gerenciar o arsenal, simulando o acesso sequencial aos equipamentos.

* **`arsenal.c` / `arsenal.h`**
  Estrutura `Equipamento` e funções para gerenciar atributos de armas, armaduras e itens.

* **`missao.c` / `missao.h`**
  Estrutura e funções para cadastrar e acompanhar missões (também utilizando fila de prioridade para missões com maior nivel de ameaça).



Cada módulo é independente internamente, mas pode interagir quando necessário.
Por exemplo: uma missão pode incluir tartarugas da lista e equipamentos da fila, etc.

---

## Funcionalidades

* **Equipe (Tartarugas)**

  * Cadastrar, listar tartarugas com status e nivel.
* **Vilões**

  * Cadastrar, listar em ordem com nivel de habilidade, ponto fraco e remover
* **Arsenal**

  * Cadastrar e listar equipamentos, com tipo e atributos.
* **Missões**

  * Criar missão, associar equipe.
  * Listar missões registradas com vitória, vitória com danos ou derrota e número de feridos.

