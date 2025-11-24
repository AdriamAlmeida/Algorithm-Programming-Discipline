#include <stdio.h>

int buscaElemento(int v[], int n, int elemento) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int dados[] = {10, 25, 33, 48, 50};
    int n = 5;
    int procurar;

    printf("Vetor: [10, 25, 33, 48, 50]\n");
    printf("Digite um valor para buscar: ");
    scanf("%d", &procurar);

    if (buscaElemento(dados, n, procurar)) {
        printf("O elemento %d ESTA presente no vetor.\n", procurar);
    } else {
        printf("O elemento %d NAO esta presente no vetor.\n", procurar);
    }

    return 0;
}