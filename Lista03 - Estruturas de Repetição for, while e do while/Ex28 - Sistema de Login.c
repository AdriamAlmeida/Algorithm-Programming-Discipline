#include <stdio.h>
#include <string.h> // Necessario para a funcao strcmp()

// Define as credenciais corretas
#define USUARIO_CORRETO "admin"
#define SENHA_CORRETA "12345"
#define MAX_TENTATIVAS 3

int main() {
    char usuario_digitado[50];
    char senha_digitada[50];
    int login_sucesso = 0; // Flag para indicar se o login foi bem-sucedido

    printf("--- Sistema de Login ---\n");
    printf("Voce tem %d tentativas.\n", MAX_TENTATIVAS);

    // 1. Loop FOR para limitar as tentativas
    // O loop ira rodar de 1 ate MAX_TENTATIVAS (3)
    for (int tentativa = 1; tentativa <= MAX_TENTATIVAS; tentativa++) {
        
        printf("\nTentativa %d de %d\n", tentativa, MAX_TENTATIVAS);
        
        // a) Entrada do usuario
        printf("Usuario: ");
        scanf("%s", usuario_digitado);
        
        printf("Senha: ");
        scanf("%s", senha_digitada);
        
        // b) Verificacao das credenciais
        // A funcao strcmp retorna 0 se as strings forem IGUAIS.
        if (strcmp(usuario_digitado, USUARIO_CORRETO) == 0 && 
            strcmp(senha_digitada, SENHA_CORRETA) == 0) {
            
            // Login BEM-SUCEDIDO
            printf("\nACESSO CONCEDIDO! Bem-vindo(a) ao sistema.\n");
            login_sucesso = 1; // Define a flag para sucesso
            break;             // Interrompe o loop FOR imediatamente
            
        } else {
            // Login FALHOU
            printf("Credenciais invalidas.");
            
            // c) Verifica se esta na ultima tentativa
            if (tentativa < MAX_TENTATIVAS) {
                printf(" Tente novamente.\n");
            }
        }
    } // Fim do loop FOR

    // 2. Mensagem de Bloqueio (Executa se o loop terminou sem sucesso)
    if (login_sucesso == 0) {
        printf("\n\n!! ERRO !!\n");
        printf("Tentativas esgotadas. Sistema bloqueado.\n");
    }

    return 0;
}