#include <stdio.h>
#include <math.h>   // Para pow() e acos()
#include <stdbool.h>

// Constante para converter radianos para graus
#define RAD_TO_DEG (180.0 / M_PI)

// Função auxiliar para classificar por ângulos
void classificar_por_angulos(double a, double b, double c);

int main() {
    double ladoA, ladoB, ladoC;
    bool e_triangulo;

    printf("--- Classificacao Completa de Triangulos ---\n");

    // 1. Leitura dos Tres Lados
    printf("Digite o comprimento do Lado A: ");
    if (scanf("%lf", &ladoA) != 1 || ladoA <= 0) return 1;

    printf("Digite o comprimento do Lado B: ");
    if (scanf("%lf", &ladoB) != 1 || ladoB <= 0) return 1;

    printf("Digite o comprimento do Lado C: ");
    if (scanf("%lf", &ladoC) != 1 || ladoC <= 0) return 1;

    // 2. Verificacao da Condicao de Existencia (Validade)
    // A soma de dois lados quaisquer deve ser maior que o terceiro lado.
    e_triangulo = (ladoA + ladoB > ladoC) && 
                  (ladoA + ladoC > ladoB) && 
                  (ladoB + ladoC > ladoA);

    printf("\n--- Resultado ---\n");

    if (e_triangulo) {
        printf("VALIDADE: ✅ Os lados formam um triangulo valido.\n");
        printf("Lados: A=%.2lf, B=%.2lf, C=%.2lf\n", ladoA, ladoB, ladoC);
        
        // 3. Classificacao por Lados
        printf("\nCLASSIFICACAO POR LADOS: ");
        if (ladoA == ladoB && ladoB == ladoC) {
            printf("Equilatero (Todos os lados iguais).\n");
        } else if (ladoA == ladoB || ladoA == ladoC || ladoB == ladoC) {
            printf("Isosceles (Apenas dois lados iguais).\n");
        } else {
            printf("Escaleno (Todos os lados diferentes).\n");
        }

        // 4. Classificacao por Angulos (usando Lei dos Cossenos)
        classificar_por_angulos(ladoA, ladoB, ladoC);

    } else {
        printf("VALIDADE: ❌ Os lados NAO formam um triangulo valido (Condicao de existencia falhou).\n");
    }

    return 0;
}

// --------------------------------------------------------------------------
// Funcao para calcular e classificar o triangulo por angulos
// --------------------------------------------------------------------------
void classificar_por_angulos(double a, double b, double c) {
    
    // Calcula o maior lado ao quadrado. 
    // O tipo de triangulo (acutangulo, retangulo, obtusangulo) e determinado
    // pelo seu maior angulo, que e oposto ao seu maior lado.
    
    // Identifica o maior lado para otimizar o calculo:
    double maior_lado_sq;
    double l1_sq, l2_sq;
    
    // Assumimos c e o maior lado inicialmente (c^2)
    if (a >= b && a >= c) {
        maior_lado_sq = pow(a, 2.0);
        l1_sq = pow(b, 2.0);
        l2_sq = pow(c, 2.0);
    } else if (b >= a && b >= c) {
        maior_lado_sq = pow(b, 2.0);
        l1_sq = pow(a, 2.0);
        l2_sq = pow(c, 2.0);
    } else {
        maior_lado_sq = pow(c, 2.0);
        l1_sq = pow(a, 2.0);
        l2_sq = pow(b, 2.0);
    }
    
    // A logica simplificada de classificacao por angulos, 
    // baseada no Teorema de Pitagoras e suas extensoes:
    // Se a^2 + b^2 = c^2 (Retangulo)
    // Se a^2 + b^2 > c^2 (Acutangulo)
    // Se a^2 + b^2 < c^2 (Obtusangulo)
    
    printf("CLASSIFICACAO POR ANGULOS: ");
    
    if (l1_sq + l2_sq == maior_lado_sq) {
        printf("Retangulo (Possui um angulo de 90 graus).\n");
    } else if (l1_sq + l2_sq > maior_lado_sq) {
        printf("Acutangulo (Todos os angulos sao menores que 90 graus).\n");
    } else { // l1_sq + l2_sq < maior_lado_sq
        printf("Obtusangulo (Possui um angulo maior que 90 graus).\n");
    }
    
    
}