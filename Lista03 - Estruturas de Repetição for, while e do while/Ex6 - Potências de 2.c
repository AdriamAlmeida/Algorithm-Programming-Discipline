#include <stdio.h>
#include <math.h>

/*
Potências de 2 Crie um programa que calcule e exiba as primeiras 10 potências de 2 (2¹, 2²,
2³, ..., 2¹⁰)
*/

int main(){
    for (int i = 1; i <=10; i++)
    {
        printf("2^%d = %.0lf \n", i, pow(2, i));
    }

    return 0;
}