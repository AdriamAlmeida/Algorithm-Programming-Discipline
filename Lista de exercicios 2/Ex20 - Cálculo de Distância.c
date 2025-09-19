#include <stdio.h>
#include <math.h>

/*
Cálculo de Distância Leia as coordenadas de dois pontos (x1,y1) e (x2,y2). Calcule a
distância entre eles usando sqrt() e pow().
*/

int main(){
    float x1, y1, x2, y2, form;

    printf("Digite a coordenada de x1 e y1: \n");
    scanf("%f %f", &x1, &y1);
    printf("Digite a coordenada de x2 e y2: \n");
    scanf("%f %f", &x2, &y2);

    form= sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

    printf(" A distância entre os pontos é %f", form);

    return 0;
}