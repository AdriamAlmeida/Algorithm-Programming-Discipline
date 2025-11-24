#include <stdio.h>

int main (){
    float comprimento, largura, altura, volume;

    printf("Digite o comprimento da caixa: \n");
    scanf("%f", &comprimento);
    printf("Digite a largura da caixa: \n");
    scanf("%f", &largura);
    printf("Digite a alutura da caixa: \n");
    scanf("%f", &altura);

    volume= comprimento*largura*altura;

    printf("O volume será %.2fcm^3", volume);

    return 0;
}