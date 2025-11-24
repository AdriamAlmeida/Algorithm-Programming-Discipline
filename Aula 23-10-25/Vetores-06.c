#include <stdio.h>

/*
Crie um programa que solicite ao usuário 10 números e os armazenando em um vetor. Então monte outro vetor com os valores do primeiro multiplicados por 5. Exiba os valores dos dois vetores na tela, simultaneamente, em duas colunas (um em cada coluna), uma posição por linha.
*/

int main(){

    int vetor[10], y=1, multiplicar[10];

    //Recebendo 10 números do usuário
    for (int i = 0; i <= 9; i++)
    {
        printf("Informe o %dº número inteiro:\n", y);
        scanf("%d", &vetor[i]);
        y++;

    }

    //Multiplicando os números recebidos por 5
    for (int i = 0; i <= 9; i++)
    {
        multiplicar[i] = vetor[i]*5;
    }


    //Imprimindo os valores
    printf("%7s%15s\n", "Vetor", "Vetor*5");

    for (int i = 0; i <= 9; i++)
    {
        printf("%5d%15d\n", vetor[i], multiplicar[i]);
    }

    return 0;
}