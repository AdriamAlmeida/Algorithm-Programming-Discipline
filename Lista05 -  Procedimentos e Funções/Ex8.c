#include <stdio.h>

int maiorDeDois(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int maiorDeTres(int a, int b, int c) {
    int maiorTemporario = maiorDeDois(a, b);
    
    return maiorDeDois(maiorTemporario, c);
}

int main() {
    int n1, n2, n3;
    printf("Digite tres numeros inteiros: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    printf("O maior dos tres e: %d\n", maiorDeTres(n1, n2, n3));
    return 0;
}