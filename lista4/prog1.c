#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int resto(int a, int b);

int main(int narg, char *argv[]){
    int x, y;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o valor do dividendo: ");
    scanf("%d", &x);
    printf("Digite o valor do divisor: ");
    scanf("%d", &y);

    if(x == 0 && y == 0)
        printf("\nEu perguntei para a Siri quanto é 0 dividido por 0 e ela respondeu: \"Imagine um cenário onde você tem zero cookies para dividir entre zero amigos. Vê? Não faz sentido. O Come-Come fica triste porque não tem cookies e você fica triste porque não tem amigos.\"\n");
    else if(y == 0)
        printf("\nErro fatal no sistema! Formatando unidade de disco... brincadeira. Mas não tenta dividir por zero aí de novo não, por favor.\n");
    else
        printf("\nO resto da divisão é %d.\n", resto(x,y));

    return EXIT_SUCCESS;
}

int resto(int a, int b){
    if(a >= b){
        a = a - b;
        resto(a, b);
    }else{
        return a;
    }
}