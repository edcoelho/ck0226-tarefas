#ifndef AGENDA_H
#define AGENDA_H

#define MAXNOME 100
#define MAXREGISTROS 1000

typedef struct _agenda {
    char nome[MAXNOME];
    int matricula;
    int ddd;
    int telefone;
    char tipo;
} TipoAgenda;

// Busca um número de telefone na agenda pelo nome
void buscar_tel(char nome[], TipoAgenda agenda[]);

// Insere um registro na agenda
void inserir_reg(TipoAgenda reg, TipoAgenda agenda[]);

// Apaga um registro da agenda pelo nome
void apagar_reg(char nome[], TipoAgenda agenda[]);

// Lista os nomes dos contatos da agenda
void listar_nomes(TipoAgenda agenda[]);

#endif