#include <stdio.h>

/*
Média de Notas Desenvolva um programa que leia 4 notas e calcule a média usando for.
*/

int main (){

    double nota, soma=0;

    for (int i = 1; i <=4; i++)
    {
        printf("Digite uma nota: \n");
        scanf("%lf", &nota);
        soma=soma+nota;
    }

    printf("A media das notas sao %.2lf", soma/4);
}