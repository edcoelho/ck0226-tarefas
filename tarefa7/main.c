#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include "agenda.h"

int main(int narg, char* argv[]){
    FILE* arq;
    char acao, nome[MAXNOME], o;
    int i, continuar = 1;
    Contato agenda[MAXREGISTROS], registro;

    setlocale(LC_ALL, "Portuguese");
    inicializar_agenda(agenda);

    // Leitura do arquivo
    if (narg > 1) {
        arq = fopen(argv[1], "rt");
        if (arq == NULL) {
            printf("Erro ao abrir o arquivo %s", argv[1]);
            return EXIT_FAILURE;
        }

        i = 0;
        while (fscanf(arq, "%d\n%[^\n]\n%d\n%d\n%c", &registro.matricula, registro.nome, &registro.ddd, &registro.telefone, &registro.tipo) != EOF)
            inserir_reg(agenda, registro.nome, registro.matricula, registro.ddd, registro.telefone, registro.tipo);

        fclose(arq);
    }
    
    // Menu interativo
    do{
        printf("\n-- Agenda Telefônica --");
        printf("\nB - Buscar telefone\nI - Inserir novo contato\nA - Apagar contato\nL - Listar nomes\nS - Sair\n\n");
        printf("Selecione uma opção: ");
        scanf(" %c", &acao);

        switch(acao) {
            // Buscar telefone
            case 'B':
            case 'b':
                printf("\nEntre o nome do contato: ");
                scanf("%s", nome);
                
                if ((i = buscar_reg(agenda, nome) >= 0))
                    printf("\n%s - (%d) %d (%s)\n", agenda[i].nome, agenda[i].ddd, agenda[i].telefone, (agenda[i].tipo == 'C' ? "celular": "fixo"));
                else
                    printf("\n%s não foi encontrado!\n", nome);

                break;

            // Inserir novo contato
            case 'I':
            case 'i':
                printf("\nEntre a matrícula: ");
                scanf("%d", &registro.matricula);
                
                printf("\nEntre o nome: ");
                scanf(" %s", registro.nome);

                printf("\nEntre o DDD do telefone: ");
                scanf("%d", &registro.ddd);

                printf("\nEntre o número do telefone: ");
                scanf("%d", &registro.telefone);

                printf("\n-- Tipos de telefone --\nC - Celular\nF - Fixo\n\nSelecione o tipo do telefone: ");
                scanf(" %c", &registro.tipo);

                while (registro.tipo != 'C' && registro.tipo != 'c' && registro.tipo != 'F' && registro.tipo != 'f'){
                    printf("\nOpção inválida!\n");
                    printf("\n-- Tipos de telefone --\nC - Celular\nF - Fixo\n\nSelecione o tipo do telefone: ");
                    scanf(" %c", &registro.tipo);
                }

                if (registro.tipo == 'c')
                    registro.tipo = 'C';
                else if (registro.tipo == 'f')
                    registro.tipo = 'F';

                if (inserir_reg(agenda, registro.nome, registro.matricula, registro.ddd, registro.telefone, registro.tipo))
                    printf("\nContato inserido com sucesso!\n");
                else
                    printf("\nNão foi possível inserir o contato porque a agenda está cheia!\n");

                break;

            // Apagar contato
            case 'A':
            case 'a':
                printf("\nEntre o nome do contato: ");
                scanf("%s", nome);

                if (apagar_reg(agenda, nome))
                    printf("\nContato removido com sucesso!\n");
                else
                    printf("\nContato não foi encontrado!\n");

                break;

            // Listar nomes
            case 'L':
            case 'l':
                listar_nomes(agenda);
                break;

            // Sair
            case 'S':
            case 's':
                continuar = 0;
                break;
                
            default:
                printf("\nOpção inválida!\n", acao);
        }

    }while(continuar);

    return EXIT_SUCCESS;
}