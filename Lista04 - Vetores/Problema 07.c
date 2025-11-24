#include <stdio.h>
#include <string.h> // Para usar strings (nomes dos dias e turnos)
#include <float.h>  // Para usar FLT_MIN (menor valor float)

// Constantes
#define NUM_DIAS 7
#define NUM_TURNOS 3

// Nomes dos dias da semana
const char *nomes_dias[NUM_DIAS] = {
    "Segunda-feira", "Terca-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado", "Domingo"
};

// Nomes dos turnos
const char *nomes_turnos[NUM_TURNOS] = {
    "Manha", "Tarde", "Noite"
};

// Protótipos de funções
void ler_producao(int producao[][NUM_DIAS]);
void gerar_relatorio(int producao[][NUM_DIAS]);

int main() {
    // Declaração da matriz (ou 3 vetores combinados) para armazenar a produção:
    // producao[TURNO][DIA]
    // Turnos: 0=Manha, 1=Tarde, 2=Noite
    // Dias: 0=Segunda, 1=Terca, ..., 6=Domingo
    int producao[NUM_TURNOS][NUM_DIAS];

    // 1. Coleta dos dados de produção
    ler_producao(producao);

    // 2. Geração e exibição do relatório
    gerar_relatorio(producao);

    return 0;
}

/**
 * @brief Coleta a produção diária de cada um dos 3 turnos por 7 dias.
 * @param producao Matriz 3x7 para armazenar os dados.
 */
void ler_producao(int producao[][NUM_DIAS]) {
    printf("=== CADASTRO DE PRODUCAO SEMANAL ===\n");
    for (int j = 0; j < NUM_DIAS; j++) { // Loop pelos dias
        printf("\n--- %s ---\n", nomes_dias[j]);
        for (int i = 0; i < NUM_TURNOS; i++) { // Loop pelos turnos
            printf("Turno %s: ", nomes_turnos[i]);
            
            int valor_lido;
            if (scanf("%d", &valor_lido) != 1 || valor_lido < 0) {
                 printf("Entrada invalida. Usando 0.\n");
                 valor_lido = 0;
                 // Limpa o buffer de entrada
                 while (getchar() != '\n'); 
            }
            producao[i][j] = valor_lido;
        }
    }
}

/**
 * @brief Calcula e exibe todas as métricas solicitadas.
 * @param producao Matriz 3x7 com os dados de produção.
 */
void gerar_relatorio(int producao[][NUM_DIAS]) {
    // Variáveis para produção total
    long long producao_total_semana = 0;
    
    // Vetor para armazenar a soma da produção de cada turno
    long long producao_por_turno[NUM_TURNOS] = {0};
    
    // Vetor para armazenar a soma da produção de cada dia
    int producao_por_dia[NUM_DIAS] = {0}; 
    
    // --- 1. Cálculos de Somas Totais (Turno, Dia e Geral) ---
    for (int i = 0; i < NUM_TURNOS; i++) { // Loop pelos turnos
        for (int j = 0; j < NUM_DIAS; j++) { // Loop pelos dias
            int valor = producao[i][j];
            
            // Acumula total da semana
            producao_total_semana += valor;
            
            // Acumula total por turno
            producao_por_turno[i] += valor;
            
            // Acumula total por dia
            producao_por_dia[j] += valor;
        }
    }
    
    // --- 2. Encontrar o Turno Mais Produtivo ---
    long long maior_prod_turno = 0;
    int indice_turno_mais_produtivo = -1;
    for (int i = 0; i < NUM_TURNOS; i++) {
        if (producao_por_turno[i] > maior_prod_turno) {
            maior_prod_turno = producao_por_turno[i];
            indice_turno_mais_produtivo = i;
        }
    }
    float perc_turno_mais_produtivo = 0.0;
    if (producao_total_semana > 0) {
        perc_turno_mais_produtivo = (float)maior_prod_turno / producao_total_semana * 100.0;
    }

    // --- 3. Encontrar o Dia Mais Produtivo ---
    int maior_prod_dia = INT_MIN;
    int indice_dia_mais_produtivo = -1;
    for (int j = 0; j < NUM_DIAS; j++) {
        if (producao_por_dia[j] > maior_prod_dia) {
            maior_prod_dia = producao_por_dia[j];
            indice_dia_mais_produtivo = j;
        }
    }
    
    // --- 4. Contar Dias Abaixo do Limite (500) ---
    int dias_abaixo_limite = 0;
    for (int j = 0; j < NUM_DIAS; j++) {
        if (producao_por_dia[j] < 500) {
            dias_abaixo_limite++;
        }
    }

    // --- 5. Exibir Relatório ---
    printf("\n\n=== RELATORIO SEMANAL DE PRODUCAO ===\n");
    printf("======================================\n");
    printf("Producao total da semana: %lld pecas\n", producao_total_semana);
    printf("--------------------------------------\n");

    if (indice_turno_mais_produtivo != -1) {
        printf("Turno mais produtivo: %s (%lld pecas - %.1f%% do total)\n", 
               nomes_turnos[indice_turno_mais_produtivo], maior_prod_turno, perc_turno_mais_produtivo);
    } else {
        printf("Turno mais produtivo: N/A\n");
    }

    if (indice_dia_mais_produtivo != -1) {
        printf("Dia mais produtivo: %s (%d pecas)\n", 
               nomes_dias[indice_dia_mais_produtivo], maior_prod_dia);
    } else {
        printf("Dia mais produtivo: N/A\n");
    }
    
    printf("Dias em que a producao total foi menor que 500 pecas: %d dias\n", dias_abaixo_limite);
    printf("--------------------------------------\n");

    printf("### Media de Producao por Turno ###\n");
    for (int i = 0; i < NUM_TURNOS; i++) {
        float media = 0.0;
        if (NUM_DIAS > 0) {
            media = (float)producao_por_turno[i] / NUM_DIAS;
        }
        printf("%s: %.1f pecas/dia (Total: %lld)\n", nomes_turnos[i], media, producao_por_turno[i]);
    }
    
    printf("--------------------------------------\n");
    printf("### Percentual de Producao por Turno sobre o Total ###\n");
    for (int i = 0; i < NUM_TURNOS; i++) {
        float percentual = 0.0;
        if (producao_total_semana > 0) {
            percentual = (float)producao_por_turno[i] / producao_total_semana * 100.0;
        }
        printf("%s: %.1f%%\n", nomes_turnos[i], percentual);
    }
    printf("======================================\n");
}