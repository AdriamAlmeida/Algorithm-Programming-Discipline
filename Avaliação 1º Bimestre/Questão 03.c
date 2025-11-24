#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Para a função tolower se necessário

// --- Definição da Estrutura de Dados ---

// Definição da constante para o limite máximo de tarefas
#define MAX_TAREFAS 20
// Definição do tamanho máximo para o nome da tarefa
#define MAX_NOME 100

// Estrutura (struct) para representar uma única tarefa
typedef struct {
    char nome[MAX_NOME];
    int prioridade;    // 1: Baixa, 2: Média, 3: Alta
    int concluida;     // 0: Pendente, 1: Concluída
} Tarefa;

// --- Variáveis Globais (Gerenciamento do Array) ---

// Array para armazenar todas as tarefas
Tarefa tarefas[MAX_TAREFAS];
// Contador para saber quantas tarefas foram realmente adicionadas
int totalTarefas = 0;

// --- Funções Auxiliares ---

// Função para converter o código da prioridade para o nome
const char* obterNomePrioridade(int p) {
    switch (p) {
        case 1: return "Baixa";
        case 2: return "Média";
        case 3: return "Alta";
        default: return "Desconhecida";
    }
}

// --- Funções do Menu ---

/**
 * 1. Adicionar Tarefa
 */
void adicionarTarefa() {
    // Requisito: Implementar validação (limite de tarefas)
    if (totalTarefas >= MAX_TAREFAS) {
        printf("\n Limite máximo de %d tarefas atingido!\n", MAX_TAREFAS);
        return;
    }

    Tarefa novaTarefa;
    int prioridade_valida = 0;
    int prioridade;

    printf("\nNome da tarefa: ");
    // Limpa o buffer de entrada para evitar problemas com fgets
    // (Pode ser necessário dependendo do ambiente/compilador)
    // while (getchar() != '\n'); 
    
    // Leitura segura do nome com fgets
    if (fgets(novaTarefa.nome, MAX_NOME, stdin) != NULL) {
        // Remove o newline ('\n') adicionado por fgets, se houver
        novaTarefa.nome[strcspn(novaTarefa.nome, "\n")] = 0; 
    } else {
        printf("\n Erro na leitura do nome.\n");
        return;
    }

    // Leitura e Validação da Prioridade
    do {
        printf("Prioridade (1-Baixa, 2-Média, 3-Alta): ");
        if (scanf("%d", &prioridade) != 1) {
            printf(" Entrada inválida. Digite um número.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n'); 
        } else if (prioridade < 1 || prioridade > 3) {
            printf(" Prioridade inválida. Escolha entre 1, 2 ou 3.\n");
        } else {
            prioridade_valida = 1;
            novaTarefa.prioridade = prioridade;
        }
    } while (!prioridade_valida);
    
    // Limpa o buffer de entrada após scanf (necessário para o próximo fgets)
    while (getchar() != '\n'); 
    
    // Define o status inicial
    novaTarefa.concluida = 0; // Pendente

    // Adiciona a tarefa no array e incrementa o contador
    tarefas[totalTarefas] = novaTarefa;
    totalTarefas++;

    printf("\n Tarefa adicionada com sucesso! (ID #%d)\n", totalTarefas);
}

/**
 * 2. Listar Tarefas
 */
void listarTarefas() {
    if (totalTarefas == 0) {
        printf("\nℹ️ Não há tarefas cadastradas.\n");
        return;
    }

    printf("\n=== LISTA DE TAREFAS ===\n");
    // Requisito: Usar for para percorrer
    for (int i = 0; i < totalTarefas; i++) {
        // Exibe o status
        const char* status = tarefas[i].concluida ? "CONCLUÍDA" : "PENDENTE";
        // Exibe o nome da prioridade
        const char* pNome = obterNomePrioridade(tarefas[i].prioridade);

        // Exibe as informações da tarefa
        printf("%d. [%s] %s (Prioridade: %s)\n",
               i + 1, // ID visual para o usuário
               status,
               tarefas[i].nome,
               pNome);
    }
}

/**
 * 3. Marcar como Concluída
 */
void marcarComoConcluida() {
    if (totalTarefas == 0) {
        printf("\nℹ️ Não há tarefas para marcar.\n");
        return;
    }

    listarTarefas(); // Exibe a lista para o usuário escolher

    int id_tarefa;
    printf("\nDigite o número (ID) da tarefa para marcar como CONCLUÍDA: ");
    
    if (scanf("%d", &id_tarefa) != 1) {
        printf(" Entrada inválida. Digite um número.\n");
        // Limpa o buffer de entrada
        while (getchar() != '\n'); 
        return;
    }
    
    // Limpa o buffer de entrada
    while (getchar() != '\n'); 

    // Validação de ID (índice)
    if (id_tarefa < 1 || id_tarefa > totalTarefas) {
        printf(" ID de tarefa inválido. Tente novamente.\n");
        return;
    }

    // O ID visual é (índice + 1), logo o índice é (id_tarefa - 1)
    int indice = id_tarefa - 1;

    if (tarefas[indice].concluida) {
        printf(" Tarefa \"%s\" já está CONCLUÍDA.\n", tarefas[indice].nome);
    } else {
        tarefas[indice].concluida = 1; // Marca como concluída
        printf("\n Tarefa #%d - \"%s\" marcada como CONCLUÍDA.\n", id_tarefa, tarefas[indice].nome);
    }
}

/**
 * 4. Gerar Relatório
 */
void gerarRelatorio() {
    if (totalTarefas == 0) {
        printf("\nℹ️ Não há tarefas cadastradas para gerar relatório.\n");
        return;
    }

    int concluidas = 0;
    int pendentes = 0;
    
    // Contadores para estatísticas por prioridade
    int p_alta = 0;
    int p_media = 0;
    int p_baixa = 0;

    // Requisito: Usar for para percorrer e processar
    // Requisito: Usar contadores para estatísticas
    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].concluida) {
            concluidas++;
        } else {
            pendentes++;
        }

        switch (tarefas[i].prioridade) {
            case 3: p_alta++; break;
            case 2: p_media++; break;
            case 1: p_baixa++; break;
        }
    }

    // Cálculo das porcentagens
    float perc_concluidas = (totalTarefas > 0) ? ((float)concluidas / totalTarefas) * 100.0 : 0.0;
    float perc_pendentes = (totalTarefas > 0) ? ((float)pendentes / totalTarefas) * 100.0 : 0.0;

    printf("\n=== RELATÓRIO DE TAREFAS ===\n");
    printf("Total de tarefas: %d\n", totalTarefas);
    printf("Concluídas: %d (%.1f%%)\n", concluidas, perc_concluidas);
    printf("Pendentes: %d (%.1f%%)\n", pendentes, perc_pendentes);
    
    printf("\nPor prioridade:\n");
    printf("- Alta: %d tarefa(s)\n", p_alta);
    printf("- Média: %d tarefa(s)\n", p_media);
    printf("- Baixa: %d tarefa(s)\n", p_baixa);
}

