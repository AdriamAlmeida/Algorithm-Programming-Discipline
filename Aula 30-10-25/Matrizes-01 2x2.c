#include <stdio.h>

/*
Vamos criar uma matriz com duas linhas e duas colunas para armazenar valores inteiros. Cada posição da matriz irá receber o seguinte valor: número linha*número coluna.
*/

int main(){

    int matriz [2][2];

    for (int i = 0; i < 2; i++) // preenche as linhas.
    {
        for (int j = 0; j < 2; j++) //preenche as colunas.
        {
            matriz[i][j] = i*j;
        }
    }
    
    //Imprimir os valores da matriz.
    printf("Matriz 2x2 \n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n"); //Quebra linha após cada linha da matriz.
    }

    return 0;
}