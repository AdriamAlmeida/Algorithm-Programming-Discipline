#include <stdio.h>

int main() {
    // Coeficientes do sistema a11x + a12y = b1
    //                     a21x + a22y = b2
    double a11, a12, b1;
    double a21, a22, b2;

    // Determinantes
    double D, Dx, Dy;

    printf("--- Solucao de Sistema 2x2 pela Regra de Cramer ---\n");
    printf("Sistema: a11*x + a12*y = b1\n");
    printf("         a21*x + a22*y = b2\n\n");

    // 1. Leitura dos Coeficientes
    printf("Digite a11 (coef. x da 1a eq): ");
    if (scanf("%lf", &a11) != 1) return 1;
    printf("Digite a12 (coef. y da 1a eq): ");
    if (scanf("%lf", &a12) != 1) return 1;
    printf("Digite b1 (termo ind. da 1a eq): ");
    if (scanf("%lf", &b1) != 1) return 1;

    printf("Digite a21 (coef. x da 2a eq): ");
    if (scanf("%lf", &a21) != 1) return 1;
    printf("Digite a22 (coef. y da 2a eq): ");
    if (scanf("%lf", &a22) != 1) return 1;
    printf("Digite b2 (termo ind. da 2a eq): ");
    if (scanf("%lf", &b2) != 1) return 1;

    // 2. Calculo dos Determinantes
    
    // Determinante Principal (D)
    // D = (a11 * a22) - (a12 * a21)
    D = (a11 * a22) - (a12 * a21);

    // Determinante de x (Dx)
    // Dx = (b1 * a22) - (a12 * b2)
    Dx = (b1 * a22) - (a12 * b2);

    // Determinante de y (Dy)
    // Dy = (a11 * b2) - (b1 * a21)
    Dy = (a11 * b2) - (b1 * a21);
    
    printf("\n--- Determinantes Calculados ---\n");
    printf("D  (Principal) = %.2lf\n", D);
    printf("Dx (para x)    = %.2lf\n", Dx);
    printf("Dy (para y)    = %.2lf\n", Dy);
    printf("--------------------------------\n");

    // 3. Verificacao e Solucao
    
    // Usamos uma pequena tolerancia (e.g., 1e-9) para comparar se D é próximo de zero,
    // devido à imprecisão de ponto flutuante, mas para este exercicio, usaremos D == 0.
    if (D != 0) {
        // Solucao Unica: D != 0
        double x = Dx / D;
        double y = Dy / D;

        printf("RESULTADO: Solucao Unica Encontrada.\n");
        printf("x = Dx / D = %.2lf / %.2lf = %.4lf\n", Dx, D, x);
        printf("y = Dy / D = %.2lf / %.2lf = %.4lf\n", Dy, D, y);
        
    } else {
        // D = 0: O sistema nao tem solucao unica.
        
        if (Dx == 0 && Dy == 0) {
            // D = 0, Dx = 0, Dy = 0: Sistema Possivel e Indeterminado (Infinitas Solucoes)
            printf("RESULTADO: Sistema Possivel e Indeterminado (SPI).\n");
            printf("Ha infinitas solucoes.\n");
        } else {
            // D = 0, e (Dx != 0 OU Dy != 0): Sistema Impossivel (Nenhuma Solucao)
            printf("RESULTADO: Sistema Impossivel (SI).\n");
            printf("Nao ha solucao para este sistema.\n");
        }
    }

    return 0;
}