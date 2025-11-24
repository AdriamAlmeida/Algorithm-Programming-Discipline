#include <stdio.h>

int calcularFatorial(int n) {
    if (n == 0) return 1;
    
    int fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial = fatorial * i;
    }
    return fatorial;
}

int main() {
    int numero;
    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &numero);

    printf("O fatorial de %d e: %d\n", numero, calcularFatorial(numero));
    return 0;
}