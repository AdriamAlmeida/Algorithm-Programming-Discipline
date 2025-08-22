#include<stdio.h>
int main(){
    int idade;
    
    printf("Informe sua idade: \n");
    scanf("%d", &idade);

    if (idade >=18 && idade < 65)
    {
        printf("Você é maior de idade!");

    } else if (idade>= 65)
    {
        printf("Você possui idade de 65 ou mais!");

    } else{
        printf("Você é menor de idade!!!");
    
    }

    return 0;
    
}