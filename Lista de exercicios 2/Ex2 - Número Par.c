#include <stdio.h>
int main(){
    int num1;

    printf("Digite um número inteiro: \n");
    scanf("%d", &num1);

    if (num1%2==0)
    {
        printf("Número par!");
    }
    else{
        printf("Número ímpar!");
    }

    return 0;
}