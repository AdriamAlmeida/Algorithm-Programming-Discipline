#include <stdio.h>
#include <math.h>
int main(){
    float x1, x2, x3, delta, bhask, bhask2, raiz_quad;

    printf("Digite o valor de a: \n");
    scanf("%f", &x1);
    printf("Digite o valor de a: \n");
    scanf("%f", &x2);
    printf("Digite o valor de a: \n");
    scanf("%f", &x3);

    delta= (x2*x2)-4*x1*x3;
    raiz_quad= sqrt (delta);
    bhask= (-x2+raiz_quad)/(2*x1);
    bhask2= (-x2-raiz_quad)/(2*x1);

    if (delta<0)
    {
        printf("Raiz não encontrada!!");
    } else if (delta==0)
    {
        printf("O resultado será %f", bhask);
    } else if (delta>0)
    {
        printf("O valor de x1 será %.2f e o valor de x2 será %.2f", bhask, bhask2);
    }
    
    return 0;
}