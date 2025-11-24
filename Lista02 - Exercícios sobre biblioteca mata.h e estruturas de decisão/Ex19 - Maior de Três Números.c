#include <stdio.h>

int main() {
    double num1, num2, num3;

    printf("--- Maior de Tres Numeros (Aninhado) ---\n");

    // 1. Leitura dos Tres Numeros
    printf("Digite o primeiro numero: ");
    if (scanf("%lf", &num1) != 1) return 1;

    printf("Digite o segundo numero: ");
    if (scanf("%lf", &num2) != 1) return 1;

    printf("Digite o terceiro numero: ");
    if (scanf("%lf", &num3) != 1) return 1;

    printf("\nNumeros lidos: %.2lf, %.2lf, %.2lf\n", num1, num2, num3);

    // 2. Estruturas de Decisao Aninhadas para Encontrar o Maior
    
    // Supondo que num1 seja o maior
    if (num1 >= num2) { 
        // Se num1 for maior ou igual a num2, ele ainda pode ser o maior.
        // Agora, comparamos num1 com num3.
        
        if (num1 >= num3) {
            // Se num1 for maior ou igual a num3, num1 é o maior de todos.
            printf("O maior numero e: %.2lf\n", num1);
        } else {
            // Se num1 for maior ou igual a num2, mas MENOR que num3, entao num3 e o maior.
            printf("O maior numero e: %.2lf\n", num3);
        }
    } 
    // Se a primeira condicao (num1 >= num2) for FALSA, 
    // significa que num2 e estritamente maior que num1.
    else { 
        // Agora, comparamos num2 com num3.
        
        if (num2 >= num3) {
            // Se num2 for maior ou igual a num3 (e ja sabemos que num2 > num1), num2 e o maior.
            printf("O maior numero e: %.2lf\n", num2);
        } else {
            // Se num2 for maior que num1, mas MENOR que num3, entao num3 e o maior.
            printf("O maior numero e: %.2lf\n", num3);
        }
    }

    return 0;
}