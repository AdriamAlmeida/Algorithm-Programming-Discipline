#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Tamanho máximo que a matriz pode ter (N)

// Protótipos das funções
void preencher_matriz_caracol(int N, int matriz[MAX_SIZE][MAX_SIZE]);
void exibir_matriz(int N, int matriz[MAX_SIZE][MAX_SIZE]);

int main() {
    int N;
    int matriz[MAX_SIZE][MAX_SIZE];

    printf("======================================\n");
    printf("     🌀 PREENCHIMENTO MATRIZ CARACOL     \n");
    printf("======================================\n");

    // 1. Leitura do Tamanho N
    printf("Digite o tamanho N da matriz (N x N, máx. %d): ", MAX_SIZE);
    if (scanf("%d", &N) != 1 || N <= 0 || N > MAX_SIZE) {
        printf("❌ Erro: Tamanho inválido. Deve ser entre 1 e %d.\n", MAX_SIZE);
        return 1;
    }

    // 2. Preenche a matriz
    preencher_matriz_caracol(N, matriz);

    // 3. Exibe o resultado
    printf("\n✅ Matriz %d x %d preenchida em formato caracol:\n", N, N);
    exibir_matriz(N, matriz);

    return 0;
}

// --- Função Principal: Preenche a matriz em espiral ---
void preencher_matriz_caracol(int N, int matriz[MAX_SIZE][MAX_SIZE]) {
    int valor = 1; // O primeiro valor a ser inserido
    
    // Variáveis que definem os limites do preenchimento
    int linha_inicio = 0;
    int linha_fim = N - 1;
    int coluna_inicio = 0;
    int coluna_fim = N - 1;

    // O loop principal continua enquanto houver espaço para preencher
    // (enquanto os limites de início não cruzarem os limites de fim)
    while (linha_inicio <= linha_fim && coluna_inicio <= coluna_fim) {
        
        // 1. Preencher da Esquerda para a Direita (Linha Superior)
        // Laço FOR para a linha atual (linha_inicio)
        for (int j = coluna_inicio; j <= coluna_fim; j++) {
            matriz[linha_inicio][j] = valor++;
        }
        linha_inicio++; // Ajusta o limite superior para baixo
        
        if (linha_inicio > linha_fim) break; // Checa se a matriz foi totalmente preenchida

        // 2. Preencher de Cima para Baixo (Coluna Direita)
        // Laço FOR para a coluna atual (coluna_fim)
        for (int i = linha_inicio; i <= linha_fim; i++) {
            matriz[i][coluna_fim] = valor++;
        }
        coluna_fim--; // Ajusta o limite direito para a esquerda
        
        if (coluna_inicio > coluna_fim) break; // Checa se a matriz foi totalmente preenchida

        // 3. Preencher da Direita para a Esquerda (Linha Inferior)
        // Laço FOR para a linha atual (linha_fim)
        for (int j = coluna_fim; j >= coluna_inicio; j--) {
            matriz[linha_fim][j] = valor++;
        }
        linha_fim--; // Ajusta o limite inferior para cima

        // 4. Preencher de Baixo para Cima (Coluna Esquerda)
        // Laço FOR para a coluna atual (coluna_inicio)
        for (int i = linha_fim; i >= linha_inicio; i--) {
            matriz[i][coluna_inicio] = valor++;
        }
        coluna_inicio++; // Ajusta o limite esquerdo para a direita
    }
}

// --- Função Auxiliar: Exibe a matriz formatada ---
void exibir_matriz(int N, int matriz[MAX_SIZE][MAX_SIZE]) {
    printf("\n");
    
    // Laço FOR aninhado para exibição
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Usa %4d para formatar com largura 4, garantindo alinhamento visual
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}