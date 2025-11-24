#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
• Tarefa: Crie um programa que:
• Armazene 6 números sorteados (de 1 a 60) em um vetor
• Leia 6 números apostados pelo usuário, Verifique quantos números o usuário acertou, Exiba quais números foram acertados
• Classifique o resultado:
• 6 acertos: SENA, 5 acertos: QUINA, 4 acertos: QUADRA, 3 acertos ou menos: Não premiado
• Desafio extra: Não permita números repetidos nem números fora da faixa 1-60
*/

int main(){

    srand(time(NULL));

    int aposta[6], x=1, num_gerados = 0, novo_num, duplicado = 0, sorteio[6];

    //Números apostados
    printf("\n ==Escolha 6 número entre 1 até 60== \n");
    for (int i = 0; i < 6; i++)
    {
        printf("Digite seu %dº número: \n", x);
        scanf("%d", &aposta[i]);
        x++;
    }

    //Sorteando 6 números para a Mega-Sena
    for (int i = 0; i < 6; i++)
    {
        while (num_gerados < 6)
        {
            //Gera um número entre 1 e 60
            novo_num = (rand() % 60) + 1;

            //Verifica se o número já foi sorteado
            for (int i = 0; i < num_gerados; i++)
            {
                if (sorteio[i] == novo_num)
                {
                    duplicado = 1;
                    break; //Para o 'for' se encontrar uma duplicata
                }
            }

            //Se não for duplicado, adiciona ao vetor
            if (!duplicado)
            {
                sorteio[i] = novo_num;
                num_gerados++;
            }
        }
    }


/*
    for (int i = 0; i < 6; i++)
    {
        if (aposta[i]<1 || aposta[i]>60)
        {
            printf("\n === ATENÇÃO!!! === \n");
            printf("Números fora da Faixa. Por favor informe 6 números entre 1 até 60!");
        }
        else
        {
            
        }
    }
*/

    return 0;
}