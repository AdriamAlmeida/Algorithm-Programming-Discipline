#include <stdio.h>
#include <math.h>

/*
Maior Número Crie um programa que leia números até o usuário digitar -1 e encontre o
maior.
*/

int main(){
    float num1, maior=0;

    while (num1 >= -1)
    {
        printf("Digite um numero: \n");
        scanf("%f", &num1);

        if (num1>maior)
        {
            maior=num1;
        }
    }
    printf("O maior numero sera %.0f", maior);

    return 0;
}