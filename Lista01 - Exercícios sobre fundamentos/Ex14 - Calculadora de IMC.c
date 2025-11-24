#include <stdio.h>
int main(){
    float peso, altura, imc;

    printf("Digite seu peso e sua altura: \n");
    scanf("%f", &peso);
    scanf("%f", &altura);

    imc= peso/(altura*altura);

    printf("Seu IMC será de: %f", imc);

    return 0;
}