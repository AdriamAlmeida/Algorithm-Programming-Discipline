#include <stdio.h>

int main() {
    int N;
    // Variaveis para armazenar os dois termos anteriores.
    // Usamos 'long long' para evitar estouro de memoria (overflow)
    // para valores maiores de N, ja que a sequencia cresce rapidamente.
    long long termo1 = 0, termo2 = 1;
    long long proximo_termo;

    // 1. Solicita o numero de termos (N) ao usuario
    printf("--- Sequencia de Fibonacci ---\n");
    printf("Quantos termos da sequencia de Fibonacci voce deseja gerar? ");
    scanf("%d", &N);

    // 2. Trata entradas invalidas
    if (N <= 0) {
        printf("O numero de termos deve ser positivo.\n");
        return 1;
    }

    // 3. Exibe a sequencia
    printf("Os primeiros %d termos da Sequencia de Fibonacci sao:\n", N);

    // 4. Loop FOR para gerar os N termos
    for (int i = 1; i <= N; i++) {
        // Exibe o termo atual
        printf("%lld", termo1);

        // Adiciona uma virgula, exceto no ultimo termo
        if (i < N) {
            printf(", ");
        }

        // Logica para calcular o proximo termo:
        // A sequencia comeca com 0 e 1.
        if (i == 1) {
            // O primeiro termo (i=1) e 0. O proximo ja e 1 (armazenado em termo2).
            proximo_termo = termo2;
        } else {
            // A partir do segundo termo, calcula-se a soma dos dois anteriores.
            proximo_termo = termo1 + termo2;
        }
        
        // Atualiza os termos para a proxima iteracao:
        // O segundo termo (termo2) torna-se o primeiro termo (termo1)
        // O proximo termo calculado (proximo_termo) torna-se o novo segundo termo (termo2)
        termo1 = termo2;
        termo2 = proximo_termo;
    }
    
    printf("\n"); // Nova linha para formatacao
    
    return 0;
}