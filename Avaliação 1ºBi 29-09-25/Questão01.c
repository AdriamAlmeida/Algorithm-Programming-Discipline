#include <stdio.h>

int main(){
    char nome[100];
    float horas, s_bruto, s_liquido, extras, valor_h, resultado, adicional=50, inss=11;

    printf("Informe o nome do funcionário: \n");
    scanf("%s", &nome);
    printf("Informe as horas semanais trabalhadas (0 a 168): \n");
    scanf("%f", &horas);
    printf("Informe o valor por hora: \n");
    scanf("%f", &valor_h);
    
    if (horas>40)
    {
        extras= horas-40;
        resultado=valor_h+(adicional/100*valor_h);

        s_bruto=horas*resultado;
        s_liquido=s_bruto-(inss/100*s_bruto);
    } else if (horas<40)
    {
        s_bruto=horas*valor_h;
        s_liquido=s_bruto-(inss/100*s_bruto);
    }
    if (horas>0 || horas<168)
    {
    printf("\n ---CÁLCULO DE PAGAMENTO--- \n");
    printf("Nome do funcionário: %s \n", nome);
    printf("Horas trabalhadas na semana: %.0fh \n", horas);
    printf("Valor por hora: %.2f \n", valor_h);
    
    printf("\n ---PAGAMENTO--- \n");
    printf("Funcionário: %s \n", nome);
    printf("Horas normais 40h x R$%.2f = R$%.2f \n", valor_h, 40*valor_h);
    printf("Horas extras %.2fh x R$%.2f = R$%.2f \n", extras, resultado, extras*resultado);
    printf("Salário Bruto: R$%.2f \n", s_bruto);
    printf("Desconto INSS (11%%): R$%.2f \n", inss);
    printf("Salário líquido: R$%.2f \n", s_liquido);
    } else 
    {
        printf("Horas excedidas!!! \n");
    }
    
    return 0;
}