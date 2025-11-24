#include <stdio.h>

// Definicao dos pesos para cada nota
#define PESO1 2.0
#define PESO2 3.0
#define PESO3 2.0
#define PESO4 3.0
#define SOMA_PESOS (PESO1 + PESO2 + PESO3 + PESO4)

int main() {
    // Variaveis de entrada para notas
    double n1, n2, n3, n4;
    
    // Variaveis de entrada para criterios adicionais
    double frequencia_pct;
    int trabalhos_entregues; // 0 para Nao, 1 para Sim (100%)

    // Variaveis de calculo
    double media_ponderada;

    printf("--- Sistema de Avaliacao Complexo ---\n");

    // 1. Leitura das 4 Notas (0.0 a 10.0)
    printf("Digite a Nota 1 (Peso %.0lf): ", PESO1);
    if (scanf("%lf", &n1) != 1 || n1 < 0 || n1 > 10) return 1;

    printf("Digite a Nota 2 (Peso %.0lf): ", PESO2);
    if (scanf("%lf", &n2) != 1 || n2 < 0 || n2 > 10) return 1;

    printf("Digite a Nota 3 (Peso %.0lf): ", PESO3);
    if (scanf("%lf", &n3) != 1 || n3 < 0 || n3 > 10) return 1;

    printf("Digite a Nota 4 (Peso %.0lf): ", PESO4);
    if (scanf("%lf", &n4) != 1 || n4 < 0 || n4 > 10) return 1;

    // 2. Leitura de Frequencia e Trabalhos
    printf("Digite a frequencia (em %%): ");
    if (scanf("%lf", &frequencia_pct) != 1 || frequencia_pct < 0 || frequencia_pct > 100) return 1;

    printf("Todos os trabalhos foram entregues? (1 para Sim / 0 para Nao): ");
    if (scanf("%d", &trabalhos_entregues) != 1 || (trabalhos_entregues != 0 && trabalhos_entregues != 1)) return 1;

    // 3. Calculo da Media Ponderada
    media_ponderada = (n1 * PESO1 + n2 * PESO2 + n3 * PESO3 + n4 * PESO4) / SOMA_PESOS;

    printf("\n========================================\n");
    printf("Media Ponderada Calculada: %.2lf\n", media_ponderada);
    printf("Frequencia: %.0lf%%\n", frequencia_pct);
    printf("Trabalhos: %s\n", (trabalhos_entregues == 1) ? "Entregues (100%%)" : "Incompletos");
    printf("========================================\n");

    // 4. Determinacao da Situacao Final (Logica Complexa)
    
    // Condicoes de Decisao
    int aprovado_direto = 
        (media_ponderada >= 7.0) && 
        (frequencia_pct >= 75.0) && 
        (trabalhos_entregues == 1);

    int em_recuperacao = 
        // Recuperacao pela nota (nota 5.0 a 6.9)
        (media_ponderada >= 5.0 && media_ponderada < 7.0) ||
        // Ou, nota alta mas reprovado por falta
        (media_ponderada >= 7.0 && frequencia_pct < 75.0);


    if (aprovado_direto) {
        printf("SITUACAO FINAL: APROVADO\n");
        printf("Parabens! Todos os requisitos atendidos.\n");
    } else if (em_recuperacao) {
        printf("SITUACAO FINAL: RECUPERACAO\n");
        if (media_ponderada < 7.0) {
             printf("Requisito de media (7.0) nao atingido.\n");
        } else if (frequencia_pct < 75.0) {
             printf("Requisito de frequencia (75%%) nao atingido.\n");
        }
    } else {
        printf("SITUACAO FINAL: REPROVADO\n");
        if (media_ponderada < 5.0) {
            printf("Motivo Principal: Media final (%.2lf) abaixo do minimo para Recuperacao (5.0).\n", media_ponderada);
        } else if (trabalhos_entregues == 0) {
            printf("Motivo Principal: Nao entrega de todos os trabalhos obrigatorios.\n");
        } else {
             printf("Outros requisitos nao foram atendidos.\n");
        }
    }

    return 0;
}