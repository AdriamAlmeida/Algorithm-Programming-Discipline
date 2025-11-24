#include <stdio.h>

int main(){
    float matriz[5][3];
    
    //preencher as notas
    for(int i = 0; i < 5; i++){ //linhas
        for(int j = 0; j < 2; j++){ //colunas
            printf("Digite a nota %d do aluno %d: ", j+1, i+1);
            scanf("%f", &matriz[i][j]);
        }
        //calcular a média e armazenar na terceira coluna
        matriz[i][2] = (matriz[i][0] + matriz[i][1]) / 2;
    }

    //imprimir a matriz
    printf("=== BOLETO DOS ALUNOS ===\n");
    printf("\nMatriz de Notas e Médias:\n");
    printf("Aluno\tNota 1\tNota 2\tMédia\n");
    for(int i = 0; i < 5; i++){ //linhas
        printf("%d\t", i+1);
        for(int j = 0; j < 3; j++){ //colunas
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}