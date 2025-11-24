#include <stdio.h>

int main() {
    int altura; // Altura de meio losango
    int i, j;   // Variaveis de controle para os loops

    printf("--- Gerador de Losango de Asteriscos ---\n");
    printf("Digite a altura de MEIO losango (ex: 5): ");
    
    // 1. Entrada de dados
    // Pedimos um numero impar para melhor simetria, mas o codigo funciona para qualquer inteiro positivo.
    if (scanf("%d", &altura) != 1 || altura <= 0) {
        printf("Altura invalida. Deve ser um numero inteiro positivo.\n");
        return 1;
    }

    printf("\n");

    // ===============================================
    // 2. PARTE SUPERIOR (Incluindo a linha central)
    // ===============================================
    for (i = 1; i <= altura; i++) {
        
        // LACO 1: Desenha os ESPACOS (Para alinhamento)
        // O numero de espacos diminui a cada linha
        for (j = 1; j <= altura - i; j++) {
            printf(" ");
        }

        // LACO 2: Desenha os ASTERISCOS
        // O numero de asteriscos e 2*i - 1
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n"); // Nova linha
    }

    // ===============================================
    // 3. PARTE INFERIOR (Excluindo a linha central)
    // ===============================================
    for (i = altura - 1; i >= 1; i--) {
        
        // LACO 3: Desenha os ESPACOS (Para alinhamento)
        // O numero de espacos aumenta a cada linha
        for (j = 1; j <= altura - i; j++) {
            printf(" ");
        }

        // LACO 4: Desenha os ASTERISCOS
        // O numero de asteriscos e 2*i - 1
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        printf("\n"); // Nova linha
    }

    return 0;
}