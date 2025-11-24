#include <stdio.h>
#include <math.h>

// Definindo uma pequena tolerancia para comparacao de ponto flutuante com zero
#define EPSILON 1e-9

int main() {
    double a, b, c;
    double delta, xv, yv;
    double x1, x2;

    printf("--- Analise de Funcao Quadratica f(x) = ax^2 + bx + c ---\n");

    // 1. Leitura dos Coeficientes
    printf("Digite o coeficiente 'a': ");
    if (scanf("%lf", &a) != 1) return 1;

    printf("Digite o coeficiente 'b': ");
    if (scanf("%lf", &b) != 1) return 1;

    printf("Digite o coeficiente 'c': ");
    if (scanf("%lf", &c) != 1) return 1;

    printf("\nFuncao: f(x) = %.2lfx^2 + %.2lfx + %.2lf\n", a, b, c);
    printf("--------------------------------------------------\n");

    // 2. Analise da Concavidade e Maximo/Minimo

    // A concavidade e determinada pelo sinal de 'a'.
    if (fabs(a) < EPSILON) {
        printf("ERRO: O coeficiente 'a' e zero. Esta nao e uma funcao quadratica.\n");
        return 1;
    } 
    
    printf("1. Concavidade e Ponto Extremo:\n");
    if (a > 0) {
        printf("   - Concavidade: Para CIMA.\n");
        printf("   - Ponto Extremo: A funcao possui um valor MINIMO.\n"); 
    } else { // a < 0
        printf("   - Concavidade: Para BAIXO.\n");
        printf("   - Ponto Extremo: A funcao possui um valor MAXIMO.\n");
    }

    // 3. Calculo do Vertice (xv, yv)
    
    // xv = -b / (2a)
    xv = -b / (2.0 * a);
    
    // Calculo do discriminante (Delta)
    // delta = b^2 - 4ac
    delta = pow(b, 2.0) - (4.0 * a * c);

    // yv = -Delta / (4a)
    yv = -delta / (4.0 * a);
    
    printf("\n2. Vertice (Ponto Extremo):\n");
    printf("   - Coordenadas do Vertice (Vx, Vy): (%.4lf, %.4lf)\n", xv, yv);

    // 4. Calculo e Analise das Raizes (Zeros da Funcao)
    
    printf("\n3. Raizes (Zeros da Funcao):\n");
    printf("   - Discriminante (Delta): %.4lf\n", delta);
    
    if (delta > EPSILON) {
        // Delta > 0: Duas raizes reais e distintas
        x1 = (-b + sqrt(delta)) / (2.0 * a);
        x2 = (-b - sqrt(delta)) / (2.0 * a);
        printf("   - O Delta e positivo, ha DUAS raizes reais e distintas.\n");
        printf("   - x1 = %.4lf\n", x1);
        printf("   - x2 = %.4lf\n", x2);
        
    } else if (fabs(delta) < EPSILON) {
        // Delta = 0: Uma raiz real (ou duas raizes reais e iguais)
        x1 = -b / (2.0 * a);
        printf("   - O Delta e zero, ha UMA raiz real (ou duas iguais).\n");
        printf("   - x = %.4lf\n", x1);
        
    } else { // Delta < 0
        // Delta < 0: Nenhuma raiz real
        printf("   - O Delta e negativo, NAO ha raizes reais.\n");
        printf("   - A parabola nao intercepta o eixo x.\n");
    }

    return 0;
}