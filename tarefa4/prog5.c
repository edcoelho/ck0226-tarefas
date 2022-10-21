#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int pot(int b, int e);
int quantDigitos(long int num);
int ultimoDigito(long int num);
int primeiroDigito(long int num);
long int digitosDoMeio(long int num);
short int palindromo(long int num);

int main(int narg, char *argv[]) {
    long int x;

    setlocale(LC_ALL, "Portuguese");
    
    printf("Digite um número inteiro positivo de até 7 dígitos: ");
    scanf("%li", &x);

    if(palindromo(x))
        printf ("\n%li é um palindromo\n", x);
    else
        printf ("\n%li não é um palindromo\n", x);
    
    return EXIT_SUCCESS;
}

int pot(int b, int e){
    if(e > 0)
        return b * pot(b, e - 1);
    else
        return 1;
}

int quantDigitos(long int num){
    if(num >= 10)
        return 1 + quantDigitos((num - num % 10) / 10);
    else
        return 1;
}

int ultimoDigito(long int num){
    return num % 10;
}

int primeiroDigito(long int num){
    if(num >= 10)
        return primeiroDigito((num - num % 10) / 10);
    else
        return num;
}

long int digitosDoMeio(long int num){
    int r;
    r = num % pot(10, quantDigitos(num) - 1);
    r = (r - r % 10) / 10;
    return r;
}

short int palindromo(long int num){
    if(num >= 10)
        if(primeiroDigito(num) == ultimoDigito(num))
            return palindromo(digitosDoMeio(num));
        else
            return 0;
    else
        return 1;
}
