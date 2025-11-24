#include <stdio.h>
#include <math.h> // Necessário para a funcao pow()

int main() {
    double peso, altura, imc;

    printf("--- Calculo e Classificacao do IMC ---\n");

    // 1. Leitura do Peso (em kg)
    printf("Digite o peso em quilogramas (ex: 75.5): ");
    if (scanf("%lf", &peso) != 1 || peso <= 0) {
        printf("Erro: Peso invalido.\n");
        return 1;
    }

    // 2. Leitura da Altura (em metros)
    printf("Digite a altura em metros (ex: 1.75): ");
    if (scanf("%lf", &altura) != 1 || altura <= 0) {
        printf("Erro: Altura invalida.\n");
        return 1;
    }
    
    // 3. Calculo do IMC
    // IMC = Peso / (Altura * Altura)
    imc = peso / pow(altura, 2.0);

    printf("\nSeu Indice de Massa Corporal (IMC) e: %.2lf\n", imc);

    // 4. Classificacao Detalhada (6 Categorias)
    printf("Classificacao: ");
    
    if (imc < 18.5) {
        printf("Abaixo do Peso\n");
    } else if (imc >= 18.5 && imc < 25.0) {
        printf("Peso Normal (ou Saudavel)\n");
    } else if (imc >= 25.0 && imc < 30.0) {
        printf("Sobrepeso\n");
    } else if (imc >= 30.0 && imc < 35.0) {
        printf("Obesidade Grau I\n");
    } else if (imc >= 35.0 && imc < 40.0) {
        printf("Obesidade Grau II (Severa)\n");
    } else { // imc >= 40.0
        printf("Obesidade Grau III (Morbida)\n");
    }

    return 0;
}