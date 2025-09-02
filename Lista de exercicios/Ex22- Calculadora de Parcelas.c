#include <stdio.h>
int main(){
    float valor_prod, quant_parcelas, valor_parcelas;

    printf("Digite o valor do produto:\n");
    scanf("%f", &valor_prod);
    printf("Digite a quantidade de parcelas:\n");
    scanf("%f", &quant_parcelas);

    valor_parcelas= valor_prod/quant_parcelas;

    printf("O valor de cada parcela será de R$%.2f", valor_parcelas);

    return 0;
}   