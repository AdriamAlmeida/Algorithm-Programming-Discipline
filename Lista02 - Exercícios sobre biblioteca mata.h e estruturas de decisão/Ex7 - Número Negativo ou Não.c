#include <stdio.h>
#include <math.h>
int main(){
    float num1;

    printf("Digite um número \n");
    scanf("%f", &num1);

    if (num1<0)
    {
        printf("Seu número é negativo \n");
    } else {
        printf("Seu número não é negativo \n");
    }
    
    return 0;
}