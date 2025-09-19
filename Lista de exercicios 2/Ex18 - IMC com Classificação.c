
#include <stdio.h>
#include <math.h>
int main(){

/*
IMC com Classificação Calcule o IMC e classifique: Abaixo do peso (<18.5), Normal
(18.5-24.9), Sobrepeso (25-29.9), Obeso (≥30).
*/

float peso, altura, IMC;

printf("Digite seu peso e altura: \n");
scanf("%f", &peso);
scanf("%f", &altura);

IMC= peso/(pow(altura,2));

if (IMC<18.5)
{
    printf("Você esta um pouco abaixo do peso");
} else if (IMC==18.5-24.9)
{
    printf("Você está no peso ideal");
} else if (IMC==25-29.9)
{
    printf("Você esta um pouco acima do peso");
} else {
    printf("Você está obeso");
}

return 0;

}