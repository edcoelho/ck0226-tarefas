#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int fat(int n);
double pot(double x, int k);
double potE(int x, int i);

int main(int narg, char *argv[]){
    int x;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o valor do expoente: ");
    scanf("%d", &x);
    printf("O número de Euler elevado a %d é %lf\n", x, potE(x, 0));

    return EXIT_SUCCESS;
}

int fat(int n){
    if(n > 1)
        return n * fat(n - 1);
    else
        return 1;
}

double pot(double x, int k){
    if(k > 0)
        return x * pot(x, k - 1);
    else
        return 1;
}

double potE(int x, int i){ // i necessário para o controle da recursividade
    double res = (pot(x, i)/fat(i));
    if(res > 10e-6)
        return res + potE(x, i + 1);
    else
        return 0;
}