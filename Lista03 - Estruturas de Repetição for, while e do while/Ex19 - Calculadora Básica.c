#include <stdio.h>

int main() {
    // Variáveis para armazenar os números, o resultado e a operação.
    double num1, num2, resultado;
    char operacao;

    printf("--- Calculadora Simples em C ---\n");

    // O loop 'do-while' garante que o programa execute pelo menos uma vez.
    do {
        // 1. Pede a operação ao usuário
        printf("\n");
        printf("Escolha a operacao (+, -, *, /) ou digite 'S' para Sair: ");
        scanf(" %c", &operacao); // O espaco antes de %c ajuda a ignorar o \n do enter anterior.

        // 2. Verifica a condicao de saida
        if (operacao == 'S' || operacao == 's') {
            printf("\nSaindo da calculadora. Ate mais!\n");
            // Usa 'break' para sair do loop imediatamente,
            // embora o 'while' tambem fizesse isso na proxima iteracao.
            break; 
        }

        // 3. Pede os dois operandos
        printf("Digite o primeiro numero: ");
        // Verifica se a leitura foi bem-sucedida
        if (scanf("%lf", &num1) != 1) {
            printf("Entrada invalida. Reiniciando...\n");
            // Limpa o buffer de entrada para evitar loop infinito
            while (getchar() != '\n'); 
            continue; // Pula para a proxima iteracao do loop
        }

        printf("Digite o segundo numero: ");
        if (scanf("%lf", &num2) != 1) {
            printf("Entrada invalida. Reiniciando...\n");
            while (getchar() != '\n');
            continue; 
        }

        // 4. Realiza o calculo e exibe o resultado
        switch (operacao) {
            case '+':
                resultado = num1 + num2;
                printf("Resultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case '-':
                resultado = num1 - num2;
                printf("Resultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case '*':
                resultado = num1 * num2;
                printf("Resultado: %.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
                break;
            case '/':
                // Trata a divisao por zero
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("Resultado: %.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
                } else {
                    printf("Erro: Divisao por zero nao e permitida!\n");
                }
                break;
            default:
                printf("Erro: Operacao '%c' invalida. Tente novamente.\n", operacao);
                break;
        }

    } while (1); // Condicao de loop infinito (true), saimos apenas com o 'break'

    return 0;
}