#include <stdio.h>

/*
Soma de Números Faça um programa que leia 5 números inteiros e calcule a soma usando
for.
*/

int main (){
    int num1, soma=0;

    for (int i = 1; i <= 5 ; i++)
    {
        printf("Digite um numero inteiro: \n");
        scanf("%d", &num1);

        soma=soma+num1;
    }

    printf("Soma dos numeros digitados: %d", soma);

    return 0;
}