#include <stdio.h>

int main() {
    int N; // Dimensao N x N (numero de linhas e colunas)
    int i, j; // Variaveis de controle dos loops

    printf("--- Gerador de Padrao Xadrez (NxN) ---\n");
    printf("Digite a dimensao N (ex: 8 para um tabuleiro 8x8): ");
    
    // 1. Entrada de dados
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Dimensao invalida. Deve ser um numero inteiro positivo.\n");
        return 1;
    }

    printf("\n");

    // 2. LACO EXTERNO: Controla as LINHAS (i)
    for (i = 0; i < N; i++) {
        
        // 3. LACO INTERNO: Controla as COLUNAS (j)
        for (j = 0; j < N; j++) {
            
            // 4. Teste de Alternancia
            // Verifica se a soma da linha (i) e da coluna (j) e par.
            // (i + j) % 2 == 0 significa que a soma e PAR.
            if ((i + j) % 2 == 0) {
                printf("* "); // Imprime o primeiro caractere (com um espaco para formatacao)
            } else {
                printf("  "); // Imprime o segundo caractere (dois espacos para formatacao)
            }
            
        } // Fim do laco de coluna (j)

        // 5. Quebra de Linha
        printf("\n");
        
    } // Fim do laco de linha (i)

    return 0;
}