#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(int narg, char* argv[]){
    int cont = 0, num = 1;

    setlocale(LC_ALL, "Portuguese");

    printf("Os 1000 primeiro ímpares não divisíveis por 3 e 7 são: \n");
    while(cont < 1000){
        if((num % 2 != 0) && (num % 3 != 0) && (num % 7 != 0)){
            printf("%d\n", num);
            cont++;
        }
        num++;
    }

    return EXIT_SUCCESS;
}