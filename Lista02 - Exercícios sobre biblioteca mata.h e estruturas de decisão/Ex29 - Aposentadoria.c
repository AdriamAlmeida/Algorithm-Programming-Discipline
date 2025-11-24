#include <stdio.h>

/*
Aposentadoria Leia idade e tempo de contribuição. Aposentadoria: (idade ≥65) OU (tempo
≥30) OU (idade+tempo ≥95).
*/

int main() {
    int idade;
    int tempo_contribuicao;
    int soma_idade_tempo;

    printf("--- Verificacao de Aposentadoria ---\n");
    
    // Leitura da Idade
    printf("Digite a idade: ");
    if (scanf("%d", &idade) != 1 || idade < 0) {
        printf("Erro: Idade invalida.\n");
        return 1;
    }

    // Leitura do Tempo de Contribuicao
    printf("Digite o tempo de contribuicao (em anos): ");
    if (scanf("%d", &tempo_contribuicao) != 1 || tempo_contribuicao < 0) {
        printf("Erro: Tempo de contribuicao invalido.\n");
        return 1;
    }

    // Calculo da soma dos pontos
    soma_idade_tempo = idade + tempo_contribuicao;

    // A condicao de aposentadoria eh: Condicao1 OU Condicao2 OU Condicao3
    if ( (idade >= 65) || 
         (tempo_contribuicao >= 30) || 
         (soma_idade_tempo >= 95) ) {
        
        // Se pelo menos uma das condicoes for verdadeira
        printf("\nRESULTADO: O individuo PODE se aposentar.\n");
        printf("Idade + Tempo: %d anos.\n", soma_idade_tempo);
        
    } else {
        // Se nenhuma das condicoes for verdadeira
        printf("\nRESULTADO: O individuo NAO pode se aposentar.\n");
        
        // Exibe o que falta para a aposentadoria
        printf("Faltam %d anos para atingir 65 anos de idade.\n", (idade < 65) ? (65 - idade) : 0);
        printf("Faltam %d anos para atingir 30 anos de contribuicao.\n", (tempo_contribuicao < 30) ? (30 - tempo_contribuicao) : 0);
        printf("Faltam %d pontos para atingir 95 pontos (Idade + Tempo).\n", (soma_idade_tempo < 95) ? (95 - soma_idade_tempo) : 0);
    }

    return 0;
}