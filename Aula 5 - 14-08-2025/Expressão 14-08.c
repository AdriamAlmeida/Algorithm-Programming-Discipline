#include <stdio.h>

int main(){
    float num1, num2, num3;
    float resultado;
    
    printf("Digite 3 números reais: \n");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    resultado = (2*((num1-num3)/8)-num2*5);

    printf("O resultado é: %.2f", resultado);

    return 0;
}