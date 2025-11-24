#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Necessário para a função strcpy

#define MAX_ALUNOS 30
#define MAX_NOTAS 4
#define TAM_NOME 50

// Arrays globais para o sistema
char nomes[MAX_ALUNOS][TAM_NOME];
float notas[MAX_ALUNOS][MAX_NOTAS];
int num_alunos = 0; // Contador de alunos matriculados

// Protótipos das Funções
void adicionar_aluno();
void calcular_media_aluno(int indice);
void exibir_estatisticas_turma();
void exibir_boletim();

int main() {
    int opcao;

    do {
        // system("cls || clear"); // Opcional: Limpar a tela

        // --- Menu Principal ---
        printf("\n======================================\n");
        printf("  📚 SISTEMA DE NOTAS DA TURMA  \n");
        printf("======================================\n");
        printf("1. Adicionar Aluno e Notas\n");
        printf("2. Exibir Boletim Completo\n");
        printf("3. Exibir Estatísticas da Turma\n");
        printf("0. Sair\n");
        printf("--------------------------------------\n");
        printf("Alunos matriculados: %d/%d\n", num_alunos, MAX_ALUNOS);
        printf("--------------------------------------\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nOpção inválida. Digite um número.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n'); 
            continue;
        }

        // Limpa o buffer após a leitura do número
        while (getchar() != '\n'); 

        switch (opcao) {
            case 1:
                adicionar_aluno();
                break;
            case 2:
                exibir_boletim();
                break;
            case 3:
                exibir_estatisticas_turma();
                break;
            case 0:
                printf("\nEncerrando o Sistema de Notas. Até mais! 👋\n");
                break;
            default:
                printf("\n⚠️ Opção inválida! Escolha de 0 a 3.\n");
                break;
        }

        // Pausa opcional para visualização
        if (opcao != 0) {
            printf("\n(Pressione ENTER para voltar ao menu...)");
            getchar();
        }

    } while (opcao != 0);

    return 0;
}

/**
 * Função 1: Adiciona um novo aluno e suas notas
 */
void adicionar_aluno() {
    if (num_alunos >= MAX_ALUNOS) {
        printf("\n❌ Limite máximo de alunos (%d) atingido.\n", MAX_ALUNOS);
        return;
    }

    printf("\n--- ADICIONAR ALUNO ---\n");
    printf("Digite o nome do aluno: ");
    // Lê a linha inteira, garantindo que não exceda o limite do array
    if (fgets(nomes[num_alunos], TAM_NOME, stdin) == NULL) {
        printf("❌ Erro ao ler o nome.\n");
        return;
    }
    // Remove o newline ('\n') adicionado pelo fgets, se houver
    size_t len = strlen(nomes[num_alunos]);
    if (len > 0 && nomes[num_alunos][len - 1] == '\n') {
        nomes[num_alunos][len - 1] = '\0';
    }

    printf("Digite as %d notas para %s:\n", MAX_NOTAS, nomes[num_alunos]);
    
    // Laço FOR para ler as notas
    for (int i = 0; i < MAX_NOTAS; i++) {
        printf("Nota %d: ", i + 1);
        if (scanf("%f", &notas[num_alunos][i]) != 1) {
            printf("❌ Erro: Entrada inválida. Nota deve ser numérica.\n");
            // Limpa o buffer e aborta a adição deste aluno
            while (getchar() != '\n');
            return; 
        }
    }
    
    num_alunos++; // Incrementa o contador de alunos
    printf("✅ Aluno '%s' adicionado com sucesso!\n", nomes[num_alunos - 1]);
    
    // Limpa o buffer após a última leitura de nota
    while (getchar() != '\n');
}

/**
 * Função Auxiliar: Calcula a média de um aluno específico
 */
void calcular_media_aluno(int indice) {
    if (indice < 0 || indice >= num_alunos) return; // Checagem de índice
    
    float soma = 0.0;
    // Laço FOR para somar as notas do aluno
    for (int i = 0; i < MAX_NOTAS; i++) {
        soma += notas[indice][i];
    }
    printf("Média: **%.2f**", soma / MAX_NOTAS);
}

/**
 * Função 2: Exibe o Boletim Completo
 */
void exibir_boletim() {
    if (num_alunos == 0) {
        printf("\nNão há alunos cadastrados.\n");
        return;
    }
    
    printf("\n--- BOLETIM DA TURMA ---\n");
    printf("Nome\t\tNotas\t\t\tMédia\tSituação\n");
    printf("----------------------------------------------------------------\n");

    // Laço FOR principal para iterar sobre CADA ALUNO
    for (int i = 0; i < num_alunos; i++) {
        printf("%-15s", nomes[i]); // Exibe o nome

        float soma = 0.0;
        // Laço FOR ANINHADO para exibir CADA NOTA e calcular a soma
        for (int j = 0; j < MAX_NOTAS; j++) {
            printf("%.1f ", notas[i][j]);
            soma += notas[i][j];
        }

        float media = soma / MAX_NOTAS;
        char situacao[20];
        
        // Determina a situação (Condicional Avançado)
        if (media >= 7.0) {
            strcpy(situacao, "APROVADO");
        } else if (media >= 5.0) {
            strcpy(situacao, "RECUPERAÇÃO");
        } else {
            strcpy(situacao, "REPROVADO");
        }
        
        printf("\t%.2f\t%-15s\n", media, situacao);
    }
}

/**
 * Função 3: Exibe Estatísticas da Turma
 */
void exibir_estatisticas_turma() {
    if (num_alunos == 0) {
        printf("\nNão há alunos cadastrados para estatísticas.\n");
        return;
    }
    
    printf("\n--- ESTATÍSTICAS DA TURMA ---\n");
    
    float soma_geral = 0.0;
    float maior_media = -1.0;
    float menor_media = 11.0; // Valor inicial maior que o máximo possível
    
    // Laço FOR principal para iterar sobre CADA ALUNO
    for (int i = 0; i < num_alunos; i++) {
        float soma_aluno = 0.0;
        
        // Laço FOR ANINHADO para calcular a média de cada aluno
        for (int j = 0; j < MAX_NOTAS; j++) {
            soma_aluno += notas[i][j];
        }
        
        float media_aluno = soma_aluno / MAX_NOTAS;
        soma_geral += media_aluno;
        
        // Verifica a maior e menor média
        if (media_aluno > maior_media) {
            maior_media = media_aluno;
        }
        if (media_aluno < menor_media) {
            menor_media = media_aluno;
        }
    }
    
    float media_turma = soma_geral / num_alunos;
    
    printf("Média Geral da Turma: **%.2f**\n", media_turma);
    printf("Maior Média Individual: **%.2f**\n", maior_media);
    printf("Menor Média Individual: **%.2f**\n", menor_media);
    printf("Total de Alunos: %d\n", num_alunos);
}