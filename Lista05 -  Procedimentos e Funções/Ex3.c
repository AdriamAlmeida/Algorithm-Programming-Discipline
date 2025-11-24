#include <stdio.h>

int contarOcorrencias(int v[10], int alvo) {
    int i, qtd = 0;
    
    for (i = 0; i < 10; i++) {
        if (v[i] == alvo) {
            qtd++;
        }
    }
    return qtd;
}

int main() {
    int numeros[10];
    int i, busca, resultado;

    printf("Digite 10 numeros inteiros:\n");
    for(i = 0; i < 10; i++) {
        printf("Posicao %d: ", i);
        scanf("%d", &numeros[i]);
    }

    printf("\nQual numero deseja contar? ");
    scanf("%d", &busca);

    resultado = contarOcorrencias(numeros, busca);

    printf("O numero %d aparece %d vezes no vetor.\n", busca, resultado);

    return 0;
}