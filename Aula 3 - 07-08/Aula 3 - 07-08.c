#include <stdio.h>

int main (){

    int numero;
    float num;
    char palavra[10];
    
    printf("Escreva um numero: \n");
    scanf("%d", &numero);

    printf("Escreva um numero decimal: \n");
    scanf("%f", &num);

    printf("Escreva um caracter: \n");
    scanf(" %s", palavra);
    
    printf("O número digitado por você foi: %d\n", numero);
    printf("O número digitado por você foi: %f\n", num);
    printf("O caracter digitado por você foi: %s\n", palavra);

    return 0;
    }