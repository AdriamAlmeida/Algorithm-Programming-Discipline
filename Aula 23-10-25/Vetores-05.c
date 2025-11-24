#include <stdio.h>

/*
5. Escreva um algoritmo que recebe 15 números inteiros informados
pelo usuário e os armazena em um vetor. Depois o algoritmo deve
verificar a quantidade de números pares e quantidade de números
múltiplos de 5.
*/

int main(){

    int entrada[15], y=1, par=0, múltiplo5=0;

    //Recebendo 15 números do usuário
    for (int i = 0; i <= 14; i++)
    {
        printf("Informe o %dº número inteiro:\n", y);
        scanf("%d", &entrada[i]);
        y++;
    }
    
    //Verificando se é par e múltiplo de 5
    for (int i = 0; i <= 14; i++)
    {
        if (entrada[i]%2==0)
        {
            par = par + 1;
        }
        if (entrada[i]%5==0)
        {
            múltiplo5 = múltiplo5 +1;
        }
    }

    //Imprindo os valores
    printf("A quantidade de número pares são %d\n", par);
    printf("A quantidade de número múltiplos de 5 são %d\n", múltiplo5);

    return 0;
}