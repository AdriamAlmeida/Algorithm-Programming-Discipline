#include <stdio.h>

int maiorDeDois(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int n1, n2;
    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &n1, &n2);

    printf("O maior valor e: %d\n", maiorDeDois(n1, n2));
    return 0;
}