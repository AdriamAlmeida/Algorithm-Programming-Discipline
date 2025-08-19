#include <stdio.h>
int main(){
    float largura, altura, área;

    printf("Digite a largura e a altura do retângulo: \n");
    scanf("%f", &largura);
    scanf("%f", &altura);

    área=largura*altura;

    printf("A área do retângulo é: %.2f", área);

    return 0;
}