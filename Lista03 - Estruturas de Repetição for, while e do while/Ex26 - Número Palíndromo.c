#include <stdio.h>

int main() {
    int numero_original, numero_temp;
    int numero_invertido = 0;
    int resto;

    // 1. Solicita o numero ao usuario
    printf("--- Verificador de Numero Palindromo ---\n");
    printf("Digite um numero inteiro positivo: ");
    
    // Verifica se a leitura foi bem-sucedida e se o numero e positivo
    if (scanf("%d", &numero_original) != 1 || numero_original < 0) {
        printf("Entrada invalida. Por favor, digite um numero inteiro positivo.\n");
        return 1;
    }

    // Cria uma copia do numero original, pois o loop 'while' ira modifica-lo.
    numero_temp = numero_original; 

    // 2. Loop WHILE para reverter o numero
    // O loop continua enquanto 'numero_temp' for maior que zero
    while (numero_temp != 0) {
        
        // a) Extrai o ultimo digito (ex: 121 % 10 = 1)
        resto = numero_temp % 10;
        
        // b) Constroi o numero invertido: 
        // Multiplica o numero_invertido atual por 10 (cria espaco para o novo digito)
        // e adiciona o digito extraido (resto)
        numero_invertido = numero_invertido * 10 + resto;
        
        // c) Remove o ultimo digito (ex: 121 / 10 = 12)
        numero_temp = numero_temp / 10;
        
    } // O loop termina quando 'numero_temp' se torna 0

    // 3. Compara o numero invertido com o original
    printf("\nNumero Original: %d\n", numero_original);
    printf("Numero Invertido: %d\n", numero_invertido);

    if (numero_original == numero_invertido) {
        printf("Resultado: O numero %d E um palindromo.\n", numero_original);
    } else {
        printf("Resultado: O numero %d NAO e um palindromo.\n", numero_original);
    }

    return 0;
}