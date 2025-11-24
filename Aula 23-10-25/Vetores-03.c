#include <stdio.h>

/*
3. Escrever um algoritmo que recebe como entrada 10 números
inteiros informados pelo usuários e os armazena em um vetor. Logo
após o seu algoritmo deverá imprimir os valores armazenados.
*/

int main(){

    int entrada[10], y=1;

    //Recebendo 10 números do usuário
    for (int i = 0; i < 9; i++)
    {
        printf("Informe o %dº número inteiro:\n", y);
        scanf("%d", &entrada[i]);
        y++;
    }

    //Imprimindo o vetor
    printf("%7s%13s\n", "elemento", "valor");
    
    for (int i = 0; i < 10; i++)
    {
        printf("%5d%13d\n", i, entrada[i]);
    }

    return 0;

}
