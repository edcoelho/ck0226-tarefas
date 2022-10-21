#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int fat(int n);
double pot(float b, int e);
double potE(int x);

int main(int narg, char *argv[]){
    int x;
    setlocale(LC_ALL, "Portuguese");

    printf("Entre o expoente: ");
    scanf("%i", &x);
    printf("e elevado a %i é: %.10lf\n", x, potE(x));

    return EXIT_SUCCESS;
}

int fat(int n){
    int f = 1;
    while(n > 0)
        f = f * n--;
    return f;
}

double pot(float b, int e){
    double x = 1;
    while(e > 0){
        x = x * b;
        e--;
    }
    if(e < 0){
        e = e * -1;
        x = 1 / pot(b, e);
    }
    return x;
}

double potE(int x){
    double n = 1;
    double c = pot(10, -6); // constante para teste de laço
    int i = x;
    while(i > 0 && n > c){
        n = n + (pot(x,i) / fat(i));
        i--;
    }
    if(x < 0){
        x = x * -1;
        n = 1 / potE(x);
    }
    return n;
}
