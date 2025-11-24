#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Para isalpha(), isupper(), islower()

#define MAX_TAMANHO 1000 // Tamanho máximo do texto

// Protótipos das funções
void criptografar(char *texto, int chave);
void descriptografar(char *texto, int chave);

int main() {
    char texto[MAX_TAMANHO];
    int chave;
    int opcao;

    printf("======================================\n");
    printf("   🛡️ IMPLEMENTAÇÃO DA CIFRA DE CÉSAR   \n");
    printf("======================================\n");

    // 1. Leitura da Chave
    printf("Digite a chave de deslocamento (número inteiro): ");
    if (scanf("%d", &chave) != 1) {
        printf("❌ Erro: Chave inválida.\n");
        return 1;
    }
    // Limpa o buffer após a leitura do número
    while (getchar() != '\n'); 

    do {
        // --- Menu Principal ---
        printf("\n--------------------------------------\n");
        printf("1. Criptografar Texto\n");
        printf("2. Descriptografar Texto\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\nOpção inválida. Digite um número.\n");
            while (getchar() != '\n'); 
            continue;
        }
        // Limpa o buffer após a leitura do número
        while (getchar() != '\n'); 

        switch (opcao) {
            case 1: // CRIPTOGRAFAR
                printf("Digite o texto a ser criptografado:\n> ");
                // Lê a linha inteira, incluindo espaços
                if (fgets(texto, MAX_TAMANHO, stdin) == NULL) continue;
                // Remove o newline ('\n') adicionado pelo fgets
                texto[strcspn(texto, "\n")] = 0; 

                criptografar(texto, chave);
                printf("✅ Texto Criptografado (Chave %d):\n%s\n", chave, texto);
                break;

            case 2: // DESCRIPTOGRAFAR
                printf("Digite o texto a ser descriptografado:\n> ");
                if (fgets(texto, MAX_TAMANHO, stdin) == NULL) continue;
                texto[strcspn(texto, "\n")] = 0; 

                descriptografar(texto, chave);
                printf("✅ Texto Descriptografado (Chave %d):\n%s\n", chave, texto);
                break;
                
            case 0: // SAIR
                printf("\nEncerrando a Cifra de César. Adeus! 👋\n");
                break;

            default:
                printf("\n⚠️ Opção inválida! Escolha 0, 1 ou 2.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

/**
 * Função: Criptografa o texto usando a Cifra de César.
 */
void criptografar(char *texto, int chave) {
    int i;
    
    // Simplifica a chave para garantir que esteja dentro de 0-25
    chave = chave % 26; 
    
    // Laço FOR principal: itera sobre cada caractere do texto
    for (i = 0; texto[i] != '\0'; ++i) {
        char caractere = texto[i];
        
        // Verifica se é uma letra
        if (isalpha(caractere)) {
            char base;
            
            // Define a base (ASCII 'A' ou 'a')
            if (isupper(caractere)) {
                base = 'A';
            } else {
                base = 'a';
            }

            // 1. Converte o caractere para sua posição no alfabeto (0-25)
            int pos_alfabeto = caractere - base;
            
            // 2. Aplica o deslocamento
            int nova_pos = pos_alfabeto + chave;
            
            // 3. Usa a aritmética modular para "circular" no alfabeto
            // Se passar de 'Z' ou 'z' (posição 25), volta para 'A' ou 'a' (posição 0)
            int pos_final = nova_pos % 26; 
            
            // 4. Converte de volta para o caractere ASCII e atualiza o texto
            texto[i] = base + pos_final;
        }
        // Caracteres não alfabéticos (espaços, pontuação) são ignorados
    }
}

/**
 * Função: Descriptografa o texto usando a Cifra de César.
 */
void descriptografar(char *texto, int chave) {
    int i;
    chave = chave % 26;
    
    // A descriptografia é o mesmo que a criptografia, mas com um deslocamento negativo
    for (i = 0; texto[i] != '\0'; ++i) {
        char caractere = texto[i];
        
        if (isalpha(caractere)) {
            char base;
            
            if (isupper(caractere)) {
                base = 'A';
            } else {
                base = 'a';
            }

            int pos_alfabeto = caractere - base;
            
            // Aplica o deslocamento inverso (negativo)
            int nova_pos = pos_alfabeto - chave;
            
            // Garante que o resultado seja positivo antes de aplicar o módulo.
            // Ex: Se 0 - 3 = -3. Adicionamos 26 para obter 23, que é a posição 'X'.
            int pos_final = (nova_pos + 26) % 26;
            
            texto[i] = base + pos_final;
        }
    }
}