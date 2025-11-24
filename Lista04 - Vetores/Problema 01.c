# include <stdio.h>

/*
• Tarefa: Crie um programa que:
• Armazene em um vetor os votos recebidos por cada um dos 5 candidatos
• Permita que o usuário digite quantos votos cada candidato recebeu
• Calcule e exiba o total de votos
• Identifique e exiba o candidato vencedor (aquele com mais votos)
*/

int main(){

    int votos[5], candidato, y=1, x=1, vencedor=0, total=0;

    // Armazenar quantidade de votos
    for (int i = 0; i < 5; i++)
    {
        printf("Informe a quantidade de votos do %dº candidato: ", y);
        scanf("%d", &votos[i]);
        y++;
    }

    // Declarar o vencedor e o total de votos
    for (int i = 0; i < 5; i++)
    {
        if (votos[i]>vencedor)
        {
            vencedor= votos[i];
            candidato= i+1;
        }

        total = total + votos[i];

    }
    
    //resultados das eleições com candidatos e suas respectivas quantidades de votos, declarar total de votos e o vencedor das eleições
    printf("\n === RESULTADO DAS ELEIÇÕES 2025 === \n");

    for (int i = 0; i < 5; i++)
    {
        printf("Candito %d: %d votos \n", x, votos[i]);
        x++;
    }

    printf("Total de votos: %d \n", total);
    printf("Candidato vencedor: Candidato %d com %d votos \n", candidato, vencedor);

    return 0;
}