#include <stdio.h>
int main(){
    float base, altura, área;

    printf("Digite a base e a altura do triângulo: \n");
    scanf("%f", &base);
    scanf("%f", &altura);

    área= base*altura;

    printf("A área do triângulo será %.2f", área);
    printf("E a área aumenta em 1 será %.2f", ++área);

    return 0;
}