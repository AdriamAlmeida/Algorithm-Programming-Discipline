#include <stdio.h>

int main() {
    int numero;
    // O tipo 'long long' é usado para o resultado, pois o fatorial cresce muito rapidamente
    // e o 'int' comum não aguentaria valores como 13! ou mais.
    long long fatorial = 1; 

    // 1. Solicita o número ao usuário
    printf("--- Calculo de Fatorial ---\n");
    printf("Digite um numero inteiro positivo para calcular o fatorial: ");
    scanf("%d", &numero);

    // 2. Trata casos especiais (números negativos e 0)
    if (numero < 0) {
        printf("Fatorial nao e definido para numeros negativos.\n");
    } else if (numero == 0) {
        printf("O fatorial de 0 e 1.\n");
    } else {
        // 3. Loop FOR para calcular o fatorial
        // A variável 'i' começa no 'numero' fornecido e vai diminuindo (i--)
        // até que 'i' seja igual a 1.
        for (int i = numero; i >= 1; i--) {
            // Multiplica o resultado parcial pelo valor atual de 'i'
            fatorial = fatorial * i;
        }

        // 4. Exibe o resultado
        printf("O fatorial de %d (!%d) e: %lld\n", numero, numero, fatorial);
    }

    return 0;
}