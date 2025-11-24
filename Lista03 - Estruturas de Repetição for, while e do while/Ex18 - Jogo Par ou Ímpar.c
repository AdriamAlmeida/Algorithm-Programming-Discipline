#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variáveis do jogo
    int escolha_usuario; // 0 para PAR, 1 para ÍMPAR
    int num_usuario;     // Número escolhido pelo usuário
    int num_computador;  // Número gerado pelo computador (0 a 10)
    int soma;            // Soma dos dois números
    int resultado_par;   // 0 se a soma for PAR, 1 se for ÍMPAR
    char jogar_novamente; // Variável para controlar o loop do-while

    // Inicializa o gerador de números aleatórios (importante para que 'rand()' gere números diferentes)
    srand(time(NULL));

    do {
        // --- 1. Escolha do Usuário (Par ou Ímpar) ---
        printf("\n--- Novo Jogo: Par ou Impar ---\n");
        printf("Escolha sua opcao:\n");
        printf("0 - PAR\n");
        printf("1 - IMPAR\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha_usuario);

        // Garante que a escolha é válida
        while (escolha_usuario != 0 && escolha_usuario != 1) {
            printf("Escolha invalida. Digite 0 para PAR ou 1 para IMPAR: ");
            scanf("%d", &escolha_usuario);
        }

        // --- 2. Entrada do Número do Usuário ---
        printf("Digite seu numero (0 a 10): ");
        scanf("%d", &num_usuario);
        
        // Garante que o número está dentro do limite
        while (num_usuario < 0 || num_usuario > 10) {
            printf("Numero invalido. Digite um numero entre 0 e 10: ");
            scanf("%d", &num_usuario);
        }

        // --- 3. Geração do Número do Computador ---
        // rand() % 11 gera um número aleatório entre 0 e 10
        num_computador = rand() % 11; 
        
        printf("\nO Computador escolheu o numero: %d\n", num_computador);

        // --- 4. Cálculo e Verificação ---
        soma = num_usuario + num_computador;
        
        // O operador módulo (%) retorna o resto da divisão.
        // Se soma % 2 for 0, o número é PAR. Se for 1, é ÍMPAR.
        resultado_par = soma % 2; 

        printf("Soma: %d + %d = %d\n", num_usuario, num_computador, soma);
        printf("Resultado da Soma: %s\n", (resultado_par == 0) ? "PAR" : "IMPAR");

        // --- 5. Determinação do Vencedor ---
        if (resultado_par == escolha_usuario) {
            // Se o resto da divisão (0=PAR, 1=IMPAR) é igual à escolha do usuário, o usuário venceu
            printf("\nPARABENS! VOCE VENCEU!\n");
        } else {
            printf("\nQUE PENA! O COMPUTADOR VENCEU!\n");
        }

        // --- 6. Pergunta para Jogar Novamente ---
        printf("\nDeseja jogar novamente? (S/N): ");
        // O ' ' antes de %c ignora qualquer caractere de espaço em branco (como o Enter anterior)
        scanf(" %c", &jogar_novamente); 

    } while (jogar_novamente == 's' || jogar_novamente == 'S');

    printf("\nObrigado por jogar! Ate a proxima.\n");
    return 0;
}