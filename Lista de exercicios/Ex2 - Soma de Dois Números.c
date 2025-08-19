#include <stdio.h>
int main (){
    int num1, num2, soma;

    printf("Digite dois numeros inteiros: \n");
    scanf("%d", &num1);
    scanf("%d", &num2);

    soma = num1+num2;

    printf("A soma entre os números %d e %d é: %d", num1, num2, soma);

    return 0;
}