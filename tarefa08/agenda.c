#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "agenda.h"

void inicializar_agenda(Contato* agenda[]){
    int i;

    for (i = 0; i < MAXREGISTROS; i++)
        agenda[i] = NULL;
}

int buscar_reg(Contato* agenda[], char nome[]){
    int i;

    for (i = 0; i < MAXREGISTROS; i++) {
        if (agenda[i] != NULL && strcmp(agenda[i]->nome, nome) == 0) {
            return i;
        }
    }

    return -1;
}

int inserir_reg(Contato* agenda[], char nome[], int matricula, int ddd, int telefone, char tipo){
    int i = 0;

    while (i < MAXREGISTROS && agenda[i] != NULL)
        i++;

    if (i < MAXREGISTROS) {
        agenda[i] = (Contato*) malloc(sizeof(Contato));

        strcpy(agenda[i]->nome, nome);
        agenda[i]->matricula = matricula;
        agenda[i]->ddd = ddd;
        agenda[i]->telefone = telefone;
        agenda[i]->tipo = tipo;

        return 1;
    }

    return 0;
}

int apagar_reg(Contato* agenda[], char nome[]){
    int i = 0;

    while (i < MAXREGISTROS) {
        if (agenda[i] != NULL && strcmp(agenda[i]->nome, nome) == 0) {
            free(agenda[i]);
            agenda[i] = NULL;

            return 1;
        }
        i++;
    }

    return 0;
}

void listar_nomes(Contato* agenda[]){
    int i, j = 0; // j serve apenas para contar os registros encontrados

    printf("\n-- Lista de nomes --\n");
    for (i = 0; i < MAXREGISTROS; i++)
        if (agenda[i] != NULL)
            printf("%d. %s\n", (++j), agenda[i]->nome);
}

void trocar_posicao(Contato* agenda[], int ind1, int ind2){
    Contato* aux;

    aux = agenda[ind1];
    agenda[ind1] = agenda[ind2];
    agenda[ind2] = aux;
}

void ordernar_por_nome(Contato* agenda[]){
    int i, trocou;

    do {
        trocou = 0;

        for (i = 0; i < MAXREGISTROS - 1; i++) {
            if ((agenda[i] == NULL && agenda[i+1] != NULL) || (agenda[i+1] != NULL && strcmp(agenda[i]->nome, agenda[i+1]->nome) > 0)) {
                trocar_posicao(agenda, i, i+1);
                trocou = 1;
            }
        }
    } while (trocou);   
}