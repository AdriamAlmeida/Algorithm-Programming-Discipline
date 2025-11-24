#include <stdio.h>

int main (){

    char nome [100];
    
    printf("Digite seu nome: ");
    scanf("%s", &nome);

    printf("Olá, %s! Bem-vindo ao mundo da programação!", nome);

    return 0;
}