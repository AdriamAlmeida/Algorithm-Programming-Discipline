#include <stdio.h>

/*
Tarefa: Desenvolva um programa que: - Armazene as temperaturas máximas dos 7 dias da semana em um vetor - Calcule a temperatura média da semana - Identifique o dia mais quente e o dia mais frio - Conte quantos dias tiveram temperatura acima de 30°C.
*/

int main(){
 
    int temperatura[7], quente=0, frio=0, acima_30=0;
    double media=0, mais_quente = 0, mais_frio = 60;
    char *dias_da_semana[7] = {
        "Segunda-feira",
        "Terca-feira",
        "Quarta-feira",
        "Quinta-feira",
        "Sexta-feira",
        "Sabado",
        "Domingo"
    };


    // Armazenar a temperatura
    for (int i = 0; i < 7; i++)
    {
        printf("Informe a temperatura maxima de %s: \n", dias_da_semana[i]);
        scanf("%d", &temperatura[i]);
    }


    for (int i = 0; i < 7; i++)
    { //Declarar a média das temperaturas
        media = (media+temperatura[i]);
        

        if (temperatura[i]> mais_quente)
        { //Declarar a temperatura mais quente
            mais_quente = temperatura[i];
            quente = i;
        }
        if (temperatura[i]< mais_frio)
        { //Declarar a temperatura mais fria
            mais_frio = temperatura[i];
            frio = i;
        }
        if (temperatura[i] >= 30)
        { //Declarar temperaturas de 30°C para cima
            acima_30++;
        }
    }

    // IMPRIMINDO OS VALORES
    printf("\n === Central de Temperatura da semana === \n");


    //Imprindo os dias da semana e suas rescpectivas temperaturas
    for (int i = 0; i < 7; i++)
    {
        printf("%s: %dC \n", dias_da_semana[i], temperatura[i]);
    }


    //Quebra de linha
    printf("\n");

    //Imprimindo a média das temperaturas, dia mais quente e mais frio de a quantidade de dias de 30°C para cima
    printf("Temperatura media: %.2lfC \n", media/7);
    printf("Dia mais quente: %s (%.2lfC) \n", dias_da_semana[quente], mais_quente);
    printf("Dia mais frio: %s (%.2lfC) \n", dias_da_semana[frio], mais_frio);
    printf("Dias acima de 30C: %d dias", acima_30);

    return 0;
}