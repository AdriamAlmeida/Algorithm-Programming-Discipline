#include <stdio.h>
#include <math.h>

/*
Conceito por Nota Leia uma nota (0-100) e atribua conceito: A (90-100), B (80-89), C
(70-79), D (60-69), F (<60).
*/

int main() {
    int nota;

    printf("Digite a nota (de 0 a 100): ");
    scanf("%d", &nota);

    do {
        if (nota >= 90) {
        printf("Sua nota foi %d. Você obteve o conceito A\n", nota);
    } else if (nota >= 80) {
        printf("Sua nota foi %d. Você obteve o conceito B\n", nota);
    } else if (nota >= 70) {
        printf("Sua nota foi %d. Você obteve o conceito C\n", nota);
    } else if (nota >= 60) {
        printf("ASua nota foi %d. Você obteve o conceito D\n", nota);
    } else {
        printf("Sua nota foi %d. Você obteve o conceito F\n", nota);
    }
    } while (nota > 0 && nota < 100);
    {
        printf("Erro: Nota invalida. Por favor, digite um valor entre 0 e 100.\n");
    }

    return 0;
}