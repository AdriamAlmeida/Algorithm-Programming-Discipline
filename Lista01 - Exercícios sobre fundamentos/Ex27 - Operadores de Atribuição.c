#include <stdio.h>

int main() {
    // Declaração das variáveis. Usamos float para resultados mais precisos.
    float num1_inicial; // Armazena o valor original de num1
    float num1;         // Variável que será modificada pelos operadores
    float num2;

    // --- Leitura dos Dados ---
    printf("Digite o primeiro numero (Num1): ");
    scanf("%f", &num1_inicial);

    printf("Digite o segundo numero (Num2): ");
    scanf("%f", &num2);

    // Inicializa a variável num1 com o valor original lido
    num1 = num1_inicial;

    // --- Demonstração dos Operadores ---
    printf("\n--- Demonstracao com Num1 = %.2f e Num2 = %.2f ---\n", num1_inicial, num2);

    // 1. Operador de Atribuição de Adição (+=)
    // Equivalente a: num1 = num1 + num2;
    num1 += num2;
    printf("1. Num1 += Num2 (Adicao): O novo Num1 e %.2f\n", num1);

    // Restaura Num1 ao valor inicial para a proxima operacao
    num1 = num1_inicial; 

    // 2. Operador de Atribuição de Subtração (-=)
    // Equivalente a: num1 = num1 - num2;
    num1 -= num2;
    printf("2. Num1 -= Num2 (Subtracao): O novo Num1 e %.2f\n", num1);

    // Restaura Num1 ao valor inicial para a proxima operacao
    num1 = num1_inicial; 

    // 3. Operador de Atribuição de Multiplicação (*=)
    // Equivalente a: num1 = num1 * num2;
    num1 *= num2;
    printf("3. Num1 *= Num2 (Multiplicacao): O novo Num1 e %.2f\n", num1);

    // Restaura Num1 ao valor inicial para a proxima operacao
    num1 = num1_inicial; 

    // 4. Operador de Atribuição de Divisão (/=)
    // É crucial verificar se Num2 não é zero antes da divisão
    if (num2 != 0) {
        // Equivalente a: num1 = num1 / num2;
        num1 /= num2;
        printf("4. Num1 /= Num2 (Divisao): O novo Num1 e %.2f\n", num1);
    } else {
        printf("4. Num1 /= Num2 (Divisao): Impossivel dividir, pois Num2 e zero.\n");
    }

    return 0;
}