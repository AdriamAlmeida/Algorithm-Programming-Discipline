#include <stdio.h>
#include <math.h>

/*
Soma até Zero Desenvolva um programa que leia números inteiros até que o usuário digite
0, então exiba a soma.
*/

int main (){
    int num1, soma=0;

    while (num1 != 0)
    {   
        printf("Digite dois numeros inteiros: \n");
        scanf("%d", &num1);

        soma=soma+num1;
    }

    printf("soma dos numeros sera %d", soma);

    return 0;
}