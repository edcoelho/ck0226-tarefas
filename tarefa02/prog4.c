#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(int narg, char *argv[]){
    int n, num, i;
    int primo; // guarda se o número é primo
    
    setlocale(LC_ALL, "Portuguese");

    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    if(n > 2){
        num = n - 1;

        primo = 0;
        while(num > 1 && !primo){
            primo = 1;

            i = 2;
            while(i <= num && primo){
                if(num % i == 0 && num != i){
                    primo = 0;
                }
                i++;
            }

            if(primo)
                printf("O maior número primo menor que %d é %d.\n", n, num);
            else
                num--;
        }
    }else{
        printf("Não existe número primo menor que %d.\n", n);
    }

    return EXIT_SUCCESS;
}