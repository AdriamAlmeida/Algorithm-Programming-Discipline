#include <stdio.h>
#include <limits.h> // Para INT_MIN

// Constantes
#define NUM_JOGADORES 8

// Protótipos de funções
void ler_pontuacoes(int pontuacoes[]);
void ordenar_ranking(int pontuacoes[], int jogadores[]);
void exibir_ranking(int pontuacoes[], int jogadores[]);

int main() {
    // Vetores principais
    int pontuacoes[NUM_JOGADORES];
    
    // Vetor Paralelo: Armazena o numero original do jogador (1, 2, ..., 8)
    int jogadores[NUM_JOGADORES];
    for(int i = 0; i < NUM_JOGADORES; i++) {
        jogadores[i] = i + 1;
    }

    // 1. Coleta das pontuações
    ler_pontuacoes(pontuacoes);

    // 2. Ordenação do vetor de pontuações e do vetor de jogadores em paralelo
    // Ordem decrescente (do maior para o menor)
    ordenar_ranking(pontuacoes, jogadores);

    // 3. Exibição do ranking, pódium e calculo de diferença
    exibir_ranking(pontuacoes, jogadores);

    return 0;
}

/**
 * @brief Permite que o usuário insira as pontuações para cada jogador.
 * @param pontuacoes O vetor onde as pontuações serão armazenadas.
 */
void ler_pontuacoes(int pontuacoes[]) {
    printf("=== CADASTRO DE PONTUACOES (8 JOGADORES) ===\n");
    for (int i = 0; i < NUM_JOGADORES; i++) {
        printf("Pontuacao do Jogador %d: ", i + 1);
        
        int pontuacao_lida;
        if (scanf("%d", &pontuacao_lida) != 1 || pontuacao_lida < 0) {
             printf("Entrada invalida. Usando 0.\n");
             pontuacao_lida = 0;
             while (getchar() != '\n'); 
        }
        pontuacoes[i] = pontuacao_lida;
    }
}

/**
 * @brief Ordena o vetor de pontuações em ordem decrescente usando Bubble Sort,
 * e realiza as mesmas trocas no vetor de identificacao dos jogadores.
 * @param pontuacoes Vetor de pontuações (principal).
 * @param jogadores Vetor paralelo de identificação.
 */
void ordenar_ranking(int pontuacoes[], int jogadores[]) {
    int i, j;
    int temp_pontuacao; // Variavel temporaria para pontuacao
    int temp_jogador;   // Variavel temporaria para o ID do jogador

    // Bubble Sort: Repete o processo ate que nao haja mais trocas
    for (i = 0; i < NUM_JOGADORES - 1; i++) {
        for (j = 0; j < NUM_JOGADORES - 1 - i; j++) {
            // Se a pontuacao atual for MENOR que a proxima (Ordem Decrescente)
            if (pontuacoes[j] < pontuacoes[j + 1]) {
                
                // 1. Troca as PONTUAÇÕES
                temp_pontuacao = pontuacoes[j];
                pontuacoes[j] = pontuacoes[j + 1];
                pontuacoes[j + 1] = temp_pontuacao;
                
                // 2. Troca os IDS dos JOGADORES EM PARALELO
                // ESSENCIAL para manter a identificacao correta
                temp_jogador = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp_jogador;
            }
        }
    }
}

/**
 * @brief Exibe o ranking completo, pódium e a diferença de pontos.
 * @param pontuacoes Vetor de pontuações (ordenado).
 * @param jogadores Vetor de identificação (ordenado em paralelo).
 */
void exibir_ranking(int pontuacoes[], int jogadores[]) {
    printf("\n\n=== RANKING FINAL DE PONTUACOES ===\n");
    printf("------------------------------------\n");

    // Exibe a tabela de ranking
    for (int i = 0; i < NUM_JOGADORES; i++) {
        
        // Exibe o pódium com emojis
        if (i == 0) {
            printf("🥇 1o lugar: ");
        } else if (i == 1) {
            printf("🥈 2o lugar: ");
        } else if (i == 2) {
            printf("🥉 3o lugar: ");
        } else {
            printf("%2do lugar: ", i + 1); // Alinha os outros lugares
        }
        
        printf("Jogador %d - %d pontos\n", jogadores[i], pontuacoes[i]);
    }
    printf("------------------------------------\n");
    
    // Calcula e exibe a diferença entre o 1o e o ultimo (indice 0 e NUM_JOGADORES - 1)
    int diferenca = pontuacoes[0] - pontuacoes[NUM_JOGADORES - 1];
    printf("Diferenca 1o-Ultimo: %d pontos\n", diferenca);
    printf("====================================\n");
}