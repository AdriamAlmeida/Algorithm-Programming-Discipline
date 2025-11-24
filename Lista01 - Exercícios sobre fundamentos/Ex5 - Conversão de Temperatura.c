#include <stdio.h>
int main (){
    float C, F;

    printf("Digite uma temperatura em Celsius: ");
    scanf("%f", &C);

    F = (C*1.8)+32;

    printf("A temperatura em Fahrenheit é: %.2f°", F);

    return 0;
}