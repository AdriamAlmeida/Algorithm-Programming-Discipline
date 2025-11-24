#include <stdio.h>

int verificaPerfeito(int n) {
    int somaDivisores = 0;

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            somaDivisores += i;
        }
    }

    if (somaDivisores == n) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int numero;
    printf("Digite um numero para verificar se e perfeito: ");
    scanf("%d", &numero);

    int resultado = verificaPerfeito(numero);

    if (resultado == 0) {
        printf("O numero %d E PERFEITO.\n", numero);
    } else {
        printf("O numero %d NAO e perfeito.\n", numero);
    }

    return 0;
}