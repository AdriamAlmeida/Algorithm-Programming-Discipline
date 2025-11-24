#include <stdio.h>

int verificaPositivo(int n) {
    if (n >= 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (verificaPositivo(numero) == 0) {
        printf("O numero e POSITIVO.\n");
    } else {
        printf("O numero e NEGATIVO.\n");
    }

    return 0;
}