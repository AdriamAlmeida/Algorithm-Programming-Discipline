#include <stdio.h>

int main() {
    // Variaveis para as notas e pesos
    double nota1, nota2, nota3;
    double peso1, peso2, peso3;
    
    // Variaveis para o calculo
    double soma_produtos;
    double soma_pesos;
    double media_ponderada;

    printf("--- Calculo de Media Ponderada ---\n");

    // 1. Leitura das 3 Notas e Pesos

    // Nota 1
    printf("Digite a Nota 1: ");
    if (scanf("%lf", &nota1) != 1 || nota1 < 0) return 1;
    printf("Digite o Peso 1: ");
    if (scanf("%lf", &peso1) != 1 || peso1 <= 0) return 1;
    
    // Nota 2
    printf("Digite a Nota 2: ");
    if (scanf("%lf", &nota2) != 1 || nota2 < 0) return 1;
    printf("Digite o Peso 2: ");
    if (scanf("%lf", &peso2) != 1 || peso2 <= 0) return 1;
    
    // Nota 3
    printf("Digite a Nota 3: ");
    if (scanf("%lf", &nota3) != 1 || nota3 < 0) return 1;
    printf("Digite o Peso 3: ");
    if (scanf("%lf", &peso3) != 1 || peso3 <= 0) return 1;

    // 2. Calculo da Media Ponderada
    
    // Calcula o numerador (soma dos produtos nota * peso)
    soma_produtos = (nota1 * peso1) + (nota2 * peso2) + (nota3 * peso3);
    
    // Calcula o denominador (soma dos pesos)
    soma_pesos = peso1 + peso2 + peso3;

    // Verifica se a soma dos pesos e zero para evitar divisao por zero
    if (soma_pesos == 0) {
        printf("\nERRO: A soma dos pesos deve ser maior que zero.\n");
        return 1;
    }

    // Calcula a media
    media_ponderada = soma_produtos / soma_pesos;

    printf("Media Ponderada Calculada: %.2lf\n", media_ponderada);

    // 3. Classificacao do Resultado
    
    if (media_ponderada >= 7.0) {
        printf("STATUS: Aprovacao\n");
    } else if (media_ponderada >= 5.0) { // Implica que media >= 5.0 E media < 7.0
        printf("STATUS: Recuperacao\n");
    } else { // Implica que media < 5.0
        printf("STATUS: Reprovacao\n");
    }

    return 0;
}