#include <stdio.h>
#include <math.h>
int main(){

/*
Equação do 2º Grau Leia a, b, c de uma equação ax²+bx+c=0. Calcule o discriminante e
informe se tem raízes reais. Se tiver, calcule-as usando sqrt().
*/

  float a, b, c, delta;
  
  printf("Digite os valores de A, B e C: \n");
  scanf("%f", &a);
  scanf("%f", &b);
  scanf("%f", &c);

  delta= pow(b, 2)-4*a*c;

  if (delta>0)
  {
    printf("A equação possui duas raízes reais");
  } else if (delta==0)
  {
    printf("A equação possui uma raíz real");
  } else {
    printf("A equação não possui raíz real");
  }
  
  return 0;
  
  }