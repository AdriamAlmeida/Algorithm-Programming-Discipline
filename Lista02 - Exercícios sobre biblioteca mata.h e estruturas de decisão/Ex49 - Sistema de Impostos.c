#include <stdio.h>
#include <math.h> // Para a funcao fmin (minimo)
#include <float.h> // Para DBL_EPSILON

// Limites de deducao e faixas de IR (valores mensais hipoteticos)
#define DEDUCAO_DEPENDENTE_MENSAL 189.59
#define LIMITE_EDUCACAO_MENSAL 296.79 // 3561.50 / 12

// Estrutura para os gastos dedutiveis (estrutura aninhada)
typedef struct {
    double medicos;
    double educacao; // Sujeito a limite
} Deducoes;

// Estrutura principal do Contribuinte
typedef struct {
    double salario_bruto_mensal;
    int num_dependentes;
    Deducoes gastos; // Estrutura aninhada
} Contribuinte;

// Funcao para calcular o imposto devido
double calcular_imposto(Contribuinte c, double *base_calculo) {
    // 1. DEDUCOES
    double deducao_dependente = c.num_dependentes * DEDUCAO_DEPENDENTE_MENSAL;
    
    // Deducoes medicas sao integrais (sem limite)
    double deducao_medica = c.gastos.medicos;
    
    // Deducoes com educacao sao limitadas
    double deducao_educacao = fmin(c.gastos.educacao, LIMITE_EDUCACAO_MENSAL);
    
    double total_deducoes = deducao_dependente + deducao_medica + deducao_educacao;

    // 2. CALCULO DA BASE TRIBUTAVEL
    *base_calculo = c.salario_bruto_mensal - total_deducoes;

    if (*base_calculo < 0) {
        *base_calculo = 0; // A base nao pode ser negativa
    }
    
    double imposto_bruto = 0.0;
    double imposto_liquido = 0.0;
    
    // 3. APLICACAO DAS FAIXAS DE IMPOSTO (Condicoes Aninhadas)
    
    // Faixa 5: Acima de R$ 4.664,68 (27.5%)
    if (*base_calculo > 4664.68) {
        imposto_bruto = (*base_calculo * 0.275);
        imposto_liquido = imposto_bruto - 884.96;
        
    // Faixa 4: De R$ 3.751,06 ate R$ 4.664,68 (22.5%)
    } else if (*base_calculo > 3751.05) {
        imposto_bruto = (*base_calculo * 0.225);
        imposto_liquido = imposto_bruto - 651.73;

    // Faixa 3: De R$ 2.826,66 ate R$ 3.751,05 (15.0%)
    } else if (*base_calculo > 2826.65) {
        imposto_bruto = (*base_calculo * 0.150);
        imposto_liquido = imposto_bruto - 370.47;

    // Faixa 2: De R$ 2.112,01 ate R$ 2.826,65 (7.5%)
    } else if (*base_calculo > 2112.00) {
        imposto_bruto = (*base_calculo * 0.075);
        imposto_liquido = imposto_bruto - 158.40;
        
    // Faixa 1: Ate R$ 2.112,00 (Isento)
    } else {
        imposto_liquido = 0.0;
    }
    
    // Garante que o imposto nunca seja negativo
    if (imposto_liquido < 0) {
        imposto_liquido = 0.0;
    }

    return imposto_liquido;
}

int main() {
    Contribuinte c;
    double imposto_devido, base_calculo;

    printf("--- Simulador de Imposto de Renda (Mensal) ---\n");

    // 1. Leitura dos Dados do Contribuinte
    printf("Salario Bruto Mensal (R$): ");
    if (scanf("%lf", &c.salario_bruto_mensal) != 1) return 1;

    printf("Numero de Dependentes: ");
    if (scanf("%d", &c.num_dependentes) != 1 || c.num_dependentes < 0) return 1;

    printf("Gastos Medicos no mes (R$): ");
    if (scanf("%lf", &c.gastos.medicos) != 1 || c.gastos.medicos < 0) return 1;

    printf("Gastos com Educacao no mes (R$): ");
    if (scanf("%lf", &c.gastos.educacao) != 1 || c.gastos.educacao < 0) return 1;

    // 2. Chamada da Funcao de Calculo
    imposto_devido = calcular_imposto(c, &base_calculo);

    // 3. Exibicao dos Resultados
    printf("\n============================================\n");
    printf("         RESUMO DO CALCULO DE IR\n");
    printf("============================================\n");
    printf("Salario Bruto:         R$ %.2lf\n", c.salario_bruto_mensal);
    printf("Dependentes:           %d (Deducao: R$ %.2lf)\n", 
           c.num_dependentes, c.num_dependentes * DEDUCAO_DEPENDENTE_MENSAL);
    printf("Deducao Medica:        R$ %.2lf\n", c.gastos.medicos);
    printf("Deducao Educacao Max:  R$ %.2lf (Limite: R$ %.2lf)\n", 
           fmin(c.gastos.educacao, LIMITE_EDUCACAO_MENSAL), LIMITE_EDUCACAO_MENSAL);
    printf("--------------------------------------------\n");
    printf("Base de Calculo (BC):  R$ %.2lf\n", base_calculo);
    printf("--------------------------------------------\n");
    
    if (imposto_devido > 0.0 + DBL_EPSILON) {
        printf("IMPOSTO DEVIDO (IRPF): R$ %.2lf\n", imposto_devido);
    } else {
        printf("IMPOSTO DEVIDO (IRPF): ISENTO\n");
    }
    printf("============================================\n");

    return 0;
}