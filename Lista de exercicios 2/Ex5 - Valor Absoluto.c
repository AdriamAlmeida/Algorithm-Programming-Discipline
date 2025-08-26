#include <stdio.h>
#include <math.h>

int main(){

    double num1, absoluto;

    printf("Digite um número: \n");
    scanf("%lf", &num1);

    absoluto= fabs(num1);
    
    printf("O número absoluto de %.2lf será: %.2lf", num1, absoluto);

    return 0;
}