#include <stdio.h>
#include <math.h> // Necessário para a função ceilf()

int main() {
    // Dimensões da Parede
    float parede_altura;
    float parede_largura;
    float area_parede;

    // Dimensões do Azulejo
    float azulejo_altura;
    float azulejo_largura;
    float area_azulejo;

    // Resultado
    float azulejos_necessarios_decimal;
    int azulejos_necessarios_final; // Variável inteira para o resultado arredondado

    // --- 1. Leitura das Dimensões da Parede ---
    printf("--- Dimensoes da Parede (em metros) ---\n");
    printf("Digite a altura da parede (m): ");
    scanf("%f", &parede_altura);
    
    printf("Digite a largura da parede (m): ");
    scanf("%f", &parede_largura);

    // --- 2. Leitura das Dimensões do Azulejo ---
    printf("\n--- Dimensoes do Azulejo (na mesma unidade) ---\n");
    printf("Digite a altura do azulejo (m): ");
    scanf("%f", &azulejo_altura);
    
    printf("Digite a largura do azulejo (m): ");
    scanf("%f", &azulejo_largura);

    // --- 3. Processamento dos Cálculos ---

    // a) Calcular a área da parede
    area_parede = parede_altura * parede_largura;

    // b) Calcular a área de um azulejo
    area_azulejo = azulejo_altura * azulejo_largura;

    // c) Calcular a quantidade de azulejos (valor decimal)
    // Evita a divisão por zero
    if (area_azulejo > 0) {
        azulejos_necessarios_decimal = area_parede / area_azulejo;

        // d) Arredondar para o próximo número inteiro maior (uso de ceilf())
        // Se precisar de 100.1 azulejos, deve comprar 101.
        azulejos_necessarios_final = (int)ceilf(azulejos_necessarios_decimal);

        // --- 4. Saída do Resultado ---
        printf("\n--- Resultado do Calculo ---\n");
        printf("Area da Parede: %.2f m²\n", area_parede);
        printf("Area de cada Azulejo: %.2f m²\n", area_azulejo);
        printf("Azulejos necessarios (teorico): %.2f\n", azulejos_necessarios_decimal);
        printf("Voce precisa comprar: %d azulejos.\n", azulejos_necessarios_final);
    } else {
        printf("\n[ERRO] A area do azulejo deve ser maior que zero.\n");
    }

    return 0;
}