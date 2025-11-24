#include <stdio.h>
int main(){
    float v_produto, v_pago, troco;

    printf("Informe o valor do produto e o valor pago: \n");
    scanf("%f", &v_produto);
    scanf("%f", &v_pago);

    troco= v_produto-v_pago;

    printf("Seu troco será de:R$%.2f!", troco);

    return 0;
}