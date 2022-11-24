#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
#include "listaencadeada.h"

int main(int narg, char *argv[]){
    FILE *arq;
    char acao, nome[MAXNOME], arquivo[255];
    int i, continuar = 1;
    Contato *agenda = NULL, registro;

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
        printf("\nI - Inserir novo contato\nL - Listar contatos\nC - Carregar arquivo de contatos\nS - Salvar contatos em arquivo\nF - Fechar programa\n\n");
        printf("Selecione uma opção: ");
        scanf(" %c", &acao);

        switch(acao) {
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

                inserir(&agenda, registro.matricula, registro.nome, registro.ddd, registro.telefone, registro.tipo);
                printf("\nContato inserido com sucesso!\n");

                break;

            // Listar contatos
            case 'L':
            case 'l':
                percorrer(agenda);
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