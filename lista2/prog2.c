#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(int narg, char *argv[]){
    int n, cont = 0, aux, num_anterior = 0, num_atual = 1;

    setlocale(LC_ALL, "Portuguese");

    do{
        printf("Digite um número inteiro positivo: ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("Os números da sequência de Fibonacci menores que %d são:\n%d\n", n, num_anterior);
    do{
        if(num_atual < n){
            printf("%d\n", num_atual);
        }
      
        aux = num_atual;
        num_atual = num_atual + num_anterior;
        num_anterior = aux;
    }while(num_atual < n);

    return EXIT_SUCCESS;
}
