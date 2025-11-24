#include <stdio.h>
#include <math.h>

/*
Potência Condicional Leia base e expoente. Se a base for 0 e expoente ≤0, exiba erro.
Senão, calcule usando pow().
*/

int main() {
    double base;
    double expoente;
    double resultado;

    printf("--- Calculo de Potencia ---\n");
    
    // Leitura da Base
    printf("Digite a base: ");
    if (scanf("%lf", &base) != 1) {
        printf("Erro na leitura da base.\n");
        return 1;
    }

    // Leitura do Expoente
    printf("Digite o expoente: ");
    if (scanf("%lf", &expoente) != 1) {
        printf("Erro na leitura do expoente.\n");
        return 1;
    }

    // Verificacao da Condicao de Erro
    // Base = 0 E Expoente <= 0
    if (base == 0 && expoente <= 0) {
        printf("\nERRO: Operacao indefinida. Base 0 com expoente menor ou igual a zero (0^n, n <= 0) nao e permitida.\n");
        return 1; // Retorna codigo de erro
    } else {
        // Calculo da Potencia
        // A funcao pow(base, expoente) esta em <math.h>
        resultado = pow(base, expoente);

        printf("\nCalculo: %.2lf ^ %.2lf = %.4lf\n", base, expoente, resultado);
    }

    return 0; // Sucesso
}