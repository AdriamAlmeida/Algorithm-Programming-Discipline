#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcao auxiliar para ordenar dois valores (necessario para verificar sequencia)
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcao para ordenar os tres dados em ordem crescente
void ordenar_dados(int *d1, int *d2, int *d3) {
    if (*d1 > *d2) trocar(d1, d2);
    if (*d1 > *d3) trocar(d1, d3);
    if (*d2 > *d3) trocar(d2, d3);
}

int main() {
    int dado1, dado2, dado3;

    printf("--- Jogo de Dados Triplo ---\n");

    // Inicializa o gerador de numeros aleatorios (SEED)
    srand(time(NULL));

    // Simula o lancamento de tres dados (numeros entre 1 e 6)
    dado1 = (rand() % 6) + 1;
    dado2 = (rand() % 6) + 1;
    dado3 = (rand() % 6) + 1;

    printf("Resultados do Lancamento: %d, %d, %d\n", dado1, dado2, dado3);
    printf("-------------------------------\n");

    // CLASSIFICACAO

    // 1. Sequencia (e Tambem util para outras verificacoes)
    // Criamos copias ordenadas para verificar a sequencia sem alterar os originais
    int d_ord1 = dado1;
    int d_ord2 = dado2;
    int d_ord3 = dado3;

    // Ordena os dados (ex: 6, 2, 4 se torna 2, 4, 6)
    ordenar_dados(&d_ord1, &d_ord2, &d_ord3);
    
    // Verifica se ha uma sequencia (ex: 3, 4, 5)
    int e_sequencia = (d_ord1 + 1 == d_ord2) && (d_ord2 + 1 == d_ord3);


    // 2. Todos Iguais (Trinca)
    if (dado1 == dado2 && dado2 == dado3) {
        printf("RESULTADO: 🏆 Todos sao Iguais (Trinca)!\n");
    } 
    // 3. Sequencia (Exclusivo, pois a trinca nao e contada como sequencia no poker de dados)
    else if (e_sequencia) {
        printf("RESULTADO: 🔢 Sequencia (Ex: %d, %d, %d)\n", d_ord1, d_ord2, d_ord3);
    } 
    // 4. Par (Pelo menos dois dados iguais, mas nao tres)
    else if (dado1 == dado2 || dado1 == dado3 || dado2 == dado3) {
        printf("RESULTADO: 👥 Ha um Par (Apenas dois dados iguais).\n");
    } 
    // 5. Todos Diferentes (Nenhum dos casos acima)
    else {
        printf("RESULTADO: 🚫 Todos Diferentes (Nao ha pares, trincas ou sequencia).\n");
    }

    return 0;
}