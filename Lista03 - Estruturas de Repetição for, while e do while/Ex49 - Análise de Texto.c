#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Protótipos das funções
int e_vogal(char c);

int main() {
    FILE *arquivo;
    char caractere;
    
    // Contadores
    long cont_caracteres = 0;
    int cont_palavras = 0;
    int cont_linhas = 0;
    int cont_vogais = 0;
    int cont_consoantes = 0;
    
    // Variável de estado para contagem de palavras:
    // 1 (true) se estiver DENTRO de uma palavra, 0 (false) se estiver FORA.
    int estado_palavra = 0; // Começa FORA de uma palavra

    printf("======================================\n");
    printf("        🔍 ANÁLISE DE ARQUIVO          \n");
    printf("======================================\n");

    // 1. Abertura do Arquivo
    arquivo = fopen("texto_exemplo.txt", "r");
    
    if (arquivo == NULL) {
        printf("❌ Erro ao abrir o arquivo 'texto_exemplo.txt'.\n");
        printf("Certifique-se de que o arquivo existe no mesmo diretório.\n");
        return 1;
    }

    printf("Arquivo 'texto_exemplo.txt' aberto com sucesso.\n");
    printf("Iniciando a leitura e contagem...\n\n");

    // 2. Loop principal: Leitura Caractere por Caractere
    // A estrutura de repetição principal usa fgetc() para ler até o fim do arquivo (EOF)
    while ((caractere = fgetc(arquivo)) != EOF) {
        
        cont_caracteres++; // Conta todos os caracteres (incluindo espaços e quebras de linha)

        // --- Contagem de Linhas ---
        if (caractere == '\n') {
            cont_linhas++;
        }
        
        // --- Contagem de Vogais e Consoantes ---
        // Converte para minúscula para simplificar a checagem (ignora maiúsculas/minúsculas)
        char lower_c = tolower(caractere); 
        
        if (isalpha(lower_c)) { // Se for uma letra (A-Z ou a-z)
            if (e_vogal(lower_c)) {
                cont_vogais++;
            } else {
                cont_consoantes++;
            }
        }
        
        // --- Contagem de Palavras (Lógica Avançada de Estado) ---
        // Checa se o caractere atual é um separador (espaço, tab, quebra de linha)
        if (isspace(caractere) || caractere == '\0' || caractere == EOF || caractere == '.') {
            // Se o caractere atual for um separador, e o estado anterior era DENTRO de uma palavra,
            // significa que a palavra acabou.
            if (estado_palavra) {
                cont_palavras++;
                estado_palavra = 0; // Muda o estado para FORA da palavra
            }
        } else {
            // Se o caractere atual NÃO for um separador, estamos DENTRO de uma palavra.
            estado_palavra = 1; // Muda o estado para DENTRO da palavra
        }
    }
    
    // Se o arquivo terminar e ainda estivermos DENTRO de uma palavra, contamos a última
    if (estado_palavra) {
        cont_palavras++;
    }
    
    // Ajusta a contagem de linhas se o arquivo não terminar com uma quebra de linha
    if (cont_caracteres > 0 && caractere != '\n') {
        cont_linhas++;
    }

    // 3. Fechamento e Resultados
    fclose(arquivo);

    printf("--- RESULTADOS DA ANÁLISE ---\n");
    printf("Total de Caracteres: %ld\n", cont_caracteres);
    printf("Total de Linhas:     %d\n", cont_linhas);
    printf("Total de Palavras:   %d\n", cont_palavras);
    printf("Total de Vogais:     %d\n", cont_vogais);
    printf("Total de Consoantes: %d\n", cont_consoantes);
    printf("--------------------------------------\n");

    return 0;
}

/**
 * Função Auxiliar: Checa se um caractere é uma vogal (após ser convertido para minúsculo).
 * Retorna 1 se for vogal, 0 caso contrário.
 */
int e_vogal(char c) {
    // Note que 'c' deve ser minúsculo
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    return 0;
}