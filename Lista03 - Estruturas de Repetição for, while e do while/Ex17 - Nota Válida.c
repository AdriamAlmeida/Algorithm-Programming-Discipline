#include <stdio.h>

/*
Nota Válida Desenvolva um programa que peça uma nota (0-10) e use do-while para
validar a entrada.
*/

int main(){
    float num;

    do {
        printf("Digite um numero: \n");
        scanf("%f", &num);

    } while (num<0 || num>10);

    printf("Numero valido");

    return 0;
}