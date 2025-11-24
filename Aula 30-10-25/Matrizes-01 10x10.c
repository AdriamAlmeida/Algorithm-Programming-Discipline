#include <stdio.h>

/*
Vamos criar uma matriz com dez linhas e dez colunas para armazenar valores inteiros. Cada posição da matriz irá receber o seguinte valor: número linha*número coluna.
*/

int main(){

    int matriz [10][10];

    for (int i = 0; i < 10; i++) // preenche as linhas.
    {
        for (int j = 0; j < 10; j++) //preenche as colunas.
        {
            matriz[i][j] = i*j;
        }
    }
    
    //Imprimir os valores da matriz.
    printf("Matriz 10x10 \n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n"); //Quebra linha após cada linha da matriz.
    }

    return 0;
}