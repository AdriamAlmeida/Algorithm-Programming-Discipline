#include <stdio.h>
int main(){
    float tensao, corrente, potencia;

    printf("Digite a tensão e a corrente: \n");
    scanf("%f", &tensao);
    scanf("%f", &corrente);

    potencia= tensao*corrente;

    printf("A potência será %.2fW", potencia);

    return 0;
}