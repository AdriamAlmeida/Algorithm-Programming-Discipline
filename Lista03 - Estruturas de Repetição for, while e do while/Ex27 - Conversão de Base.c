#include <stdio.h>
#include <math.h> // Necessario para a funcao pow()

int main() {
    int decimal;
    int resto;
    long long binario = 0; // Armazena o resultado binario (usando long long para numeros maiores)
    int i = 1; // Base de potencia de 10, usada para posicionar os restos

    // 1. Solicita o numero decimal ao usuario
    printf("--- Conversor Decimal para Binario ---\n");
    printf("Digite um numero inteiro positivo na base decimal: ");
    
    // Verifica se a entrada e valida e positiva
    if (scanf("%d", &decimal) != 1 || decimal < 0) {
        printf("Entrada invalida. Por favor, digite um numero inteiro positivo.\n");
        return 1;
    }

    // Salva o valor original para exibicao no final
    int original = decimal; 

    // 2. Trata o caso especial de 0
    if (original == 0) {
        printf("O numero %d em binario e: 0\n", original);
        return 0;
    }

    // 3. Loop WHILE para realizar as divisoes sucessivas
    while (decimal != 0) {
        
        // a) Calcula o resto (o proximo digito binario: 0 ou 1)
        resto = decimal % 2; 
        
        // b) Acumula o resto, multiplicando pela potencia de 10 correta 
        // para posiciona-lo corretamente na representacao decimal do binario.
        // Ex: Se i = 100, o resto e colocado na posicao das centenas.
        binario = binario + resto * i;
        
        // c) Realiza a divisao inteira (prepara para a proxima iteracao)
        decimal = decimal / 2;
        
        // d) Aumenta a base de potencia de 10 para o proximo digito
        i = i * 10;
        
    } // O loop termina quando 'decimal' se torna 0

    // 4. Exibe o resultado
    printf("O numero %d na base binaria e: %lld\n", original, binario);

    return 0;
}