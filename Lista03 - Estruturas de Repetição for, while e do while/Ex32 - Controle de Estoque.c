#include <stdio.h>

int main() {
    int estoque_atual = 0; // Inicializa o estoque com zero
    int opcao;           // Opcao do menu
    int quantidade;      // Quantidade de itens a adicionar/remover

    printf("--- Controle Simples de Estoque ---\n");
    printf("Estoque inicial: %d\n", estoque_atual);

    // 1. Loop DO-WHILE para o Menu Principal
    do {
        // Exibe o menu de opcoes
        printf("\n-----------------------------------\n");
        printf("Estoque Atual: %d\n", estoque_atual);
        printf("-----------------------------------\n");
        printf("1. Adicionar Itens\n");
        printf("2. Remover Itens\n");
        printf("0. Sair e Fechar Sistema\n");
        printf("Escolha uma opcao: ");
        
        // Verifica se a leitura da opcao e bem-sucedida
        if (scanf("%d", &opcao) != 1) {
            printf("\nERRO: Entrada invalida. Tente novamente.\n");
            // Limpa o buffer
            while (getchar() != '\n'); 
            continue; // Pula para a proxima iteracao
        }

        // 2. SWITCH para processar a opcao
        switch (opcao) {
            case 1:
                // Adicionar Itens
                printf("Quantos itens deseja ADICIONAR? ");
                if (scanf("%d", &quantidade) == 1 && quantidade > 0) {
                    estoque_atual += quantidade; // Incrementa o estoque
                    printf(">> %d itens adicionados. Novo estoque: %d.\n", quantidade, estoque_atual);
                } else {
                    printf(">> Quantidade invalida. Deve ser um numero positivo.\n");
                    while (getchar() != '\n');
                }
                break;

            case 2:
                // Remover Itens
                printf("Quantos itens deseja REMOVER? ");
                if (scanf("%d", &quantidade) == 1 && quantidade > 0) {
                    // Verifica se ha estoque suficiente
                    if (estoque_atual >= quantidade) {
                        estoque_atual -= quantidade; // Decrementa o estoque
                        printf(">> %d itens removidos. Novo estoque: %d.\n", quantidade, estoque_atual);
                    } else {
                        printf(">> ERRO: Nao ha estoque suficiente para remover %d itens. Maximo disponivel: %d.\n", quantidade, estoque_atual);
                    }
                } else {
                    printf(">> Quantidade invalida. Deve ser um numero positivo.\n");
                    while (getchar() != '\n');
                }
                break;

            case 0:
                // Sair
                printf("\nFechando o sistema de controle de estoque. Estoque final: %d.\n", estoque_atual);
                break;

            default:
                // Opcao Invalida
                printf(">> Opcao invalida. Por favor, escolha 1, 2 ou 0.\n");
                break;
        }

    } while (opcao != 0); // O loop continua enquanto a opcao nao for '0' (Sair)

    return 0;
}