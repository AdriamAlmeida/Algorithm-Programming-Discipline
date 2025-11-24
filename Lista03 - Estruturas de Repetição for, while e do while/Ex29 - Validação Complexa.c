#include <stdio.h>

int main() {
    int numero;
    int entrada_valida = 0; // Flag para controlar se a entrada e valida (0 = falso, 1 = verdadeiro)

    printf("--- Validador de Entrada ---\n");
    printf("Requisitos: Par, Positivo e Menor que 100.\n");

    // 1. Loop DO-WHILE para garantir que o codigo rode pelo menos uma vez
    do {
        printf("\nDigite um numero: ");
        
        // Verifica se a leitura do numero e bem-sucedida
        if (scanf("%d", &numero) != 1) {
            printf("\nERRO: Por favor, digite apenas numeros inteiros.\n");
            // Limpa o buffer de entrada para evitar loop infinito em caso de entrada nao-numerica
            while(getchar() != '\n'); 
            entrada_valida = 0; // Garante que o loop continue
            continue; // Pula para a proxima iteracao do loop
        }
        
        // Reseta a flag para falso antes de testar as condicoes
        entrada_valida = 1; 

        // 2. Verifica as tres condicoes e fornece feedback especifico
        
        // Condicao 1: Positivo
        if (numero <= 0) {
            printf("FALHA: O numero deve ser POSITIVO.\n");
            entrada_valida = 0;
        } 
        
        // Condicao 2: Par
        if (numero % 2 != 0) {
            printf("FALHA: O numero deve ser PAR.\n");
            entrada_valida = 0;
        }
        
        // Condicao 3: Menor que 100
        if (numero >= 100) {
            printf("FALHA: O numero deve ser MENOR que 100.\n");
            entrada_valida = 0;
        }

    // 3. Condicao de Continuacao do Loop
    // O loop continua ENQUANTO a entrada NAO for valida (entrada_valida == 0)
    } while (entrada_valida == 0); 
    
    // 4. Saida de sucesso
    printf("\nSUCESSO! O numero %d e Par, Positivo e Menor que 100.\n", numero);

    return 0;
}