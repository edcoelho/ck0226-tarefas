#include <stdio.h>
#include <stdlib.h>

int main(int narg, char *argv[]) {
	int num, numFinal, c, d, u;
	printf("digite um número de 3 dígitos para a inversão: ");
	scanf("%d", &num);
	c = (num % 10);
	d = (num % 100) / 10;
	u = (num / 100);

	numFinal = c * 100 + d * 10 + u;
	printf("%d -- %d", num, numFinal);

	return EXIT_SUCCESS;
}
