#include <stdio.h>
#include <math.h>

/*
Área do Círculo Condicional Leia o raio de um círculo. Se for positivo, calcule a área
usando M_PI. Senão, exiba mensagem de erro.
*/

int main (){
    double raio, area;

    printf("Digite o raio do círculo: \n");
    scanf("%lf", &raio);

    if (raio>0)
    {
        area = M_PI * pow(raio, 2);

        printf("O valor da área será %.2lfcm^2", area);
    } else
    {
        printf("\n === ERRO!!! === \n");
        printf("\n O valor do raio deve ser positivo para calcular a área! \n");
    }
    
    return 0;
}