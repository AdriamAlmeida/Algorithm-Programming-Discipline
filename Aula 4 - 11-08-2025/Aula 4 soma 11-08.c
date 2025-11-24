#include <stdio.h>

int main(){
    double num1;
    double num2;
    double media;

    printf("Digite os números para calcular a média entre eles: \n");
    scanf("%lf", &num1);
    scanf("%lf", &num2);

    media = (num1+num2)/2;

    printf("A média é: %.2lf", media);

    return 0;
}