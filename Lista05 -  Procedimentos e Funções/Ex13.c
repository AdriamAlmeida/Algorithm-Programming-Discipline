#include <stdio.h>

int verificaPar(int n) {
    if (n % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (verificaPar(numero) == 0) {
        printf("O numero e PAR.\n");
    } else {
        printf("O numero e IMPAR.\n");
    }

    return 0;
}