#include <stdio.h>
int main(){
    float capital_inicial, taxa_juros, tempo, juros_simples;

    printf("Digite o capital inicial, taxa de juros e o tempo: \n");
    scanf("%f", &capital_inicial);
    scanf("%f", &taxa_juros);
    scanf("%f", &tempo);

    juros_simples= capital_inicial*(taxa_juros/100)*tempo;

    printf("O juros simples será de: %f", juros_simples);

    return 0;

}