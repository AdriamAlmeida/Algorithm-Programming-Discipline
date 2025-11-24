#include <stdio.h>

/*
Senha Simples Crie um programa que peça uma senha (1234) e use do-while para
repetir até acertar.
*/

int main (){
    int senha;
    
    do {
        printf("Digite a senha: \n");
        scanf("%d", &senha);

    } while (senha!=1234);

    printf("Acesso liberado");

    return 0;
}