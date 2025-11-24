#include <stdio.h>

int main() {
    int N; 
    int passos = 0; // Contador de passos

    printf("--- Gerador de Sequencia de Collatz ---\n");
    printf("Digite um numero inteiro positivo (N): ");
    
    // 1. Entrada de dados
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Entrada invalida. Deve ser um numero inteiro positivo.\n");
        return 1;
    }

    printf("\nSequencia de Collatz para %d:\n", N);
    
    // Armazenar o numero atual da sequencia em uma variavel separada
    int numero_atual = N; 

    // 2. Loop WHILE: Continua ENQUANTO o numero atual nao for 1
    while (numero_atual != 1) {
        
        // Imprime o numero atual, seguido de uma seta (se nao for o primeiro)
        if (passos > 0) {
            printf(" -> ");
        }
        printf("%d", numero_atual);
        
        // 3. Incrementa o contador de passos
        passos++; 

        // 4. Aplica a Regra de Collatz
        if (numero_atual % 2 == 0) {
            // Regra PAR: divide por 2
            numero_atual = numero_atual / 2;
        } else {
            // Regra IMPAR: 3N + 1
            // Use (long long) para evitar overflow, pois 3N+1 pode crescer rapidamente
            // Dependendo do ambiente, podemos simplificar para int se N for pequeno
            numero_atual = (3 * numero_atual) + 1;
        }
        
    } // O loop termina quando numero_atual e 1

    // 5. Imprime o termo final (1) e o total de passos
    if (passos > 0) {
        printf(" -> ");
    }
    printf("1\n");
    printf("\nA sequencia chegou a 1 em %d passos.\n", passos);

    return 0;
}