#include <stdio.h>
#include <math.h>

/*
Calculadora Simples Leia dois números e uma operação (+, -, *, /). Execute a operação.
Para divisão, verifique se o divisor não é zero.
*/

int main() {
    double num1, num2, resultado;
    char operacao;

    printf("--- Calculadora Simples ---\n");
    
    // 1. Leitura dos números e da operação
    printf("Digite o primeiro numero: ");
    scanf("%lf", &num1);

    printf("Digite a operacao (+, -, *, /): ");
    // O espaco antes de %c é importante para ignorar qualquer espaco ou quebra de linha pendente
    scanf(" %c", &operacao); 

    printf("Digite o segundo numero: ");
    scanf("%lf", &num2);

    // 2. Execução da Operação usando 'switch'
    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            printf("\nResultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
            break;

        case '-':
            resultado = num1 - num2;
            printf("\nResultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
            break;

        case '*':
            resultado = num1 * num2;
            printf("\nResultado: %.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
            break;

        case '/':
            // 3. Verificação de Divisão por Zero
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("\nResultado: %.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
            } else {
                printf("\nErro: Divisao por zero nao e permitida!\n");
                return 1; // Indica um erro
            }
            break;

        default:
            printf("\nErro: Operacao invalida! Use apenas +, -, *, ou /.\n");
            return 1; // Indica um erro
    }

    return 0;
}