#include<stdio.h>
#include<stdlib.h>
int main(int narg, char *argv[]){
    float valor_prestacao, valor_atual, taxa_juros;
    int atraso;

    printf("Digite o valor original da prestação: R$");
    scanf("%f", &valor_prestacao);
    printf("Digite o percentual da taxa mensal de juros: ");
    scanf("%f", &taxa_juros);
    printf("Digite a quantidade de meses em atraso: ");
    scanf("%i", &atraso);

    valor_atual = valor_prestacao + (valor_prestacao * (taxa_juros/100) * atraso);
    printf("O novo valor da prestação em atraso é R$%.2f\n", valor_atual);
}
