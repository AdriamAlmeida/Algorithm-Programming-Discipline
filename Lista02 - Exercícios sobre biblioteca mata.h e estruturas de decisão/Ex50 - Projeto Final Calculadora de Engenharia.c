#include <stdio.h>
#include <math.h>   // Para sqrt(), pow(), atan2()
#include <stdlib.h> // Para exit()

// Constante Pi (M_PI esta disponivel se _USE_MATH_DEFINES for definido, mas e bom declarar por seguranca)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Constante para conversao de radianos para graus
#define RAD_TO_DEG (180.0 / M_PI)

// --- FUNCOES DE CALCULO ---

// Opcao 1: Menu de Areas
void menu_areas() {
    int opcao;
    double resultado;
    
    printf("\n--- MENU DE AREAS ---\n");
    printf("1. Circulo\n");
    printf("2. Triangulo\n");
    printf("3. Trapezio\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    if (scanf("%d", &opcao) != 1) return;

    switch (opcao) {
        case 1: { // Area do Circulo
            double raio;
            printf("Digite o raio do circulo: ");
            if (scanf("%lf", &raio) != 1) break;
            if (raio <= 0) {
                printf("ERRO: O raio deve ser positivo.\n");
                break;
            }
            // Area = pi * r^2
            resultado = M_PI * pow(raio, 2.0);
            printf("Area do Circulo: %.4lf\n", resultado);
            break;
        }
        case 2: { // Area do Triangulo (Base x Altura)
            double base, altura;
            printf("Digite o valor da base: ");
            if (scanf("%lf", &base) != 1) break;
            printf("Digite o valor da altura: ");
            if (scanf("%lf", &altura) != 1) break;
            if (base <= 0 || altura <= 0) {
                printf("ERRO: Base e altura devem ser positivas.\n");
                break;
            }
            // Area = (base * altura) / 2
            resultado = (base * altura) / 2.0;
            printf("Area do Triangulo: %.4lf\n", resultado);
            break;
        }
        case 3: { // Area do Trapezio
            double base_maior, base_menor, altura;
            printf("Digite o valor da Base Maior: ");
            if (scanf("%lf", &base_maior) != 1) break;
            printf("Digite o valor da Base Menor: ");
            if (scanf("%lf", &base_menor) != 1) break;
            printf("Digite o valor da altura: ");
            if (scanf("%lf", &altura) != 1) break;

            if (base_maior <= 0 || base_menor <= 0 || altura <= 0 || base_maior < base_menor) {
                printf("ERRO: Bases e altura devem ser positivas. Base Maior deve ser maior ou igual a Base Menor.\n");
                break;
            }
            // Area = ((B + b) * h) / 2
            resultado = ((base_maior + base_menor) * altura) / 2.0;
            printf("Area do Trapezio: %.4lf\n", resultado);
            break;
        }
        case 0:
            printf("Voltando ao menu principal.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}

// Opcao 2: Menu de Volumes
void menu_volumes() {
    int opcao;
    double resultado;
    
    printf("\n--- MENU DE VOLUMES ---\n");
    printf("1. Esfera\n");
    printf("2. Cilindro\n");
    printf("3. Cone\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    if (scanf("%d", &opcao) != 1) return;

    switch (opcao) {
        case 1: { // Volume da Esfera
            double raio;
            printf("Digite o raio da esfera: ");
            if (scanf("%lf", &raio) != 1) break;
            if (raio <= 0) {
                printf("ERRO: O raio deve ser positivo.\n");
                break;
            }
            // Volume = (4/3) * pi * r^3
            resultado = (4.0 / 3.0) * M_PI * pow(raio, 3.0);
            printf("Volume da Esfera: %.4lf\n", resultado);
            break;
        }
        case 2: { // Volume do Cilindro
            double raio, altura;
            printf("Digite o raio da base: ");
            if (scanf("%lf", &raio) != 1) break;
            printf("Digite a altura: ");
            if (scanf("%lf", &altura) != 1) break;
            if (raio <= 0 || altura <= 0) {
                printf("ERRO: Raio e altura devem ser positivos.\n");
                break;
            }
            // Volume = pi * r^2 * h
            resultado = M_PI * pow(raio, 2.0) * altura;
            printf("Volume do Cilindro: %.4lf\n", resultado);
            break;
        }
        case 3: { // Volume do Cone
            double raio, altura;
            printf("Digite o raio da base: ");
            if (scanf("%lf", &raio) != 1) break;
            printf("Digite a altura: ");
            if (scanf("%lf", &altura) != 1) break;
            if (raio <= 0 || altura <= 0) {
                printf("ERRO: Raio e altura devem ser positivos.\n");
                break;
            }
            // Volume = (1/3) * pi * r^2 * h
            resultado = (1.0 / 3.0) * M_PI * pow(raio, 2.0) * altura;
            printf("Volume do Cone: %.4lf\n", resultado);
            break;
        }
        case 0:
            printf("Voltando ao menu principal.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}

// Opcao 3: Conversao de Coordenadas
void menu_conversoes() {
    double x, y;
    double r, theta_rad, theta_deg;

    printf("\n--- CONVERSAO CARTESIANO (x,y) -> POLAR (r, theta) ---\n");
    printf("Digite a coordenada x: ");
    if (scanf("%lf", &x) != 1) return;
    printf("Digite a coordenada y: ");
    if (scanf("%lf", &y) != 1) return;
    
    // Raio (r) = sqrt(x^2 + y^2)
    r = sqrt(pow(x, 2.0) + pow(y, 2.0));

    // Angulo (theta) = atan2(y, x). Garante o quadrante correto.
    theta_rad = atan2(y, x);

    // Converte de radianos para graus
    theta_deg = theta_rad * RAD_TO_DEG;

    printf("\n--- Resultado ---\n");
    printf("Coordenadas Cartesianas: (%.4lf, %.4lf)\n", x, y);
    printf("Coordenadas Polares:\n");
    printf("  Raio (r): %.4lf\n", r);
    printf("  Angulo (theta): %.4lf radianos (%.2lf graus)\n", theta_rad, theta_deg);
}

// Opcao 4: Solucao de Equacoes
void solucionar_equacoes() {
    int opcao;
    
    printf("\n--- SOLUCAO DE EQUACOES ---\n");
    printf("1. Equacao de 1o Grau (ax + b = 0)\n");
    printf("2. Equacao de 2o Grau (ax^2 + bx + c = 0)\n");
    printf("0. Voltar\n");
    printf("Escolha uma opcao: ");
    if (scanf("%d", &opcao) != 1) return;

    switch (opcao) {
        case 1: { // Equacao de 1o Grau (ax + b = 0)
            double a, b, x;
            printf("Digite o coeficiente a: ");
            if (scanf("%lf", &a) != 1) break;
            printf("Digite o coeficiente b: ");
            if (scanf("%lf", &b) != 1) break;

            // Validacao: a nao pode ser zero
            if (fabs(a) < 1e-9) { 
                if (fabs(b) < 1e-9) {
                    printf("Solucao: Infinitas solucoes (0 = 0).\n");
                } else {
                    printf("Solucao: Sem solucao (e.g., 5 = 0).\n");
                }
                break;
            }

            // x = -b / a
            x = -b / a;
            printf("A equacao %.2lfx + %.2lf = 0 tem a solucao: x = %.4lf\n", a, b, x);
            break;
        }
        case 2: { // Equacao de 2o Grau (ax^2 + bx + c = 0)
            double a, b, c, delta;
            double x1, x2;
            
            printf("Digite o coeficiente a: ");
            if (scanf("%lf", &a) != 1) break;
            printf("Digite o coeficiente b: ");
            if (scanf("%lf", &b) != 1) break;
            printf("Digite o coeficiente c: ");
            if (scanf("%lf", &c) != 1) break;
            
            // Validacao: Se a = 0, nao e equacao de 2o grau
            if (fabs(a) < 1e-9) {
                printf("ERRO: O coeficiente 'a' deve ser diferente de zero para uma equacao de 2o grau.\n");
                break;
            }

            // Calculo do Discriminante (Delta): delta = b^2 - 4ac
            delta = pow(b, 2.0) - 4.0 * a * c;

            printf("\nDelta (Discriminante): %.4lf\n", delta);

            if (delta > 0) {
                // Duas raizes reais distintas
                x1 = (-b + sqrt(delta)) / (2.0 * a);
                x2 = (-b - sqrt(delta)) / (2.0 * a);
                printf("Solucao: Duas raizes reais distintas.\n");
                printf("x1 = %.4lf\n", x1);
                printf("x2 = %.4lf\n", x2);
            } else if (fabs(delta) < 1e-9) {
                // Uma raiz real (ou duas iguais)
                x1 = -b / (2.0 * a);
                printf("Solucao: Uma raiz real (ou duas raizes iguais).\n");
                printf("x = %.4lf\n", x1);
            } else {
                // Raizes complexas (delta < 0)
                double parte_real = -b / (2.0 * a);
                double parte_imaginaria = sqrt(fabs(delta)) / (2.0 * a);
                printf("Solucao: Duas raizes complexas conjugadas.\n");
                printf("x1 = %.4lf + %.4lfi\n", parte_real, parte_imaginaria);
                printf("x2 = %.4lf - %.4lfi\n", parte_real, parte_imaginaria);
            }
            break;
        }
        case 0:
            printf("Voltando ao menu principal.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}


// --- FUNCAO PRINCIPAL (MENU) ---
int main() {
    int escolha;

    do {
        printf("\n\n========================================\n");
        printf("  CALCULADORA DE ENGENHARIA (Menu Principal)\n");
        printf("========================================\n");
        printf("1. Calculo de Areas (2D)\n");
        printf("2. Calculo de Volumes (3D)\n");
        printf("3. Conversao de Coordenadas (Cartesiano/Polar)\n");
        printf("4. Solucao de Equacoes (1o e 2o Grau)\n");
        printf("0. Sair\n");
        printf("----------------------------------------\n");
        printf("Digite sua escolha: ");
        
        // Verifica se a leitura da escolha e valida
        if (scanf("%d", &escolha) != 1) {
            printf("\nEntrada invalida. Saindo do programa.\n");
            // Limpa o buffer de entrada para evitar loops infinitos em caso de entrada nao numerica
            while (getchar() != '\n'); 
            escolha = 0; 
        }

        switch (escolha) {
            case 1:
                menu_areas();
                break;
            case 2:
                menu_volumes();
                break;
            case 3:
                menu_conversoes();
                break;
            case 4:
                solucionar_equacoes();
                break;
            case 0:
                printf("\nEncerrando a Calculadora de Engenharia. Ate mais!\n");
                break;
            default:
                printf("\nOpcao %d invalida. Por favor, escolha uma opcao de 0 a 4.\n", escolha);
                break;
        }
    } while (escolha != 0);

    return 0;
}