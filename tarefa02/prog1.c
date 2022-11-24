#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(int narg, char *argv[]){
    int n;
    int i, j, num = 2; // contadores
    int primo; // guarda se o número é primo

    setlocale(LC_ALL, "Portuguese");

    do{
        printf("Digite um número inteiro positivo: ");
        scanf("%d", &n);
    }while(n <= 0);

    printf("Os %d primeiros números primos são: \n", n);

    i = 0;
    while(i < n){
        primo = 1; 

        j = 2;
        while(j <= num && primo){
            if(num % j == 0 && num != j){
                primo = 0;
            }
            j++;
        } 

        if(primo){
            printf("%d\n", num);
            i++;
        }

        num++;
    }

    return EXIT_SUCCESS;
}
