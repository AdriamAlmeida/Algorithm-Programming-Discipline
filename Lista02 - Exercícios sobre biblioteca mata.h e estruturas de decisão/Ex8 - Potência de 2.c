#include <stdio.h>
#include <math.h>
int main(){
    float num1;

    printf("Digite um número \n");
    scanf("%f", &num1);

    printf("O valor será %.2f", pow(num1, 2));

    return 0;

}