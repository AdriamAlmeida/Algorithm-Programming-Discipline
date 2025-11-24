#include <stdio.h>
#include <math.h> // Para a funcao pow()

int main() {
    // Variaveis de entrada
    double valor_bem, entrada, num_parcelas_d;
    int num_parcelas;

    // Variaveis de calculo
    double valor_financiado;
    double taxa_mensal; // em decimal
    double valor_parcela;
    double total_pago;
    double total_juros;
    
    printf("--- Calculo de Financiamento (Sistema Price) ---\n");

    // 1. Leitura dos Dados
    printf("Digite o valor total do bem (R$): ");
    if (scanf("%lf", &valor_bem) != 1) return 1;

    printf("Digite o valor da entrada (R$): ");
    if (scanf("%lf", &entrada) != 1) return 1;

    printf("Digite o numero de parcelas (meses): ");
    // Leitura como double para validacao, depois conversao para int
    if (scanf("%lf", &num_parcelas_d) != 1 || num_parcelas_d <= 0) return 1;
    num_parcelas = (int)num_parcelas_d;

    // 2. Calculo do Valor Financiado
    valor_financiado = valor_bem - entrada;
    
    if (valor_financiado <= 0) {
        printf("\nERRO: O valor financiado deve ser maior que zero (Entrada <= Valor do Bem).\n");
        return 1;
    }

    // 3. Determinacao da Taxa de Juros (baseada nas regras hipoteticas)
    if (num_parcelas <= 12) {
        taxa_mensal = 0.015; // 1.5% ao mes
    } else if (num_parcelas <= 36) {
        taxa_mensal = 0.020; // 2.0% ao mes
    } else { // num_parcelas > 36
        taxa_mensal = 0.025; // 2.5% ao mes
    }
    
    // 4. Calculo do Fator de Financiamento (Fator PMT)
    
    // Fator do numerador: i * (1 + i)^n
    double fator_num = taxa_mensal * pow(1.0 + taxa_mensal, num_parcelas);
    
    // Fator do denominador: (1 + i)^n - 1
    double fator_den = pow(1.0 + taxa_mensal, num_parcelas) - 1.0;

    // Fator PMT: fator_num / fator_den
    double fator_pmt = fator_num / fator_den;

    // 5. Calculo da Parcela
    valor_parcela = valor_financiado * fator_pmt;
    
    // 6. Calculo dos Totais
    total_pago = valor_parcela * num_parcelas;
    total_juros = total_pago - valor_financiado;

    // 7. Exibicao dos Resultados
    printf("\n============================================\n");
    printf("   RESUMO DO FINANCIAMENTO\n");
    printf("============================================\n");
    printf("Valor do Bem:         R$ %.2lf\n", valor_bem);
    printf("Entrada:              R$ %.2lf\n", entrada);
    printf("--------------------------------------------\n");
    printf("Valor Financiado (P): R$ %.2lf\n", valor_financiado);
    printf("Prazo (n):            %d meses\n", num_parcelas);
    printf("Taxa de Juros (i):    %.2lf%% ao mes\n", taxa_mensal * 100.0);
    printf("--------------------------------------------\n");
    printf("Valor da Parcela:     R$ %.2lf\n", valor_parcela);
    printf("Total Pago (com juros): R$ %.2lf\n", total_pago);
    printf("Total de Juros:       R$ %.2lf\n", total_juros);
    printf("============================================\n");

    return 0;
}