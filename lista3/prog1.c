#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int mdc(int a, int b){
	int r;

	while(b != 0){
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main(int narg, char *argv[]){
	int x, y;

	setlocale(LC_ALL, "Portuguese");
	
	do{
		printf("Entre um valor inteiro positivo para x: ");
		scanf("%i", &x);
	}while(x < 1);

	do{
		printf("Entre um valor inteiro positivo para y: ");
		scanf("%i", &y);
	}while(y < 1);

	printf("O MDC de %i e %i é %i.\n", x, y, mdc(x,y));

    return EXIT_SUCCESS;
}
