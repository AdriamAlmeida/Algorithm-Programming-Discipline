#include <stdio.h>
#include <string.h>
#include <float.h> // Para usar FLT_MAX e FLT_MIN

// Constantes
#define NUM_CATEGORIAS 5
#define LIMITE_ALERTA 0.30 // 30%

// Categorias fixas (para simplificar a entrada de dados)
const char *categorias[NUM_CATEGORIAS] = {
    "Alimentacao", 
    "Transporte", 
    "Moradia", 
    "Lazer", 
    "Outros"
};

// Protótipos de funções
void ler_gastos(float gastos[], const char *nomes[], int tamanho);
void gerar_analise(float gastos[], const char *nomes[], int tamanho);

int main() {
    // Vetor para armazenar os gastos em Reais (R$)
    float gastos[NUM_CATEGORIAS];

    // 1. Coleta dos dados de gastos
    ler_gastos(gastos, categorias, NUM_CATEGORIAS);

    // 2. Análise e geração do relatório
    gerar_analise(gastos, categorias, NUM_CATEGORIAS);

    return 0;
}

/**
 * @brief Permite que o usuário insira o valor gasto em cada categoria.
 * @param gastos Vetor onde os valores gastos serão armazenados.
 * @param nomes Vetor com os nomes das categorias.
 * @param tamanho Número de categorias.
 */
void ler_gastos(float gastos[], const char *nomes[], int tamanho) {
    printf("=== CADASTRO DE GASTOS MENSAIS ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Gasto em %s (R$): ", nomes[i]);
        
        float valor_lido;
        if (scanf("%f", &valor_lido) != 1 || valor_lido < 0) {
             printf("Entrada invalida ou valor negativo. Usando R$0.00.\n");
             valor_lido = 0.0;
             // Limpa o buffer de entrada
             while (getchar() != '\n'); 
        }
        gastos[i] = valor_lido;
    }
}

/**
 * @brief Calcula métricas e exibe o relatório financeiro com alertas.
 * @param gastos Vetor com os valores gastos.
 * @param nomes Vetor com os nomes das categorias.
 * @param tamanho Número de categorias.
 */
void gerar_analise(float gastos[], const char *nomes[], int tamanho) {
    // Variáveis para cálculos
    float gasto_total = 0.0;
    
    // Variáveis para identificação de extremos
    float maior_gasto = FLT_MIN;
    int indice_maior = -1;
    float menor_gasto = FLT_MAX;
    int indice_menor = -1;

    // --- 1. Cálculo do Gasto Total e Identificação de Extremos ---
    for (int i = 0; i < tamanho; i++) {
        gasto_total += gastos[i];

        // Maior gasto
        if (gastos[i] > maior_gasto) {
            maior_gasto = gastos[i];
            indice_maior = i;
        }

        // Menor gasto (apenas para gastos > 0)
        if (gastos[i] < menor_gasto) {
            menor_gasto = gastos[i];
            indice_menor = i;
        }
    }
    
    // --- 2. Exibição do Relatório de Análise ---
    printf("\n\n=== ANALISE FINANCEIRA DO MES ===\n");
    printf("==================================\n");
    printf("GASTO TOTAL: R$ %.2f\n", gasto_total);
    printf("----------------------------------\n");

    printf("### Distribuicao por Categoria ###\n");
    
    // --- 3. Cálculo e Exibição do Percentual e Alerta ---
    int alerta_emitido = 0;
    
    if (gasto_total > 0) {
        for (int i = 0; i < tamanho; i++) {
            float percentual = (gastos[i] / gasto_total) * 100.0;
            printf("%s: R$ %.2f (%.1f%%)", nomes[i], gastos[i], percentual);
            
            // Verifica o ALERTA (se ultrapassou 30%)
            if ((gastos[i] / gasto_total) > LIMITE_ALERTA) {
                printf(" ❗ ALERTA: Gasto excessivo!");
                alerta_emitido = 1;
            }
            printf("\n");
        }
    } else {
        printf("Nenhum gasto registrado para analise.\n");
    }

    printf("----------------------------------\n");
    
    // Exibição dos Extremos
    if (indice_maior != -1) {
        printf("Maior Gasto: %s (R$ %.2f)\n", nomes[indice_maior], maior_gasto);
    }
    if (indice_menor != -1) {
        printf("Menor Gasto: %s (R$ %.2f)\n", nomes[indice_menor], menor_gasto);
    }
    printf("----------------------------------\n");

    // --- 4. Sugestão de Economia ---
    if (alerta_emitido) {
        printf("### DICAS DE ECONOMIA ###\n");
        printf("Sugestao: Considere reavaliar a(s) categoria(s) que ultrapassaram %.0f%% do total.\n", LIMITE_ALERTA * 100.0);
        
        printf("Para que a sua saude financeira melhore, o ideal e que NENHUM gasto represente mais de 25%%.\n");
        printf("Se Moradia, por exemplo, esta em 40%%, tente reduzir para 25%% nos proximos meses.\n");
    } else {
         printf("Saude financeira equilibrada! Nenhum gasto ultrapassou o limite de %.0f%%.\n", LIMITE_ALERTA * 100.0);
    }
    printf("==================================\n");
}