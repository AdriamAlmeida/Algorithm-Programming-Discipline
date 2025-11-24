#include <stdio.h>
#include <math.h>   // Para sqrt() e pow()
#include <stdbool.h> // Para usar o tipo bool

// Estrutura para representar um ponto 2D
typedef struct {
    double x;
    double y;
} Ponto;

// Funcao para calcular a distancia entre dois pontos
double calcular_distancia(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.x - p1.x, 2.0) + pow(p2.y - p1.y, 2.0));
}

int main() {
    Ponto pA, pB, pC;
    double ladoA, ladoB, ladoC;
    double s, area, perimetro;

    printf("--- Analise Geometrica Completa de um Triangulo ---\n");

    // 1. Leitura das Coordenadas dos 3 Pontos
    printf("Digite as coordenadas do Ponto A (x y): ");
    if (scanf("%lf %lf", &pA.x, &pA.y) != 2) return 1;

    printf("Digite as coordenadas do Ponto B (x y): ");
    if (scanf("%lf %lf", &pB.x, &pB.y) != 2) return 1;

    printf("Digite as coordenadas do Ponto C (x y): ");
    if (scanf("%lf %lf", &pC.x, &pC.y) != 2) return 1;

    // 2. Calculo das Distancias (Lados do Triangulo)
    ladoA = calcular_distancia(pB, pC); // Lado oposto ao Ponto A
    ladoB = calcular_distancia(pA, pC); // Lado oposto ao Ponto B
    ladoC = calcular_distancia(pA, pB); // Lado oposto ao Ponto C
    
    printf("\n--- Lados Calculados ---\n");
    printf("Lado a (BC): %.4lf\n", ladoA);
    printf("Lado b (AC): %.4lf\n", ladoB);
    printf("Lado c (AB): %.4lf\n", ladoC);

    // 3. Verificacao da Condicao de Existencia do Triangulo
    // A soma de dois lados deve ser estritamente maior que o terceiro.
    bool e_triangulo = (ladoA + ladoB > ladoC) && 
                       (ladoA + ladoC > ladoB) && 
                       (ladoB + ladoC > ladoA);

    printf("\n--- Resultados ---\n");

    if (!e_triangulo) {
        printf("VALIDADE: ❌ Os pontos NAO formam um triangulo.\n");
        printf("Motivo: Condicao de existencia nao satisfeita (os pontos sao colineares ou coincidentes).\n");
    } else {
        printf("VALIDADE: ✅ Os pontos formam um triangulo valido.\n");
        
        // 4. Calculo do Perimetro e Area (Formula de Heron)
        
        // Perimetro
        perimetro = ladoA + ladoB + ladoC;
        
        // Semiperimetro
        s = perimetro / 2.0;
        
        // Area (Formula de Heron)
        area = sqrt(s * (s - ladoA) * (s - ladoB) * (s - ladoC));

        printf("\nRESULTADOS NUMERICOS:\n");
        printf("Perimetro: %.4lf\n", perimetro);
        printf("Semiperimetro (s): %.4lf\n", s);
        printf("Area (Formula de Heron): %.4lf\n", area);
        
        // 5. Classificacao por Lados
        printf("\nCLASSIFICACAO POR LADOS: ");
        
        // Usa uma pequena tolerancia para comparacao de ponto flutuante
        #define TOLERANCIA 1e-9 
        
        if (fabs(ladoA - ladoB) < TOLERANCIA && fabs(ladoB - ladoC) < TOLERANCIA) {
            printf("Equilatero (Todos os lados iguais).\n");
        } else if (fabs(ladoA - ladoB) < TOLERANCIA || 
                   fabs(ladoA - ladoC) < TOLERANCIA || 
                   fabs(ladoB - ladoC) < TOLERANCIA) {
            printf("Isosceles (Pelo menos dois lados iguais).\n");
        } else {
            printf("Escaleno (Todos os lados diferentes).\n");
        }
    }

    return 0;
}