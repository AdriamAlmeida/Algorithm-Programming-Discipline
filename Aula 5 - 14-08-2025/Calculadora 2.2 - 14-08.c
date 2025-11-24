#include <stdio.h>

int main(){
    int num1;
    int num2;
    float soma;
    float multiplicação;
    float subtração;
    float divisão;
    float resto;

    printf("Digite seu número: \n");
    scanf("%d", &num1);
    scanf("%d", &num2);

    soma = num1+num2;
    multiplicação = num1*num2;
    subtração = num1-num2;
    divisão = num1/num2;
    resto = num1%num2;

    printf("O resultado da soma entre %d e %d é: %.2f\n", num1, num2, soma);
    printf("O resultado da multiplicação entre %d e %d é: %.2f\n", num1, num2, multiplicação);
    printf("O resultado da subtração entre %d e %d é: %.2f\n", num1, num2, subtração);
    printf("O resultado da divisão entre %d e %d é: %.2f\n", num1, num2, divisão);
    printf("O resultado da divisão inversa entre %d e %d é: %f.2\n", num1, num2, resto);

    return 0;
}