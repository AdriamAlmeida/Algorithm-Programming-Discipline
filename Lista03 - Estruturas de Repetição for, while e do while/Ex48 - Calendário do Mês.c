#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
int e_bissexto(int ano);
int dias_no_mes(int mes, int ano);
int dia_semana_inicial(int mes, int ano);
void exibir_calendario(int mes, int ano);

int main() {
    int mes, ano;

    printf("======================================\n");
    printf("     📅 GERADOR DE CALENDÁRIO EM C     \n");
    printf("======================================\n");

    // 1. Leitura do Mês
    do {
        printf("Digite o mês (1-12): ");
        if (scanf("%d", &mes) != 1) {
            printf("❌ Erro: Entrada inválida.\n");
            while (getchar() != '\n'); // Limpa buffer
            mes = 0; // Garante que o loop continue
        } else if (mes < 1 || mes > 12) {
            printf("⚠️ Mês deve estar entre 1 e 12.\n");
        }
    } while (mes < 1 || mes > 12);

    // 2. Leitura do Ano
    do {
        printf("Digite o ano (ex: 2025): ");
        if (scanf("%d", &ano) != 1) {
            printf("❌ Erro: Entrada inválida.\n");
            while (getchar() != '\n'); // Limpa buffer
            ano = 0; // Garante que o loop continue
        } else if (ano < 1800) { // Limite prático para simplificação do algoritmo
            printf("⚠️ Digite um ano a partir de 1800.\n");
        }
    } while (ano < 1800);

    // 3. Exibe o Calendário
    exibir_calendario(mes, ano);

    return 0;
}

/**
 * Função Auxiliar: Checa se um ano é bissexto.
 * Retorna 1 se bissexto, 0 caso contrário.
 */
int e_bissexto(int ano) {
    // Regra do ano bissexto: (Divisível por 4 E não divisível por 100) OU divisível por 400
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return 1;
    }
    return 0;
}

/**
 * Função Auxiliar: Retorna o número de dias em um dado mês/ano.
 */
int dias_no_mes(int mes, int ano) {
    switch (mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30; // Meses de 30 dias
        case 2:
            // Fevereiro: 29 dias se bissexto, 28 se não for
            return e_bissexto(ano) ? 29 : 28;
        default:
            return 31; // Meses de 31 dias
    }
}

/**
 * Função Avançada: Calcula o dia da semana (0=Dom, 6=Sáb) para o dia 1 do mês.
 * Usa uma variação do Algoritmo de Zeller.
 */
int dia_semana_inicial(int mes, int ano) {
    // Ajusta o mês e o ano para o cálculo de Zeller (Janeiro e Fevereiro são tratados como 13º e 14º mês do ano anterior)
    if (mes < 3) {
        mes += 12;
        ano -= 1;
    }
    
    int K = ano % 100; // Os dois últimos dígitos do ano
    int J = ano / 100; // Os séculos
    
    // Fórmula: h = (q + (13*(m+1))/5 + K + K/4 + J/4 - 2*J) mod 7
    // Onde q=dia (usamos 1), m=mes ajustado, K=ano_final, J=século
    // O resultado h dará o dia da semana, onde 0=Sáb, 1=Dom... 6=Sex.
    // Usaremos a fórmula adaptada para retornar 0=Dom.
    
    // A fórmula adaptada abaixo calcula o dia da semana (0=Dom, 6=Sáb)
    // h = (1 + 2*mes + 3*(mes+1)/5 + ano + ano/4 - ano/100 + ano/400) mod 7
    // Esta fórmula dá 0=Dom, 1=Seg...
    int dia_da_semana = (1 + 2 * mes + (3 * (mes + 1) / 5) + ano + (ano / 4) - (ano / 100) + (ano / 400)) % 7;
    
    return dia_da_semana;
}

/**
 * Função Principal: Gera e exibe o calendário.
 */
void exibir_calendario(int mes, int ano) {
    int total_dias = dias_no_mes(mes, ano);
    int primeiro_dia_semana = dia_semana_inicial(mes, ano);
    int dia_atual = 1;
    
    // Nomes dos meses (Para exibição)
    char *nomes_meses[] = {"", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    printf("\n\n=============== %s / %d ===============\n", nomes_meses[mes], ano);
    printf(" Dom Seg Ter Qua Qui Sex Sáb\n");
    printf("---------------------------------------\n");

    // 1. Insere espaços (padding) para o primeiro dia do mês
    // Laço FOR simples para pular colunas
    for (int i = 0; i < primeiro_dia_semana; i++) {
        printf("    "); // 4 espaços para alinhamento
    }

    // 2. Preenche os dias do mês
    // Laço FOR principal que itera sobre o total de dias
    for (int i = primeiro_dia_semana; dia_atual <= total_dias; i++) {
        
        // Imprime o dia, usando %3d para alinhamento (ex: "  1" ou " 10")
        printf("%4d", dia_atual++); 

        // Se for sábado (ou o último dia da semana), pule para a próxima linha
        // O dia da semana é calculado por 'i' modulo 7.
        if ((i + 1) % 7 == 0) {
            printf("\n");
        }
    }
    
    printf("\n---------------------------------------\n");
}