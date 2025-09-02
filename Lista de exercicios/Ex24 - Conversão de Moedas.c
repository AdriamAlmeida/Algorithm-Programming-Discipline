#include <stdio.h>
int main(){
    float reais, cotação_dol, dol;

    printf("Digite o valor em reais: ");
    scanf("%f", &reais);
    printf("Digite a cotação do dólar: ");
    scanf("%f", &cotação_dol);

    dol= reais/cotação_dol;

    printf("O valor em dolares será %f", dol);

    return 0;
}