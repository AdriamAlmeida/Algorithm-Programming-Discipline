#include <stdio.h>

#define NUM_PRODUTOS 10
#define LIMITE_BAIXO 5
#define NUM_VENDAS 5

// Protótipos de funções
void inicializar_estoque(int estoque[], int tamanho);
void simular_vendas(int estoque[], int tamanho, int *total_vendido);
void exibir_relatorio(int estoque[], int tamanho, int total_vendido);

int main() {
    // Declaração do vetor de estoque para 10 produtos (índices de 0 a 9)
    int estoque[NUM_PRODUTOS];
    int total_vendido = 0;

    printf("=== CONTROLE DE ESTOQUE E VENDAS (10 PRODUTOS) ===\n\n");

    // 1. Inicializa o estoque com as quantidades informadas pelo usuário
    inicializar_estoque(estoque, NUM_PRODUTOS);

    // 2. Simula as 5 vendas
    simular_vendas(estoque, NUM_PRODUTOS, &total_vendido);

    // 3. Exibe o relatório final
    exibir_relatorio(estoque, NUM_PRODUTOS, total_vendido);

    return 0;
}

// Função para permitir que o usuário informe as quantidades iniciais
void inicializar_estoque(int estoque[], int tamanho) {
    printf("=== ESTOQUE INICIAL ===\n");
    for (int i = 0; i < tamanho; i++) {
        // O produto será chamado de Produto 1, Produto 2, ..., Produto 10
        // O índice i + 1 facilita a visualização para o usuário
        printf("Informe a quantidade inicial para o Produto %d: ", i + 1);
        // Garantir que a leitura seja bem-sucedida
        if (scanf("%d", &estoque[i]) != 1) {
            printf("Erro na leitura. Usando 0 como padrão.\n");
            estoque[i] = 0;
            // Limpar o buffer de entrada para evitar loops infinitos em erros de leitura
            while (getchar() != '\n');
        }
        if (estoque[i] < 0) {
            printf("Quantidade inválida. Usando 0 como padrão.\n");
            estoque[i] = 0;
        }
    }
    printf("\nEstoque inicial registrado com sucesso!\n\n");
}

// Função para simular 5 vendas e atualizar o estoque
void simular_vendas(int estoque[], int tamanho, int *total_vendido) {
    int produto_vendido; // Armazena o número do produto (1 a 10)
    int indice_produto;  // Armazena o índice do vetor (0 a 9)

    printf("=== SIMULAÇÃO DE %d VENDAS ===\n", NUM_VENDAS);
    for (int i = 0; i < NUM_VENDAS; i++) {
        printf("\nVENDA %d de %d\n", i + 1, NUM_VENDAS);
        
        do {
            printf("Qual produto foi vendido? (Digite o número de 1 a %d): ", tamanho);
            if (scanf("%d", &produto_vendido) != 1) {
                 printf("Entrada inválida. Tente novamente.\n");
                 while (getchar() != '\n'); // Limpar o buffer
                 produto_vendido = -1; // Forçar a repetição
                 continue;
            }

            // Mapeia o número do produto (1 a 10) para o índice do vetor (0 a 9)
            indice_produto = produto_vendido - 1;

            // Verifica se o produto é válido
            if (indice_produto < 0 || indice_produto >= tamanho) {
                printf("❌ Número de produto inválido. Por favor, digite um número entre 1 e %d.\n", tamanho);
            } 
            // Verifica se há estoque
            else if (estoque[indice_produto] <= 0) {
                printf("⚠️ O Produto %d está esgotado. Escolha outro produto.\n", produto_vendido);
            }
            
        } while (indice_produto < 0 || indice_produto >= tamanho || estoque[indice_produto] <= 0);

        // Atualiza o estoque e o total vendido
        estoque[indice_produto]--;
        (*total_vendido)++;

        printf("✅ Venda registrada! Produto %d: %d unidades restantes.\n", 
               produto_vendido, estoque[indice_produto]);
    }
    printf("\nSimulação de vendas concluída.\n");
}

// Função para exibir o relatório final de estoque e vendas
void exibir_relatorio(int estoque[], int tamanho, int total_vendido) {
    printf("\n--- RELATÓRIO FINAL ---\n");
    printf("========================\n");
    
    // Variáveis para construir as listas
    printf("Produtos esgotados (Estoque: 0): ");
    int zerados = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (estoque[i] == 0) {
            printf("Produto %d, ", i + 1);
            zerados++;
        }
    }
    if (zerados == 0) {
        printf("Nenhum");
    }
    printf("\n");

    // Produtos com estoque baixo
    printf("Produtos com estoque baixo (Estoque < %d): ", LIMITE_BAIXO);
    int baixos = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (estoque[i] > 0 && estoque[i] < LIMITE_BAIXO) {
            printf("Produto %d (%d), ", i + 1, estoque[i]);
            baixos++;
        }
    }
    if (baixos == 0) {
        printf("Nenhum");
    }
    printf("\n");

    // Total de produtos vendidos
    printf("\n💰 Total de produtos vendidos na simulação: **%d unidades**.\n", total_vendido);
    
    printf("\n--- ESTOQUE ATUAL COMPLETO ---\n");
    for (int i = 0; i < tamanho; i++) {
         printf("Produto %d: %d\n", i + 1, estoque[i]);
    }
}