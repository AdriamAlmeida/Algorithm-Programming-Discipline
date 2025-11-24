#include <stdio.h>
int main(){
    float num1;
    float desconto;
    float valor_final;

    printf("Digite o valor do produto: \n");
    scanf("%f", &num1);
    
    desconto = (num1 * 0.09);
    valor_final = (num1 - desconto);

    printf("O valor do produto com o desconto aplicado será: %.2f", valor_final);

    return 0;

}