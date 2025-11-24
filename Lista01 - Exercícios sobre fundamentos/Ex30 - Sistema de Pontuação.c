#include <stdio.h>
int main(){
    int num1, pontuação=0;
    char resp = 's';

    printf("Descubra a regra do jogo. Sua pontuação inicial será de 0 pontos, digite um número para começar \n");

    do
    {
        printf("Digite um número\n");
        scanf("%d", &num1);

        if (num1%5==0)
        {
            ++pontuação;
            printf("Parabéns, você acertou um dos números, %d pontos\n", pontuação);
        }
        else{
            --pontuação;
            printf("Número errado, tente denovo. %d pontos\n", pontuação);
        }
        
        if (pontuação<0)
        {
            printf("Você perdeu o jogo, deseja começar denovo? s/n\n");
            scanf(" %c", &resp);

            if (resp== 's')
            {
                pontuação=0;
            }
            else{
                printf("Obrigado por jogar\n");
            }
        }
        
        
    } while (pontuação>=0 && pontuação!=5);


    return 0;
    
}