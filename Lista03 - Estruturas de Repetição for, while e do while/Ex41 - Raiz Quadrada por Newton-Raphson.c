#include <stdio.h>
#include <math.h>

int main() {
    double S; // O número do qual queremos a raiz quadrada
    double aproximacao_atual; // x_atual (chute inicial)
    double aproximacao_nova; // x_novo
    // Tolerancia (epsilon) para determinar a precisao
    const double TOLERANCIA = 0.00001; 
    int iteracoes = 0; // Contador de iteracoes

    printf("--- Raiz Quadrada pelo Metodo de Newton-Raphson ---\n");
    printf("Digite um numero (S) para calcular a raiz quadrada: ");
    
    // 1. Entrada de dados
    if (scanf("%lf", &S) != 1 || S < 0) {
        printf("Entrada invalida. Digite um numero nao-negativo.\n");
        return 1;
    }

    if (S == 0) {
        printf("A raiz quadrada de 0 e 0.0.\n");
        return 0;
    }

    // 2. Chute inicial (pode ser S/2 ou 1.0)
    aproximacao_atual = S / 2.0; 

    printf("Iniciando com chute: %.4f\n", aproximacao_atual);

    // 3. Loop DO-WHILE para as iteracoes
    do {
        // Salva a aproximacao atual para a verificacao da condicao no final
        aproximacao_nova = aproximacao_atual; 
        
        // Aplica a formula de Newton-Raphson
        aproximacao_atual = 0.5 * (aproximacao_nova + (S / aproximacao_nova));
        
        iteracoes++;
        
        // Opcional: imprimir o progresso
        // printf("Iteracao %d: %.10f\n", iteracoes, aproximacao_atual); 

    // O loop continua ENQUANTO a diferenca absoluta (fabs) entre as duas
    // aproximacoes for MAIOR que a TOLERANCIA.
    } while (fabs(aproximacao_atual - aproximacao_nova) > TOLERANCIA); 

    // 4. Exibe o resultado
    printf("\nRESULTADO:\n");
    printf("Raiz Quadrada de %.2f e aproximadamente: %.10f\n", S, aproximacao_atual);
    printf("Calculado em %d iteracoes (Tolerancia: %.6f)\n", iteracoes, TOLERANCIA);

    return 0;
}