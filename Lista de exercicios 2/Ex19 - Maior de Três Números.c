
#include <stdio.h>  
#include <math.h>

/*
Maior de Três Números Leia três números e determine qual é o maior usando estruturas de
decisão aninhadas.
*/

int main(){
    float num1, num2, num3, max;

    printf("Digite três números: \n");
    scanf("%f %f %f", &num1, &num2, &num3);

    max = num1;
    if (num2 > max)
    {
        max = num2;
    }
    if (num3 > max)
    {
        max = num3;
    }
        printf("O maior número é %.2f", max);

        return 0;

}