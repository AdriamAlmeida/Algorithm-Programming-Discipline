#include <stdio.h>
#include <math.h>
int main(){
    float compra, desconto=10, valor_final;

    printf("Informe o valor da compra: \n");
    scanf("%f", &compra);

    valor_final= compra-(desconto/100*compra);

    if (compra>100)
    {
        printf("Parabéns, você receberá um desconto de 10%%, o valor que final será de R$%.2f", valor_final);
    } else {
        printf("O valor da sua compra de R$%.2f", compra);
    }
     return 0;
}