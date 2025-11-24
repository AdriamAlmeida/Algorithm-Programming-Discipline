#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PONTUACAO_MAX 21
#define DEALER_STOP 17 // O dealer para de pedir cartas em 17 ou mais

// Protótipos das funções auxiliares
int obter_carta();
void vez_jogador(int *pontuacao_jogador);
void vez_dealer(int *pontuacao_dealer);
void determinar_vencedor(int jogador, int dealer);

int main() {
    // 1. Inicializa o gerador de números aleatórios
    srand(time(NULL)); 
    
    int pontuacao_jogador = 0;
    int pontuacao_dealer = 0;
    char jogar_novamente;

    printf("=======================================\n");
    printf("     🃏 JOGO 21 (BLACKJACK SIMPLIFICADO)   \n");
    printf("=======================================\n");
    
    // O Loop principal do jogo permite múltiplas rodadas
    do {
        pontuacao_jogador = 0;
        pontuacao_dealer = 0;

        printf("\n--- NOVA RODADA ---\n");
        
        // 2. Distribuição inicial de cartas
        printf("Sua primeira carta...\n");
        pontuacao_jogador += obter_carta();
        printf("Sua segunda carta...\n");
        pontuacao_jogador += obter_carta();
        printf("Sua pontuação inicial: **%d**\n", pontuacao_jogador);

        // A primeira carta do Dealer é revelada (para simulação)
        pontuacao_dealer += obter_carta();
        printf("Carta visível do Dealer: **%d**\n", pontuacao_dealer);
        // A segunda carta do Dealer é oculta
        pontuacao_dealer += obter_carta(); 
        
        // 3. Vez do Jogador
        vez_jogador(&pontuacao_jogador);
        
        // Se o jogador não estourou (passou de 21), é a vez do Dealer
        if (pontuacao_jogador <= PONTUACAO_MAX) {
            // 4. Vez do Dealer
            printf("\n--- VEZ DO DEALER ---\n");
            printf("Dealer revela sua segunda carta. Pontuação total: **%d**\n", pontuacao_dealer);
            vez_dealer(&pontuacao_dealer);
        }

        // 5. Determinação do Vencedor
        determinar_vencedor(pontuacao_jogador, pontuacao_dealer);

        // 6. Pergunta se deseja jogar novamente
        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);
        while (getchar() != '\n'); // Limpa o buffer de entrada
        
    } while (jogar_novamente == 's' || jogar_novamente == 'S');

    printf("\nObrigado por jogar! Tchau. 👋\n");
    return 0;
}

/**
 * Retorna um valor de carta aleatório (1 a 11)
 * Simula 10s e Figuras como 10, e o Ás como 11.
 */
int obter_carta() {
    // Gera um número entre 2 e 11 (2..9, 10, 11)
    // Para simplificar: 10, Valete, Dama, Rei valem 10. Ás vale 11.
    // rand() % 10 -> 0 a 9. + 2 -> 2 a 11.
    int valor = (rand() % 10) + 2;
    
    // Simula as Figuras (Valete, Dama, Rei) com o valor 10
    if (valor > 11) { // Só acontece se rand() % 10 for 10 ou mais, o que não é possível com % 10
        // Para manter a distribuição mais fiel, se o valor for 11, trata como Ás
        valor = 11;
    }
    
    // Para simplificar a distribuição em C:
    // Retorna 10 (cerca de 4/13), 11 (Ás, 1/13), 2-9 (1/13 cada)
    // Simulação mais simples:
    int carta_simples = (rand() % 11) + 1; // 1 a 11
    
    // Tratamento de Figuras (J, Q, K) como 10
    if (carta_simples >= 10) return 10;
    if (carta_simples == 1) return 11; // Ás vale 11
    return carta_simples;
}

/**
 * Gerencia a rodada do Jogador (uso de laço WHILE)
 */
void vez_jogador(int *pontuacao_jogador) {
    char acao;
    int nova_carta;
    
    // O loop continua enquanto o jogador não estourar E escolher 'P' (Pedir)
    while (*pontuacao_jogador < PONTUACAO_MAX) {
        printf("\nSua pontuação atual: **%d**\n", *pontuacao_jogador);
        printf("O que você deseja? (P)edir carta ou (F)icar: ");
        scanf(" %c", &acao);
        while (getchar() != '\n');
        
        if (acao == 'p' || acao == 'P') {
            nova_carta = obter_carta();
            *pontuacao_jogador += nova_carta;
            printf("Você recebeu a carta: **%d**\n", nova_carta);
            
            if (*pontuacao_jogador > PONTUACAO_MAX) {
                printf("💥 **Você estourou!** Pontuação: %d\n", *pontuacao_jogador);
                break;
            }
        } else if (acao == 'f' || acao == 'F') {
            printf("Você decidiu parar com **%d** pontos.\n", *pontuacao_jogador);
            break;
        } else {
            printf("⚠️ Ação inválida. Digite 'P' para Pedir ou 'F' para Ficar.\n");
        }
    }
}

/**
 * Gerencia a rodada do Dealer (uso de laço WHILE)
 */
void vez_dealer(int *pontuacao_dealer) {
    int nova_carta;

    // O loop continua enquanto o dealer tiver menos que DEALER_STOP (17)
    while (*pontuacao_dealer < DEALER_STOP) {
        printf("Dealer pede carta...\n");
        nova_carta = obter_carta();
        *pontuacao_dealer += nova_carta;
        printf("Dealer recebeu: **%d**. Pontuação total: **%d**\n", nova_carta, *pontuacao_dealer);

        if (*pontuacao_dealer > PONTUACAO_MAX) {
            printf("💥 **Dealer estourou!** Pontuação: %d\n", *pontuacao_dealer);
            break;
        }
    }
    
    if (*pontuacao_dealer >= DEALER_STOP && *pontuacao_dealer <= PONTUACAO_MAX) {
        printf("Dealer para com **%d** pontos.\n", *pontuacao_dealer);
    }
}

/**
 * Determina e exibe o vencedor
 */
void determinar_vencedor(int jogador, int dealer) {
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Sua Pontuação: %d\n", jogador);
    printf("Pontuação do Dealer: %d\n", dealer);
    
    // Condições de vitória
    if (jogador > PONTUACAO_MAX) {
        printf("🎉 **DEALER VENCE!** (Você estourou)\n");
    } else if (dealer > PONTUACAO_MAX) {
        printf("🏆 **VOCÊ VENCE!** (Dealer estourou)\n");
    } else if (jogador > dealer) {
        printf("🏆 **VOCÊ VENCE!** (Maior pontuação)\n");
    } else if (dealer > jogador) {
        printf("🎉 **DEALER VENCE!** (Maior pontuação)\n");
    } else {
        printf("🤝 **EMPATE!** (Push)\n");
    }
}