#include <stdio.h>
#include <math.h> // Para a classificacao da potencia, vamos supor uma tensao padrao

// Tensao Padrao Assumida para o Calculo da Potencia (P = V^2 / Req)
#define TENSAO_PADRAO 12.0 // Volts

int main() {
    double r1, r2, r3;
    char tipo_ligacao;
    double req; // Resistencia Equivalente
    double potencia_total;

    printf("--- Analise de Resistores (Serie/Paralelo) ---\n");

    // 1. Leitura dos Valores de Resistencia (em Ohms)
    printf("Digite o valor do Resistor R1 (Ohms): ");
    if (scanf("%lf", &r1) != 1 || r1 <= 0) return 1;

    printf("Digite o valor do Resistor R2 (Ohms): ");
    if (scanf("%lf", &r2) != 1 || r2 <= 0) return 1;

    printf("Digite o valor do Resistor R3 (Ohms): ");
    if (scanf("%lf", &r3) != 1 || r3 <= 0) return 1;

    // 2. Leitura do Tipo de Ligacao
    printf("Digite o tipo de ligacao (S para Serie / P para Paralelo): ");
    scanf(" %c", &tipo_ligacao); // Espaco antes de %c para ignorar espacos/quebras de linha

    printf("\n--- Resultados do Circuito ---\n");
    
    // 3. Calculo da Resistencia Equivalente (Req)
    if (tipo_ligacao == 'S' || tipo_ligacao == 's') {
        // Ligacao em Serie: Req = R1 + R2 + R3
        req = r1 + r2 + r3;
        printf("Tipo de Ligacao: Serie (Req = R1 + R2 + R3)\n");
    } else if (tipo_ligacao == 'P' || tipo_ligacao == 'p') {
        // Ligacao em Paralelo: 1/Req = 1/R1 + 1/R2 + 1/R3
        // Req = 1 / (1/R1 + 1/R2 + 1/R3)
        // O codigo ja validou que R1, R2, R3 > 0, entao nao ha divisao por zero
        req = 1.0 / ((1.0 / r1) + (1.0 / r2) + (1.0 / r3));
        printf("Tipo de Ligacao: Paralelo (1/Req = 1/R1 + 1/R2 + 1/R3)\n");
    } else {
        printf("ERRO: Tipo de ligacao invalido. Use 'S' ou 'P'.\n");
        return 1;
    }

    printf("Resistencia Equivalente (Req): %.4lf Ohms\n", req);

    // 4. Classificacao da Potencia (P = V^2 / Req)
    
    // Calcula a potencia total com base na tensao padrao assumida
    potencia_total = pow(TENSAO_PADRAO, 2.0) / req;

    printf("Potencia Total Dissipada (Assumindo V=%.1lfV): %.4lf Watts\n", TENSAO_PADRAO, potencia_total);
    
    printf("\nCLASSIFICACAO DE POTENCIA (Hipotetica): ");
    
    if (potencia_total > 50.0) {
        printf("Alta Potencia (Circuito exige dissipacao significativa) ⚡\n");
    } else if (potencia_total >= 10.0) {
        printf("Media Potencia (Circuito padrao) 🔋\n");
    } else {
        printf("Baixa Potencia (Circuito de baixa dissipacao) 📉\n");
    }

    return 0;
}