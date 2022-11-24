#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "listaencadeadadupla.h"

void inserir(Agenda *agenda, int matricula, char *nome, int ddd, int telefone, char tipo) {
    Contato *novo, **head = &agenda->inicio, *inicio = agenda->inicio;
    char *nome_alocado;

    // nome com espaço de memória sob medida
    nome_alocado = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(nome_alocado, nome);

    novo = (Contato *) malloc(sizeof(Contato));
    novo->matricula = matricula;
    novo->nome = nome_alocado;
    novo->ddd = ddd;
    novo->telefone = telefone;
    novo->tipo = tipo;
    novo->ant = NULL;
    novo->prox = NULL;

    while (*head != NULL && (*head)->prox != NULL && strcmp(nome, (*head)->nome) > 0)
        *head = (*head)->prox;

    if (*head == NULL) {
        agenda->inicio = novo;
        agenda->fim = novo;
    } else if (strcmp(nome, (*head)->nome) <= 0) {
        if ((*head)->ant == NULL) {
            novo->prox = *head;
            (*head)->ant = novo;
            inicio = novo;
        } else {
            (*head)->ant->prox = novo;
            novo->ant = (*head)->ant;
            novo->prox = *head;
            (*head)->ant = novo;
        }
    } else {
        (*head)->prox = novo;
        novo->ant = *head;
        agenda->fim = novo;
    }

    if (inicio != NULL)
        agenda->inicio = inicio;
}

void percorrer(Agenda agenda) {
    Contato *head = agenda.inicio;

    while (head != NULL) {
        printf("\n%d\n%s\n(%d) %d - %s\n", head->matricula, head->nome, head->ddd, head->telefone, (head->tipo == 'C' ? "celular" : "fixo"));
        head = head->prox;
    }
}

int remover(Agenda *agenda, char *nome) {
    Contato **head = &agenda->inicio, *inicio = *head, *lixo = NULL;
    int encontrado = 0; // guarda quantos contatos foram encontrados

    while (*head != NULL) {
        if (strcmp((*head)->nome, nome) == 0) {
            encontrado++;

            if ((*head)->ant == NULL) {
                inicio = (*head)->prox;
                (*head)->prox->ant = NULL;
            } else {
                (*head)->ant->prox = (*head)->prox;
                if ((*head)->prox != NULL)
                    (*head)->prox->ant = (*head)->ant;
            }

            lixo = *head;
        }
        
        *head = (*head)->prox;
        if (lixo != NULL) {
            free(lixo);
            lixo = NULL;
        }
    }

    if (inicio != NULL)
        *head = inicio;

    return encontrado;
}

void inserir_inicio(Agenda *agenda, int matricula, char *nome, int ddd, int telefone, char tipo) {
    Contato *novo;
    char *nome_alocado;

    // nome com espaço de memória sob medida
    nome_alocado = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(nome_alocado, nome);

    novo = (Contato *) malloc(sizeof(Contato));
    novo->matricula = matricula;
    novo->nome = nome_alocado;
    novo->ddd = ddd;
    novo->telefone = telefone;
    novo->tipo = tipo;
    novo->ant = NULL;
    novo->prox = NULL;

    if (agenda->inicio != NULL) {
        novo->prox = agenda->inicio;
        agenda->inicio->ant = novo;
        agenda->inicio = novo;
    } else {
        agenda->inicio = novo;
        agenda->fim = novo;
    }
}

void inserir_final(Agenda *agenda, int matricula, char *nome, int ddd, int telefone, char tipo) {
    Contato *novo;
    char *nome_alocado;

    // nome com espaço de memória sob medida
    nome_alocado = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(nome_alocado, nome);

    novo = (Contato *) malloc(sizeof(Contato));
    novo->matricula = matricula;
    novo->nome = nome_alocado;
    novo->ddd = ddd;
    novo->telefone = telefone;
    novo->tipo = tipo;
    novo->ant = NULL;
    novo->prox = NULL;

    if (agenda->fim != NULL) {
        novo->ant = agenda->fim;
        agenda->fim->prox = novo;
        agenda->fim = novo;
    } else {
        agenda->inicio = novo;
        agenda->fim = novo;
    }
}

void ordernar(Agenda *agenda){
    Contato **head = &agenda->inicio, *inicio = agenda->inicio, *fim = agenda->fim;
    int i, trocou;

    // bubble sort
    do {
        trocou = 0;

        while (*head != NULL) {
            if ((*head)->prox != NULL && strcmp((*head)->nome, (*head)->prox->nome) > 0) {

                // troca de posição
                if ((*head)->prox != NULL) {
                    if ((*head)->ant != NULL)
                        (*head)->ant->prox = (*head)->prox;
                    else
                        inicio = (*head)->prox;
                    (*head)->prox->ant = (*head)->ant;

                    (*head)->ant = (*head)->prox;
                    (*head)->prox = (*head)->prox->prox;
                    (*head)->ant->prox = *head;

                    if ((*head)->prox != NULL)
                        (*head)->prox->ant = *head;
                    else
                        fim = *head;
                }

                trocou = 1;
            }
            
            *head = (*head)->prox;
        }

        agenda->inicio = inicio;
        agenda->fim = fim;
    } while (trocou);   
}

int carregar(Agenda *agenda, char arquivo[]) {
    int matricula, ddd, contato, telefone;
    char nome[MAXNOME], tipo;
    FILE *arq = fopen(arquivo, "rt");

    if (arq == NULL) 
        return 0;

    while (fscanf(arq, "%d\n%s\n%d\n%d\n%c", &matricula, nome, &ddd, &telefone, &tipo) != EOF)
        inserir(agenda, matricula, nome, ddd, telefone, tipo);

    fclose(arq);

    return 1;
}

int salvar(Agenda agenda, char arquivo[]) {
    Contato *head = agenda.inicio;
    FILE *arq = fopen(arquivo, "wt");

    if (arq == NULL) 
        return 0;

    while (head != NULL) {
        fprintf(arq, "%d\n%s\n%d\n%d\n%c\n", head->matricula, head->nome, head->ddd, head->telefone, head->tipo);
        head = head->prox;
    }

    fclose(arq);

    return 1;
}