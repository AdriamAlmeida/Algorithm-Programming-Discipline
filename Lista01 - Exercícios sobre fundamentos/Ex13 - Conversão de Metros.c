#include <stdio.h>
int main(){
    float metros, centímetros, quilômetros, milímetros;
    
    printf("Digite um número para que eu possa convertê-lo: \n");
    scanf("%f", &metros);

    centímetros= metros*100;
    quilômetros= metros/1000;
    milímetros= metros*1000;

    printf("%.2fm convertido em centímetros será %f\n", metros, centímetros);
    printf("%.2fm convertido em quilômetros será %f\n", metros, quilômetros);
    printf("%.2fm convertido em milímetros será %f\n", metros, milímetros);

    return 0;
}