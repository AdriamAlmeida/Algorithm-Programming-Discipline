#include <stdio.h>
#include <math.h>

/*
Categoria do Nadador Leia a idade de um nadador e classifique: Infantil (5-7), Juvenil
(8-10), Adolescente (11-15), Adulto (16-30), Senior (>30).
*/

int main(){
    int idade;
    
    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    if (idade==5-7)
    {
        printf("Você é um nadador infantil!");
    } else if (idade==8-10)
    {
        printf("Você é um nadador juvenil!");
    } else if (idade==11-15)
    {
        printf("Você é um nadador adolescente!");
    } else if (idade==16-30)
    {
        printf("Você é um nadador adulto!");
    } else if (idade>30)
    {
        printf("Você é um nadador Senior!!!");
    } 
    else {
        printf("A idade mínima requerida é 5 anos para cima.");
    }
    
    return 0;
}
