#include <stdio.h>
#include <string.h> // Para usar a função strlen()
#include <ctype.h>  // Para usar a função isdigit()
#include <stdbool.h> // Para usar o tipo bool (true/false)

int main() {
    char cpf_input[15];
    int cpf_digits[11];
    int i;

    // ENTRADA E VALIDAÇÃO BÁSICA DO FORMATO
    printf("=== VALIDADOR DE CPF ===\n");
    printf("Digite os 11 dígitos do CPF (apenas números): ");
    scanf(" %s", &cpf_input);

    // Verifica se existe 11 caracteres
    if (strlen(cpf_input) != 11) {
        printf("Erro: O CPF deve conter exatamente 11 dígitos.\n");
        return 1; // Termina o programa com erro
    }
    
    // Verifica se todos os caracteres são dígitos numéricos
    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf_input[i])) {
            printf("Erro: Digite apenas números.\n");
            return 1; // Termina o programa com erro
        }
    }

    // Converte os caracteres para números inteiros
    for (i = 0; i < 11; i++) {
        cpf_digits[i] = cpf_input[i] - '0';
    }
    
    // Verifica se todos os dígitos são iguais (ex: 11111111111), que é um CPF inválido
    bool all_same = true;
    for (i = 1; i < 11; i++) {
        if (cpf_digits[i] != cpf_digits[0]) {
            all_same = false;
            break;
        }
    }
    if (all_same) {
        printf("CPF Inválido! (Dígitos repetidos)\n");
        return 0;
    }

    // --- 2. CÁLCULO DO PRIMEIRO DÍGITO VERIFICADOR (J) ---
    int soma1 = 0;
    for (i = 0; i < 9; i++) {
        soma1 += cpf_digits[i] * (10 - i);
    }

    int resto1 = soma1 % 11;
    int digito_verificador1;

    if (resto1 < 2) {
        digito_verificador1 = 0;
    } else {
        digito_verificador1 = 11 - resto1;
    }

    // --- 3. CÁLCULO DO SEGUNDO DÍGITO VERIFICADOR (K) ---
    int soma2 = 0;
    for (i = 0; i < 10; i++) {
        soma2 += cpf_digits[i] * (11 - i);
    }
    
    int resto2 = soma2 % 11;
    int digito_verificador2;

    if (resto2 < 2) {
        digito_verificador2 = 0;
    } else {
        digito_verificador2 = 11 - resto2;
    }

    // --- 4. VALIDAÇÃO FINAL ---
    // Compara os dígitos calculados com os dígitos informados pelo usuário
    if (digito_verificador1 == cpf_digits[9] && digito_verificador2 == cpf_digits[10]) {
        printf("\n CPF Válido! \n");
    } else {
        printf("\n CPF Inválido! \n");
    }

    return 0;
}