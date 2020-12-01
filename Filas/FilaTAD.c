#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<stdbool.h>
#include "filaTAD.h"

FirstFila* criarFilaSimples(int senhaInicial){
    FirstFila* inicio = (FirstFila*)malloc(sizeof(FirstFila));
    inicio->first = NULL;
    inicio->tamanho = 0;
    inicio->senhaInicial = senhaInicial - 1;
    return inicio;
}

void adcionarItemFS(FirstFila* first){

    if(first->first == NULL){
        Item* item = (Item*)malloc(sizeof(Item));
        item->senha = first->senhaInicial + 1;
        item->proximo = first->first;
        first->first = item;
        first->tamanho++;
    }else{

        Item* percorre = first->first;

        while(percorre->proximo != NULL){
            percorre = percorre->proximo;
        }

        Item* item = (Item*) malloc(sizeof(Item));
        item->senha = percorre->senha + 1;
        item->proximo = NULL;
        percorre->proximo = item;
        first->tamanho++;
        first->senhaInicial = item->senha;
    }
}
void removerItemFS(FirstFila* first){
    if(!first->first == NULL){
        Item* ponteiro = first->first;
        first->first = ponteiro->proximo;
        free(ponteiro);
        first->tamanho--;
    }else{
         printf("Vazia\n\n");
    }
}

TipoFila* criarTipoFila(FirstFila* fila, char nomeDaFila[30]){
    TipoFila* tipo = (TipoFila*)malloc(sizeof(TipoFila));
    tipo->first = fila;
    for(int i = 0; nomeDaFila[i] != '\0' || nomeDaFila[i-1] != '\0'; i++){
        tipo->nomeFila[i] = nomeDaFila[i];
        tipo->tamanhoNome = i;
    }
    tipo->proximaFila = NULL;
    return tipo;
}

void imprimeNomeFila(TipoFila* fila){
    for(int i = 0; i != fila->tamanhoNome; i++){
        printf("%c", fila->nomeFila[i]);
    }
}

FilaCircularFirst* criarFilaCircular(){
    FilaCircularFirst* inicioFC = (FilaCircularFirst*)malloc(sizeof(FilaCircularFirst));
    inicioFC->firstItem = NULL;
    inicioFC->lastItem = NULL;
    inicioFC->tamanho = 0;
    return inicioFC;
}

void adcionarItemFC(FilaCircularFirst* first, TipoFila* tipo){

    if(first->firstItem == NULL){
        first->firstItem = tipo;
        first->firstItem->proximaFila = tipo;
        first->lastItem = tipo;
        first->lastItem->proximaFila = tipo;
        first->tamanho++;
    }else{
        TipoFila* percorre = first->firstItem;

        while(percorre->proximaFila != first->lastItem){
            percorre = percorre->proximaFila;
        }
        percorre->proximaFila->proximaFila = tipo;
        tipo->proximaFila = first->firstItem;
        first->lastItem = tipo;
        first->tamanho++;
    }
}

void removerItemFC(FilaCircularFirst* first){

        if(first->firstItem == NULL && first->lastItem == NULL){
            printf("Vazia\n\n");
        }else if (first->firstItem == first->lastItem){
            free(first->firstItem);
            free(first->lastItem);
            first->firstItem = NULL;
            first->lastItem = NULL;
            first->tamanho--;
        }else{
            first->lastItem->proximaFila = first->firstItem->proximaFila;
            free(first->firstItem);
            first->firstItem = first->lastItem->proximaFila;
            first->tamanho--;
        }
}

void percorrerFilaCircular(FilaCircularFirst* first){

    TipoFila* aux = first->firstItem;
    first->firstItem = first->firstItem->proximaFila;
    first->lastItem = aux;

}

void imprimePrimeiraPercorre(FilaCircularFirst* fila){
    int controlador = 0;
    if(fila->firstItem->first->first != NULL){
        printf(fila->firstItem->nomeFila);
        printf("\n");
        printf("Senha: %d\n\n",fila->firstItem->first->first->senha);
        removerItemFS(fila->firstItem->first);
        percorrerFilaCircular(fila);
    } else{
        for(int i = 0; i != fila->tamanho ; i++){
            if(fila->firstItem->first->first == NULL){
                controlador++;
            }
            percorrerFilaCircular(fila);
        }
        percorrerFilaCircular(fila);
        if(controlador < fila->tamanho){
            imprimePrimeiraPercorre(fila);
        } else if(controlador = fila->tamanho){
            printf("aguardando senhas...\n\n");
        }
    }

}


