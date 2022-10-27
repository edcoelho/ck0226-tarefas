#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "agenda.h"

void buscar_tel(char nome[], TipoAgenda agenda[]){
    int i, encontrado = 0;

    for (i = 0; i < MAXREGISTROS; i++) {
        if (strcmp(agenda[i].nome, nome) == 0 && agenda[i].tipo != '\0') {
            printf("\n%s - (%d) %d ", agenda[i].nome, agenda[i].ddd, agenda[i].telefone);
            if (agenda[i].tipo == 'C')
                printf("(celular)\n");
            else
                printf("(fixo)\n");
            encontrado = 1;
        }
    }
    if (!encontrado)
        printf("\nContato não encontrado!\n");
}

void inserir_reg(TipoAgenda reg, TipoAgenda agenda[]){
    int i = 0, inserido = 0;

    while (i < MAXREGISTROS && !inserido) {
        if (agenda[i].tipo == '\0') {
            strcpy(agenda[i].nome, reg.nome);
            agenda[i].matricula = reg.matricula;
            agenda[i].ddd = reg.ddd;
            agenda[i].telefone = reg.telefone;
            agenda[i].tipo = reg.tipo;
            inserido = 1;
        }
        i++;
    }

    if (inserido)
        printf("\nContato inserido com sucesso!\n");
    else
        printf("\nA agenda está cheia!\n");
}

void apagar_reg(char nome[], TipoAgenda agenda[]){
    int i = 0, encontrado = 0;

    while (i < MAXREGISTROS && !encontrado) {
        if (strcmp(agenda[i].nome, nome) == 0 && agenda[i].tipo != '\0') {
            agenda[i].nome[0] = '\0';
            agenda[i].matricula = 0;
            agenda[i].ddd = 0;
            agenda[i].telefone = 0;
            agenda[i].tipo = '\0';
            encontrado = 1;
        }
        i++;
    }
    if (encontrado)
        printf("\nContato removido com sucesso!\n");
    else
        printf("\nContato não encontrado!\n");
}

void listar_nomes(TipoAgenda agenda[]){
    int i, j = 0; // j serve apenas para contar os registros encontrados

    printf("\n-- Lista de nomes --\n");
    for (i = 0; i < MAXREGISTROS; i++)
        if (agenda[i].tipo != '\0')
            printf("%d. %s\n", (++j), agenda[i].nome);
}