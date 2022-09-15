#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int main(int narg, char *argv[]){
    int div_tres = 0, n, cont = 1, cont_tres = 1;
    float media = 0, media_tres = 0;

    setlocale(LC_ALL, "Portuguese");

    while(cont_tres <= 10){
        printf("Digite um número inteiro: ");
        scanf("%d", &n);

        if(n % 3 == 0){
            media_tres = media_tres + n;
            cont_tres = cont_tres + 1;
        }else{
            media = media + n;
            cont = cont + 1;
        }
    }

    media = media / cont;
    media_tres = media_tres / cont_tres;

    printf("A média dos números divisíveis por 3 é %.2f.\n", media_tres);
    printf("A média dos demais números é %.2f.\n", media);

    return EXIT_SUCCESS;
}