// --- Menu Principal ---

/**
 * Função principal que roda o menu e o programa.
 */
int main() {
    int escolha;

    // Requisito: Usar do-while para manter o menu ativo
    do {
        // Exibição do Menu
        printf("\n============================================\n");
        printf("=== SISTEMA DE GERENCIAMENTO DE TAREFAS ===\n");
        printf("============================================\n");
        printf("1 - Adicionar Tarefa\n");
        printf("2 - Listar Tarefas\n");
        printf("3 - Marcar como Concluída\n");
        printf("4 - Gerar Relatório\n");
        printf("0 - Sair\n");
        printf("--------------------------------------------\n");
        printf("Escolha: ");
        
        // Leitura da escolha do usuário
        if (scanf("%d", &escolha) != 1) {
            // Se o usuário digitar algo que não é um número
            printf("\n Opção inválida. Digite um número.\n");
            // Limpa o buffer de entrada para evitar loop infinito
            while (getchar() != '\n'); 
            escolha = -1; // Garante que não é uma opção válida
            continue; // Volta para o início do loop
        }
        
        // Limpa o buffer de entrada após scanf (necessário para o fgets em adicionarTarefa)
        while (getchar() != '\n'); 

        // Requisito: Usar switch-case para o menu
        switch (escolha) {
            case 1:
                adicionarTarefa();
                break;
            case 2:
                listarTarefas();
                break;
            case 3:
                marcarComoConcluida();
                break;
            case 4:
                gerarRelatorio();
                break;
            case 0:
                printf("\n Encerrando o Sistema. Até logo!\n");
                break;
            default:
                printf("\n Opção inválida. Tente novamente.\n");
                break;
        }

    } while (escolha != 0); // Requisito: Continua até que a opção de sair (0) seja escolhida

    return 0;
}