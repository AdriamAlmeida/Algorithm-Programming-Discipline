#include <stdio.h>

int main() {
    double salario, valor_emprestimo;
    double limite_valor;

    printf("--- Verificacao de Emprestimo Bancario ---\n");

    // 1. Leitura do Salario
    printf("Digite o valor do seu salario (R$): ");
    if (scanf("%lf", &salario) != 1 || salario <= 0) {
        printf("Erro: Salario invalido.\n");
        return 1;
    }

    // 2. Leitura do Valor do Emprestimo
    printf("Digite o valor do emprestimo desejado (R$): ");
    if (scanf("%lf", &valor_emprestimo) != 1 || valor_emprestimo <= 0) {
        printf("Erro: Valor do emprestimo invalido.\n");
        return 1;
    }

    // Calcula o limite maximo do valor do emprestimo (10x o salario)
    limite_valor = salario * 10.0;

    printf("\n--- Detalhes da Analise ---\n");
    printf("Salario: R$ %.2lf\n", salario);
    printf("Valor Maximo Aprovado (10x Salario): R$ %.2lf\n", limite_valor);
    printf("Valor Solicitado: R$ %.2lf\n", valor_emprestimo);
    printf("---------------------------\n");


    // 3. Verificacao das Condicoes de Aprovacao usando o operador logico E (&&)
    if ( (valor_emprestimo <= limite_valor) && (salario >= 1000.0) ) {
        
        printf("RESULTADO: Emprestimo APROVADO.\n");
        
    } else {
        
        printf("RESULTADO: Emprestimo REPROVADO.\n");
        
        // Mensagens detalhadas sobre o motivo da reprovacao
        printf("\nMotivo(s) da Reprovacao:\n");
        
        if (salario < 1000.0) {
            printf("- Salario minimo nao atingido (Requisito: R$ 1000.00).\n");
        }
        
        if (valor_emprestimo > limite_valor) {
            printf("- Valor do emprestimo excede o limite (Requisito: Valor <= 10x Salario).\n");
        }
    }

    return 0;
}