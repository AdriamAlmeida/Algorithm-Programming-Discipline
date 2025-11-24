#include <stdio.h>
#include <math.h> // Necessário para a funcao pow()

int main() {
    double capital, taxa_anual;
    int tempo_anos;

    // Variaveis de Juros Simples
    double montante_simples, juros_simples;

    // Variaveis de Juros Compostos
    double montante_composto, juros_composto;

    printf("--- Simulador de Investimento (Juros Simples vs. Compostos) ---\n");

    // 1. Leitura dos Dados
    printf("Digite o Capital Inicial (R$): ");
    if (scanf("%lf", &capital) != 1 || capital <= 0) return 1;

    printf("Digite a Taxa de Juros Anual (em %%): ");
    if (scanf("%lf", &taxa_anual) != 1 || taxa_anual <= 0) return 1;
    
    printf("Digite o Tempo de Investimento (em anos): ");
    // Leitura como double para validacao, depois conversao para int
    if (scanf("%d", &tempo_anos) != 1 || tempo_anos <= 0) return 1;

    // Converte a taxa percentual para decimal
    double i = taxa_anual / 100.0;
    
    // 2. Calculo de Juros Simples
    // Montante = Capital * (1 + i * t)
    montante_simples = capital * (1.0 + i * tempo_anos);
    juros_simples = montante_simples - capital;

    // 3. Calculo de Juros Compostos
    // Montante = Capital * (1 + i)^t
    // pow(base, expoente)
    montante_composto = capital * pow(1.0 + i, tempo_anos);
    juros_composto = montante_composto - capital;
    
    printf("\n======================================================\n");
    printf("   RESULTADOS DA SIMULACAO (Tempo: %d anos, Taxa: %.2lf%% ao ano)\n", tempo_anos, taxa_anual);
    printf("======================================================\n");

    // Exibicao dos Resultados
    
    // Tabela Juros Simples
    printf("REGIME: JUROS SIMPLES\n");
    printf("  Montante Final: R$ %.2lf\n", montante_simples);
    printf("  Total de Juros: R$ %.2lf\n", juros_simples);
    
    printf("\nREGIME: JUROS COMPOSTOS\n");
    printf("  Montante Final: R$ %.2lf\n", montante_composto);
    printf("  Total de Juros: R$ %.2lf\n", juros_composto);
    printf("------------------------------------------------------\n");

    // 4. Analise e Comparacao
    
    printf("ANALISE E CONCLUSAO:\n");
    
    // Juros Compostos e sempre mais vantajoso (seja para investimento ou divida)
    if (montante_composto > montante_simples) {
        double diferenca_juros = juros_composto - juros_simples;
        printf("  O regime de **Juros Compostos** e superior.\n");
        printf("  Gerou R$ %.2lf a mais em juros do que o regime simples.\n", diferenca_juros);
        printf("  CONCLUSÃO: Em investimentos (capitalizacao), o juro composto e o **melhor** regime.\n");
    } else {
         // Este bloco so seria atingido se o tempo fosse 0 ou a taxa fosse 0, 
         // o que foi evitado pelas validacoes, mas e mantido por seguranca.
        printf("  Os regimes geraram o mesmo montante. (Isso so ocorre se o tempo for zero).\n");
    }
    printf("======================================================\n");

    return 0;
}