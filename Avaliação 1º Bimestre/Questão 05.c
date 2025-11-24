#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // Para isupper, islower, isdigit
#include <math.h>   // Para pow (backoff exponencial)
#include <time.h>   // Para simular o timestamp e o sleep (se disponível)

#ifdef _WIN32
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define sleep_ms(ms) usleep(ms * 1000)
#endif

// --- Constantes e Variáveis Globais ---
#define MAX_SENHA 100
#define MIN_LEN 8
#define MAX_TENTATIVAS 3
#define BLOQUEIO_SEGUNDOS 60

// Senha cadastrada (variável global simulando armazenamento)
char senha_cadastrada[MAX_SENHA] = "";
// Tempo de desbloqueio (simulação de timestamp)
time_t tempo_desbloqueio = 0;

// --- Funções Auxiliares ---

/**
 * Simula um timestamp de log.
 */
void registrarLog(const char *mensagem) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char buffer[26];
    strftime(buffer, 26, "[%H:%M:%S]", tm_info);
    printf("LOG: %s %s\n", buffer, mensagem);
}

/**
 * MODO 1 - Validação e Pontuação da Senha
 */
void cadastrarSenha() {
    char senha[MAX_SENHA];
    int len;

    printf("\n--- CADASTRO DE SENHA ---\n");
    printf("Digite a nova senha: ");
    if (fgets(senha, MAX_SENHA, stdin) == NULL) {
        printf(" Erro na leitura.\n");
        return;
    }
    // Remove o newline adicionado por fgets
    len = strlen(senha);
    if (len > 0 && senha[len - 1] == '\n') {
        senha[len - 1] = '\0';
        len--;
    } else if (len >= MAX_SENHA - 1) {
        // Se a senha for muito longa, limpa o buffer
        int c; while ((c = getchar()) != '\n' && c != EOF);
    }
    
    if (len == 0) {
        printf("Senha vazia.\n");
        return;
    }

    // --- Variáveis de Validação e Pontuação ---
    int tem_maiuscula = 0;
    int tem_minuscula = 0;
    int tem_digito = 0;
    int tem_especial = 0;
    int pontuacao = 0;
    int requisitos_atendidos = 0;
    const char *especiais = "!@#$%&*";

    // Requisito: Usar múltiplos for/while para validar senha
    // 1. Verificar os 4 tipos de caracteres
    // Requisito: Usar estruturas de decisão aninhadas para validação
    for (int i = 0; i < len; i++) {
        if (isupper(senha[i])) {
            tem_maiuscula = 1;
        } else if (islower(senha[i])) {
            tem_minuscula = 1;
        } else if (isdigit(senha[i])) {
            tem_digito = 1;
        } else if (strchr(especiais, senha[i]) != NULL) {
            tem_especial = 1;
        }
    }

    // 2. Pontuação por Requisito (Máximo: 40)
    printf("\nAnálise de Segurança:\n");
    
    // Comprimento
    if (len >= MIN_LEN) {
        pontuacao += 10;
        requisitos_atendidos++;
        printf("- Comprimento (>= 8):  (+10 pontos)\n");
    } else {
        printf("- Comprimento (>= 8):  (Falta comprimento mínimo)\n");
    }
    
    // Letra maiúscula
    if (tem_maiuscula) {
        pontuacao += 10;
        requisitos_atendidos++;
        printf("- Letra maiúscula:  (+10 pontos)\n");
    } else {
        printf("- Letra maiúscula: \n");
    }
    
    // Letra minúscula
    if (tem_minuscula) {
        pontuacao += 10;
        requisitos_atendidos++;
        printf("- Letra minúscula:  (+10 pontos)\n");
    } else {
        printf("- Letra minúscula: \n");
    }
    
    // Dígito
    if (tem_digito) {
        pontuacao += 10;
        requisitos_atendidos++;
        printf("- Dígito:  (+10 pontos)\n");
    } else {
        printf("- Dígito: \n");
    }
    
    // Caractere especial
    if (tem_especial) {
        pontuacao += 10;
        requisitos_atendidos++;
        printf("- Caractere especial (%s): (+10 pontos)\n", especiais);
    } else {
        printf("- Caractere especial (%s): \n", especiais);
    }
    
    // 3. Pontuação Bônus
    int bonus_pontos = 0;
    if (len > MIN_LEN) {
        // +5 pontos para cada caractere extra acima de 8
        bonus_pontos += (len - MIN_LEN) * 5;
    }
    if (len > 12) {
        // +10 pontos se tiver mais de 12 caracteres
        bonus_pontos += 10;
    }
    pontuacao += bonus_pontos;
    
    if (bonus_pontos > 0) {
        printf("- Bônus de tamanho (%d caracteres):  (+%d pontos)\n", len, bonus_pontos);
    } else {
        printf("- Bônus de tamanho (%d caracteres): \n", len);
    }

    printf("- Pontuação de base (50 pts, 10 por requisito atendido): %d\n", requisitos_atendidos * 10);

    printf("\nPontuação Total: %d/100\n", pontuacao);

    // Classificação
    const char *classificacao;
    if (pontuacao >= 80) {
        classificacao = "MUITO FORTE";
    } else if (pontuacao >= 60) {
        classificacao = "FORTE";
    } else if (pontuacao >= 40) {
        classificacao = "MÉDIA";
    } else {
        classificacao = "FRACA";
    }

    printf("Classificação: %s\n", classificacao);

    // Só armazena se a senha for "Média" ou superior e atender a todos os requisitos básicos
    if (requisitos_atendidos >= 5) {
        strcpy(senha_cadastrada, senha);
        printf("\n Senha aceita e cadastrada com sucesso!\n");
    } else {
        printf("\n Senha rejeitada! Não atendeu a todos os 5 requisitos básicos. Por favor, tente novamente.\n");
    }
}

