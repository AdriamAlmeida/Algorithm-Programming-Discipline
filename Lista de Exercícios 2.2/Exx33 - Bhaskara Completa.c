#include <stdio.h>
#include <math.h>
int main(){
    float a, b, c, delta, x1, x2;

    printf("Digite o valor de A: \n");
    scanf("%f", &a);
    printf("Digite o valor de B: \n");
    scanf("%f", &b);
    printf("Digite o valor de C: \n");
    scanf("%f", &c);

    delta= pow(b, 2)-4*a*c;
    x1= (-b+sqrt(delta))/(2*a);
    x2=(-b-sqrt(delta))/(2*a);

    if (delta>0)
    {
        printf("O valor do delta será %.2f e do x1 será %.2f e do x2 será %.2f!", delta, x1, x2);
    } else if (delta==0)
    {
        printf("O valor do delta será %.2f e do x será %.2f!", delta, x1);
    } else if (delta<0)
    {
        printf("O valor do delta será %.2f e não existe o x para essa equação!", delta);
    }
    
    return 0;
}