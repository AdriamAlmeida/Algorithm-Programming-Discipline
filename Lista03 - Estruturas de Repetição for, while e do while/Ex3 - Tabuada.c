#include <stdio.h>

/*
Tabuada Desenvolva um programa que leia um número e exiba sua tabuada (de 1 a 10)
usando for.
*/

int main(){

    int num1;

    printf("Digite um numero: \n");
    scanf("%d", &num1);

    for (int i = 1; i <=10; i++)
    {
        printf("%d x %d = %d \n", num1, i, num1*i);
    }
    
    return 0;
}