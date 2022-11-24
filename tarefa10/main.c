#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include "listaencadeadadupla.h"

int main(int narg, char *argv[]){
    int matricula, ddd, contato, telefone, continuar = 1;
    char nome[MAXNOME], tipo, arquivo[255], acao;
    FILE *arq;
    Agenda agenda;

    // Inicialização da lista
    agenda.inicio = NULL;
    agenda.fim = NULL;

    setlocale(LC_ALL, "Portuguese");

    // Leitura do arquivo
    if (narg > 1)
        if (!carregar(&agenda, argv[1])) {
            printf("Erro ao abrir o arquivo %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    
    // Menu interativo
    do{
        printf("\n-- Agenda Telefônica --");
        printf("\nI - Inserir novo contato\nL - Listar contatos\nR - Remover contato\nO - Ordenar contatos\nC - Carregar arquivo de contatos\nS - Salvar contatos em arquivo\nF - Fechar programa\n\n");
        printf("Selecione uma opção: ");
        scanf(" %c", &acao);

        switch(acao) {
            // Inserir novo contato
            case 'I':
            case 'i':
                printf("\nEntre a matrícula: ");
                scanf("%d", &matricula);
                
                printf("\nEntre o nome: ");
                scanf(" %s", nome);

                printf("\nEntre o DDD do telefone: ");
                scanf("%d", &ddd);

                printf("\nEntre o número do telefone: ");
                scanf("%d", &telefone);

                printf("\n-- Tipos de telefone --\nC - Celular\nF - Fixo\n\nSelecione o tipo do telefone: ");
                scanf(" %c", &tipo);

                while (tipo != 'C' && tipo != 'c' && tipo != 'F' && tipo != 'f'){
                    printf("\nOpção inválida!\n");
                    printf("\n-- Tipos de telefone --\nC - Celular\nF - Fixo\n\nSelecione o tipo do telefone: ");
                    scanf(" %c", &tipo);
                }

                if (tipo == 'c')
                    tipo = 'C';
                else if (tipo == 'f')
                    tipo = 'F';

                printf("\n1 - Inserir em ordem alfabética\n2 - Inserir no início\n3 - Inserir no final\n\nSelecione onde deseja inserir: ");
                scanf(" %c", &acao);

                while (acao != '1' && acao != '2' && acao != '3'){
                    printf("\nOpção inválida!\n");
                    printf("\n1 - Inserir em ordem alfabética\n2 - Inserir no início\n3 - Inserir no final\n\nSelecione onde deseja inserir: ");
                    scanf(" %c", &acao);
                }

                if (acao == '1')
                    inserir(&agenda, matricula, nome, ddd, telefone, tipo);
                else if (acao == '2')
                    inserir_inicio(&agenda, matricula, nome, ddd, telefone, tipo);
                else
                    inserir_final(&agenda, matricula, nome, ddd, telefone, tipo);

                printf("\nContato inserido com sucesso!\n");
                break;

            // Listar contatos
            case 'L':
            case 'l':
                percorrer(agenda);
                break;

            // Remover contato
            case 'R':
            case 'r':
                printf("\nEntre o nome do contato: ");
                scanf("%s", nome);

                if (remover(&agenda, nome))
                    printf("\nTodos contatos com nome %s foram removidos com sucesso!\n", nome);
                else
                    printf("\nContato não foi encontrado!\n");

                break;

            // Ordenar contatos
            case 'O':
            case 'o':
                ordernar(&agenda);
                printf("\nAgenda ordenada com sucesso!\n");
                break;

            // Carregar arquivo de contatos
            case 'C':
            case 'c':
                printf("\nEntre o nome do arquivo: ");
                scanf(" %s", arquivo);

                if (carregar(&agenda, arquivo))
                    printf("\nArquivo carregado com sucesso!\n");
                else
                    printf("\nErro ao carregar o arquivo!\n");

                break;

            // Salvar contatos em arquivo
            case 'S':
            case 's':
                printf("\nEntre o nome do arquivo: ");
                scanf(" %s", arquivo);

                if (salvar(agenda, arquivo))
                    printf("\nContatos salvos com sucesso!\n");
                else
                    printf("\nErro ao salvar os contatos!\n");
                break;

            // Fechar programa
            case 'F':
            case 'f':
                continuar = 0;
                break;
                
            default:
                printf("\nOpção inválida!\n");
        }

    }while(continuar);

    return EXIT_SUCCESS;
}