#include <stdio.h>
#include <math.h> // Necessário para a função pow (potencia)

int main() {
    int N_termos;
    // O resultado da soma é um número decimal, use double
    double soma_serie = 0.0;
    double pi_aproximado;

    printf("--- Aproximacao de PI pela Serie de Leibniz ---\n");
    printf("Digite o numero de termos (N) para calcular: ");
    
    // 1. Entrada de dados
    if (scanf("%d", &N_termos) != 1 || N_termos <= 0) {
        printf("Entrada invalida. O numero de termos deve ser um inteiro positivo.\n");
        return 1;
    }

    // 2. Loop FOR para calcular a soma dos N termos
    // O loop roda de n = 0 até N_termos - 1
    for (int n = 0; n < N_termos; n++) {
        
        // Termo da Serie de Leibniz: (-1)^n / (2n + 1)
        
        // a) Alternancia de Sinal: Calcula (-1)^n.
        // Se n é par, pow(-1, n) é 1. Se n é ímpar, é -1.
        double sinal = pow(-1, n); 
        
        // b) Denominador: 2n + 1 (sempre ímpar: 1, 3, 5, 7, ...)
        double denominador = 2.0 * n + 1.0; 
        
        // c) Soma o termo atual
        soma_serie += sinal / denominador;
    }

    // 3. Multiplica o resultado por 4 (pois a série converge para PI/4)
    pi_aproximado = soma_serie * 4.0;

    // 4. Exibe os resultados
    printf("\nCom %d termos:\n", N_termos);
    printf("Soma da serie (PI/4) = %.10f\n", soma_serie);
    printf("Aproximacao de PI = %.10f\n", pi_aproximado);
    printf("Valor real de PI (M_PI) = %.10f\n", M_PI); // M_PI é uma constante em math.h

    return 0;
}