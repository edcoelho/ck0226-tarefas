#ifndef LISTAENCADEADA_H

#define LISTAENCADEADA_H
#define MAXNOME 100

// Os nós da lista são os contatos.
typedef struct contato {
    int matricula;
    char nome[MAXNOME];
    int ddd;
    int telefone;
    char tipo;
    struct contato *prox;
} Contato;

// A agenda é uma lista, ou seja, é um ponteiro para o primeiro contato.

void inserir(Contato **agenda, int matricula, char nome[], int ddd, int telefone, char tipo);

void percorrer(Contato *agenda);

int carregar(Contato **agenda, char arquivo[]);

int salvar(Contato *agenda, char arquivo[]);

#endif