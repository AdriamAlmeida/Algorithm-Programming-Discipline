#include <stdio.h>

int main() {
    // Distâncias (km) e Tempos (horas) para os dois trechos
    float d1, t1; // Trecho 1: Distância e Tempo
    float d2, t2; // Trecho 2: Distância e Tempo

    // Velocidades médias
    float vm1;      // Velocidade Média do Trecho 1
    float vm2;      // Velocidade Média do Trecho 2
    float vm_total; // Velocidade Média Total

    // Variáveis para o cálculo total
    float d_total; // Distância total (d1 + d2)
    float t_total; // Tempo total (t1 + t2)

    // --- 1. Leitura dos Dados do Trecho 1 ---
    printf("--- Dados do Primeiro Trecho ---\n");
    printf("Digite a distancia percorrida no Trecho 1 (km): ");
    scanf("%f", &d1);
    printf("Digite o tempo gasto no Trecho 1 (horas): ");
    scanf("%f", &t1);

    // --- 2. Leitura dos Dados do Trecho 2 ---
    printf("\n--- Dados do Segundo Trecho ---\n");
    printf("Digite a distancia percorrida no Trecho 2 (km): ");
    scanf("%f", &d2);
    printf("Digite o tempo gasto no Trecho 2 (horas): ");
    scanf("%f", &t2);

    // --- 3. Processamento e Cálculo ---
    
    printf("\n--- Resultados ---\n");

    // a) Cálculo da Velocidade Média do Trecho 1
    if (t1 > 0) {
        vm1 = d1 / t1;
        printf("Velocidade Media do Trecho 1: %.2f km/h\n", vm1);
    } else {
        vm1 = 0; // Atribui 0 ou trata erro
        printf("Velocidade Media do Trecho 1: Tempo gasto deve ser maior que zero.\n");
    }

    // b) Cálculo da Velocidade Média do Trecho 2
    if (t2 > 0) {
        vm2 = d2 / t2;
        printf("Velocidade Media do Trecho 2: %.2f km/h\n", vm2);
    } else {
        vm2 = 0; // Atribui 0 ou trata erro
        printf("Velocidade Media do Trecho 2: Tempo gasto deve ser maior que zero.\n");
    }

    // c) Cálculo da Velocidade Média TOTAL
    
    // Distância Total
    d_total = d1 + d2;
    // Tempo Total
    t_total = t1 + t2;

    // A Velocidade Média Total é a Distância Total dividida pelo Tempo Total
    if (t_total > 0) {
        vm_total = d_total / t_total;
        printf("Distancia Total Percorrida: %.2f km\n", d_total);
        printf("Tempo Total Gasto: %.2f horas\n", t_total);
        printf("Velocidade Media TOTAL: %.2f km/h\n", vm_total);
    } else {
        printf("\n[ERRO] O tempo total gasto (T1 + T2) e zero. Impossivel calcular a velocidade media total.\n");
    }

    return 0;
}