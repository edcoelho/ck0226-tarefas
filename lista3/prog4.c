#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define PI 3.14

double volumeDaEsfera(double r);
double areaDaEsfera(double r);

int main(int narg, char *argv[]){
    double raio;

    setlocale(LC_ALL, "Portuguese");

    printf("Entre o valor do raio da circunferência: ");
    scanf("%lf", &raio);

    printf("\nO volume da esfera é %.2lf u.v.\n", volumeDaEsfera(raio));
    printf("A área da esfera é %.2lf u.a.\n", areaDaEsfera(raio));

    return EXIT_SUCCESS;
}

double volumeDaEsfera(double r){
    return (4*PI*r*r*r)/3; // (4/3)*PI*r*r*r deu o valor errado por algum motivo
}
double areaDaEsfera(double r){
   return 4*PI*r*r; 
}
