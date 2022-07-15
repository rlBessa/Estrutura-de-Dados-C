#include <stdio.h>
#include <stdlib.h>

//---------------Declaracao da struct ALUNO--------------------------
typedef struct Aluno{
    int matricula;
    char nome[50];
    char curso[30];
    float nota1;
    float nota2;
    float media;
    struct Aluno *proximo;
    struct Aluno *anterior;
    int cod_aluno;
}Aluno;
//---------------Struct Lista de Alunos--------------------------
typedef struct Lista{
    Aluno *inicio;
    Aluno *fim;
    int tam;
}Lista;

//---------------Funcao Inserir--------------------------
void inserir_aluno_fim(Lista *lista){
    Aluno *no, *aux, *novo = (Aluno*)malloc(sizeof(Aluno));
    int valida=0;

    getchar();
    system("cls"); //system("clear") em unix
    printf("Digite o nome do aluno: ");
    fgets(novo->nome, 50, stdin);
    unsigned int x;

    if(lista->inicio!=NULL){
        aux=lista->inicio;
        while(valida==0){
            printf("Digite a matricula do aluno: ");
            scanf("%u", &x);
            novo->matricula=x;
            while(aux!=NULL){
                valida=1;
                if(aux->matricula==novo->matricula){
                    valida=0;
                    printf("Matricula existente!\n\n");
                    break;
                }
                aux=aux->proximo;
            }
        }
    }
    else{
        printf("Digite a matricula do aluno: ");
        scanf("%u", &x);
        novo->matricula=x;
    }



    getchar();
    printf("Digite o curso do aluno: ");
    fgets(novo->curso, 30, stdin);

    printf("Digite a Nota 1 do aluno: ");
    float c;
    scanf("%f", &c);
    novo->nota1=c;

    printf("Digite a Nota 2 do aluno: ");
    scanf("%f", &c);
    novo->nota2=c;

    novo->media=(novo->nota1+novo->nota2)/2;
    if(lista->fim!=NULL){
        novo->anterior=lista->fim;
    }

    system("cls"); //system("clear") em unix
    printf("Aluno inserido com sucesso!\n");

    novo->proximo=NULL;

    if(lista->inicio==NULL){
        lista->inicio=novo;
        lista->fim=novo;
        lista->inicio->anterior=NULL;
    }
    else{
        no=lista->inicio;
        while(no->proximo!=NULL){
            no=no->proximo;
        }
        no->proximo=novo;
        lista->fim=novo;
    }
    lista->tam++;
    novo->cod_aluno=lista->tam;

}
//---------------Funcao Consultar--------------------------
void consultar_aluno(Lista *lista){
    Aluno *inicio=lista->inicio;
    if(inicio==NULL){
            system("cls"); //system("clear") em unix
        printf("Nao ha alunos cadastrados!\n");
        return;
    }
    while(inicio!=NULL){
        printf("[%d] %s", inicio->cod_aluno, inicio->nome);
        //printf("\n");
        printf("Matricula: %i\n", inicio->matricula);
        printf("Curso: %s", inicio->curso);
        //printf("\n");
        printf("Nota 1: %.2f\n", inicio->nota1);
        printf("Nota 2: %.2f\n", inicio->nota2);
        printf("Media: %.2f\n", inicio->media);
        if(inicio->anterior!=NULL){
        printf("Aluno anterior na lista: %s", inicio->anterior->nome);
        }
        if(inicio->anterior==NULL){
            printf("Este e o primeiro aluno da lista.\n");
        }
        if(inicio->proximo!=NULL){
          printf("Proximo aluno na lista: %s\n\n", inicio->proximo->nome);
        }
        if(inicio->proximo==NULL){
            printf("Este e o ultimo aluno da lista.\n\n");
        }
        inicio= inicio->proximo;
    }
    printf("Primeiro aluno na lista: %sUltimo aluno na lista: %s", lista->inicio->nome, lista->fim->nome);
    printf("\n\n\n");
}
//---------------Funcao Editar--------------------------
void editar_aluno(Aluno *aluno){
    int x;
    int valida_mat=0;
    if(aluno!=NULL){
        getchar();
        printf("Digite o nome do aluno: ");
        fgets(aluno->nome, 50, stdin);
        unsigned int x;
        printf("Digite a matricula do aluno: ");
        scanf("%u", &x);
        aluno->matricula=x;

        getchar();
        printf("Digite o curso do aluno: ");
        fgets(aluno->curso, 30, stdin);

        printf("Digite a Nota 1 do aluno: ");
        float c;
        scanf("%f", &c);
        aluno->nota1=c;

        printf("Digite a Nota 2 do aluno: ");
        scanf("%f", &c);
        aluno->nota2=c;

        aluno->media=(aluno->nota1+aluno->nota2)/2;

        system("cls"); //system("clear") em unix
        printf("Aluno editado com sucesso!\n");
    }
}
//---------------Funcao Excluir--------------------------
void excluir_aluno(Lista *lista, int cod){
    Aluno *inicio = lista->inicio;
    Aluno *aux, *no, *no2= NULL;
    /*
        Verifica se o aluno procurado é o primeiro da lista
    */
    if(inicio != NULL && lista->inicio->cod_aluno==cod){
        no = lista->inicio;
        lista->inicio=no->proximo;
    }
    /*
        Caso o aluno procurado não seja o primeiro varremos a lista
        em busca dele, comparando o cod do parametro com o cod_aluno dos alunos
        já cadastrados
    */
    else{
        while(inicio != NULL && inicio->proximo!=NULL && inicio->proximo->cod_aluno!=cod){
            inicio = inicio->proximo;
        }
        if(inicio!=NULL && inicio->proximo != NULL){
            no = inicio->proximo;
            inicio->proximo=no->proximo;
        }
    }
    if(no){
        if(no->proximo!=NULL){
            no2=no->proximo;
            no2->anterior=no->anterior;
            while(no2->proximo!=NULL){
                inicio=no2;
                inicio->cod_aluno--;
                no2=no2->proximo;
            }

            no2->cod_aluno--;
        }
        free(no);
        lista->tam--;
    }
}
//---------------Funcao Validar--------------------------
/*
    Esta funcao tem por objetiva validar se o codigo informado via parametro
    é igual ao codigo de algum dos alunos cadastrados na lista;
    Caso verdadeiro, esta função retorna um ponteiro para o aluno cujo codigo é
    igual ao fornecido em seu parametro.
    Caso falso, retornará um ponteiro para um aluno NULL.
*/
Aluno *validar(Lista *lista, int cod){
    Aluno *aux, *no = NULL;
    aux = lista->inicio;
    /*
        A partir do primeiro aluno, enquanto o aluno for diferente de NULL,
        o loop continuara comparando o cod_aluno com o cod recebido pelo parametro.
        Quando o codigo for igual, o ponteiro para aluno chamado "aux" apontara para aquele aluno
        de cod_aluno=cod; Caso chegar ao ultimo aluno e não econtrar um valor igual ao cod, então
        o retorno é nulo.
    */
    while(aux!=NULL && aux->cod_aluno!=cod){
        aux=aux->proximo;
    }
    /*
        Caso o ponteiro nao seja nulo, é impresso na tela aquele aluno correspondente ao cod_aluno
    */
    if(aux){
        no = aux;
        system("cls"); //system("clear") em unix
        printf("[%d] %s", no->cod_aluno, no->nome);
        //printf("\n");
        printf("Matricula: %i\n", no->matricula);
        printf("Curso: %s", no->curso);
        //printf("\n");
        printf("Nota 1: %.2f\n", no->nota1);
        printf("Nota 2: %.2f\n", no->nota2);
        printf("Media: %.2f\n\n", no->media);
    }
    return no;
}
//---------------Funcao Principal--------------------------
int main(){
    Lista lista;
    int opcao;
    lista.inicio=NULL;
    lista.fim=NULL;
    lista.tam=0;
    int cod, validade=0;

    do{// Menu
        printf("\n1 - Inserir Alunos\n2 - Consultar Alunos\n3 - Editar Aluno\n4 - Excluir Aluno\n5 - Sair\n\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1: //inserir alunos
                inserir_aluno_fim(&lista);
            break;
/*--------------------------------------------------------------------------------------------------------------*/
            case 2: // Consultar alunos
                system("cls"); //system("clear") em unix
                consultar_aluno(&lista);
            break;
/*--------------------------------------------------------------------------------------------------------------*/
            case 3: // Editar alunos
                system("cls"); //system("clear") em unix
                consultar_aluno(&lista);
                if(lista.inicio==NULL){
                    break;
                }
                else{
                    while(validade==0){
                        printf("Digite o codigo do aluno: ");
                        scanf("%d", &cod);
                        if(validar(&lista, cod)!=NULL){
                            int ctz=0;
                            printf("Tem certeza que deseja editar este aluno?\n1 - Sim\n2 - Nao\n");
                            scanf("%d", &ctz);
                            if(ctz==2){
                                break;
                            }
                            editar_aluno(validar(&lista,cod));
                            validade=1;
                            system("cls"); //system("clear") em unix
                            printf("Aluno editado com sucesso!\n");
                            break;
                        }
                        printf("Codigo invalido! Tente novamente.\n\n");
                    }
                    validade=0;
                }

            break;
/*--------------------------------------------------------------------------------------------------------------*/
            case 4: // Excluir alunos
                system("cls"); //system("clear") em unix
                consultar_aluno(&lista);
                if(lista.inicio==NULL){
                    break;
                }
                else{
                    while(validade==0){
                        printf("Digite o codigo do aluno: ");
                        scanf("%d", &cod);
                        if(validar(&lista, cod)!=NULL){
                            int ctz=0;
                            printf("Tem certeza que deseja excluir este aluno?\n1 - Sim\n2 - Nao\n");
                            scanf("%d", &ctz);
                            if(ctz==2){
                                break;
                            }
                            excluir_aluno(&lista,cod);
                            validade=1;
                            system("cls"); //system("clear") em unix
                            printf("Aluno excluido com sucesso!\n");
                            break;
                        }
                        printf("Codigo invalido! Tente novamente.\n\n");
                    }
                    validade=0;
                }

            break;
/*--------------------------------------------------------------------------------------------------------------*/
            case 5: // Sair
                system("cls"); //system("clear") em unix
                printf("Encerrando o programa...\n");
            break;
/*--------------------------------------------------------------------------------------------------------------*/
            default:
                printf("Opcao invalida!\n\n");
            break;
        }

    }while(opcao!=5);

    return 0;
}


