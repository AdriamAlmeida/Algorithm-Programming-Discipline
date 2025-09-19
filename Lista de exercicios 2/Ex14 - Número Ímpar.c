#include <stdio.h>
#include <math.h>
int main(){
    int num;
    
    printf("Digite um número inteiro: \n");
    scanf("%d", &num);

    if (num%2!=0)
    {
        printf("Esse número é ímpar");
    } else{
        printf("Esse número é par");
    }
    
    return 0;
}
