#include <stdio.h>
int main(){
    float preço, desconto, valor_final;

    printf("Insira o valor do produto: \n");
    scanf("%f", &preço);
    printf("Insira o desconto que será aplicado: \n");
    scanf("%f", &desconto);

    desconto= desconto/100;
    valor_final= preço - desconto;

    printf ("O desconto aplicado será de: %.2f", valor_final);

    return 0;
}