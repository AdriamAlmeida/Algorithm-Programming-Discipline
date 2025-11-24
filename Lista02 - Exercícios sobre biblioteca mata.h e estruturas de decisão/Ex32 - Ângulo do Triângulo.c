#include <stdio.h>

int main() {
    int a1, a2, a3;
    int soma;

    printf("--- Classificacao de Triangulos por Angulos ---\n");

    // 1. Leitura dos Tres Angulos
    printf("Digite o primeiro angulo: ");
    if (scanf("%d", &a1) != 1 || a1 <= 0) {
        printf("Erro: Angulo invalido.\n");
        return 1;
    }

    printf("Digite o segundo angulo: ");
    if (scanf("%d", &a2) != 1 || a2 <= 0) {
        printf("Erro: Angulo invalido.\n");
        return 1;
    }

    printf("Digite o terceiro angulo: ");
    if (scanf("%d", &a3) != 1 || a3 <= 0) {
        printf("Erro: Angulo invalido.\n");
        return 1;
    }

    // 2. Verificacao da Soma dos Angulos
    soma = a1 + a2 + a3;

    if (soma != 180) {
        // Se a soma nao for 180, os angulos nao formam um triangulo.
        printf("\nRESULTADO: Nao e um triangulo valido.\n");
        printf("A soma dos angulos e %d, deveria ser 180.\n", soma);
    } else {
        // Se a soma for 180, classifique o triangulo:

        printf("\nRESULTADO: E um triangulo valido (Soma = 180).\n");

        if (a1 == 90 || a2 == 90 || a3 == 90) {
            // Se algum angulo for 90 graus
            printf("CLASSIFICACAO: Triangulo Retangulo (Possui um angulo de 90 graus).\n");
        } else if (a1 > 90 || a2 > 90 || a3 > 90) {
            // Se algum angulo for maior que 90 graus
            printf("CLASSIFICACAO: Triangulo Obtusangulo (Possui um angulo maior que 90 graus).\n");
        } else {
            // Se nenhum for maior ou igual a 90, todos sao menores que 90
            printf("CLASSIFICACAO: Triangulo Acutangulo (Todos os angulos sao menores que 90 graus).\n");
        }
    }

    return 0;
}