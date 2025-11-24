#include <stdio.h>
#include <math.h>

int main() {
    double raio;
    double volume;

    printf("--- Calculo do Volume da Esfera ---\n");

    // 1. Leitura do Raio
    printf("Digite o raio da esfera: ");
    if (scanf("%lf", &raio) != 1) {
        printf("Erro: Entrada invalida. Por favor, digite um numero.\n");
        return 1;
    }

    // 2. Verificacao: O Raio deve ser Positivo
    if (raio > 0) {
        
        // 3. Calculo do Volume: V = (4/3) * pi * r^3
        // pow(raio, 3.0) calcula r³
        // Usamos 4.0/3.0 para garantir que a divisao seja feita em ponto flutuante
        volume = (4.0 / 3.0) * M_PI * pow(raio, 3.0);
        
        printf("\n✅ Calculo Concluido:\n");
        printf("Raio (r): %.2lf\n", raio);
        printf("Constante Pi (M_PI): %.10lf\n", M_PI);
        printf("Volume da Esfera: %.4lf\n", volume);
        
    } else {
        // Mensagem de erro se o raio nao for positivo
        printf("\nERRO: O raio deve ser um valor positivo para calcular o volume.\n");
        return 1; // Retorna codigo de erro
    }

    return 0; // Sucesso
}