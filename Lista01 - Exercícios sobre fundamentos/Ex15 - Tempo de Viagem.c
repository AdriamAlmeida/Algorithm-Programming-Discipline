#include <stdio.h>
int main(){
    float dist, vm, tempo;

    printf("Digite a distância percorrida: \n");
    scanf("%f", &dist);
    printf("Digite a velocidade média: \n");
    scanf("%f", &vm);

    tempo= dist/vm;

    printf("O tempo gasto foi de: %.2fh", tempo);

    return 0;
}