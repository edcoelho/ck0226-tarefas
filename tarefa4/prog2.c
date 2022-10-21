#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int mdc(int x, int y);

int main(int narg, char *argv[]){
    int a, b;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo o número: ");
    scanf("%d", &b);

    printf("\nO MDC(%d,%d) é %d.\n", a, b, mdc(a,b));

    return EXIT_SUCCESS;
}

int mdc(int x, int y){
    int r = x % y;

    if(r != 0)
        return mdc(y, r);
    else
        return y;
}