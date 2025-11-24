#include <stdio.h>
#include <math.h>

/*
Menu Simples Faça um programa com menu usando while: 1-Somar, 2-Subtrair, 3-Sair.
*/

int main(){
    float num1, num2;
    int menu;

    while (menu!=3)
    {
        printf("O que deseja fazer?\n 1-Somar\n 2-Subtrair\n 3-Sair\n");
        scanf("%d", &menu);

        if (menu==1)
        {
            printf("Digite dois numeros: \n");
            scanf("%f %f", &num1, &num2);
            
            printf("A soma entre os numeros %.2f e %.2f sera %.2f \n", num1, num2, num1+num2);
        } 
        else if (menu==2)
        {
            printf("Digite dois numeros: \n");
            scanf("%f %f", &num1, &num2);
            
            printf("A subtracao entre os numeros %.2f e %.2f sera %.2f \n", num1, num2, num1-num2);
        } 
        else
        {
            printf("Voce saiu!");
        }
    }
    
    return 0;
}