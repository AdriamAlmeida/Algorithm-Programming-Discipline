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

    printf("O resultado da soma entre os números escolhidos é: %.2f\n", soma);
    printf("O resultado da multiplicação entre os números escolhidos é: %.2f\n", multiplicação);
    printf("O resultado da subtração entre os números escolhidos é: %.2f\n", subtração);
    printf("O resultado da divisão entre os números escolhidos é: %.2f\n", divisão);
    printf("O resultado da divisão inversa entre os números escolhidos é: %.2f\n", resto);

    return 0;
}