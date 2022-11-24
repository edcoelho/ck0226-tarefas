#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2){
	float distancia;

	distancia = pow((x1-x2), 2) + pow((y1-y2), 2) + pow((z1-z2), 2);
	distancia = sqrt(distancia);

	return distancia;
}

int main(int narg, char *argv[]){
	float x1, y1, z1, x2, y2, z2, distancia;

	printf("Entre as coodernadas do ponto p1\n\n");

	printf("x1: ");
	scanf("%f", &x1);
	printf("y1: ");
	scanf("%f", &y1);
	printf("z1: ");
	scanf("%f", &z1);

	printf("\nEntre as coodernadas do ponto p2\n\n");

	printf("x2: ");
	scanf("%f", &x2);
	printf("y2: ");
	scanf("%f", &y2);
	printf("z2: ");
	scanf("%f", &z2);

	distancia = calcularDistancia(x1,y1,z1,x2,y2,z2);

	printf("\nA distância entre os pontos p1(%.1f, %.1f, %.1f) e p2(%.1f,%.1f,%.1f) é %.2f.\n", x1, y1, z1, x2, y2, z2, distancia);

    return EXIT_SUCCESS;
}
