#include <stdio.h>

/*
2. Escreva um algoritmo em C que cria um vetor de 10 posições,
preenche o mesmo com os números pares a partir do 2 e depois
imprime o conteúdo do vetor.
*/

int main(){
     
     int vetor[10];

     for (int i = 0; i < 10; i++)
     {
        if (i%2==0)
        {
            vetor[i]= i;
        }
        else
        {
            vetor[i]=0;
        }
     }
     printf("%7s%13s\n", "elemento", "valor");
    
    for (int i = 0; i < 10; i++)
    {
        printf("%5d%13d\n", i, vetor[i]);
    }

    return 0;
}