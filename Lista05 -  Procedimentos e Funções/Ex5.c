#include <stdio.h>

int somaSequencial(int n) {
    int soma = 0;
    for (int i = 0; i <= n; i++) {
        soma += i;
    }
    return soma;
}

int main() {
    int numero;
    printf("Digite um numero para somar de 0 ate ele: ");
    scanf("%d", &numero);

    printf("A soma e: %d\n", somaSequencial(numero));
    return 0;
}