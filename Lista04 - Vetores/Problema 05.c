#include <stdio.h>
#include <stdlib.h> // Para a função system("clear") ou similar

// Constantes
#define NUM_SENHAS 20

// Definições de Status (para melhor legibilidade do código)
#define STATUS_DISPONIVEL 0 // Senha aguardando ser chamada
#define STATUS_CHAMADA    1 // Senha em atendimento (chamada, mas não finalizada)
#define STATUS_ATENDIDA   2 // Senha já atendida

// Protótipos de funções
void exibir_menu();
void chamar_proxima_senha(int status_senhas[], int *proxima_disponivel);
void marcar_como_atendida(int status_senhas[], int proxima_disponivel);
void exibir_fila(int status_senhas[]);
void gerar_relatorio(int status_senhas[], int *todas_atendidas);

int main() {
    // Inicializa o vetor de status: todas as 20 senhas como DISPONIVEIS (0)
    int status_senhas[NUM_SENHAS] = {0}; 
    
    // Variável que rastreia o índice da próxima senha disponível para chamada.
    // Começa em 0 (Senha 001).
    int proxima_disponivel = 0; 

    // Variáveis de controle
    int opcao;
    int todas_atendidas = 0;

    printf("=== BEM-VINDO AO SISTEMA DE SENHAS ===\n");

    // Loop principal: Continua enquanto houver senhas não atendidas
    do {
        // Verifica se todas foram atendidas antes de exibir o menu
        gerar_relatorio(status_senhas, &todas_atendidas);
        if (todas_atendidas) {
            printf("\n✅ Todas as %d senhas foram atendidas. Encerrando o sistema.\n", NUM_SENHAS);
            break;
        }

        exibir_menu();
        printf("Opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            // Limpa o buffer de entrada
            while(getchar() != '\n'); 
            continue;
        }

        printf("\n");
        switch (opcao) {
            case 1:
                // Chamar a próxima senha que está DISPONÍVEL (0)
                chamar_proxima_senha(status_senhas, &proxima_disponivel);
                break;
            case 2:
                // Marcar a senha em CHMADA (1) como ATENDIDA (2)
                marcar_como_atendida(status_senhas, proxima_disponivel);
                break;
            case 3:
                // Exibir o status detalhado de todas as senhas
                exibir_fila(status_senhas);
                break;
            case 4:
                // O relatório já foi gerado no início do loop, mas podemos exibir novamente se o usuário quiser
                // A flag 'todas_atendidas' é passada apenas para a função conseguir alterar
                printf("=== RELATÓRIO ATUAL ===\n");
                gerar_relatorio(status_senhas, &todas_atendidas);
                break;
            case 0:
                printf("Encerrando o sistema a pedido do usuário...\n");
                todas_atendidas = 1; // Sai do loop
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção de 0 a 4.\n");
        }
        printf("\n-------------------------------------------------\n");
    } while (!todas_atendidas);

    return 0;
}

// Exibe as opções do menu
void exibir_menu() {
    printf("\n=== SISTEMA DE SENHAS ===\n");
    printf("1 - Chamar próxima senha\n");
    printf("2 - Marcar senha como atendida\n");
    printf("3 - Ver fila de espera\n");
    printf("4 - Gerar relatório\n");
    printf("0 - Sair\n");
}

// Opção 1: Encontra a próxima senha DISPONÍVEL (0) e a marca como CHAMADA (1)
void chamar_proxima_senha(int status_senhas[], int *proxima_disponivel) {
    int i = *proxima_disponivel;
    
    // Procura o próximo índice que ainda está DISPONÍVEL (0)
    while (i < NUM_SENHAS && status_senhas[i] != STATUS_DISPONIVEL) {
        i++;
    }

    if (i < NUM_SENHAS) {
        // O índice 'i' é a próxima senha a ser chamada
        status_senhas[i] = STATUS_CHAMADA;
        
        // Atualiza a variável global (ponteiro) para o próximo índice a ser verificado
        *proxima_disponivel = i; 
        
        // Exibe a senha no formato 001, 002, etc. (i + 1)
        printf("📢 Senha %03d chamada! Por favor, dirija-se ao guichê de atendimento.\n", i + 1);
        printf("Status atualizado para 'Em Atendimento'.\n");
    } else {
        // Se i == NUM_SENHAS, significa que não há mais senhas disponíveis para chamar
        printf("⚠️ Todas as senhas disponíveis (001 a %d) já foram chamadas ou atendidas.\n", NUM_SENHAS);
    }
}

// Opção 2: Marca a senha CHAMADA (1) como ATENDIDA (2)
void marcar_como_atendida(int status_senhas[], int proxima_disponivel) {
    
    // Verifica se a senha atualmente CHMADA é a mais recente que foi CHMADA (1)
    if (proxima_disponivel < NUM_SENHAS && status_senhas[proxima_disponivel] == STATUS_CHAMADA) {
        status_senhas[proxima_disponivel] = STATUS_ATENDIDA;
        printf("✅ Senha %03d marcada como ATENDIDA com sucesso!\n", proxima_disponivel + 1);
        
        // Na prática, em um sistema real, aqui o 'proxima_disponivel' seria incrementado para procurar a próxima,
        // mas vamos mantê-lo aqui para que a função 'chamar_proxima_senha' o atualize de forma segura.
        // Contudo, é uma boa prática atualizar o ponteiro para a próxima senha DISPONÍVEL (0) imediatamente após o atendimento.
        
    } else {
        printf("❌ Nenhuma senha está atualmente 'Em Atendimento' (chamada). Chame a próxima senha primeiro (Opção 1).\n");
    }
}

// Opção 3: Exibe o status de cada senha
void exibir_fila(int status_senhas[]) {
    printf("=== FILA DE ESPERA E STATUS ===\n");
    for (int i = 0; i < NUM_SENHAS; i++) {
        printf("Senha %03d: ", i + 1);
        switch (status_senhas[i]) {
            case STATUS_DISPONIVEL:
                printf("Aguardando (0)\n");
                break;
            case STATUS_CHAMADA:
                printf("Em Atendimento (1) - 🔔 CHAMADA\n");
                break;
            case STATUS_ATENDIDA:
                printf("Atendida (2) - ✅ FINALIZADA\n");
                break;
            default:
                printf("Status Desconhecido\n");
        }
    }
}

// Opção 4: Gera o relatório e verifica o status de encerramento
void gerar_relatorio(int status_senhas[], int *todas_atendidas) {
    int atendidas = 0;
    int chamadas = 0;
    int aguardando = 0;
    
    // Itera sobre o vetor e conta os status
    for (int i = 0; i < NUM_SENHAS; i++) {
        switch (status_senhas[i]) {
            case STATUS_ATENDIDA:
                atendidas++;
                break;
            case STATUS_CHAMADA:
                chamadas++;
                break;
            case STATUS_DISPONIVEL:
                aguardando++;
                break;
        }
    }

    printf("Total de senhas no sistema: %d\n", NUM_SENHAS);
    printf("Atendidas: %d\n", atendidas);
    printf("Em Atendimento (Chamadas): %d\n", chamadas);
    printf("Aguardando (Disponíveis): %d\n", aguardando);

    // Verifica a condição de saída
    if (atendidas == NUM_SENHAS) {
        *todas_atendidas = 1; // Define a flag para sair do loop principal
    } else {
        *todas_atendidas = 0;
    }
}