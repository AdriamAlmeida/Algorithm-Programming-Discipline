#include <stdio.h>
#include <math.h>
int main(){
    float num1, num2;

    printf("Digite dois números \n");
    scanf("%f", &num1);
    scanf("%f", &num2);

    if (num1>num2)
    {
        printf("%.2f é maior que %.2f", num1, num2);
    } else {
        printf("%.2f é maior que %.2f", num2, num1);
    }
    
    return 0;
}