#include <stdio.h>
#include <stdlib.h> // Necessário para a função rand() e srand()
#include <time.h>   // Necessário para a função time()

int main() {
    // 1. Gerar um número aleatório (o "número secreto")
    int numero_secreto;
    // O 'srand' inicializa o gerador de números aleatórios
    // com base na hora atual para que o número secreto mude a cada execucao.
    srand(time(NULL)); 
    // rand() % 10 gera um número de 0 a 9. Adicionando 1, temos de 1 a 10.
    numero_secreto = (rand() % 10) + 1;

    // 2. Variaveis de controle
    int palpite = 0; // Palpite do usuário, inicializado com 0 para entrar no loop
    int tentativas = 0; // Contador de tentativas

    printf("--- Jogo de Adivinhacao (1 a 10) ---\n");
    printf("Tente adivinhar o numero secreto!\n");

    // 3. Loop principal (while)
    // Continua enquanto o palpite for diferente do número secreto
    while (palpite != numero_secreto) {
        
        // a) Incrementa o contador de tentativas
        tentativas++;
        
        // b) Solicita o palpite
        printf("\nTentativa #%d. Digite seu palpite (1 a 10): ", tentativas);
        scanf("%d", &palpite);
        
        // c) Feedback para o usuário
        if (palpite < numero_secreto) {
            printf("Seu palpite (%d) e muito baixo. Tente novamente!", palpite);
        } else if (palpite > numero_secreto) {
            printf("Seu palpite (%d) e muito alto. Tente novamente!", palpite);
        }
        
    } // O loop termina quando (palpite != numero_secreto) é falso

    // 4. Exibe a mensagem de sucesso e o total de tentativas
    printf("\n--- PARABENS! ---\n");
    printf("Voce acertou o numero %d em %d tentativas!\n", numero_secreto, tentativas);

    return 0;
}