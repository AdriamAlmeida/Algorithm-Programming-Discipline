#include <stdio.h>
#include <math.h>

/*
Salário com Aumento Leia o salário atual. Se for ≤R$1000, aumento de 20%. Se for
≤R$2000, aumento de 15%. Senão, 10%.
*/

int main(){
    float salario;

    printf("Digite seu salário: \n");
    scanf("%f", &salario);

    if (salario<=1000)
    {
        salario = (salario * 20) / 100 + salario;
        printf("Você recebeu um aumento de 20%%, seu salário atual será de R$%.2f", salario);
    }
    else if (salario<=2000)
    {
        salario = ( salario * 15 ) / 100 + salario;
        printf("Você recebeu um aumento de 15%%, seu salário atual será de R$%.2f", salario);
    }
    else{
        salario = ( salario * 10 ) / 100 + salario;
        printf("Você recebeu um aumento de 10%%, seu salário atual será de R$%.2f", salario);
    }

    return 0;
    
}