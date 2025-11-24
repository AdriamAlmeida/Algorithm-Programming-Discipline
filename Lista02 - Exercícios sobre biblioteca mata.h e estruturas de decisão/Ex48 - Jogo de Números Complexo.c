#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> // Para DBL_EPSILON ou definicao de tolerancia

// Definicao de uma pequena tolerancia para comparacao de numeros de ponto flutuante
#define EPSILON 1e-9

// Funcao auxiliar para ordenar tres numeros (simplifica a busca por min/max e a verificacao de PA/PG)
void ordenar_numeros(double *a, double *b, double *c) {
    // Ordenacao por troca simples
    if (*a > *b) { double temp = *a; *a = *b; *b = temp; }
    if (*a > *c) { double temp = *a; *a = *c; *c = temp; }
    if (*b > *c) { double temp = *b; *b = *c; *b = temp; }
}

int main() {
    double n1, n2, n3;
    
    printf("--- Jogo de Analise de 3 Numeros ---\n");

    // 1. Leitura dos 3 Numeros
    printf("Digite o primeiro numero: ");
    if (scanf("%lf", &n1) != 1) return 1;

    printf("Digite o segundo numero: ");
    if (scanf("%lf", &n2) != 1) return 1;

    printf("Digite o terceiro numero: ");
    if (scanf("%lf", &n3) != 1) return 1;

    printf("\nNumeros digitados: (%.2lf, %.2lf, %.2lf)\n", n1, n2, n3);

    // Cria copias para ordenacao (o que simplifica as verificacoes)
    double a = n1;
    double b = n2;
    double c = n3;
    
    // Ordena os numeros (a <= b <= c)
    ordenar_numeros(&a, &b, &c);

    // 2. Determinar Maior e Menor
    double menor = a; // O primeiro elemento apos a ordenacao
    double maior = c; // O ultimo elemento apos a ordenacao

    printf("\n--- Analise de Extremos ---\n");
    printf("Menor numero: %.4lf\n", menor);
    printf("Maior numero: %.4lf\n", maior);
    
    // 3. Calculo da Media Geometrica
    // Mg = (n1 * n2 * n3)^(1/3)
    double produto = n1 * n2 * n3;
    double media_geometrica;

    if (produto < 0) {
        // Se o produto for negativo, a raiz cubica existe
        // Usa pow(fabs(produto), 1.0/3.0) e aplica o sinal negativo
        media_geometrica = -pow(fabs(produto), 1.0/3.0);
    } else {
        // Se o produto for zero ou positivo
        media_geometrica = pow(produto, 1.0/3.0);
    }

    printf("\n--- Calculo da Media ---\n");
    printf("Produto (n1 * n2 * n3): %.4lf\n", produto);
    printf("Media Geometrica: %.4lf\n", media_geometrica);
    
    // 4. Verificacao de Progressao Aritmetica (PA) e Geometrica (PG)
    printf("\n--- Classificacao de Progressao ---\n");

    // Condicao de PA: a diferenca deve ser constante (b - a) = (c - b)
    double dif_ba = b - a;
    double dif_cb = c - b;
    // Verifica se as diferencas sao aproximadamente iguais
    int e_pa = fabs(dif_ba - dif_cb) < EPSILON; 

    // Condicao de PG: a razao deve ser constante (b / a) = (c / b)
    int e_pg = 0;
    
    // Tratamento para PG: Evitar divisao por zero e tratar o caso especial de 0.
    if (fabs(a) > EPSILON && fabs(b) > EPSILON) {
        // Se 'a' e 'b' nao sao zero:
        double razao_ba = b / a;
        double razao_cb = c / b;
        // Verifica se as razoes sao aproximadamente iguais
        e_pg = fabs(razao_ba - razao_cb) < EPSILON;
    } else if (fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON) {
        // Caso especial: (0, 0, 0) é PA (razao 0) e PG (razao indefinida, mas frequentemente considerada 1)
        e_pa = 1;
        e_pg = 1; // Consideramos (0, 0, 0) como PG
    } else if (fabs(a) < EPSILON || fabs(b) < EPSILON) {
        // Se apenas um ou dois sao zero, e os outros nao, geralmente nao e uma PG valida
        e_pg = 0;
    }

    if (e_pa && e_pg) {
        printf("RESULTADO: 🔄 Os numeros formam uma Progressao Aritmetica (PA) E Geometrica (PG).\n");
        printf("  (Isso so ocorre se todos os numeros forem iguais, e.g., (5, 5, 5)).\n");
    } else if (e_pa) {
        printf("RESULTADO: ➕ Os numeros formam uma Progressao Aritmetica (PA).\n");
        printf("  Razao (diferenca): %.4lf\n", dif_ba);
    } else if (e_pg) {
        printf("RESULTADO: ✖️ Os numeros formam uma Progressao Geometrica (PG).\n");
        printf("  Razao: %.4lf\n", b / a);
    } else {
        printf("RESULTADO: 🛑 Os numeros NAO formam uma PA nem uma PG.\n");
    }

    return 0;
}