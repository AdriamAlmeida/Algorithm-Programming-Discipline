#include <stdio.h>

/*
Números Pares Escreva um programa que imprima todos os números pares de 2 a 50
usando for.
*/

int main (){
    for (int i = 1; i <=50; i++)
    {
        if (i%2==0)
        {
            printf("%d \n", i );
        }
    }

    return 0;
}