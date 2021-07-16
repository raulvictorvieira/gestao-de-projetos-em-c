#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 199

typedef struct projeto{
    int codigo, ano, status;
    char titulo[20], descricao[50], responsavel[20];
}base_projeto;

int i = 0;

void cadastrarProjeto(base_projeto cadastro[MAX]);
void listarTodos(base_projeto cadastro[MAX]);
void listarAFazer(base_projeto cadastro[MAX]);
void listarFazendo(base_projeto cadastro[MAX]);
void listarConcluido(base_projeto cadastro[MAX]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    base_projeto cadastro[MAX];

    int op;

    system("cls");
    do{
        printf("\n******** GERENCIADOR DE PROJETOS V1.0 ********\n");
        printf("*** DEVELOPED BY RAUL VIEIRA RA:21014005-5 ***\n");
        printf("************* UNICESUMAR - ALPII *************\n\n\n");
        printf("******************** MENU ********************\n");
        printf("* 1 - Novo Projeto                           *\n");
        printf("* 2 - Listar Todos os Projetos               *\n");
        printf("* 3 - Listar Todos os Projetos - A Fazer     *\n");
        printf("* 4 - Listar Todos os Projetos - Fazendo     *\n");
        printf("* 5 - Listar Todos os Projetos - Concluído   *\n");
        printf("* 0 - Sair                                   *\n");
        printf("**********************************************\n");
        printf("<< Escolha uma opção do menu: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                cadastrarProjeto(cadastro);
                break;
            case 2:
                listarTodos(cadastro);
                break;
            case 3:
                listarAFazer(cadastro);
                break;
            case 4:
                listarFazendo(cadastro);
                break;
            case 5:
                listarConcluido(cadastro);
                break;
            case 0:
                printf("\nSaindo da Aplicação...\n");
                system("Pause");
                break;
            default:
                printf("\nOpção iválida!\n");
                system("Pause");
        }
    }while(op != 0);
    return 0;
}

void cadastrarProjeto(base_projeto cadastro[MAX]){
    system("cls");
    printf("****************************************\n");
    printf("*             NOVO PROJETO             *\n");
    printf("****************************************\n");
    char resp = 's';

    while(resp == 's' && i <= MAX){
        i++;
        cadastro[i-1].codigo = i;
        printf("\n>> Código: %d ", i);
        printf("\n>> Titulo: ");
        scanf(" %20[^\n]s", &cadastro[i-1].titulo);
        fflush(stdin);
        printf(">> Descrição: ");
        scanf(" %50[^\n]s", &cadastro[i-1].descricao);
        fflush(stdin);
        printf(">> Ano: ");
        scanf("%d", &cadastro[i-1].ano);
        fflush(stdin);
        printf(">> Status [1]-A Fazer [2]-Fazendo [3]-Concluído: ");
        scanf("%d", &cadastro[i-1].status);
        fflush(stdin);
        printf(">> Responsável: ");
        scanf(" %20[^\n]s", &cadastro[i-1].responsavel);
        fflush(stdin);

        if(i <= MAX){
            printf("\n\nDeseja cadastrar um novo Projeto? [s]-Sim [n]-Não: ");
            fflush(stdin);
            scanf("%c", &resp);
        }else{
            printf("\nSua base de dados está cheia\n");
            resp = 'n';
        }
    }
}

void listarTodos(base_projeto cadastro[MAX]){
    system("cls");
    printf("\n***************************************\n");
    printf("*          TODOS OS PROJETOS          *\n");
    printf("***************************************\n");
    int linha = 0;

    if(i >= 0){
        while(linha < i){
            printf("\n**** Projeto %d ****", cadastro[linha].codigo);
            printf("\n%s", cadastro[linha].titulo);
            printf("\n%s", cadastro[linha].descricao);
            printf("\n%d", cadastro[linha].ano);
            printf("\n%d", cadastro[linha].status);
            printf("\n%s", cadastro[linha].responsavel);
            printf("\n******************************");
            linha++;
        }

    }else{
        printf("\nSem Registros Cadastrados\n");
    }
    system("Pause");
}

void listarAFazer(base_projeto cadastro[MAX]){
    system("cls");
    printf("\n****************************************\n");
    printf("*           PROJETOS A FAZER           *\n");
    printf("****************************************\n");

    int j = 0;

    do{
        if(cadastro[j].status == 1){
            printf("\n**** Projeto %d ****", cadastro[j].codigo);
            printf("\n%s", cadastro[j].titulo);
            printf("\n%s", cadastro[j].descricao);
            printf("\n%d", cadastro[j].ano);
            printf("\n%d", cadastro[j].status);
            printf("\n%s", cadastro[j].responsavel);
            printf("\n******************************");
            j++;
        }else{
            j++;
        }
    }while(j <= i);
    system("Pause");
}

void listarFazendo(base_projeto cadastro[MAX]){
    system("cls");
    printf("\n****************************************\n");
    printf("*           PROJETOS FAZENDO           *\n");
    printf("****************************************\n");

    int j = 0;

    do{
        if(cadastro[j].status == 2){
            printf("\n**** Projeto %d ****", cadastro[j].codigo);
            printf("\n%s", cadastro[j].titulo);
            printf("\n%s", cadastro[j].descricao);
            printf("\n%d", cadastro[j].ano);
            printf("\n%d", cadastro[j].status);
            printf("\n%s", cadastro[j].responsavel);
            printf("\n******************************");
            j++;
        }else{
            j++;
        }
    }while(j <= i);
    system("Pause");
}

void listarConcluido(base_projeto cadastro[MAX]){
    system("cls");
    printf("\n*****************************************\n");
    printf("*          PROJETOS CONCLUIDOS          *\n");
    printf("*****************************************\n");

    int j = 0;

    do{
        if(cadastro[j].status == 3){
            printf("\n**** Projeto %d ****", cadastro[j].codigo);
            printf("\n%s", cadastro[j].titulo);
            printf("\n%s", cadastro[j].descricao);
            printf("\n%d", cadastro[j].ano);
            printf("\n%d", cadastro[j].status);
            printf("\n%s", cadastro[j].responsavel);
            printf("\n******************************");
            j++;
        }else{
            j++;
        }
    }while(j <= i);
    system("Pause");
}
