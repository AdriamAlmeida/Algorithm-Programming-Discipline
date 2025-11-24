#include <stdio.h>
#include <stdlib.h> // Necessário para a função rand() e srand()
#include <time.h>   // Necessário para a função time()

int main() {
    // 1. Gerar um número aleatório (o "número secreto")
    int numero_secreto;
    // Inicializa o gerador de números aleatórios com a hora atual
    srand(time(NULL)); 
    // Gera um número no intervalo de 1 a 100
    numero_secreto = (rand() % 100) + 1; 

    // 2. Variaveis de controle
    int palpite = 0; // Palpite do usuário
    int tentativas = 0; // Contador de tentativas

    printf("--- Jogo de Adivinhacao (1 a 100) ---\n");
    printf("Tente adivinhar o numero secreto. Daremos dicas!\n");

    // 3. Loop principal (while)
    // O jogo continua enquanto o palpite for diferente do número secreto
    while (palpite != numero_secreto) {
        
        tentativas++;
        
        printf("\nTentativa #%d. Digite seu palpite (1 a 100): ", tentativas);
        
        // Verifica se a entrada e valida
        if (scanf("%d", &palpite) != 1) {
            printf("Entrada invalida. Por favor, digite um numero inteiro.\n");
            // Limpa o buffer de entrada
            while(getchar() != '\n'); 
            // Decrementa tentativas para nao contar a tentativa invalida
            tentativas--;
            continue; 
        }

        // 4. Feedback para o usuário
        if (palpite < 1 || palpite > 100) {
            printf("Seu palpite esta fora do intervalo (1 a 100). Tente novamente!");
        } else if (palpite < numero_secreto) {
            // Dica "maior"
            printf("Seu palpite e MUITO MENOR. Tente um numero MAIOR!");
        } else if (palpite > numero_secreto) {
            // Dica "menor"
            printf("Seu palpite e MUITO MAIOR. Tente um numero MENOR!");
        }
        
    } // O loop termina quando (palpite == numero_secreto)

    // 5. Exibe a mensagem de sucesso e o total de tentativas
    printf("\n\n--- PARABENS! VOCE ACERTOU! ---\n");
    printf("O numero secreto era %d.\n", numero_secreto);
    printf("Voce precisou de %d tentativas para vencer.\n", tentativas);

    return 0;
}