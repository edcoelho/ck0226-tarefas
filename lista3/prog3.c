#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int mdc(int a, int b);

int main(int narg, char *argv[]){
    int x, y, z;

    setlocale(LC_ALL, "Portuguese");

    do{
        printf("Entre o primeiro valor inteiro positivo: ");
        scanf("%i", &x);
    }while(x < 1);

    do{
        printf("Entre o segundo valor inteiro positivo: ");
        scanf("%i", &y);
    }while(y < 1);

    do{
        printf("Entre o terceiro valor inteiro positivo: ");
        scanf("%i", &z);
    }while(z < 1);

    printf("O MDC de %i, %i e %i é %i.\n", x, y, z, mdc(mdc(x,y),z));

    return EXIT_SUCCESS;
}

int mdc(int a, int b){
	int r;

	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}