void criaInterface(){
    system("cls");
    int tipoMenu = 0;
    int funcionalidadeADM = 0;
    int funcionalidadeAtend = 0;
    int funcionalidadeCli = 0;
    bool filaInstanciada = false;
    bool sair = false;
    FilaCircularFirst* filaCircular;
    FirstFila* fila;
    TipoFila* tipo;
    char nome[30] = "Nome Fila";
    int senhaInicial = 0;
    int filaDesejada = 0;

    while(sair != true){

    printf("Selecione o tipo de funcionalidades:\n\n(1)ADM\n(2)Cliente\n(3)Atendente\n(4)Sair\n\n");
    scanf("%i", &tipoMenu);

    switch(tipoMenu){

    case 1:
        system("cls");
        printf("Selecione a funcionalidade:\n\n(0)Instanciar Fila Circular\n(1)Imprimir Nome da Fila Atual\n(2)Adicionar Nova Fila\n(3)Remover Fila Atual\n(4)Percorrer Fila Circular\n\n");
        scanf("%i", &funcionalidadeADM);
        printf("\n");

        switch(funcionalidadeADM){
            case 0:
                if(filaInstanciada == false){
                    filaCircular = criarFilaCircular();
                    filaInstanciada = true;
                    printf("\nFila Instanciada\n\n");
                }else{
                    printf("\nFila ja existe\n\n");
                }
            break;
            case 1:
                if(filaInstanciada == true){
                    if(filaCircular->firstItem != NULL){
                        printf("\n");
                        printf(filaCircular->firstItem->nomeFila);
                        printf("\n\n");
                    }else{
                        printf("\nNão existem filas\n\n");
                    }
                }else{
                    printf("\nPrimeiro instancie uma fila circular\n\n");
                }
            break;
            case 2:
                if(filaInstanciada == true){
                    printf("\nInsira a senha inicial da Fila:\n");
                    scanf("%d", &senhaInicial);
                    printf("\nInsira o nome da Fila:\n");
                    scanf("%s", &nome);
                    printf("\n");
                    fila = criarFilaSimples(senhaInicial);
                    tipo = criarTipoFila(fila, nome);
                    adcionarItemFC(filaCircular, tipo);
                }else{
                    printf("\nPrimeiro instancie uma fila circular\n\n");
                }
            break;
            case 3:
                if(filaInstanciada == true){
                    removerItemFC(filaCircular);
                }else{
                    printf("\nPrimeiro instancie uma fila circular\n\n");
                }
            break;
            case 4:
                 if(filaInstanciada == true){
                    percorrerFilaCircular(filaCircular);
                }else{
                    printf("\nPrimeiro instancie uma fila circular\n\n");
                }
            break;
            default:
                printf ("\nValor invalido!\n");
        }
    break;
    case 2:
        system("cls");
        printf("Selecione a funcionalidade:\n\n(1)Listar Filas\n\n");
        scanf("%i", &funcionalidadeCli);
        printf("\n");
        switch(funcionalidadeCli){
            case 1:
                if(filaInstanciada == true){
                    if(filaCircular->firstItem != NULL){
                        printf("\n");
                        for(int i = 0; i < filaCircular->tamanho; i++){
                            printf("(%d) ", i+1);
                            printf(filaCircular->firstItem->nomeFila);
                            printf("\n\n");
                            percorrerFilaCircular(filaCircular);
                        }
                        printf("\nEscolha uma fila: ");
                        scanf("%d", &filaDesejada);
                        printf("\n");

                        for(int i = 1; i < filaDesejada; i++){
                            percorrerFilaCircular(filaCircular);
                        }

                        if(filaCircular->firstItem->first->first == NULL){
                            adcionarItemFS(filaCircular->firstItem->first);
                            filaCircular->firstItem->first->senhaInicial++;
                        }else{
                            adcionarItemFS(filaCircular->firstItem->first);
                        }

                        printf("\nAdicionada a senha:%d na Fila ", filaCircular->firstItem->first->senhaInicial);
                        printf(filaCircular->firstItem->nomeFila);
                        printf("\n\n");

                        for(int i = 0; i < (filaCircular->tamanho - (filaDesejada - 1)); i++){
                            percorrerFilaCircular(filaCircular);
                        }
                    }else{
                        printf("\nNão existem filas\n\n");
                    }

                }else{
                    printf("\nPrimeiro instancie uma fila circular\n\n");
                }

            break;
            default:
                printf ("\nValor invalido!\n");
        }
    break;
    case 3:
        system("cls");
        printf("Selecione a funcionalidade:\n\n(1)Chamar Senha\n(2)Atender\n\n");
        scanf("%i", &funcionalidadeAtend);
        printf("\n");
        switch(funcionalidadeAtend){
            case 1:
                if(filaInstanciada == true){
                    if(filaCircular->firstItem != NULL){
                        printf("\nProxima Senha: \n");
                        printf(filaCircular->firstItem->nomeFila);
                        printf("\n");
                        printf("%d\n\n",filaCircular->firstItem->first->first->senha);
                    }else{
                        printf("\nNao existem filas\n\n");
                    }
                }else{
                    printf("\nPrimeiro instancie uma fila circular\n\n");
                }
            break;
            case 2:
                if(filaInstanciada == true){
                    if(filaCircular->firstItem != NULL){
                        if(filaCircular->firstItem->first != NULL)
                        printf("Atendendo Fila: ");
                        imprimePrimeiraPercorre(filaCircular);
                    }else{
                        printf("\nNao existem filas\n\n");
                    }
                }else{
                    printf("\nPrimeiro instancie uma fila circular\n\n");
                }
            break;
            default:
                printf ("\nValor invalido!\n");
        }
    break;
    case 4:
        system("cls");
        sair = true;
    break;

    default:
        printf ("\nValor invalido!\n");
    }
    }
}

