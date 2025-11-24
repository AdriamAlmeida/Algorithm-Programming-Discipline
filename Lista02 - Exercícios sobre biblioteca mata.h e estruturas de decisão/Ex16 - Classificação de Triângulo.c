#include <stdio.h>
#include <stdbool.h>

int main() {
    double ladoA, ladoB, ladoC;
    bool e_triangulo;

    printf("--- Classificacao de Triangulos por Lados ---\n");

    // 1. Leitura dos Tres Lados
    printf("Digite o comprimento do Lado A: ");
    if (scanf("%lf", &ladoA) != 1 || ladoA <= 0) {
        printf("Erro: Lado invalido.\n");
        return 1;
    }

    printf("Digite o comprimento do Lado B: ");
    if (scanf("%lf", &ladoB) != 1 || ladoB <= 0) {
        printf("Erro: Lado invalido.\n");
        return 1;
    }

    printf("Digite o comprimento do Lado C: ");
    if (scanf("%lf", &ladoC) != 1 || ladoC <= 0) {
        printf("Erro: Lado invalido.\n");
        return 1;
    }

    // 2. Verificacao da Condicao de Existencia do Triangulo
    // A soma de dois lados quaisquer deve ser maior que o terceiro lado.
    e_triangulo = (ladoA + ladoB > ladoC) && 
                  (ladoA + ladoC > ladoB) && 
                  (ladoB + ladoC > ladoA);

    printf("\n--- Resultado ---\n");
    
    if (e_triangulo) {
        printf("RESULTADO: Os lados (%.2lf, %.2lf, %.2lf) formam um triangulo valido.\n", ladoA, ladoB, ladoC);

        // 3. Classificacao (Usando if-else if-else)
        if (ladoA == ladoB && ladoB == ladoC) {
            printf("CLASSIFICACAO: Triangulo Equilatero (Todos os lados iguais).\n");
        } else if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC) {
            printf("CLASSIFICACAO: Triangulo Isosceles (Apenas dois lados iguais).\n");
        } else {
            printf("CLASSIFICACAO: Triangulo Escaleno (Todos os lados diferentes).\n");
        }
    } else {
        printf("RESULTADO: Os lados (%.2lf, %.2lf, %.2lf) NAO formam um triangulo valido.\n", ladoA, ladoB, ladoC);
        printf("Motivo: A soma de dois lados deve ser maior que o terceiro lado.\n");
    }

    return 0;
}