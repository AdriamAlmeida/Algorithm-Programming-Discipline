#include <stdio.h>

/*
. Escreva um algoritmo em C que recebe como entrada 10 números
inteiros informados pelo usuários e os armazena-os em um vetor.
Depois, o seu algoritmo deve calcular a soma e a média dos
números armazenados. Ao final, o seu algoritmo deve imprimir o
vetor, a soma e a média de seus elementos.
*/

int main(){

    float entrada[10], y=1, soma=0;
    double média=0;

    //Recebendo 10 números do usuário
    for (int i = 0; i <= 9; i++)
    {
        printf("Informe o %.0fº número inteiro:\n", y);
        scanf("%f", &entrada[i]);
        y++;
    }

    //Cálculo da soma
    for (int i = 0; i <=9; i++)
    {
        soma = soma + entrada[i];
    }

    //Cálculo da média
     média= soma / 10;

    //Imprimindo o vetor
    for (int i = 0; i <= 9; i++)
    {
        printf("Vetor: %.0f\n", entrada[i]);
    }

    //Imprimindo soma e média
    printf("Soma: %.0f \n Média: %0.1lf\n", soma, média);
    
    return 0;
}