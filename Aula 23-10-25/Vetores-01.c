#include <stdio.h>

/*
1. Vamos escrever um algoritmo em C que cria um vetor de
10 posições, preenche todas as posições com zero e depois
imprime o conteúdo do vetor.
*/

int main(){
    int vetor[10];

    //preenchendo o vetor
    for (int i = 0; i <= 9; i++)
    {
        vetor[i] = 0;
    
    }

    //imprimindo o vetor
    printf("%7s%13s\n", "elemento", "valor");
    
    for (int i = 0; i < 10; i++)
    {
        printf("%5d%13d\n", i, vetor[1]);
    }
    
    return 0;
}