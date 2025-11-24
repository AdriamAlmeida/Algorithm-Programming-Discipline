#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Requisito: Usar a biblioteca math.h (sqrt, pow)

// --- Constantes de Classificação ---
#define LIMITE_RAPIDO 100 // < 100ms
#define LIMITE_LENTO 500  // > 500ms
#define MAX_TEMPOS 100    // Limite máximo para o array de tempos

// --- Funções Auxiliares ---

// Função para calcular o Desvio Padrão
double calcularDesvioPadrao(double tempos[], int n, double media) {
    if (n <= 1) {
        return 0.0;
    }

    double soma_quadrados_diferencas = 0.0;
    
    // Requisito: Usar pow para (xi - media)^2
    for (int i = 0; i < n; i++) {
        soma_quadrados_diferencas += pow(tempos[i] - media, 2);
    }

    // Fórmula: sqrt( Σ(xi - média)² / N )
    // Requisito: Usar sqrt para a raiz quadrada
    return sqrt(soma_quadrados_diferencas / n);
}


// --- Função Principal ---

int main() {
    double tempos[MAX_TEMPOS]; // Array para armazenar os tempos (usado para o desvio padrão)
    int total_requisicoes = 0;
    double tempo_atual;
    
    double soma_tempos = 0.0;
    double tempo_min = -1.0; // Inicializado para facilitar a primeira comparação
    double tempo_max = -1.0;

    // Requisito: Usar contadores para cada categoria
    int rapidas = 0;      // < 100ms
    int aceitaveis = 0;   // 100ms - 500ms
    int lentas = 0;       // > 500ms

    printf("=== ANÁLISE DE PERFORMANCE DE API ===\n");
    printf("Digite os tempos de resposta em ms (valor negativo para parar):\n");

    // Requisito: Usar while para leitura contínua
    while (1) {
        printf("Tempo %d: ", total_requisicoes + 1);
        
        // Leitura do tempo de resposta
        if (scanf("%lf", &tempo_atual) != 1) {
            printf("\n Entrada inválida. Encerrando leitura.\n");
            // Limpa o buffer de entrada
            while(getchar() != '\n'); 
            break; 
        }

        // Requisito: Continue lendo até o usuário digitar um valor negativo
        if (tempo_atual < 0) {
            break;
        }

        // 1. Armazenar o tempo (para desvio padrão) e atualizar a soma total
        if (total_requisicoes < MAX_TEMPOS) {
            tempos[total_requisicoes] = tempo_atual;
        } else {
            // Se o limite do array for atingido, ainda processamos o tempo, mas não o armazenamos
            printf(" Limite de tempos para desvio padrão (%d) atingido. Continuando processamento...\n", MAX_TEMPOS);
        }
        
        soma_tempos += tempo_atual;

        // 2. Calcular Mínimo e Máximo
        if (tempo_min < 0 || tempo_atual < tempo_min) {
            tempo_min = tempo_atual;
        }
        if (tempo_max < 0 || tempo_atual > tempo_max) {
            tempo_max = tempo_atual;
        }

        // 3. Classificar o tempo e atualizar contadores
        // Requisito: Usar if-else aninhado para classificação
        if (tempo_atual < LIMITE_RAPIDO) { // < 100ms
            rapidas++;
        } else if (tempo_atual <= LIMITE_LENTO) { // 100ms - 500ms
            aceitaveis++;
        } else { // > 500ms
            lentas++;
        }
        
        total_requisicoes++;
        
        // Proteção contra estouro do array
        if (total_requisicoes >= MAX_TEMPOS) {
            // Para garantir que a leitura pare se o array de suporte encher.
            // Se não fosse para calcular desvio padrão, poderíamos continuar.
            printf("\n Limite de armazenamento atingido. Encerrando leitura.\n");
            break;
        }
    }

    printf("\n");
    // Verifica se houve alguma requisição válida
    if (total_requisicoes == 0) {
        printf("Nenhuma requisição válida foi inserida. Encerrando.\n");
        return 0;
    }

    // --- CÁLCULO E EXIBIÇÃO DO RELATÓRIO ---

    // Cálculo da Média
    double tempo_medio = soma_tempos / total_requisicoes;

    // Cálculo do Desvio Padrão
    double desvio_padrao = calcularDesvioPadrao(tempos, total_requisicoes, tempo_medio);

    // Cálculo dos Percentuais
    double perc_rapidas = ((double)rapidas / total_requisicoes) * 100.0;
    double perc_aceitaveis = ((double)aceitaveis / total_requisicoes) * 100.0;
    double perc_lentas = ((double)lentas / total_requisicoes) * 100.0;

    printf("=== RELATÓRIO DE PERFORMANCE ===\n");
    
    // Estatísticas Básicas
    printf("Estatísticas Básicas:\n");
    printf("- Total de requisições: %d\n", total_requisicoes);
    printf("- Tempo médio: %.2f ms\n", tempo_medio);
    printf("- Tempo mínimo: %.0f ms\n", tempo_min);
    printf("- Tempo máximo: %.0f ms\n", tempo_max);
    printf("- Desvio padrão: %.2f ms\n", desvio_padrao);

    printf("\nClassificação por Performance:\n");
    
    // Classificação por Categoria
    printf("- Rápidas (< %dms): %d requisições (%.1f%%)\n", LIMITE_RAPIDO, rapidas, perc_rapidas);
    printf("- Aceitáveis (%d-%dms): %d requisições (%.1f%%)\n", LIMITE_RAPIDO, LIMITE_LENTO, aceitaveis, perc_aceitaveis);
    printf("- Lentas (> %dms): %d requisições (%.1f%%)\n", LIMITE_LENTO, lentas, perc_lentas);

    // Requisito: Gerar alertas condicionais
    if (perc_lentas > 20.0) {
        printf("\n\n ALERTA: %.1f%% das requisições estão lentas!\n", perc_lentas);
        printf("Recomendação: Investigar otimizações no backend.\n");
    } else {
        printf("\n A performance da API está dentro dos limites aceitáveis.\n");
    }

    return 0;
}