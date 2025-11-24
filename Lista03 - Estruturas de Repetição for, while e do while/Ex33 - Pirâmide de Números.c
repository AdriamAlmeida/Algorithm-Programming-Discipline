#include <stdio.h>

int main() {
    int altura; // Numero de linhas da piramide
    int numero; // Variavel para o numero a ser impresso

    printf("--- Gerador de Piramide de Numeros ---\n");
    printf("Digite a altura da piramide (numero de linhas, ex: 5): ");
    
    // 1. Entrada de dados
    if (scanf("%d", &altura) != 1 || altura <= 0) {
        printf("Altura invalida. Deve ser um numero inteiro positivo.\n");
        return 1;
    }

    printf("\n");

    // 2. LACO EXTERNO: Controla as LINHAS (de 1 ate a altura)
    for (int linha = 1; linha <= altura; linha++) {
        
        // 3. LACO INTERNO 1: Desenha os ESPACOS (para alinhar a piramide)
        // O numero de espacos diminui a cada linha
        for (int espaco = 1; espaco <= altura - linha; espaco++) {
            printf("  "); // Imprime dois espacos para um bom alinhamento
        }

        // 4. LACO INTERNO 2: Imprime os NUMEROS
        // Os numeros comecam em 1, vao ate a 'linha', e depois voltam
        
        // PARTE CRESCENTE (1 ate 'linha')
        numero = 1;
        for (int j = 1; j <= linha; j++) {
            printf("%d ", numero);
            numero++;
        }
        
        // PARTE DECRESCENTE ('linha'-1 ate 1)
        numero = linha - 1;
        for (int k = 1; k < linha; k++) {
            if (numero >= 1) {
                printf("%d ", numero);
                numero--;
            }
        }

        // 5. QUEBRA DE LINHA: Passa para a proxima linha da piramide
        printf("\n");
    }

    return 0;
}