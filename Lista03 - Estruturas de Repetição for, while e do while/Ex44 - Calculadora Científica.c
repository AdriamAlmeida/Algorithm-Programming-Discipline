#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Necessário para pow() e sqrt()

// Protótipos das funções auxiliares
void operacoes_basicas();
void operacoes_cientificas();

int main() {
    int opcao_menu;
    double num1, num2, resultado;
    char operador;

    do {
        // system("cls || clear"); // Opcional: Limpar a tela a cada iteração

        // --- Menu Principal ---
        printf("\n===================================\n");
        printf("    CALCULADORA CIENTÍFICA EM C    \n");
        printf("===================================\n");
        printf("1. Operações Básicas (+, -, *, /)\n");
        printf("2. Operações Científicas (Potência, Raiz Quadrada)\n");
        printf("0. Sair\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao_menu) != 1) {
            printf("\nOpção inválida. Digite um número.\n");
            // Limpa o buffer
            while (getchar() != '\n'); 
            continue;
        }

        switch (opcao_menu) {
            case 1:
                operacoes_basicas();
                break;
            
            case 2:
                operacoes_cientificas();
                break;
                
            case 0:
                printf("\nObrigado por utilizar a Calculadora Científica! 👋\n");
                break;
                
            default:
                printf("\n⚠️ Opção inválida! Por favor, escolha 1, 2 ou 0.\n");
                break;
        }
        
        // Se a opção não for 'Sair', espera para o usuário ver o resultado
        if (opcao_menu != 0) {
            printf("\n(Pressione ENTER para voltar ao menu...)");
            while (getchar() != '\n'); // Limpa o buffer
            getchar(); // Espera pela próxima tecla
        }

    } while (opcao_menu != 0); // O loop continua até que a opção 0 seja escolhida

    return 0;
}

// Implementação das Operações Básicas
void operacoes_basicas() {
    double num1, num2, resultado;
    char operador;
    
    printf("\n--- OPERAÇÕES BÁSICAS ---\n");
    printf("Exemplo: 10 + 5\n");
    printf("Digite a operação (num1 operador num2): ");
    
    // Leitura dos três elementos: número, operador e número
    if (scanf("%lf %c %lf", &num1, &operador, &num2) != 3) {
        printf("❌ Erro: Formato da operação inválido.\n");
        // Limpa o buffer
        while (getchar() != '\n'); 
        return;
    }

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: **%.2f**\n", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado: **%.2f**\n", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("Resultado: **%.2f**\n", resultado);
            break;
        case '/':
            // Tratamento de erro avançado: divisão por zero
            if (num2 == 0) {
                printf("❌ Erro: Divisão por zero não é permitida.\n");
            } else {
                resultado = num1 / num2;
                printf("Resultado: **%.2f**\n", resultado);
            }
            break;
        default:
            printf("⚠️ Operador básico inválido ('%c').\n", operador);
            break;
    }
}

// Implementação das Operações Científicas
void operacoes_cientificas() {
    int opcao_cientifica;
    double num, base, expoente, resultado;
    
    printf("\n--- OPERAÇÕES CIENTÍFICAS ---\n");
    printf("1. Potenciação (x^y)\n");
    printf("2. Raiz Quadrada (sqrt(x))\n");
    printf("Escolha uma opção: ");
    
    if (scanf("%d", &opcao_cientifica) != 1) {
        printf("❌ Erro: Opção inválida.\n");
        // Limpa o buffer
        while (getchar() != '\n'); 
        return;
    }
    
    switch (opcao_cientifica) {
        case 1: // Potenciação
            printf("Digite a base e o expoente (ex: 2 3 para 2^3): ");
            if (scanf("%lf %lf", &base, &expoente) != 2) {
                printf("❌ Erro: Entrada inválida para Potenciação.\n");
                break;
            }
            // Usa a função pow(base, expoente)
            resultado = pow(base, expoente); 
            printf("%.2f elevado a %.2f é: **%.2f**\n", base, expoente, resultado);
            break;
            
        case 2: // Raiz Quadrada
            printf("Digite o número para calcular a Raiz Quadrada: ");
            if (scanf("%lf", &num) != 1) {
                printf("❌ Erro: Entrada inválida para Raiz Quadrada.\n");
                break;
            }
            // Tratamento de erro avançado: raiz de número negativo
            if (num < 0) {
                printf("❌ Erro: Não é possível calcular a raiz quadrada de um número negativo no domínio real.\n");
            } else {
                // Usa a função sqrt(num)
                resultado = sqrt(num); 
                printf("A raiz quadrada de %.2f é: **%.2f**\n", num, resultado);
            }
            break;
            
        default:
            printf("⚠️ Opção científica inválida.\n");
            break;
    }
}