#include <stdio.h>

float calcularVolumeEsfera(float raio) {
    float pi = 3.14159;
    return (4.0 / 3.0) * pi * (raio * raio * raio);
}

int main() {
    float raio, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    volume = calcularVolumeEsfera(raio);

    printf("O volume da esfera e: %.2f\n", volume);

    return 0;
}