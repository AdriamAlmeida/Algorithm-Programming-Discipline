#include <stdio.h>
int main(){
    float num1, peso1, num2, peso2, num3, peso3, vol_pond;

    printf("Digitem o primeiro valor e seu peso: \n");
    scanf("%f", &num1);
    scanf("%f", &peso1);
    printf("Digitem o segundo valor e seu peso: \n");
    scanf("%f", &num2);
    scanf("%f", &peso2);
    printf("Digitem o terceiro valor e seu peso: \n");
    scanf("%f", &num3);
    scanf("%f", &peso3);

    vol_pond= (num1*peso1*num2*peso2*num3*peso3)/(peso1*peso2*peso3);

    printf("O volume ponderado será %.2fcm^3", vol_pond);

    return 0;
}