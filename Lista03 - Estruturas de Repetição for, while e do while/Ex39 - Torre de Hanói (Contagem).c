#include <stdio.h>

int main() {
    int N; // Numero de discos
    // Usamos 'long long' pois o numero de movimentos cresce muito rapidamente
    long long movimentos = 1; 

    printf("--- Calculo de Movimentos da Torre de Hanoi ---\n");
    printf("Digite o numero de discos (N): ");
    
    // 1. Entrada de dados
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Entrada invalida. O numero de discos deve ser um inteiro positivo.\n");
        return 1;
    }

    // 2. Trata o caso N=0
    if (N == 0) {
        movimentos = 0;
    } else {
        // 3. Loop FOR para calcular 2^N
        // Comecamos o 'movimentos' em 1 e multiplicamos por 2, N vezes
        // Isso e equivalente a 2^(N-1), entao o calculo final sera:
        // 2 * (2^(N-1)) - 1 = 2^N - 1.

        // Uma forma mais direta de calcular 2^N:
        // Resetamos movimentos para 1, e multiplicamos por 2, N vezes.
        movimentos = 1;
        for (int i = 0; i < N; i++) {
            movimentos *= 2; // movimentos = movimentos * 2
        }
        
        // 4. Aplica a formula: 2^N - 1
        movimentos -= 1; 
    }

    // 5. Exibe o resultado
    printf("\nPara %d discos, o numero minimo de movimentos e:\n", N);
    printf("M = 2^%d - 1 = %lld\n", N, movimentos);

    return 0;
}