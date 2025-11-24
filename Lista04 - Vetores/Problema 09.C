#include <stdio.h>
#include <stdlib.h> // Para srand, rand
#include <time.h>   // Para time (usado no srand)

// Constantes
#define QTD_NUMEROS 6
#define MAX_NUMERO 60
#define MIN_NUMERO 1

// Protótipos de funções
void gerar_sorteio(int sorteados[]);
int ler_aposta(int aposta[], int index_atual);
int verificar_repeticao(int aposta[], int index_atual, int novo_numero);
void verificar_acertos(int sorteados[], int aposta[], int acertos[], int *num_acertos);
void classificar_resultado(int num_acertos);
void exibir_vetor(int vetor[], int tamanho);

int main() {
    // Vetores principais
    int sorteados[QTD_NUMEROS];  // Números sorteados (de 1 a 60)
    int aposta[QTD_NUMEROS];     // Números apostados pelo usuário
    int acertos[QTD_NUMEROS];    // Números que o usuário acertou
    int num_acertos = 0;         // Contador de acertos

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    printf("=== SIMULADOR DE LOTERIA (Acerto de %d em %d) ===\n", QTD_NUMEROS, MAX_NUMERO);

    // 1. Geração do Sorteio (Números aleatórios não repetidos)
    gerar_sorteio(sorteados);
    printf("\nOs numeros sorteados foram: ");
    exibir_vetor(sorteados, QTD_NUMEROS);

    // 2. Leitura da Aposta do Usuário (Com validação)
    printf("\n\n--- REGISTRO DA APOSTA ---\n");
    for (int i = 0; i < QTD_NUMEROS; i++) {
        // A função ler_aposta garante que o número lido seja válido e não repetido
        aposta[i] = ler_aposta(aposta, i); 
    }
    printf("Sua aposta registrada: ");
    exibir_vetor(aposta, QTD_NUMEROS);

    // 3. Verificação de Acertos
    verificar_acertos(sorteados, aposta, acertos, &num_acertos);

    // 4. Exibição do Resultado e Classificação
    printf("\n\n=== RESULTADO DA APOSRA ===\n");
    printf("Voce acertou %d numeros!\n", num_acertos);
    
    if (num_acertos > 0) {
        printf("Numeros certos: ");
        // Exibe apenas a parte do vetor de acertos que foi preenchida
        exibir_vetor(acertos, num_acertos); 
    } else {
        printf("Nenhum numero correto. Tente novamente!\n");
    }

    // Exibe a premiação com base no número de acertos
    classificar_resultado(num_acertos);
    
    printf("===========================\n");

    return 0;
}

/**
 * @brief Gera 6 números únicos e aleatórios entre 1 e 60.
 * @param sorteados O vetor onde os números serão armazenados.
 */
void gerar_sorteio(int sorteados[]) {
    int i = 0;
    while (i < QTD_NUMEROS) {
        // Gera um número aleatório entre 1 e MAX_NUMERO (60)
        int novo_numero = (rand() % MAX_NUMERO) + 1; 
        
        // Verifica se o número já foi sorteado
        if (verificar_repeticao(sorteados, i, novo_numero) == 0) {
            sorteados[i] = novo_numero;
            i++;
        }
    }
}

/**
 * @brief Lê um número do usuário, garantindo que seja válido (1-60 e sem repetição).
 * @param aposta O vetor de aposta do usuário.
 * @param index_atual O índice atual do vetor que está sendo preenchido.
 * @return O número válido lido.
 */
int ler_aposta(int aposta[], int index_atual) {
    int numero;
    int valido = 0;

    do {
        printf("Numero %d (entre %d e %d): ", index_atual + 1, MIN_NUMERO, MAX_NUMERO);
        if (scanf("%d", &numero) != 1) {
            printf("❌ Entrada invalida. Digite um numero inteiro.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n'); 
            continue;
        }

        // 1. Validação de faixa (1 a 60)
        if (numero < MIN_NUMERO || numero > MAX_NUMERO) {
            printf("❌ Numero fora da faixa. Deve ser entre %d e %d.\n", MIN_NUMERO, MAX_NUMERO);
        } 
        // 2. Validação de repetição
        else if (verificar_repeticao(aposta, index_atual, numero) == 1) {
            printf("❌ Numero ja apostado. Escolha um numero diferente.\n");
        } 
        // 3. Número válido
        else {
            valido = 1;
        }

    } while (!valido);

    return numero;
}

/**
 * @brief Verifica se um número já existe em uma parte do vetor.
 * @param vetor O vetor a ser verificado (aposta ou sorteados).
 * @param tamanho_busca O limite do vetor a ser verificado.
 * @param novo_numero O número a ser procurado.
 * @return 1 se for repetido, 0 se não for.
 */
int verificar_repeticao(int vetor[], int tamanho_busca, int novo_numero) {
    for (int i = 0; i < tamanho_busca; i++) {
        if (vetor[i] == novo_numero) {
            return 1; // Repetido
        }
    }
    return 0; // Não repetido
}

/**
 * @brief Compara os vetores sorteados e apostados e preenche o vetor de acertos.
 * @param sorteados Vetor com os números sorteados.
 * @param aposta Vetor com os números apostados.
 * @param acertos Vetor para armazenar os números acertados.
 * @param num_acertos Ponteiro para a variável que contará os acertos.
 */
void verificar_acertos(int sorteados[], int aposta[], int acertos[], int *num_acertos) {
    *num_acertos = 0; // Reinicia o contador
    
    // Percorre cada número apostado
    for (int i = 0; i < QTD_NUMEROS; i++) {
        // Compara com cada número sorteado
        for (int j = 0; j < QTD_NUMEROS; j++) {
            if (aposta[i] == sorteados[j]) {
                // Acertou! Armazena no vetor de acertos e incrementa o contador
                acertos[*num_acertos] = aposta[i];
                (*num_acertos)++;
                break; // Sai do loop interno (já encontramos a correspondência)
            }
        }
    }
}

/**
 * @brief Exibe a premiação baseada no número de acertos.
 * @param num_acertos Quantidade de acertos.
 */
void classificar_resultado(int num_acertos) {
    printf("Premiacao: ");
    switch (num_acertos) {
        case 6:
            printf("🎉🎉 SENA! PARABENS! 🎉🎉\n");
            break;
        case 5:
            printf("🌟 QUINA! OTIMO RESULTADO! 🌟\n");
            break;
        case 4:
            printf("✅ QUADRA!\n");
            break;
        default:
            printf("Nao premiado. Tente a sorte novamente.\n");
            break;
    }
}

/**
 * @brief Exibe o conteúdo de um vetor no formato [n1, n2, ...].
 * @param vetor O vetor a ser exibido.
 * @param tamanho O tamanho real do vetor (ou a parte preenchida).
 */
void exibir_vetor(int vetor[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}