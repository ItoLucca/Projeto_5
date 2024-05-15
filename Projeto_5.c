#include <string.h>
#include <stdio.h>
#include "projeto_5.h"

int Adicionar_contatos(lista_contatos Lista[], int *contador_tarefas){
    if(*contador_tarefas < MAX_CONTATOS){
        printf("\nDigite o seu nome: ");
        scanf("%s", Lista[*contador_tarefas].nome);

        printf("\ndigite o seu sobrenome: ");
        scanf("%s", Lista[*contador_tarefas].sobrenome);

        printf("\ndigite o seu email: ");
        scanf("%s", Lista[*contador_tarefas].email);

        printf("\ndigite novamente seu email: ");
        scanf("%s", Lista[*contador_tarefas].revalida);        

        if(strcmp(Lista[*contador_tarefas].email, Lista[*contador_tarefas].revalida) == 0){
            printf("\ndigite o seu telefone: ");
            scanf("%s", Lista[*contador_tarefas].telefone);

            
            for(int i = 0; i < *contador_tarefas; i++){
                if(strcmp(Lista[*contador_tarefas].telefone, Lista[i].telefone) == 0){
                    printf("\nEste telefone ja esta sendo usado.. \n");
                    return 0; 
                }
            }

            
            printf("____Contato salvo com sucesso!!____ \n");
            (*contador_tarefas)++;
            return 1;

        } else {
            printf("\nOs emails nao correspondem.. \n");
        }

    } else {
        printf("\nA lista esta cheia.. \n");
    }
    return 0;
}

int Listar_contatos(lista_contatos Lista[], int *contador_tarefas){
    if(*contador_tarefas > 0){
        printf("\n--> Lista de Contatos: \n");

        for(int i = 0 ; i < *contador_tarefas ; i++){
            printf("\n     Tarefa: %d\n", i + 1);
            printf("     --> Nome: %s\n", Lista[i].nome);
            printf("     --> Sobreome: %s\n", Lista[i].nome);
            printf("     --> Email: %s\n", Lista[i].email);
            printf("     --> Telefone: %s\n", Lista[i].telefone);
        }
    }
    else{
        printf("A lista está vazia.. \n");
        printf("\n");
        return 0;
    }
}

int Deletar_contatos(lista_contatos Lista[], int *contador_tarefas){
    char telefone_deletar[MAX_TELEFONE];
    
    if(*contador_tarefas > 0){
        printf("\nDigite o telefone referente a conta a ser deletada: ");
        scanf("%s", telefone_deletar);
        
        for (int i = 0; i < *contador_tarefas; i++) {
            if (strcmp(telefone_deletar, Lista[i].telefone) == 0) {
                for (int j = i; j < *contador_tarefas - 1; j++) {
                    Lista[j] = Lista[j + 1];
                }
                (*contador_tarefas)--;
                printf("\n____Contato deletado com sucesso!!____\n");
                return 1;
            }
            else{
                printf("\nO telefone inserido nao bate com nenhum numero no sistema.. \n");
                return 0;
            }
        }
    }
    else{
        printf("\nA lista está vazia!! \n");
    }
}


int Alterar_contatos(lista_contatos Lista[], int *contador_tarefas){
    char email_alterar[MAX_EMAIL];
    char telefone_alterar[MAX_TELEFONE];
    int telefone_duplicado = 0;

    if(*contador_tarefas > 0){
        printf("\nDigite as suas informacoes para realizarmos a alteracao desejada: ");

        printf("\nDigite seu email: ");
        scanf("%s", email_alterar);

        printf("\nDigite seu telefone: ");
        scanf("%s", telefone_alterar);

        for(int i = 0 ; i < *contador_tarefas ; i ++){
            if(strcmp(email_alterar, Lista[i].email) == 0 && strcmp(telefone_alterar, Lista[i].telefone) == 0){
                
                printf("\nDigite o novo nome: ");
                scanf("%s", Lista[i].nome);

                printf("\nDigite o novo sobrenome: ");
                scanf("%s", Lista[i].sobrenome);

                printf("\nDigite o novo email: ");
                scanf("%s", Lista[i].email);

                do{
                    printf("\nDigite o novo telefone: ");
                    scanf("%s", Lista[i].telefone);

                    for(int j = 0; j < *contador_tarefas; j++){
                        if (i != j && strcmp(Lista[i].telefone, Lista[j].telefone) == 0) {
                            telefone_duplicado = 1;

                            printf("\nO telefone já está sendo usado. Tente outro.. \n");
                            break;
                        }                     
                    }
                } while (telefone_duplicado);

            }
            else{
                printf("\nO email e/ou o telefone nao batem com os dados salvos.. \n");
            }
        }

        printf("\n____Alteracao feita com sucesso!!____\n");

    }
    else{
        printf("\nNao ha nenhum contato salvo na lista.. \n");
    }
}


int Salvar_contatos(lista_contatos Lista[], int *contador_tarefas, const char *tipo){
    char agenda_contatos[20];

    sprintf(agenda_contatos, "agenda_%s.bin", tipo);

    FILE *f = fopen(agenda_contatos, "wb");
    
    if(f == NULL) {
        printf("Erro ao abrir o arquivo para escrita.. \n");
        return 0;
    }
    else{
        fwrite(Lista, sizeof(lista_contatos), *contador_tarefas, f);
        fclose(f);
        
        return 1;
    }

}

int Carregar_contatos(lista_contatos Lista[], int *contador_tarefas, const char *tipo){
    char agenda_contatos[20];

    sprintf(agenda_contatos, "agenda_%s.bin", tipo);

    FILE *f = fopen(agenda_contatos, "rb");
    
    if(f == NULL) {
        printf("Erro ao abrir o arquivo para leitura.. \n");
        *contador_tarefas = 0;
        return 0;
    }
    else{
        *contador_tarefas = fread(Lista, sizeof(lista_contatos), MAX_CONTATOS, f);
        fclose(f);

        return 1;
    }

}

