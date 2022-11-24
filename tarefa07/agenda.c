#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "agenda.h"

void inicializar_agenda(Contato agenda[]){
    int i;

    for (i = 0; i < MAXREGISTROS; i++)
        agenda[i].tipo = '\0';
};

int buscar_reg(Contato agenda[], char nome[]){
    int i;

    for (i = 0; i < MAXREGISTROS; i++) {
        if (strcmp(agenda[i].nome, nome) == 0 && agenda[i].tipo != '\0') {
            return i;
        }
    }

    return -1;
}

int inserir_reg(Contato agenda[], char nome[], int matricula, int ddd, int telefone, char tipo){
    int i = 0, inserido = 0;

    while (i < MAXREGISTROS && agenda[i].tipo != '\0')
        i++;

    if (i < MAXREGISTROS) {
        strcpy(agenda[i].nome, nome);
        agenda[i].matricula = matricula;
        agenda[i].ddd = ddd;
        agenda[i].telefone = telefone;
        agenda[i].tipo = tipo;

        return 1;
    }

    return 0;
}

int apagar_reg(Contato agenda[], char nome[]){
    int i = 0, encontrado = 0;

    while (i < MAXREGISTROS) {
        if (strcmp(agenda[i].nome, nome) == 0 && agenda[i].tipo != '\0') {
            agenda[i].nome[0] = '\0';
            agenda[i].matricula = 0;
            agenda[i].ddd = 0;
            agenda[i].telefone = 0;
            agenda[i].tipo = '\0';

            return 1;
        }
        i++;
    }

    return 0;
}

void listar_nomes(Contato agenda[]){
    int i, j = 0; // j serve apenas para contar os registros encontrados

    printf("\n-- Lista de nomes --\n");
    for (i = 0; i < MAXREGISTROS; i++)
        if (agenda[i].tipo != '\0')
            printf("%d. %s\n", (++j), agenda[i].nome);
}