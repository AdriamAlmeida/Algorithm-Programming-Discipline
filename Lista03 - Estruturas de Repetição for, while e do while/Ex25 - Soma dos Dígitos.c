#include <stdio.h>

int main() {
    int numero_original, numero;
    int soma_digitos = 0;
    int digito;

    // 1. Solicita o numero ao usuario
    printf("--- Calculo da Soma dos Digitos ---\n");
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero_original);

    // Salva o valor original para exibicao e usa uma copia para o calculo
    numero = numero_original; 

    // Trata numeros negativos: calcula a soma dos digitos do valor absoluto
    if (numero < 0) {
        numero = -numero;
    }

    // 2. Loop WHILE para processar os digitos
    // O loop continua enquanto 'numero' for maior que zero
    while (numero > 0) {
        
        // a) Extrai o ultimo digito (ex: 456 % 10 = 6)
        digito = numero % 10;
        
        // b) Adiciona o digito a soma total
        soma_digitos = soma_digitos + digito;
        
        // c) Remove o ultimo digito (ex: 456 / 10 = 45)
        numero = numero / 10;
        
    } // O loop termina quando 'numero' se torna 0

    // 3. Exibe o resultado
    printf("\nA soma dos digitos do numero %d e: %d\n", numero_original, soma_digitos);

    return 0;
}