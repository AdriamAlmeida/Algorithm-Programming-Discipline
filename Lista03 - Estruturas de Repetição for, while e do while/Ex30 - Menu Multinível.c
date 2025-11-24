#include <stdio.h>

int main() {
    int opcao_principal;
    int opcao_sub;

    printf("--- Sistema de Menu Multinivel ---\n");

    // 1. LACO EXTERNO (Menu Principal)
    do {
        // Exibe o Menu Principal
        printf("\n===================================\n");
        printf("         MENU PRINCIPAL\n");
        printf("===================================\n");
        printf("1. Opcoes de Calculo\n");
        printf("2. Opcoes de Configuracao\n");
        printf("0. Sair do Programa\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao_principal);

        switch (opcao_principal) {
            case 1:
                // LACO INTERNO (Submenu de Calculo)
                do {
                    printf("\n-----------------------------------\n");
                    printf("        SUBMENU DE CALCULO\n");
                    printf("-----------------------------------\n");
                    printf("1. Somar dois numeros\n");
                    printf("2. Subtrair dois numeros\n");
                    printf("9. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao_sub);

                    switch (opcao_sub) {
                        case 1:
                            printf("-> Executando Soma...\n");
                            break;
                        case 2:
                            printf("-> Executando Subtracao...\n");
                            break;
                        case 9:
                            printf("<- Voltando ao Menu Principal...\n");
                            break;
                        default:
                            printf("Opcao invalida no Submenu de Calculo.\n");
                            break;
                    }

                } while (opcao_sub != 9); // O submenu roda ate o usuario digitar 9
                break; // Sai do switch principal

            case 2:
                // LACO INTERNO (Submenu de Configuracao)
                do {
                    printf("\n-----------------------------------\n");
                    printf("      SUBMENU DE CONFIGURACAO\n");
                    printf("-----------------------------------\n");
                    printf("1. Mudar tema\n");
                    printf("2. Resetar configuracoes\n");
                    printf("9. Voltar ao Menu Principal\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao_sub);

                    switch (opcao_sub) {
                        case 1:
                            printf("-> Mudando o tema para Escuro...\n");
                            break;
                        case 2:
                            printf("-> Resetando configuracoes padrao...\n");
                            break;
                        case 9:
                            printf("<- Voltando ao Menu Principal...\n");
                            break;
                        default:
                            printf("Opcao invalida no Submenu de Configuracao.\n");
                            break;
                    }

                } while (opcao_sub != 9); // O submenu roda ate o usuario digitar 9
                break; // Sai do switch principal
            
            case 0:
                printf("\nSaindo do programa. Ate logo!\n");
                break;
            
            default:
                printf("\nOpcao invalida no Menu Principal. Tente novamente.\n");
                break;
        }

    } while (opcao_principal != 0); // O menu principal roda ate o usuario digitar 0

    return 0;
}