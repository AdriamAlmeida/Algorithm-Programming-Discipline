#include <stdio.h>
int main(){
    float número_real;
    float desc = 0.04;
    float valor_final;

    printf("Digite um número real: \n");
    scanf("%f", &número_real);

    valor_final = número_real*desc;

    printf("O valor lido do desconto aplicado em %.2f é: %.2f", número_real, valor_final);

    return 0;
    }