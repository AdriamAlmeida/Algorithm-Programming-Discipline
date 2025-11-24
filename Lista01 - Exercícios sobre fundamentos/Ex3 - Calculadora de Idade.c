#include <stdio.h>
int main(){
    int ano_atual, ano_nasc, idade;

    printf("Digite o ano em que você está e o ano em que você nasceu: \n");
    scanf("%d", &ano_atual);
    scanf("%d", &ano_nasc);

    idade = ano_atual-ano_nasc;

    printf("Sua idade é: %d", idade);

    return 0;

}