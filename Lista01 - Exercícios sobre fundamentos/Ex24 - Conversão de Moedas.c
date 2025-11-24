#include <stdio.h>

int main() {
    // Declaração das variáveis
    float valor_reais;
    float cotacao_dolar;
    float valor_dolares;

    // --- Leitura dos Dados ---

    // 1. Solicita e lê o valor em Reais (R$)
    printf("Digite o valor em Reais (R$): ");
    scanf("%f", &valor_reais);

    // 2. Solicita e lê a cotação do Dólar
    printf("Digite a cotacao atual do Dolar (ex: 5.20): ");
    scanf("%f", &cotacao_dolar);

    // --- Processamento ---

    /* * O cálculo é feito dividindo o valor em reais pela cotação do dólar.
     * Exemplo: R$ 500.00 / R$ 5.00/dólar = $ 100.00
     */
    valor_dolares = valor_reais / cotacao_dolar;

    // --- Saída do Resultado ---
    
    // Imprime o resultado formatado
    printf("\n--- Resultado da Conversão ---\n");
    printf("Valor em Reais: R$ %.2f\n", valor_reais);
    printf("Cotacao do Dolar: R$ %.2f\n", cotacao_dolar);
    printf("O valor correspondente em Dolares e: US$ %.2f\n", valor_dolares);

    return 0;
}