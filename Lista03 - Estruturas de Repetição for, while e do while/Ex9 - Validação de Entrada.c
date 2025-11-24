#include <stdio.h>
#include <math.h>

/*
Validação de Entrada Crie um programa que peça ao usuário um número entre 1 e 10. Use
while para repetir até que seja válido.
*/

int main(){
    int num1;

    while (num1<1 || num1>10)
    {
        printf("Digite um numero: \n");
        scanf("%d", &num1);
    }

    printf("Numero valido");

    return 0;
}