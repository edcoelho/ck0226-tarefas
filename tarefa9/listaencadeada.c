#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "listaencadeada.h"

void inserir(Contato **agenda, int matricula, char nome[], int ddd, int telefone, char tipo) {
    Contato *novo, *anterior = NULL, *inicio = *agenda;

    novo = (Contato *) malloc(sizeof(Contato *));
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    novo->ddd = ddd;
    novo->telefone = telefone;
    novo->tipo = tipo;
    novo->prox = NULL;

    while (*agenda != NULL && (*agenda)->prox != NULL && strcmp(nome, (*agenda)->nome) > 0) {
        anterior = *agenda;
        *agenda = (*agenda)->prox;
    }

    if (*agenda == NULL) {
        *agenda = novo;
    } else if (strcmp(nome, (*agenda)->nome) < 0) {
        if (anterior == NULL) {
            novo->prox = *agenda;
            inicio = novo;
        } else {
            anterior->prox = novo;
            novo->prox = *agenda;
        }
    } else {
        (*agenda)->prox = novo;
    }

    if (inicio != NULL)
        *agenda = inicio;
}

void percorrer(Contato *agenda) {
    while (agenda != NULL) {
        printf("\n%d\n%s\n(%d) %d - %s\n", agenda->matricula, agenda->nome, agenda->ddd, agenda->telefone, (agenda->tipo == 'C' ? "celular" : "fixo"));
        agenda = agenda->prox;
    }
}

int carregar(Contato **agenda, char arquivo[]) {
    Contato contato;
    FILE *arq = fopen(arquivo, "rt");

    if (arq == NULL) 
        return 0;

    while (fscanf(arq, "%d\n%s\n%d\n%d\n%c", &contato.matricula, contato.nome, &contato.ddd, &contato.telefone, &contato.tipo) != EOF)
        inserir(agenda, contato.matricula, contato.nome, contato.ddd, contato.telefone, contato.tipo);

    fclose(arq);

    return 1;
}

int salvar(Contato *agenda, char arquivo[]) {
    Contato contato;
    FILE *arq = fopen(arquivo, "wt");

    if (arq == NULL) 
        return 0;

    while (agenda != NULL) {
        fprintf(arq, "%d\n%s\n%d\n%d\n%c\n", agenda->matricula, agenda->nome, agenda->ddd, agenda->telefone, agenda->tipo);
        agenda = agenda->prox;
    }

    fclose(arq);

    return 1;
}