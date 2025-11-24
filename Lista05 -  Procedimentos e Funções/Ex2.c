#include <stdio.h>

int contarInversoes(int v[], int n) {
    int i, j;
    int contador = 0;


    for (i = 0; i < n; i++) {

        for (j = i + 1; j < n; j++) {

            if (v[i] > v[j]) {
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    int vetor[] = {5, 4, 3, 2, 1}; 
    int tamanho = 5;

    int total = contarInversoes(vetor, tamanho);

    printf("Total de inversoes no vetor: %d\n", total);

    return 0;
}