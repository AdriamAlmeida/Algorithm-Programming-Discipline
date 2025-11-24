#include <stdio.h>
#include <stdlib.h> // Para a função system() (opcional, para limpar a tela)

#define MAX_HISTORICO 100 // Define o tamanho máximo do histórico de transações

// Protótipo da função para exibir o histórico
void exibir_historico(float hist[], int count);

int main() {
    float saldo = 0.0;
    float historico[MAX_HISTORICO];
    int contador_historico = 0;
    int opcao;
    float valor;

    do {
        // Limpa a tela (funciona no terminal Linux/macOS ou prompt de comando Windows)
        // Se não funcionar ou for indesejado, basta comentar esta linha.
        // system("cls || clear");

        // --- Menu Principal ---
        printf("\n===================================\n");
        printf("       🏦 SIMULADOR BANCÁRIO        \n");
        printf("===================================\n");
        printf("1. Depósito\n");
        printf("2. Saque\n");
        printf("3. Consultar Saldo e Histórico\n");
        printf("0. Sair\n");
        printf("-----------------------------------\n");
        printf("Saldo Atual: R$ %.2f\n", saldo);
        printf("-----------------------------------\n");
        printf("Escolha uma opção: ");
        
        // Garante que a entrada seja um número inteiro
        if (scanf("%d", &opcao) != 1) {
            printf("\nOpção inválida. Digite um número.\n");
            // Limpa o buffer de entrada para evitar loop infinito em caso de erro de leitura
            while (getchar() != '\n'); 
            continue;
        }

        // --- Estrutura de Seleção (switch) ---
        switch (opcao) {
            case 1: // DEPOSITO
                printf("\n--- OPERAÇÃO DE DEPÓSITO ---\n");
                printf("Digite o valor a depositar: R$ ");
                if (scanf("%f", &valor) != 1 || valor <= 0) {
                    printf("❌ Erro: Valor de depósito inválido.\n");
                    while (getchar() != '\n');
                    break;
                }
                
                // Atualiza o saldo
                saldo += valor;
                
                // Armazena no histórico, se houver espaço
                if (contador_historico < MAX_HISTORICO) {
                    historico[contador_historico++] = valor;
                }
                printf("✅ Depósito de R$ %.2f realizado com sucesso.\n", valor);
                break;

            case 2: // SAQUE
                printf("\n--- OPERAÇÃO DE SAQUE ---\n");
                printf("Digite o valor a sacar: R$ ");
                if (scanf("%f", &valor) != 1 || valor <= 0) {
                    printf("❌ Erro: Valor de saque inválido.\n");
                    while (getchar() != '\n');
                    break;
                }

                // Verifica se há saldo suficiente (Avançado: Checagem)
                if (valor > saldo) {
                    printf("❌ Erro: Saldo insuficiente! (R$ %.2f)\n", saldo);
                } else {
                    // Atualiza o saldo
                    saldo -= valor;
                    
                    // Armazena no histórico (Saques são valores negativos)
                    if (contador_historico < MAX_HISTORICO) {
                        historico[contador_historico++] = -valor;
                    }
                    printf("✅ Saque de R$ %.2f realizado com sucesso.\n", valor);
                }
                break;

            case 3: // CONSULTA
                printf("\n--- CONSULTA DE SALDO E HISTÓRICO ---\n");
                printf("Saldo Atual: R$ **%.2f**\n", saldo);
                printf("-------------------------------------\n");
                exibir_historico(historico, contador_historico);
                printf("\n(Pressione ENTER para voltar ao menu...)");
                // Espera por uma tecla para o usuário poder ler o histórico
                while (getchar() != '\n'); // Limpa o buffer
                getchar(); // Espera pela próxima tecla
                break;

            case 0: // SAIR
                printf("\nObrigado por utilizar o Simulador Bancário. 👋\n");
                break;

            default: // OPÇÃO INVÁLIDA
                printf("\n⚠️ Opção inválida! Por favor, escolha um número entre 0 e 3.\n");
                break;
        }
        
    } while (opcao != 0); // O loop continua até que a opção 0 (Sair) seja escolhida

    return 0;
}

// --- Implementação da Função de Histórico ---
void exibir_historico(float hist[], int count) {
    if (count == 0) {
        printf("Nenhuma transação registrada ainda.\n");
        return;
    }

    printf("📜 Histórico de Transações (%d registradas):\n", count);
    
    // Laço for para iterar e exibir cada transação
    for (int i = 0; i < count; i++) {
        if (hist[i] > 0) {
            printf("  [%03d] DEPÓSITO: + R$ %.2f\n", i + 1, hist[i]);
        } else {
            // Usa o valor absoluto para exibir o saque
            printf("  [%03d] SAQUE:    - R$ %.2f\n", i + 1, -hist[i]);
        }
    }
}