#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Para a função strlen

#define TAMANHO 4 // O número de dígitos fixo (4)
#define MAX_TENTATIVAS 10 // Limite de tentativas

// Protótipo da função de geração do número secreto
void gerar_numero_secreto(char *secreto, int tamanho);

int main() {
    char numero_secreto[TAMANHO + 1]; // +1 para o terminador nulo '\0'
    char adivinhado[TAMANHO + 1];
    int tentativas = 0;
    int acertos = 0;
    char palpite;
    int jogo_terminado = 0;

    // 1. Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // 2. Gera o número secreto e inicializa o array de adivinhação
    gerar_numero_secreto(numero_secreto, TAMANHO);
    
    // Inicializa 'adivinhado' com underlines
    for (int i = 0; i < TAMANHO; i++) {
        adivinhado[i] = '_';
    }
    adivinhado[TAMANHO] = '\0'; // Adiciona o terminador nulo

    printf("======================================\n");
    printf("  🎯 JOGO DA FORCA NUMÉRICO (4 DÍGITOS)\n");
    printf("======================================\n");
    printf("Tente adivinhar o número secreto de 4 dígitos.\n");
    printf("Você tem %d tentativas.\n", MAX_TENTATIVAS);
    printf("--------------------------------------\n");

    // 3. O LOOP PRINCIPAL DO JOGO
    // O jogo continua enquanto houver tentativas E o número não tiver sido adivinhado
    while (tentativas < MAX_TENTATIVAS && !jogo_terminado) {
        printf("\nNúmero atual: %s\n", adivinhado);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        printf("Digite um dígito (0-9) como palpite: ");
        
        // Leitura do palpite (apenas um caractere)
        if (scanf(" %c", &palpite) != 1) { 
            printf("⚠️ Entrada inválida. Tente novamente.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n');
            continue;
        }
        
        // Limpa o restante da entrada (para garantir que só um char seja lido)
        while (getchar() != '\n');
        
        // Checagem de validade do palpite
        if (palpite < '0' || palpite > '9') {
            printf("❌ Palpite inválido! Digite um dígito de 0 a 9.\n");
            continue;
        }

        tentativas++;
        int acertou_na_rodada = 0;

        // 4. Laço FOR para checar o palpite contra cada dígito do segredo
        for (int i = 0; i < TAMANHO; i++) {
            // Se o palpite for igual ao dígito secreto E ainda não foi adivinhado
            if (palpite == numero_secreto[i] && adivinhado[i] == '_') {
                adivinhado[i] = palpite; // Revela o dígito
                acertos++;              // Incrementa o contador de acertos
                acertou_na_rodada = 1;  // Sinaliza acerto na rodada
            }
        }

        // 5. Feedback para o usuário
        if (acertou_na_rodada) {
            printf("✅ Parabéns! O dígito '%c' está no número!\n", palpite);
        } else {
            printf("❌ Que pena! O dígito '%c' NÃO está no número.\n", palpite);
        }

        // 6. Condição de Vitória (todas as posições preenchidas)
        if (acertos == TAMANHO) {
            jogo_terminado = 1;
        }
    }

    // 7. Fim do jogo (Resultado)
    printf("\n======================================\n");
    if (jogo_terminado) {
        printf("         🥳 VOCÊ VENCEU! 🥳          \n");
        printf("O número secreto era: **%s**\n", numero_secreto);
    } else {
        printf("         😥 FIM DE JOGO 😥           \n");
        printf("Suas tentativas acabaram.\n");
        printf("O número secreto era: **%s**\n", numero_secreto);
    }
    printf("======================================\n");

    return 0;
}

// Implementação da Função: Gera um número aleatório de 'tamanho' dígitos
void gerar_numero_secreto(char *secreto, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        // Gera um dígito aleatório de 0 a 9 e o armazena como caractere
        // '0' + (0..9) resulta no código ASCII do dígito.
        secreto[i] = '0' + (rand() % 10);
    }
    secreto[tamanho] = '\0'; // Adiciona o terminador nulo
}