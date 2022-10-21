#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(int narg, char *argv[]){
    long int n, num; 
    double aux;
    long int n_inv = 0; // número invertido
    int quant_digitos = 0;
    int i, j; // contadores

    setlocale(LC_ALL, "Portuguese");

    do{
        printf("Digite um número inteiro de até 10 dígitos: ");
        scanf("%li", &n);
    }while(n < -9999999999 || n > 9999999999);

    num = n; // salvando valor original de n para mostrar na saída
    aux = n;
    while(aux < -1 || aux > 1){
        aux = aux / 10;
        quant_digitos++;
    }

    for(i = 0; i < quant_digitos; i++){
        aux = n % 10;
        n = (n - aux) / 10;

        for(j = 0; j < (quant_digitos - i - 1); j++){
            aux = aux * 10;
        }

        n_inv = n_inv + aux;
    }

    printf("O número %li invertido é %li.\n", num, n_inv);

    return EXIT_SUCCESS;
}