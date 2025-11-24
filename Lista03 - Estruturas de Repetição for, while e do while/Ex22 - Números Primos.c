#include <stdio.h>
#include <math.h> // Necessário para a função sqrt()

int main() {
    int numero;
    int eh_primo = 1; // Flag (bandeira) booleana. 1 = true (e primo), 0 = false (nao e primo)

    // 1. Solicita o número ao usuário
    printf("--- Verificador de Numero Primo ---\n");
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    // 2. Trata os casos especiais: 0, 1 e negativos
    if (numero <= 1) {
        eh_primo = 0; // 0 e 1 nao sao primos
    } else {
        // 3. Loop FOR para testar divisibilidade
        // O teste vai de i = 2 ate a raiz quadrada do numero (otimizacao).
        // Se o numero for divisivel por i, ele nao e primo.
        int limite = (int)sqrt(numero); 
        
        for (int i = 2; i <= limite; i++) {
            // Teste de divisibilidade usando o operador módulo (%)
            if (numero % i == 0) {
                eh_primo = 0; // O numero e divisivel por 'i', logo, nao e primo
                break;       // Interrompe o loop, pois ja sabemos a resposta
            }
        }
    }

    // 4. Exibe o resultado com base no valor da flag 'eh_primo'
    if (eh_primo == 1) {
        printf("\nO numero %d E um numero primo.\n", numero);
    } else {
        printf("\nO numero %d NAO e um numero primo.\n", numero);
    }

    return 0;
}