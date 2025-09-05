#include <stdio.h>
#include <math.h>
int main(){
    int idade;

    printf("Informe a sua idade: \n");
    scanf("%d", &idade);

    if (idade<=12)
    {
        printf("Criança!");
    } else{
        printf("Não é criança!");
    }

    return 0;
}