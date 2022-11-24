#ifndef LISTAENCADEADADUPLA_H

#define LISTAENCADEADADUPLA_H
#define MAXNOME 100

// Os nós da lista são os contatos.
typedef struct _contato {
    int matricula;
    char *nome;
    int ddd;
    int telefone;
    char tipo;
    struct _contato *ant;
    struct _contato *prox;
} Contato;

typedef struct _agenda {
    Contato *inicio;
    Contato *fim;
} Agenda;

void inserir(Agenda *agenda, int matricula, char *nome, int ddd, int telefone, char tipo);

void percorrer(Agenda agenda);

int remover(Agenda *agenda, char *nome);

void inserir_inicio(Agenda *agenda, int matricula, char *nome, int ddd, int telefone, char tipo);

void inserir_final(Agenda *agenda, int matricula, char *nome, int ddd, int telefone, char tipo);

void ordernar(Agenda *agenda);

int carregar(Agenda *agenda, char arquivo[]);

int salvar(Agenda agenda, char arquivo[]);

#endif