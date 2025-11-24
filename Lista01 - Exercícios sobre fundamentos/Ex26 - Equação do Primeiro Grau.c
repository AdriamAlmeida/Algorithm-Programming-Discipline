#include <stdio.h>

int main() {
    // Declaração das variáveis. Usamos float para lidar com coeficientes e resultados decimais.
    float a;
    float b;
    float x;

    // --- Leitura dos Coeficientes ---

    // 1. Solicita e lê o coeficiente 'a'
    printf("Para a equacao ax + b = 0:\n");
    printf("Digite o coeficiente 'a': ");
    scanf("%f", &a);

    // 2. Solicita e lê o coeficiente 'b'
    printf("Digite o coeficiente 'b': ");
    scanf("%f", &b);

    // --- Processamento e Verificação ---

    /* Uma equação do primeiro grau tem a forma ax + b = 0.
     * O cálculo para 'x' é: x = -b / a
     * A solução só é possível e única se 'a' for diferente de zero.
     */
    if (a != 0) {
        // Cálculo do valor de x
        x = -b / a;

        // --- Saída do Resultado ---
        printf("\n--- Solucao da Equacao ---\n");
        printf("Equacao: (%.2f)x + (%.2f) = 0\n", a, b);
        printf("O valor de x e: x = %.2f\n", x);
        
    } else {
        // Casos em que 'a' é igual a zero
        printf("\n--- Analise da Equacao ---\n");
        printf("O coeficiente 'a' e zero (a = 0).\n");

        if (b == 0) {
            // Se 0x + 0 = 0, a solução é qualquer número real
            printf("A equacao e 0x + 0 = 0. Ela possui infinitas solucoes (qualquer x satisfaz).\n");
        } else {
            // Se 0x + b = 0 (com b != 0), a solução é impossível
            printf("A equacao e 0x + (%.2f) = 0. Ela nao possui solucao (impossivel).\n", b);
        }
    }

    return 0;
}