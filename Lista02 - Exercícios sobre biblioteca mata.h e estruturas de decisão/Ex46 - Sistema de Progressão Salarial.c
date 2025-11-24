#include <stdio.h>
#include <stdbool.h>

int main() {
    double salario_atual;
    int anos_empresa;
    int avaliacao; // 1 a 5
    
    double taxa_aumento_base = 0.0;
    double bonus_avaliacao = 0.0;
    double percentual_total_aumento;
    double novo_salario;
    
    // Flag para indicar se houve aumento ou reducao
    bool aumento_concedido = false;

    printf("--- Sistema de Progressao Salarial ---\n");

    // 1. Leitura dos Dados
    printf("Digite o Salario Atual (R$): ");
    if (scanf("%lf", &salario_atual) != 1 || salario_atual <= 0) return 1;

    printf("Digite os Anos de Empresa: ");
    if (scanf("%d", &anos_empresa) != 1 || anos_empresa < 0) return 1;

    printf("Digite a Avaliacao (1 = Pessimo, 5 = Excelente): ");
    if (scanf("%d", &avaliacao) != 1 || avaliacao < 1 || avaliacao > 5) return 1;

    printf("\n--- Analise de Progressao ---\n");

    // 2. Logica de Progressao (Decisoes Aninhadas e Multiplos Criterios)
    
    // Estrutura Principal: Baseada na Avaliacao
    if (avaliacao == 5) { // Avaliacao Excelente
        printf("Avaliacao: Excelente (5).\n");
        if (anos_empresa >= 5) {
            // Criterio 1: 5 (Excelente) E >= 5 Anos
            taxa_aumento_base = 0.20; // 20%
            bonus_avaliacao = 0.05;   // +5%
            aumento_concedido = true;
        } else {
            // Criterio 1.1: Excelente, mas nao atende ao tempo minimo
            taxa_aumento_base = 0.05; // Aumento padrao de 5%
            printf("Tempo de empresa (%d anos) nao atende ao requisito minimo (5 anos). Aumento Padrao.\n", anos_empresa);
        }

    } else if (avaliacao == 4) { // Avaliacao Boa
        printf("Avaliacao: Boa (4).\n");
        if (anos_empresa >= 3) {
            // Criterio 2: 4 (Bom) E >= 3 Anos
            taxa_aumento_base = 0.15; // 15%
            bonus_avaliacao = 0.03;   // +3%
            aumento_concedido = true;
        } else {
            // Criterio 2.1: Boa, mas nao atende ao tempo minimo
            taxa_aumento_base = 0.05; // Aumento padrao de 5%
            printf("Tempo de empresa (%d anos) nao atende ao requisito minimo (3 anos). Aumento Padrao.\n", anos_empresa);
        }

    } else if (avaliacao == 3) { // Avaliacao Regular
        printf("Avaliacao: Regular (3).\n");
        if (anos_empresa >= 1) {
            // Criterio 3: 3 (Regular) E >= 1 Ano
            taxa_aumento_base = 0.10; // 10%
            aumento_concedido = true;
        } else {
            // Criterio 3.1: Regular, mas menos de 1 ano
            taxa_aumento_base = 0.05; // Aumento padrao de 5%
            printf("Tempo de empresa (%d anos) nao atende ao requisito minimo (1 ano). Aumento Padrao.\n", anos_empresa);
        }

    } else if (avaliacao == 2) { // Avaliacao Insuficiente
        printf("Avaliacao: Insuficiente (2).\n");
        // Criterio 4: Insuficiente
        taxa_aumento_base = 0.00; // 0%
        printf("Resultado insuficiente. Sem aumento.\n");

    } else { // Avaliacao Pessima (avaliacao == 1)
        printf("Avaliacao: Pessima (1).\n");
        // Criterio 5: Pessima
        taxa_aumento_base = -0.05; // -5% (Reducao salarial)
        printf("Resultado pessimo. Reducao salarial aplicada.\n");
    }

    // 3. Calculo Final
    percentual_total_aumento = taxa_aumento_base + bonus_avaliacao;
    novo_salario = salario_atual * (1.0 + percentual_total_aumento);

    printf("\n========================================\n");
    printf("Salario Atual: R$ %.2lf\n", salario_atual);
    
    if (percentual_total_aumento >= 0) {
        printf("Aumento Total: %.2lf%% (Base %.2lf%% + Bonus %.2lf%%)\n", 
               percentual_total_aumento * 100.0, taxa_aumento_base * 100.0, bonus_avaliacao * 100.0);
    } else {
        printf("Reducao Total: %.2lf%%\n", percentual_total_aumento * 100.0);
    }
    
    printf("Novo Salario: R$ %.2lf\n", novo_salario);
    printf("========================================\n");

    return 0;
}