#include <stdio.h>
int main(){
    float lado, área, perímetro;

    printf("Qual será o lado quadrado?: \n");
    scanf("%f", &lado);

    área= lado*lado;
    perímetro= 4*lado;

    printf("A área do quadrado será de: %f. E o perímetro será de: %f", área, perímetro);

    return 0;
}