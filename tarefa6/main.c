#include<stdlib.h>
#include<stdio.h>
#include "cadeia.h"

char *num_extenso(char *n, char *extenso);
char *int_para_str(int num, char *str);
int quant_digitos(int num);

int main(int narg, char *argv[]){
    int i = 0, j; // contadores
    int num; // número entrado no terminal
    char num_str[5]; // número em formato string
    char numextenso[1000][1024]; // números por extenso
    char arq_endereco[128] = "./"; // endereço do arquivo
    FILE *arq;

    if(narg == 1){
        printf("Entre um inteiro no intervalo fechado de 1 a 999: ");
        scanf("%d", &num);

        while(num < 1 || num > 999){
            printf("Entrada inválida!\n\n");
            printf("Entre um inteiro no intervalo fechado de 1 a 999: ");
            scanf("%d", &num);
        }

        int_para_str(num, num_str);
        num_extenso(num_str, numextenso[0]);
        printf("Número %d por extenso: %s\n", num, numextenso[0]);
    }else{
        str_concatenar(argv[1], arq_endereco);
        arq = fopen(arq_endereco, "rt");

        if(arq == NULL){
            printf("Erro na abertura do arquivo.\n");
            return EXIT_FAILURE;
        }

        while(fgets(num_str, 5, arq) != NULL){
            // trocar \n por \0
            j = 0;
            while(j < 5){
                if(num_str[j] == '\n'){
                    num_str[j] = '\0';
                }
                j++;
            }

            if(str_tamanho(num_str) <= 3)
                num_extenso(num_str, numextenso[i]);
            i++;
        }

        fclose(arq);

        for(j = 0; j <= i; j++)
            printf("%s\n", numextenso[j]);
    }

    return EXIT_SUCCESS;
}

char *num_extenso(char *n, char *extenso){
    int tamanho = str_tamanho(n);
    int maior_indice = 0;

    if(tamanho == 3){
        maior_indice = 2;

        switch(n[0]){
            case '1':
                if(n[1] == '0' && n[2] == '0')
                    str_concatenar("cem", extenso);
                else
                    str_concatenar("cento", extenso);
                break;
            case '2':
                str_concatenar("duzentos", extenso);
                break;
            case '3':
                str_concatenar("trezentos", extenso);
                break;
            case '4':
                str_concatenar("quatrocentos", extenso);
                break;
            case '5':
                str_concatenar("quinhentos", extenso);
                break;
            case '6':
                str_concatenar("seiscentos", extenso);
                break;
            case '7':
                str_concatenar("setecentos", extenso);
                break;
            case '8':
                str_concatenar("oitocentos", extenso);
                break;
            case '9':
                str_concatenar("novecentos", extenso);
        }

        if(n[maior_indice - 1] != '0' || n[maior_indice] != '0')
            str_concatenar(" e ", extenso);
    }

    if(tamanho >= 2){
        if(tamanho == 2)
            maior_indice = 1;

        if(n[maior_indice - 1] == '1'){
            switch(n[maior_indice]){
                case '0':
                    str_concatenar("dez", extenso);
                    break;
                case '1':
                    str_concatenar("onze", extenso);
                    break;
                case '2':
                    str_concatenar("doze", extenso);
                    break;
                case '3':
                    str_concatenar("treze", extenso);
                    break;
                case '4':
                    str_concatenar("quatorze", extenso);
                    break;
                case '5':
                    str_concatenar("quinze", extenso);
                    break;
                case '6':
                    str_concatenar("dezesseis", extenso);
                    break;
                case '7':
                    str_concatenar("dezessete", extenso);
                    break;
                case '8':
                    str_concatenar("dezoito", extenso);
                    break;
                case '9':
                    str_concatenar("dezenove", extenso);
            }
        }else{
            switch(n[maior_indice - 1]){
                case '2':
                    str_concatenar("vinte", extenso);
                    break;
                case '3':
                    str_concatenar("trinta", extenso);
                    break;
                case '4':
                    str_concatenar("quarenta", extenso);
                    break;
                case '5':
                    str_concatenar("cinquenta", extenso);
                    break;
                case '6':
                    str_concatenar("sessenta", extenso);
                    break;
                case '7':
                    str_concatenar("setenta", extenso);
                    break;
                case '8':
                    str_concatenar("oitenta", extenso);
                    break;
                case '9':
                    str_concatenar("noventa", extenso);
            }

            if(n[maior_indice - 1] != '0' && n[maior_indice - 1] != '1' && n[maior_indice] != '0')
                str_concatenar(" e ", extenso);
        }
    }

    if(tamanho == 1 || (tamanho > 1 && n[maior_indice - 1] != '1')){
        switch(n[maior_indice]){
            case '0':
                if(tamanho == 1)
                    str_concatenar("zero", extenso);
                break;
            case '1':
                str_concatenar("um", extenso);
                break;
            case '2':
                str_concatenar("dois", extenso);
                break;
            case '3':
                str_concatenar("três", extenso);
                break;
            case '4':
                str_concatenar("quatro", extenso);
                break;
            case '5':
                str_concatenar("cinco", extenso);
                break;
            case '6':
                str_concatenar("seis", extenso);
                break;
            case '7':
                str_concatenar("sete", extenso);
                break;
            case '8':
                str_concatenar("oito", extenso);
                break;
            case '9':
                str_concatenar("nove", extenso);
        }
    }

    return extenso;
}

char *int_para_str(int num, char *str){
    int qtd_digitos = quant_digitos(num);
    int i = qtd_digitos - 1;
    char digito;

    while(i >= 0){
        switch(num % 10){
            case 0:
                digito = '0';
                break;
            case 1:
                digito = '1';
                break;
            case 2:
                digito = '2';
                break;
            case 3:
                digito = '3';
                break;
            case 4:
                digito = '4';
                break;
            case 5:
                digito = '5';
                break;
            case 6:
                digito = '6';
                break;
            case 7:
                digito = '7';
                break;
            case 8:
                digito = '8';
                break;
            case 9:
                digito = '9';
        }
        
        num = (num - num % 10) / 10;
        str[i] = digito;
        i--;
    }

    str[qtd_digitos] = '\0';

    return str;
}

int quant_digitos(int num){
    if(num >= 10)
        return 1 + quant_digitos((num - num % 10) / 10);
    else
        return 1;
}