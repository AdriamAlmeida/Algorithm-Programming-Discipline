#include <stdio.h>
int main(){
    float nota1, nota2, nota3, total, média;

    printf("Quais foram suas notas?: \n");
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);

    total=nota1+nota2+nota3;
    média=total/3;

    printf("Sua média aritmética foi de: %.2f", média);

    return 0;
}