#include <stdio.h>
int main(){
    float nota;
    
    printf("Digite a nota do aluno: \n");
    scanf("%f", &nota);

    if (nota>=7)
    {
        printf("Parabéns, você foi aprovado!");
    } else {
        printf("Infelizmente você foi reprovado :(");
    }
    
    return 0;
}