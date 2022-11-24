#include<stdio.h>
#include<stdlib.h>
int main(int narg, char *argv[]){
    float preco_dolar, preco_real, taxa_dolar, icms, lucro, preco_final;

    printf("Digite o valor da compra em dólares: ");
    scanf("%f", &preco_dolar);
    printf("Digite a taxa do dólar: ");
    scanf("%f", &taxa_dolar);
    printf("Digite o percentual de ICMS: ");
    scanf("%f", &icms);
    printf("Digite o percentual de lucro: ");
    scanf("%f", &lucro);

    preco_real = preco_dolar * taxa_dolar; 
    preco_final = preco_real + (preco_real * (lucro / 100));
    preco_final = preco_final + (preco_final * (icms / 100));

    printf("Valor a ser pago: R$%.2f\n", preco_final);
}
