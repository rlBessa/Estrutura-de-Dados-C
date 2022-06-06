#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 50

typedef struct{
    char nome[70];
    char curso[40];
    int matricula;
    float nota1, nota2;
}aluno;

aluno numero[tam];

int main(){
    int opcao=0;
    bool validade=false;


    printf("SGN - Sistema de gerenciamento de notas!\n");
/*--------------------------------------------------------------------------------------------------------------*/
    while(opcao!=5){
        printf("\n1 - Inserir Alunos\n2 - Consultar Alunos\n3 - Editar Aluno\n4 - Excluir Aluno\n5 - Sair\n\n");
        scanf("%d", &opcao);
/*--------------------------------------------------------------------------------------------------------------*/
        switch(opcao){
            case 1:
            while(!validade){
                printf("Digite o nome do aluno:\n");
                scanf();
                if(){
                    printf("Nome invalido! Min. 3 caracteres.");
                }
                else{validade=true;}
            }
            validade = false;
            /*------------------------------------------------------*/
            while(!validade){
                printf("Digite a matricula do aluno:\n");
                scanf();
                if(){
                    printf("Matricula invalida! A matricula e composta por 9 numeros.");
                }
                else{validade=true;}
            }
            validade = false;
            /*------------------------------------------------------*/
            while(!validade){
                printf("Digite o curso do aluno:\n");
                scanf();
                if(){
                    printf("Nome invalido! Min. 3 caracteres.");
                }
                else{validade=true;}
            }
            validade = false;
            /*------------------------------------------------------*/
            while(!validade){
                printf("Digite as notas do aluno:\n");
                scanf();
                if(){
                    printf("Nome invalido! Min. 3 caracteres.");
                }
                else{validade=true;}
            }
            validade = false;

            break;
/*--------------------------------------------------------------------------------------------------------------*/
            case 2:

            break;
/*--------------------------------------------------------------------------------------------------------------*/
            case 3:

            break;
/*--------------------------------------------------------------------------------------------------------------*/
            case 4:

            break;
/*--------------------------------------------------------------------------------------------------------------*/
            case 5:
            break;
/*--------------------------------------------------------------------------------------------------------------*/
        }
    }

    return 0;
}
