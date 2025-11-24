#include <stdio.h>

float adicao(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Erro: Divisao por zero!\n");
        return 0.0;
    }
}

int main() {
    int opcao;
    float n1, n2, resultado;

    do {
        printf("\n******************************************\n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Sair do programa\n");
        printf("******************************************\n");
        printf("Entre com sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 5) {
            printf("Saindo...\n");
            break; 
        }

        if (opcao >= 1 && opcao <= 4) {
            printf("Digite dois numeros: ");
            scanf("%f %f", &n1, &n2);

            switch(opcao) {
                case 1:
                    printf("Resultado: %.2f\n", adicao(n1, n2));
                    break;
                case 2:
                    printf("Resultado: %.2f\n", subtracao(n1, n2));
                    break;
                case 3:
                    printf("Resultado: %.2f\n", multiplicacao(n1, n2));
                    break;
                case 4:
                    resultado = divisao(n1, n2);
                    if(n2 != 0) printf("Resultado: %.2f\n", resultado);
                    break;
            }
        } else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}