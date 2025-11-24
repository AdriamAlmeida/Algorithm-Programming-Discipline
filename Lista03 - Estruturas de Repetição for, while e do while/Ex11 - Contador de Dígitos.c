#include <stdio.h>
#include <math.h>

/*
Contador de Dígitos Escreva um programa que conte quantos dígitos tem um número
inteiro usando while.
*/

int main(){
    int num, contador=0;
    
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    while (num!=0)
    {
        num=num/10;
        contador++;
    }

    printf("Seu numero tem %d digitos", contador);

    return 0;

}