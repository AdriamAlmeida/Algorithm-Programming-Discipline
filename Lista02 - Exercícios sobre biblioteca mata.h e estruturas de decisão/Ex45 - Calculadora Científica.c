#include <stdio.h>
#include <math.h>
#include <string.h>

// Constante para conversao de graus para radianos
#define DEG_TO_RAD (M_PI / 180.0)

int main() {
    double valor, resultado;
    char operacao[10]; // String para armazenar a operacao (sin, log, etc.)

    printf("--- Calculadora Cientifica ---\n");
    printf("Operacoes disponiveis: sin, cos, tan, log, ln, sqrt, pow\n");
    printf("Para 'pow', o formato de entrada sera: base [pow] expoente.\n");

    // 1. Leitura da Operacao
    printf("\nDigite a operacao: ");
    if (scanf("%s", operacao) != 1) return 1;

    // 2. Execucao da Operacao com Validacoes
    
    // Funcoes que operam em um unico valor (sin, cos, tan, log, ln, sqrt)
    if (strcmp(operacao, "sin") == 0 || strcmp(operacao, "cos") == 0 || 
        strcmp(operacao, "tan") == 0 || strcmp(operacao, "log") == 0 || 
        strcmp(operacao, "ln") == 0 || strcmp(operacao, "sqrt") == 0) {
        
        printf("Digite o valor: ");
        if (scanf("%lf", &valor) != 1) return 1;

        if (strcmp(operacao, "sin") == 0 || strcmp(operacao, "cos") == 0 || strcmp(operacao, "tan") == 0) {
            // Trigonometria: Converte de graus para radianos, se desejado
            double radianos = valor * DEG_TO_RAD;
            
            if (strcmp(operacao, "sin") == 0) {
                resultado = sin(radianos);
            } else if (strcmp(operacao, "cos") == 0) {
                resultado = cos(radianos);
            } else { // tan
                // Validacao simples para evitar tangentes que tendem ao infinito (90, 270, etc.)
                // Note: Esta é uma validacao simplificada e o valor sera muito grande, mas o C lida com 'inf'
                if (fabs(fmod(valor - 90.0, 180.0)) < 1e-9) { 
                    printf("\nERRO: Tangente indefinida para %.2lf graus.\n", valor);
                    return 1;
                }
                resultado = tan(radianos);
            }
            printf("\nResultado de %s(%.2lf graus): %.4lf\n", operacao, valor, resultado);
            
        } else if (strcmp(operacao, "log") == 0) {
            // Logaritmo na base 10: Deve ser > 0
            if (valor <= 0) {
                printf("\nERRO: Logaritmo na base 10 so e definido para valores positivos (> 0).\n");
                return 1;
            }
            resultado = log10(valor);
            printf("\nResultado de log10(%.2lf): %.4lf\n", valor, resultado);
            
        } else if (strcmp(operacao, "ln") == 0) {
            // Logaritmo natural (ln): Deve ser > 0
            if (valor <= 0) {
                printf("\nERRO: Logaritmo natural so e definido para valores positivos (> 0).\n");
                return 1;
            }
            resultado = log(valor); // log() em C é o logaritmo natural
            printf("\nResultado de ln(%.2lf): %.4lf\n", valor, resultado);
            
        } else { // sqrt
            // Raiz Quadrada: Deve ser >= 0
            if (valor < 0) {
                printf("\nERRO: Raiz quadrada so e definida para valores nao negativos (>= 0).\n");
                return 1;
            }
            resultado = sqrt(valor);
            printf("\nResultado de sqrt(%.2lf): %.4lf\n", valor, resultado);
        }
        
    } 
    // Funcao que opera em dois valores (pow)
    else if (strcmp(operacao, "pow") == 0) {
        double base, expoente;
        
        printf("Digite a base: ");
        if (scanf("%lf", &base) != 1) return 1;
        
        printf("Digite o expoente: ");
        if (scanf("%lf", &expoente) != 1) return 1;
        
        // Validacao critica para pow (Base 0 e Expoente <= 0)
        if (base == 0 && expoente <= 0) {
            printf("\nERRO: Operacao indefinida (0^n, n <= 0) nao e permitida.\n");
            return 1;
        }

        resultado = pow(base, expoente);
        printf("\nResultado de %.2lf ^ %.2lf: %.4lf\n", base, expoente, resultado);
        
    } else {
        // Operacao Invalida
        printf("\nERRO: Operacao '%s' nao reconhecida.\n", operacao);
        return 1;
    }

    return 0;
}