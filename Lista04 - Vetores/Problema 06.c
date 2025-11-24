#include <stdio.h>
#include <limits.h> // Para usar INT_MAX e INT_MIN

// Constantes
#define NUM_PESSOAS 30

// Função principal
int main() {
    // Declaração do vetor para armazenar as idades
    int idades[NUM_PESSOAS];

    // Contadores para as faixas etárias
    int cont_criancas = 0;   // 0-12 anos
    int cont_adolescentes = 0; // 13-17 anos
    int cont_adultos = 0;      // 18-59 anos
    int cont_idosos = 0;       // 60+ anos

    // Variáveis para cálculos
    long long soma_idades = 0; // Usar long long para garantir que a soma não estoure
    float idade_media = 0.0;
    
    // Variáveis para identificação dos extremos
    int idade_mais_jovem = INT_MAX; // Inicializa com o maior valor possível
    int idade_mais_velha = INT_MIN;  // Inicializa com o menor valor possível

    // 1. Coleta das idades e processamento inicial (soma, min/max, classificação)
    printf("=== COLETA DE IDADES ===\n");
    printf("Por favor, digite a idade de %d pessoas:\n", NUM_PESSOAS);

    for (int i = 0; i < NUM_PESSOAS; i++) {
        int idade_atual;
        printf("Pessoa %02d: ", i + 1);
        
        if (scanf("%d", &idade_atual) != 1) {
            printf("Erro na leitura. Digite um número inteiro.\n");
            // Limpa o buffer e sai para evitar problemas
            while(getchar() != '\n'); 
            i--; // Repete a leitura da pessoa atual
            continue;
        }

        // Garante que a idade seja válida (não negativa, embora 0 seja permitido)
        if (idade_atual < 0) {
            printf("Idade inválida. Por favor, digite uma idade positiva.\n");
            i--; // Repete a leitura da pessoa atual
            continue;
        }

        // Armazena a idade no vetor
        idades[i] = idade_atual;

        // Acumula a soma
        soma_idades += idade_atual;

        // Identifica a idade mais jovem (menor valor)
        if (idade_atual < idade_mais_jovem) {
            idade_mais_jovem = idade_atual;
        }

        // Identifica a idade mais velha (maior valor)
        if (idade_atual > idade_mais_velha) {
            idade_mais_velha = idade_atual;
        }

        // Classificação por Faixa Etária (lógica principal)
        if (idade_atual >= 0 && idade_atual <= 12) {
            cont_criancas++;
        } else if (idade_atual >= 13 && idade_atual <= 17) {
            cont_adolescentes++;
        } else if (idade_atual >= 18 && idade_atual <= 59) {
            cont_adultos++;
        } else { // 60 anos ou mais
            cont_idosos++;
        }
    }

    // 2. Cálculos Finais
    if (NUM_PESSOAS > 0) {
        idade_media = (float)soma_idades / NUM_PESSOAS;
    }

    // Cálculo das porcentagens
    float perc_criancas = (float)cont_criancas / NUM_PESSOAS * 100.0;
    float perc_adolescentes = (float)cont_adolescentes / NUM_PESSOAS * 100.0;
    float perc_adultos = (float)cont_adultos / NUM_PESSOAS * 100.0;
    float perc_idosos = (float)cont_idosos / NUM_PESSOAS * 100.0;

    // 3. Exibição do Relatório
    printf("\n\n=== ANÁLISE DEMOGRÁFICA ===\n");
    printf("---------------------------\n");
    printf("Total de pessoas analisadas: %d\n", NUM_PESSOAS);
    printf("Idade média geral: %.1f anos\n", idade_media);
    printf("---------------------------\n");
    
    printf("### Distribuição Etária ###\n");
    printf("Crianças (0-12): %2d pessoas (%.1f%%)\n", cont_criancas, perc_criancas);
    printf("Adolescentes (13-17): %2d pessoas (%.1f%%)\n", cont_adolescentes, perc_adolescentes);
    printf("Adultos (18-59): %2d pessoas (%.1f%%)\n", cont_adultos, perc_adultos);
    printf("Idosos (60+): %2d pessoas (%.1f%%)\n", cont_idosos, perc_idosos);
    printf("---------------------------\n");
    
    printf("Pessoa mais jovem: %d anos\n", idade_mais_jovem);
    printf("Pessoa mais velha: %d anos\n", idade_mais_velha);
    printf("===========================\n");

    return 0;
}