#include <stdio.h>
int main(){
    float área, raio, perímetro;
    float pi = 3.14;

    printf("Digite o valor do raio de um círculo: \n");
    scanf("%f", &raio);

    área = pi*raio;
    perímetro = 2*pi*raio;

    printf("O valor da área é de: %.2f\n", área);
    printf("O valor do perímetro é de: %.2f\n", perímetro);

    return 0;
}