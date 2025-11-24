#include <stdio.h>
#include <math.h>

/*
Conversão de Temperatura com Validação Leia uma temperatura em Celsius. Se estiver
entre -273 e 1000, converta para Fahrenheit. Senão, exiba erro.
*/

int main(){
    float celsius, Fahrenheint;

    printf("Digite uma temperatura: \n");
    scanf("%f", &celsius);

    if (celsius > -273 || celsius < 1000)
    {
        Fahrenheint= (celsius*(9/5))+32;
        printf("Convertendo a temperatura de %f°C em Fahrenheint será %f", celsius, Fahrenheint);
    }
    
}