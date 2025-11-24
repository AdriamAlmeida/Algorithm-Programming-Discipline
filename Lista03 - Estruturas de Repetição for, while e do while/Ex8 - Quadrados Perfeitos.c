#include <stdio.h>
#include <math.h>

/*
Quadrados Perfeitos Faça um programa que exiba os quadrados dos números de 1 a 15 (1²,
2², 3², ..., 15²).
*/

int main(){
    for (int i = 1; i <=15; i++)
    {
        printf("%d^2 = %.0lf \n", i, pow(i,2));
    }

    return 0;
}