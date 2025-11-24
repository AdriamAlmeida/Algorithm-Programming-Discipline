#include <stdio.h>
#include <stdbool.h> // Necessario para usar o tipo 'bool'

int main() {
    int N; // Limite superior
    
    printf("--- Crivo de Eratostenes (Buscador de Primos) ---\n");
    printf("Digite o limite superior (N) para encontrar os primos: ");
    
    // 1. Entrada de dados
    if (scanf("%d", &N) != 1 || N < 2) {
        printf("Limite invalido. Deve ser um numero inteiro maior ou igual a 2.\n");
        return 1;
    }

    // 2. Criacao e Inicializacao do Array/Crivo
    // O array tem tamanho N+1 para incluir os indices de 0 ate N.
    // Inicializa todos os elementos como 'true' (primos)
    // O compilador C99 ou C11 suporta a inicializacao dinamica, mas usaremos uma forma simples:
    bool primo[N + 1];
    
    // Inicializacao manual para garantir compatibilidade e clareza
    for (int i = 0; i <= N; i++) {
        primo[i] = true;
    }

    // Os numeros 0 e 1 nao sao primos
    if (N >= 0) primo[0] = false;
    if (N >= 1) primo[1] = false;
    
    // 3. LACO PRINCIPAL DO CRIVO: Percorre os numeros de 2 ate a raiz quadrada de N
    // O loop continua enquanto i*i for menor ou igual a N (i <= sqrt(N))
    for (int p = 2; p * p <= N; p++) {
        
        // Se primo[p] ainda e 'true', entao 'p' e um numero primo
        if (primo[p] == true) {
            
            // 4. LACO INTERNO: Marca todos os multiplos de p como 'false' (nao-primos)
            // O loop comeca em p*p porque os multiplos menores que p*p (ex: 2*p, 3*p...)
            // ja teriam sido marcados por primos anteriores (2, 3...)
            for (int i = p * p; i <= N; i += p) {
                primo[i] = false;
            }
        }
    }

    // 5. Exibe os resultados
    printf("\nNumeros primos ate %d sao:\n", N);
    
    // LACO DE IMPRESSAO: Itera de 2 ate N
    for (int p = 2; p <= N; p++) {
        if (primo[p] == true) {
            printf("%d ", p);
        }
    }
    printf("\n");

    return 0;
}