/**
 * MODO 2 - Sistema de Login
 */
void fazerLogin() {
    if (senha_cadastrada[0] == '\0') {
        printf("\n Nenhuma senha cadastrada. Por favor, cadastre uma senha (Opção 1) antes de fazer login.\n");
        return;
    }

    int tentativas_restantes = MAX_TENTATIVAS;
    int login_sucesso = 0;
    
    // Verifica bloqueio
    time_t now = time(NULL);
    if (now < tempo_desbloqueio) {
        long espera_restante = (long)(tempo_desbloqueio - now);
        printf("\n Conta temporariamente BLOQUEADA. Tente novamente em %ld segundos.\n", espera_restante);
        registrarLog("Tentativa de login bloqueada (ainda em timeout)");
        return;
    }
    
    char senha_digitada[MAX_SENHA];
    
    // Requisito: Manter contador de tentativas
    for (int i = 0; i < MAX_TENTATIVAS; i++) {
        // Requisito: Backoff exponencial (espera antes da próxima tentativa)
        int espera_segundos = 0;
        if (i > 0) {
            // Usa pow(2.0, (double)i - 1) para 2^0, 2^1, 2^2...
            espera_segundos = (int)pow(2.0, (double)i - 1); // 1ª falha (i=1) -> 2^0=1, 2ª falha (i=2) -> 2^1=2, etc.
            
            // Corrigindo para o exemplo (onde 1ª tentativa tem 0s e 2ª tem 2s)
            // A espera é *após* a falha
            espera_segundos = (int)pow(2.0, (double)i - 1); 
            
            if (i == 1) espera_segundos = 2; // Após 1ª falha
            if (i == 2) espera_segundos = 4; // Após 2ª falha

            printf("\nPróxima tentativa disponível em %d segundos...", espera_segundos);
            fflush(stdout); // Garante que a mensagem é exibida
            sleep_ms(espera_segundos * 1000); // Simula a espera
            printf("\n");
        }
        
        printf("\n=== LOGIN ===\n");
        printf("Digite a senha: ");
        if (fgets(senha_digitada, MAX_SENHA, stdin) == NULL) {
            printf(" Erro na leitura.\n");
            return;
        }
        // Remove o newline
        int len_digitada = strlen(senha_digitada);
        if (len_digitada > 0 && senha_digitada[len_digitada - 1] == '\n') {
            senha_digitada[len_digitada - 1] = '\0';
        }

        // 3. Comparação da Senha
        if (strcmp(senha_digitada, senha_cadastrada) == 0) {
            login_sucesso = 1;
            break;
        } else {
            tentativas_restantes--;
            printf(" Senha incorreta! (Tentativa %d/%d)\n", i + 1, MAX_TENTATIVAS);
            registrarLog("Tentativa falha de login");
        }
    }

    if (login_sucesso) {
        printf("\n✓ Login realizado com sucesso!\n");
        registrarLog("Login bem-sucedido");
        // Reinicia o bloqueio/tentativas se necessário
        tempo_desbloqueio = 0;
    } else {
        // Requisito: Bloqueio temporário após 3 tentativas
        printf("\n Todas as tentativas esgotadas. Conta bloqueada temporariamente.\n");
        tempo_desbloqueio = time(NULL) + BLOQUEIO_SEGUNDOS;
        printf("Você foi bloqueado por %d segundos. Tente novamente após este período.\n", BLOQUEIO_SEGUNDOS);
        registrarLog("Conta bloqueada por excesso de falhas");
    }
}

// --- Menu Principal ---
int main() {
    int escolha;
    
    // Define um valor inicial para a senha cadastrada para o exemplo
    strcpy(senha_cadastrada, "Senh@Forte123"); 

    // Requisito: Usar menu com do-while
    do {
        printf("\n============================================\n");
        printf("=== SISTEMA DE AUTENTICAÇÃO AVANÇADO ===\n");
        printf("============================================\n");
        printf("1 - Cadastrar Senha\n");
        printf("2 - Fazer Login\n");
        printf("0 - Sair\n");
        printf("--------------------------------------------\n");
        printf("Escolha: ");

        if (scanf("%d", &escolha) != 1) {
            printf("\n Opção inválida. Digite um número.\n");
            // Limpa o buffer de entrada
            while (getchar() != '\n'); 
            escolha = -1;
            continue;
        }
        
        // Limpa o buffer de entrada após scanf para o próximo fgets
        while (getchar() != '\n'); 

        switch (escolha) {
            case 1:
                cadastrarSenha();
                break;
            case 2:
                fazerLogin();
                break;
            case 0:
                printf("\n Encerrando o Sistema de Autenticação. Até logo!\n");
                break;
            default:
                printf("\n Opção inválida. Tente novamente.\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}