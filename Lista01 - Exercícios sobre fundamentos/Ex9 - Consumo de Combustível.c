#include <stdio.h>
int main (){
    float distância, combustível, consumo_médio;

    printf("Digite a distância percorrida (em KM) de seu veículo e o combustível consumido (em L): \n");
    scanf("%f", &distância);
    scanf("%f", &combustível);

    consumo_médio= distância/combustível;

    printf("O consumo médio é: %.2f", consumo_médio);

    return 0;
}