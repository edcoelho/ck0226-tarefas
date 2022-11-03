#ifndef AGENDA_H
#define AGENDA_H

#define MAXNOME 100
#define MAXREGISTROS 1000

typedef struct {
    char nome[MAXNOME];
    int matricula;
    int ddd;
    int telefone;
    char tipo;
} Contato;

// Inicializa um vetor de contatos.
void inicializar_agenda(Contato* agenda[]);

// Busca um registro pelo nome e retorna seu indíce no vetor, se não encontrar retorna -1.
int buscar_reg(Contato* agenda[], char nome[]);

// Insere um registro na agenda. Retorna 1 se conseguir inserir, senão retorna 0.
int inserir_reg(Contato* agenda[], char nome[], int matricula, int ddd, int telefone, char tipo);

// Apaga um registro da agenda pelo nome. Retorna 1 se conseguir apagar, senão retorna 0.
int apagar_reg(Contato* agenda[], char nome[]);

// Lista os nomes dos contatos da agenda.
void listar_nomes(Contato* agenda[]);

// Troca a posição de dois contatos.
void trocar_posicao(Contato* agenda[], int ind1, int ind2);

// Ordena os contatos da agenda por ordem alfabética do nome.
void ordernar_por_nome(Contato* agenda[]);

#endif