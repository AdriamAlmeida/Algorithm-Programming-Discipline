#include <stdio.h>
#include <math.h>
int main (){
    float num1, num2, num3;

    printf("Digite três números; \n");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    if (num1+num2>num3)
    {
        printf("Esse triângulo é um triângulo válido");
    } else if (num1==num2==num3)
    {
        printf("É um triângulo equilátero");

    } else if (num1==num2!=num3)
    {
        printf("É um triângulo isósceles");

    } else if (num1!=num2!=num3)
    {
        printf("É um triângulo escaleno");

    } else if (num1+num2<num3)
    {
        printf("Esse triângulo não é um triângulo válido");
    }
    
    
    
    return 0;
    
}