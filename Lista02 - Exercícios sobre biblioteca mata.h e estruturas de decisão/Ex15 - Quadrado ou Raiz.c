#include <stdio.h>
#include <math.h>
int main(){
    float num;

    printf("Digite um número: \n");
    scanf("%f", &num);

    if (num>10)
    {
        printf("O quadrado do seu número é %.2f", pow(num, 2));
    } else {
        printf("A raiz do seu número é %.2f", sqrt(num));
    }
    
    return 0;
}