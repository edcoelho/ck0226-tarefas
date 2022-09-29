#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int palindromo(long int num, long int num_inv, long int comp);

int main(int narg, char *argv[]) {
    long int x;

    setlocale(LC_ALL, "Portuguese");
    
    printf("Digite um número inteiro positivo de até 7 dígitos: ");
    scanf("%li", &x);

    if(palindromo(x, 0, x))
        printf ("\n%li é um palindromo\n", x);
    else
        printf ("\n%li não é um palindromo\n", x);
    
    return EXIT_SUCCESS;
}

int palindromo(long int num, long int num_inv, long int comp){
    long int aux;
  
    if (num != 0){
        aux = (int) num % 10;
        num_inv = num_inv * 10 + aux;
        num = (int) num / 10;
        return palindromo(num, num_inv, comp);
    }else{
        if(comp == num_inv)
            return 1;
        else
            return 0;
    }
}