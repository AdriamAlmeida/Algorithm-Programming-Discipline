#include <stdio.h>
#include <float.h> // Para usar FLT_MAX e FLT_MIN (maior/menor float representável)

#define NUM_CORRIDAS 12

// Função principal
int main() {
    // Declaração do vetor para armazenar os 12 tempos (em minutos)
    float tempos[NUM_CORRIDAS];
    
    // Variáveis de análise
    float soma_tempos = 0.0;
    float tempo_medio = 0.0;
    
    float melhor_tempo = FLT_MAX; // Inicializa com o maior valor possível para garantir que o primeiro tempo seja menor
    int indice_melhor = -1;
    
    float pior_tempo = FLT_MIN;  // Inicializa com o menor valor possível para garantir que o primeiro tempo seja maior
    int indice_pior = -1;
    
    int corridas_melhores_que_media = 0;
    float variacao_tempo = 0.0;
    int atleta_melhorando = 0;

    // 1. Armazenar os 12 tempos no vetor e calcular a soma
    printf("=== REGISTRO DE TEMPOS ===\n");
    printf("Digite os tempos das %d corridas (em minutos):\n", NUM_CORRIDAS);
    
    for (int i = 0; i < NUM_CORRIDAS; i++) {
        printf("Corrida %d: ", i + 1);
        
        // Leitura do tempo. Usamos %f para float.
        if (scanf("%f", &tempos[i]) != 1) {
            printf("Erro na leitura ou entrada inválida. Terminando o programa.\n");
            return 1;
        }

        // Acumula a soma
        soma_tempos += tempos[i];
        
        // 3. Identificar o melhor tempo (menor)
        if (tempos[i] < melhor_tempo) {
            melhor_tempo = tempos[i];
            indice_melhor = i + 1; // Guarda o número da corrida (1 a 12)
        }
        
        // 4. Identificar o pior tempo (maior)
        if (tempos[i] > pior_tempo) {
            pior_tempo = tempos[i];
            indice_pior = i + 1; // Guarda o número da corrida (1 a 12)
        }
    }

    // 2. Calcular o tempo médio
    if (NUM_CORRIDAS > 0) {
        tempo_medio = soma_tempos / NUM_CORRIDAS;
    }
    
    // 5. Calcular a diferença entre o melhor e o pior tempo
    variacao_tempo = pior_tempo - melhor_tempo;
    
    // 6. Contar quantas corridas foram feitas em tempo melhor que a média
    for (int i = 0; i < NUM_CORRIDAS; i++) {
        // Um tempo 'melhor' é um tempo 'menor' (ex: 40s é melhor que 50s)
        if (tempos[i] < tempo_medio) {
            corridas_melhores_que_media++;
        }
    }
    
    // 7. Exibir status de melhora (Últimos 3 tempos melhores (menores) que a média geral)
    // As últimas 3 corridas têm índices: NUM_CORRIDAS - 3, NUM_CORRIDAS - 2, NUM_CORRIDAS - 1
    // Que correspondem a índices 9, 10 e 11 para 12 corridas
    if (NUM_CORRIDAS >= 3) {
        if (tempos[NUM_CORRIDAS - 3] < tempo_medio &&
            tempos[NUM_CORRIDAS - 2] < tempo_medio &&
            tempos[NUM_CORRIDAS - 1] < tempo_medio) {
            atleta_melhorando = 1; // true
        }
    }

    // 8. Exibir o relatório final
    printf("\n=== ANÁLISE DE DESEMPENHO ===\n");
    printf("--------------------------------\n");
    printf("Tempo médio: %.2f min\n", tempo_medio);
    printf("Melhor tempo: %.2f min (Corrida %d)\n", melhor_tempo, indice_melhor);
    printf("Pior tempo: %.2f min (Corrida %d)\n", pior_tempo, indice_pior);
    printf("Variação entre melhor e pior: %.2f min\n", variacao_tempo);
    printf("Corridas com tempo MELHOR que a média: %d\n", corridas_melhores_que_media);
    
    printf("\nStatus: ");
    if (atleta_melhorando) {
        printf("🏆 Atleta em evolução! (Últimas 3 corridas abaixo da média).\n");
    } else {
        printf("📈 Necessita de mais consistência. (Últimas 3 corridas não foram todas abaixo da média).\n");
    }
    printf("--------------------------------\n");

    return 0;
}