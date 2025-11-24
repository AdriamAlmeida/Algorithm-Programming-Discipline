#include <stdio.h>
int main(){
    int ano = 365;
    int idade, dias_vivos;

    printf("Me diga sua idade: \n");
    scanf("%d", &idade);

    dias_vivos = idade*ano;

    printf("Uau que incrível, você está vivo há %d dias!!!", dias_vivos);

    return 0;
}