#include <stdio.h>

/*
Crie um programa que: - Armazene a quantidade em estoque de 10 produtos em um vetor - Permita que o usuário informe as
quantidades iniciais - Simule 5 vendas (usuário informa qual produto foi vendido) - Atualize o estoque após cada venda - Ao final, exiba: -
Produtos com estoque zerado - Produtos com estoque baixo (menos de 5 unidades) - Total de produtos vendidos
*/

int main(){

    int y=1, x=1, vendas[5];
    char *estoque[10] = {
        "Produto-1",
        "Produto-2",
        "Produto-3",
        "Produto-4",
        "Produto-5",
        "Produto-6",
        "Produto-7",
        "Produto-8",
        "Produto-9",
        "Produto-10"
    };

    //Informar a quantidade dos produtos iniciais
    for (int i = 0; i < 10; i++)
    {
        printf("Informe a quantidade do %dº produto: \n", y);
        scanf("%s", &estoque[i]);
        y++;
    }

    //Informar os produtos vendidos
    for (int i = 0; i < 5; i++)
    {
        printf("Informe o %dº produto vendido e sua quantidade: \n", x);
        scanf("%d", &vendas[i]);
        x++;
    }

    //Resultados finais

    printf("\n ===ESTOQUE INCIAL=== \n");

    for (int i = 1; i <= 10; i++)
    {
        printf("Produto %d: %d unidades. \n", i, estoque[i]);
    }

    printf("\n ===VENDAS=== \n");
    printf("Quais produtos foram vendidos?\n");

    for (int i = 1; i <= 5; i++)
    {
        printf("%d Produto %d: %d unidades restantes \n", estoque[i], )
    }

    return 0;
}