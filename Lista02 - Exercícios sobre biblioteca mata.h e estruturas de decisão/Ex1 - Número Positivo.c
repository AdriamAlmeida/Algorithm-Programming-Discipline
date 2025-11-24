#include <stdio.h>
int main(){
    float num1;

    printf("Digite um número: \n");
    scanf("%f", &num1);

    if (num1>0)
    {
        printf("Número Positivo!");
    } else 
    {
        printf("Número Negativo!");
    }
    
    return 0;
}