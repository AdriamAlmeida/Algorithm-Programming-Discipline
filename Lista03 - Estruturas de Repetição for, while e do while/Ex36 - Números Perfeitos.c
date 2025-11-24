#include <stdio.h>

int main() {
    int N; // Limite superior
    int soma_divisores; // Variavel para acumular a soma dos divisores

    printf("--- Buscador de Numeros Perfeitos ---\n");
    printf("Digite o limite superior (N): ");
    
    // 1. Entrada de dados
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Limite invalido. Deve ser um numero inteiro positivo.\n");
        return 1;
    }

    printf("\nNumeros Perfeitos encontrados ate %d:\n", N);

    // 2. LACO EXTERNO: Testa cada numero (i) de 2 ate N
    // Numeros perfeitos sao sempre positivos, e 1 nao e considerado perfeito.
    for (int i = 2; i <= N; i++) {
        
        soma_divisores = 0; // Zera a soma para cada novo numero i
        
        // 3. LACO INTERNO: Encontra e soma os divisores proprios de i
        // Os divisores proprios vao de 1 ate i/2 (otimizacao).
        // Se um numero for divisivel por algo maior que i/2 (exceto i),
        // ele ja teria sido divisivel por algo menor.
        for (int j = 1; j <= i / 2; j++) {
            
            // Verifica se j e um divisor de i
            if (i % j == 0) {
                soma_divisores += j; // Adiciona o divisor a soma
            }
        }
        
        // 4. Teste de Perfeicao
        // Se a soma dos divisores for igual ao numero i, ele e perfeito.
        if (soma_divisores == i) {
            printf("%d\n", i);
        }
        
    } // Fim do laco externo

    if (N < 6) {
        printf("Nenhum numero perfeito encontrado (o primeiro e 6).\n");
    }

    return 0;
}