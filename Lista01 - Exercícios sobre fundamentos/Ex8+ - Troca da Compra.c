#include <stdio.h>
int main(){
    float troco, compra, pagamento;

    printf("Digite o valo da compra: \n");
    scanf("%f", &compra);
    printf("Digite o valor recebido pelo cliente: \n");
    scanf("%f", &pagamento);

    if (pagamento<compra)
    { printf("Valor insuficiente!");
    } else {
        troco= pagamento-compra;
        printf("Seu troco será de R$%.2f!", troco);
    }

    return 0;
}