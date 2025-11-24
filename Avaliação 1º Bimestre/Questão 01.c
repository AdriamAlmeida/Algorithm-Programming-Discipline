#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
Problema:
Desenvolva um programa em C que:
1. Leia o nome do funcionário
2. Leia a quantidade de horas trabalhadas na semana (0 a 168 horas)
3. Leia o valor da hora trabalhada
4. Calcule e exiba:
◦ Salário bruto (horas × valor/hora)
◦ Se trabalhou mais de 40 horas, as horas extras (acima de 40h) devem ser pagas com
50% de adicional
◦ Desconto de INSS: 11% sobre o salário bruto
◦ Salário líquido (bruto - INSS)
Exemplo de Execução:
=== SISTEMA DE CÁLCULO DE PAGAMENTO ===
Nome do funcionário: João Silva
Horas trabalhadas na semana: 45
Valor por hora: R$ 25.00
--- RECIBO DE PAGAMENTO ---
Funcionário: João Silva
Horas normais: 40h x R$ 25.00 = R$ 1000.00
Horas extras: 5h x R$ 37.50 = R$ 187.50
Salário bruto: R$ 1187.50
Desconto INSS (11%): R$ 130.63
Salário líquido: R$ 1056.87
*/

int main(){
    char nome[100];
    float horas, s_bruto, s_liquido, extras, valor_h, horas_normais, salario_normais, valor_extras, salario_extras, inss;

    printf("Informe o nome do funcionário: \n");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")]=0;

    printf("Informe as horas semanais trabalhadas (0 a 168): \n");
    scanf("%f", &horas);

    while (horas < 0 || horas > 168) /* Laço de repetição para caso informe alguma hora inválida */
    { 
        printf("Horas Inválidas. Informe um valor entre 0 a 168 horas. \n");
        printf("Informe as horas semanais trabalhadas (0 a 168): \n");
        scanf("%f", &horas);
    }

    printf("Informe o valor por hora: \n");
    scanf("%f", &valor_h);
        
    if (horas>40) /* Condição com hora extra */
    { 
        extras = horas - 40;
        valor_extras = (valor_h * 0.5 + valor_h);
        salario_extras = extras * valor_extras;
        horas_normais = horas - extras;
        salario_normais = horas_normais * valor_h;

    } else /* Condição sem hora extra */
    { 
        extras = 0;
        valor_extras = (horas * 0.5 + valor_h) * extras;
        horas_normais = horas;
        salario_normais = horas * valor_h;
        salario_extras = 0;

    }

    s_bruto = salario_normais + salario_extras; /* Calculo salario bruto*/
    inss = s_bruto * 0.11; /* Calculo do INSS */
    s_liquido = s_bruto - inss; /* Calculo do salario liquido */

    /* Resultado Final */
    
    printf("\n ---CÁLCULO DE PAGAMENTO--- \n");
    printf("Nome do funcionário: %s \n", nome);
    printf("Horas trabalhadas na semana: %.0fh \n", horas);
    printf("Valor por hora: %.2f \n", valor_h);
        
    printf("\n ---PAGAMENTO--- \n");
    printf("Funcionário: %s \n", nome);
    printf("Horas normais %.2f x R$%.2f = R$%.2f \n", horas_normais, valor_h, salario_normais);
    printf("Horas extras %.2fh x R$%.2f = R$%.2f \n", extras, valor_extras, salario_extras);
    printf("Salário Bruto: R$%.2f \n", s_bruto);
    printf("Desconto INSS (11%%): R$%.2f \n", inss);
    printf("Salário líquido: R$%.2f \n", s_liquido);
        
    return 0;
}