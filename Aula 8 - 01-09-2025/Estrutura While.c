#include <stdio.h>
int main(){
    int contador= 10;

    printf("Contagem regressiva: \n");
    while (contador>=0)
    {
        printf("%d... \n", contador);
        contador--;
    }
    
    printf("Decolagem!\n");

    return 0;
}