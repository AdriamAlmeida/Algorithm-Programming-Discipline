#include <stdio.h>
#include <math.h>
int main(){
    float num1, res;

    printf("Digite um número \n");
    scanf("%f", &num1);

    res=log(num1);

    if (res<0)
    {
        printf("ERRO!!!");
    } else{
        printf("O valor de log do número digitado será %.2f", res);
    }
    
    return 0;

}