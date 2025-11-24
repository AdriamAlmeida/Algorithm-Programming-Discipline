#include <stdio.h>
#include <math.h> // Para sqrt(), pow(), atan2() e M_PI

// Constante para conversao de radianos para graus
#define RAD_TO_DEG (180.0 / M_PI)

int main() {
    double x, y;
    double r, theta_rad, theta_deg;

    printf("--- Conversao de Coordenadas Cartesianas (x,y) para Polares (r, theta) ---\n");

    // 1. Leitura das Coordenadas Cartesianas
    printf("Digite a coordenada x: ");
    if (scanf("%lf", &x) != 1) return 1;

    printf("Digite a coordenada y: ");
    if (scanf("%lf", &y) != 1) return 1;

    printf("\nCoordenadas Cartesianas: (%.2lf, %.2lf)\n", x, y);

    // 2. Calculo do Raio (r)
    // r = sqrt(x^2 + y^2)
    r = sqrt(pow(x, 2.0) + pow(y, 2.0));

    // 3. Calculo do Angulo (theta)
    // A funcao atan2(y, x) retorna o angulo correto no intervalo (-pi, pi]
    theta_rad = atan2(y, x);

    // Converte de radianos para graus
    theta_deg = theta_rad * RAD_TO_DEG;

    printf("\n--- Coordenadas Polares ---\n");
    printf("Raio (r): %.4lf\n", r);
    printf("Angulo (theta): %.4lf radianos (%.2lf graus)\n", theta_rad, theta_deg);

    // 4. Classificacao do Quadrante
    printf("\n--- Classificacao ---\n");

    if (r < 1e-9) { // Verifica se r é aproximadamente zero (Origem)
        printf("Ponto: Origem (0, 0).\n");
    } else if (fabs(y) < 1e-9) { // Ponto no eixo x (y é aproximadamente zero)
        if (x > 0) {
            printf("Eixo: Eixo x positivo (theta = 0 graus).\n");
        } else { // x < 0
            printf("Eixo: Eixo x negativo (theta = 180 graus).\n");
        }
    } else if (fabs(x) < 1e-9) { // Ponto no eixo y (x é aproximadamente zero)
        if (y > 0) {
            printf("Eixo: Eixo y positivo (theta = 90 graus).\n");
        } else { // y < 0
            printf("Eixo: Eixo y negativo (theta = -90 graus).\n");
        }
    } else if (x > 0 && y > 0) {
        printf("Quadrante: Primeiro Quadrante (I)\n");
    } else if (x < 0 && y > 0) {
        printf("Quadrante: Segundo Quadrante (II)\n");
    } else if (x < 0 && y < 0) {
        printf("Quadrante: Terceiro Quadrante (III)\n");
    } else { // x > 0 && y < 0
        printf("Quadrante: Quarto Quadrante (IV)\n");
    }

    return 0;
}