#include <stdio.h>
#include <math.h>
int main(){
    float angulo, rad, seno, p=3.14;

    printf("Digite um ângulo: \n");
    scanf("%f", &angulo);

    rad= angulo*(p/180);
    seno= sin(rad);

    printf("O seno do ângulo %.2f°, será de %.2f", angulo, seno);

    return 0;
}