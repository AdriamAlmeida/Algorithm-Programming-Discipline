#include <stdio.h>

/*
Menu com DO-WHILE Refaça o exercício 12 usando do-while para garantir que o
menu apareça pelo menos uma vez.
*/

int main (){
    float num1, num2;
    int menu;

    do {
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
    } while (menu!=3);

    return 0;

}