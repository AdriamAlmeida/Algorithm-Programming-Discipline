#include <stdio.h>

float calcularPesoIdeal(float altura, char sexo) {
    if (sexo == 'M' || sexo == 'm') {
        return (72.7 * altura) - 58;
    } 
    else {
        return (62.1 * altura) - 44.7;
    }
}

int main() {
    float altura, peso;
    char sexo;

    printf("Digite sua altura (ex: 1.75): ");
    scanf("%f", &altura);

    printf("Digite o sexo (M para masculino, F para feminino): ");
    scanf(" %c", &sexo);

    peso = calcularPesoIdeal(altura, sexo);

    printf("O peso ideal calculado e: %.2f kg\n", peso);

    return 0;
}