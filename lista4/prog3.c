#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

double pot(double x, int k);

int main(int narg, char *argv[]){
    double x, res, res_pow;
    int k;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o valor da base: ");
    scanf("%lf", &x);
    printf("Digite o valor do expoente: ");
    scanf("%d", &k);

    res = pot(x, k);
    res_pow = pow(x, k);

    if(res == res_pow){
        printf("\n%.2lf elevado a %d é %.2lf\n", x, k, res);
    }else{
        printf("\nEu calculei %.2lf elevado a %d e deu %.2lf, mas está errado.\n", x, k, res);
        printf("O resultado correto seria %.2lf.\n", res_pow);
    }

    return EXIT_SUCCESS;
}

double pot(double x, int k){
    if(k > 0)
        return x * pot(x, k - 1);
    else
        return 1;
}