#include <stdio.h>
#include <string.h>
#include "projeto_5.h"


int main(){
    lista_contatos Lista_Pessoal[MAX_CONTATOS];
    lista_contatos Lista_Trabalho[MAX_CONTATOS];
    int contador_tarefas_pessoal = 0;
    int contador_tarefas_trabalho = 0;
    int opcao;
    int cod;
    int tipo_conta;

    cod = Carregar_contatos(Lista_Pessoal, &contador_tarefas_pessoal, "pessoal");
   
    cod = Carregar_contatos(Lista_Trabalho, &contador_tarefas_trabalho, "trabalho");

    do{
        printf("\n\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n");
        printf("\nBem vindo a sua agenda de Contatos!! \n");
        printf("\nDigite uma das opcoes abaixo: \n");

        printf("\n ---> 1. Adicionar Contato \n");
        printf("\n ---> 2. Listar os Contatos \n");
        printf("\n ---> 3. Deletar Contato \n");
        printf("\n ---> 4. Alterar Contato \n");
        printf("\n ---> 0. Finalizar programa\n");
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);

        printf("\n");

        if(opcao != 0){
            printf("\nDigite o tipo de conta entre:\n\n 1. pessoal\n 2. trabalho\n\n Digite aqui: ");
            scanf("%d", &tipo_conta);
        }

        switch(opcao){
            case 1:
                if(tipo_conta == 1){
                    Adicionar_contatos(Lista_Pessoal, &contador_tarefas_pessoal);
                }
                else if(tipo_conta == 2){
                    Adicionar_contatos(Lista_Trabalho, &contador_tarefas_trabalho);
                }
                break;
                

            case 2:
                if(tipo_conta == 1){
                    Listar_contatos(Lista_Pessoal, &contador_tarefas_pessoal);
                }
                else if(tipo_conta == 2){
                    Listar_contatos(Lista_Trabalho, &contador_tarefas_trabalho);
                }
                break;

            case 3:
                if(tipo_conta == 1){
                    Deletar_contatos(Lista_Pessoal, &contador_tarefas_pessoal);
                }
                else if(tipo_conta == 2){
                    Deletar_contatos(Lista_Trabalho, &contador_tarefas_trabalho);
                }
                break;

            case 4:
                if(tipo_conta == 1){
                    Alterar_contatos(Lista_Pessoal, &contador_tarefas_pessoal);
                }
                else if(tipo_conta == 2){
                    Alterar_contatos(Lista_Trabalho, &contador_tarefas_trabalho);
                }
                break;

            case 0:
                cod = Salvar_contatos(Lista_Pessoal, &contador_tarefas_pessoal, "pessoal");
                    if (cod != 0) {
                        printf("\nAgenda pessoal salva com sucesso.\n");
                    }

                cod = Salvar_contatos(Lista_Trabalho, &contador_tarefas_trabalho, "trabalho");
                    if (cod != 0) {
                        printf("\nAgenda de tarefas salva com sucesso.\n");
                    }

                    printf("\n___- Programa finalizado!! -___\n");
                    break;
            
            default:
                printf("\nopcao invalida..\n");
        }

    }while(opcao != 0);

    return 0;
}