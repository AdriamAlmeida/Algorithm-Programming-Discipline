#include <stdio.h>

int main() {
    int a, b;
    int resto; // Armazena o resto da divisao
    int num1, num2; // Copias dos numeros originais para impressao no final

    // 1. Solicita os dois números ao usuário
    printf("--- Calculo do MDC (Algoritmo de Euclides) ---\n");
    printf("Digite o primeiro numero (A): ");
    scanf("%d", &a);
    printf("Digite o segundo numero (B): ");
    scanf("%d", &b);

    // Salva os valores originais para exibi-los no resultado final
    num1 = a;
    num2 = b;

    // Garante que 'a' seja maior ou igual a 'b' (opcional, mas facilita o fluxo)
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // 2. Loop WHILE para aplicar o Algoritmo de Euclides
    // O loop continua enquanto 'b' (o divisor/resto anterior) nao for zero.
    while (b != 0) {
        // a) Calcula o resto da divisao de 'a' por 'b'
        resto = a % b;

        // b) Atualiza os valores:
        // O valor de 'b' se torna o novo 'a'
        a = b; 
        
        // O valor do 'resto' se torna o novo 'b'
        b = resto;
        
    } // O loop termina quando b for 0. O MDC sera o ultimo valor de 'a'.

    // 3. Exibe o resultado. O MDC e o ultimo valor armazenado em 'a'.
    printf("\nO MDC (Maximo Divisor Comum) entre %d e %d e: %d\n", num1, num2, a);

    return 0;
}