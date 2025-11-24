#include <stdio.h>
#include <math.h>

int main(){
    float num1;
    double raiz;

    printf("Digite um número: \n");
    scanf("%f", &num1);

    if (num1>0)
    {
        raiz=sqrt(num1);
        printf("A raiz quadrada de %.2f é: %.2lf", num1, raiz);
    } else {
        printf("Raiz negativa não existe!");
    }

    return 0;
    
}