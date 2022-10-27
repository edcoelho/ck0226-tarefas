#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "agenda.h"

int main(int narg, char* argv[]){
    FILE* arq;
    char buff[MAXNOME], acao, nome[MAXNOME], o;
    int i, continuar = 1, chave_atual = 0; // 0 - matricula, 1 - nome, 2 - ddd, 3 - telefone, 4 - tipo
    TipoAgenda agenda[MAXREGISTROS], registro;

    // Iniciar agenda vazia
    for (i = 0; i < MAXREGISTROS; i++)
        agenda[i].tipo = '\0';

    if (narg > 1) {
        arq = fopen(argv[1], "rt");
        if (arq == NULL) {
            printf("Erro ao abrir o arquivo %s", argv[1]);
            return EXIT_FAILURE;
        }

        i = 0;
        while (fscanf(arq, "%s", buff) == 1) {
            if (chave_atual == 0) {
                agenda[i].matricula = atoi(buff);
                chave_atual++;
            } else if (chave_atual == 1) {
                strcpy(agenda[i].nome, buff);
                chave_atual++;
            } else if (chave_atual == 2) {
                agenda[i].ddd = atoi(buff);
                chave_atual++;
            } else if (chave_atual == 3) {
                agenda[i].telefone = atoi(buff);
                chave_atual++;
            } else {
                agenda[i].tipo = buff[0];
                chave_atual = 0;
                i++;
            }
        }

        fclose(arq);
    }
    
    do{
        printf("\n-- Agenda Telefônica --");
        printf("\nB - Buscar telefone\nI - Inserir novo registro\nA - Apagar registro\nL - Listar nomes\nS - Sair\n\n");
        printf("Selecione uma opção: ");
        scanf(" %c", &acao);

        switch(acao) {
            case 'B':
            case 'b':
                printf("\nEntre o nome do contato: ");
                scanf("%s", nome);
                buscar_tel(nome, agenda);
                break;
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

                inserir_reg(registro, agenda);

                break;
            case 'A':
            case 'a':
                printf("\nEntre o nome do contato: ");
                scanf("%s", nome);
                apagar_reg(nome, agenda);
                break;
            case 'L':
            case 'l':
                listar_nomes(agenda);
                break;
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