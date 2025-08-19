#include <stdio.h>
int main(){
    float pi=3.14, raio, perímetro;

    printf("Digite o raio do círculo: \n");
    scanf("%f", &raio);
    
    perímetro= 2*pi*raio;

    printf("O perímetro do círculo é de: %.2f", perímetro);

    return 0;
    }