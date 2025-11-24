#include <stdio.h>
int main(){
    float num1, num2, soma, sub, vezes, divisão;

    printf("Digite dois números reais: \n");
    scanf("%f", &num1);
    scanf("%f", &num2);

    soma= num1+num2;
    sub= num1-num2;
    vezes= num1*num2;
    divisão= num1/num2;

    printf("a soma entre os números %.2f mais %.2f será: %.2f\n", num1, num2, soma);
    printf("a subtração entre os números %.2f menos %.2f será: %.2f\n", num1, num2, sub);
    printf("a multiplicação entre os números %.2f vezes %.2f será: %.2f\n", num1, num2, vezes);
    printf("a divisão entre os números %.2f divido por %.2f será: %.2f\n", num1, num2, divisão);

    return 0;
}