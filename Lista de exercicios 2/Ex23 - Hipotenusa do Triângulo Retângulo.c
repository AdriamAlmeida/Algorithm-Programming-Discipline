#include <stdio.h>
#include <math.h>

/*
Hipotenusa do Triângulo Retângulo Leia dois catetos de um triângulo retângulo. Se
ambos forem positivos, calcule a hipotenusa usando sqrt() e pow().
*/

int main (){
    double cat_adj, cat_op, hip;

    printf("Informe os valores do Cateto Adjascente e do Cateto Oposto: \n");
    scanf("%lf %lf", &cat_adj, &cat_op);

    if (cat_adj>=0 && cat_op>=0)
    {
        hip = sqrt(pow (cat_adj, 2) + pow(cat_op, 2));
        printf("O resultado será %.2lf", hip);
    }
    else {
        printf("Insira valores positivos");
    }
    return 0;
    
}