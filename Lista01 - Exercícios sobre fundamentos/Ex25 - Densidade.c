#include <stdio.h>

int main() {
    // Declaração das variáveis
    float massa_kg;
    float volume_m3;
    float densidade;

    // --- Leitura dos Dados ---

    // 1. Solicita e lê o valor da Massa em quilogramas (kg)
    printf("Digite a massa do objeto em quilogramas (kg): ");
    scanf("%f", &massa_kg);

    // 2. Solicita e lê o valor do Volume em metros cubicos (m³)
    printf("Digite o volume do objeto em metros cubicos (m³): ");
    scanf("%f", &volume_m3);

    // --- Processamento e Verificação ---

    /* O cálculo da densidade (d = m/v) só é válido se o volume não for zero.
     * Uma vez que a divisão por zero é indefinida e causaria um erro.
     */
    if (volume_m3 > 0) {
        // Cálculo da densidade
        densidade = massa_kg / volume_m3;

        // --- Saída do Resultado ---
        
        // Imprime o resultado formatado
        printf("\n--- Resultado do Calculo ---\n");
        printf("Massa (m): %.2f kg\n", massa_kg);
        printf("Volume (v): %.2f m³\n", volume_m3);
        printf("A Densidade (d = m/v) do objeto e: %.2f kg/m³\n", densidade);
    } else {
        // Mensagem de erro se o volume for zero ou negativo
        printf("\n[ERRO] O volume deve ser maior que zero para calcular a densidade.\n");
    }

    return 0;
}