#include <stdio.h>

int main(){
    int num1;
    float quadrado;

    printf("Digite um número para mostrá-lo ao quadrado: \n");
    scanf("%d", &num1);

    quadrado = (num1*num1);

    printf("O número ao quadrado é: %f", quadrado);

    return 0;
}
