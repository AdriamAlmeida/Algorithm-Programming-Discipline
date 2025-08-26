#include <stdio.h>
int main(){
    int idade;

    printf("Informe sua idade: ");
    scanf("%d", &idade);

    if (idade>=18)
    {
        printf("Maior de idade!");
        } else 
        {
            printf("Menor de Idade!");
            }
            
    return 0;
}