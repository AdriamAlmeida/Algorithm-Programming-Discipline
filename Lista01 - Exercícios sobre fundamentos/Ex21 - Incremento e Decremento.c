#include <stdio.h>

int main (){

  int num1;

  printf("Digite um valor; \n");
  scanf("%d", &num1);

  printf("O número digitado foi %d, agora vamos ver com incremento e decremento\n", num1);
  printf("Número digitado pos incremento na mesma linha: %d\n", num1++);
  printf("Número digitado pos incremento na próxima linha: %d\n", num1);
  printf("Número digitado pré incremento na mesma linha: %d\n", ++num1);
  printf("Número digitado pos decremento na mesma linha: %d\n", num1--);
  printf("Número digitado pos decremento na próxima linha: %d\n", num1);
  printf("Número digitado pré decremento na mesma linha: %d\n", --num1);

  return 0;
}