#include <stdio.h>
int main(){
    int segundos, segundos_rest;
    float horas, minutos;

    printf("Quantos segundos?: \n");
    scanf("%d", &segundos);

    minutos= segundos/60;
    horas= segundos/3600;
    segundos_rest= segundos%60;
    segundos= segundos%3600;

    printf("%.2ds, %.2fm, %.2fh, %.2d segundos restantes", segundos, minutos, horas, segundos_rest);

    return 0;
}