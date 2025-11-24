#include <stdio.h>
/*
Divisão Sucessiva Desenvolva um programa que divida um número por 2 até que seja
menor que 1, contando as divisões.
*/

int main(){
    float num, div=0;

    printf("Digite um numero: \n");
    scanf("%f", &num);

    while (num>1)
    {
        num=num/2;
        div++;
    }

    printf("O numero foi dividido %.2f vezes para ser menor que 1.", div);

    return 0;
}