#include <stdio.h>
int main(){
    int A, B;

    printf("Digite dois números inteiros: \n");
    scanf("%d", &A);
    scanf("%d", &B);

    if (A%2==0 && B%2==0)
    {
        printf("Ambos números informados são pares!");
        
    }else if (A%2 == 0 || B%2 == 0)
    {
        printf("Um dos número %d ou %d é par", A, B);
    } else {
        printf("Todos são ímpares");
    }

    return 0;
}