#include <stdio.h>
#include <stdlib.h>

int main(int narg, char *argv[]) {
	float sal, val_h, acresc;
	int h_trab, n_filhos;

	printf("digite o número de horas trabalhadas: ");
	scanf("%d", &h_trab);
	printf("digite o salário/h: ");
	scanf("%f", &val_h);
	printf("digite o numero de filhos: ");
	scanf("%d", &n_filhos);

	sal = val_h * h_trab;

	if (n_filhos > 3)
	{
		acresc = (sal * 0.03) * n_filhos;
	} else
	{
		acresc = 0;
	}

	sal += acresc;

	printf("o salario final é: %.2f\n", sal);

	return EXIT_SUCCESS;
}
