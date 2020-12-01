#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "filaTAD.h"

int main()
{
    FirstFila* fila01 = criarFilaSimples(100);
    adcionarItemFS(fila01);
    adcionarItemFS(fila01);
    adcionarItemFS(fila01);
    //adcionarItemFS(fila01, 103);
    //adcionarItemFS(fila01, 104);
    printf("A primeira senha eh: %d\n", fila01->first->senha);
    printf("A ultima senha eh: %d\n", fila01->first->proximo->proximo->senha);
    printf("O tamanho da fila eh: %d\n\n", fila01->tamanho);

    printf("removi um item\n\n");

    removerItemFS(fila01);
    printf("A primeira senha eh: %d\n", fila01->first->senha);
    printf("A ultima senha eh: %d\n", fila01->first->proximo->senha);
    printf("O tamanho da fila eh: %d\n", fila01->tamanho);

    FirstFila* fila02 = criarFilaSimples(200);
    adcionarItemFS(fila02);
    adcionarItemFS(fila02);
    adcionarItemFS(fila02);
    adcionarItemFS(fila02);
    adcionarItemFS(fila02);
    printf("A primeira senha eh: %d\n", fila02->first->senha);
    printf("A ultima senha eh: %d\n", fila02->first->proximo->proximo->proximo->proximo->senha);
    printf("O tamanho da fila eh: %d\n", fila02->tamanho);

    FirstFila* fila03 = criarFilaSimples(300);
    adcionarItemFS(fila03);
    adcionarItemFS(fila03);
    adcionarItemFS(fila03);
    adcionarItemFS(fila03);
    adcionarItemFS(fila03);
    adcionarItemFS(fila03);
    printf("A primeira senha eh: %d\n", fila03->first->senha);
    printf("A ultima senha eh: %d\n", fila03->first->proximo->proximo->proximo->proximo->proximo->senha);
    printf("O tamanho da fila eh: %d\n", fila03->tamanho);

    FirstFila* fila04 = criarFilaSimples(400);
    adcionarItemFS(fila04);
    adcionarItemFS(fila04);
    adcionarItemFS(fila04);
    adcionarItemFS(fila04);
    adcionarItemFS(fila04);
    adcionarItemFS(fila04);
    printf("A primeira senha eh: %d\n", fila04->first->senha);
    printf("A senha inicial eh: %d\n", fila04->senhaInicial);
    printf("A ultima senha eh: %d\n", fila04->first->proximo->proximo->proximo->proximo->proximo->senha);
    printf("O tamanho da fila eh: %d\n", fila04->tamanho);

    char nome01[30] = "Fila Normal";

    TipoFila* filaNormal = criarTipoFila(fila01, nome01);
    printf("\n");
    //printf(filaNormal->nomeFila);
    //printf("\n\n");

    //imprimeNomeFila(filaNormal);

    //printf("\n\n");



    FilaCircularFirst* filaCircular01 = criarFilaCircular();

    adcionarItemFC(filaCircular01, filaNormal);

    printf(filaNormal->nomeFila);
    printf("\n");
    printf(filaNormal->proximaFila->nomeFila);
    printf("\n\n");

    printf("O tamanho da fila circular eh: %d\n", filaCircular01->tamanho);

    char nome02[30] = "Fila Prioritaria";
    TipoFila* filaNormal02 = criarTipoFila(fila02, nome02);

    adcionarItemFC(filaCircular01, filaNormal02);

    printf(filaNormal->nomeFila);
    printf("\n");
    printf(filaNormal->proximaFila->nomeFila);
    printf("\n\n");

    printf("O tamanho da fila circular eh: %d\n\n", filaCircular01->tamanho);

    char nome03[30] = "Fila Especial";
    TipoFila* filaNormal03 = criarTipoFila(fila03, nome03);

    adcionarItemFC(filaCircular01, filaNormal03);

    char nome04[30] = "Fila Realmente Especial";
    TipoFila* filaNormal04 = criarTipoFila(fila04, nome04);

    adcionarItemFC(filaCircular01, filaNormal04);

    printf("O tamanho da fila circular eh: %d\n\n", filaCircular01->tamanho);

    printf(filaNormal->nomeFila);
    printf("\n");
    printf(filaNormal->proximaFila->nomeFila);
    printf("\n");
    printf(filaNormal->proximaFila->proximaFila->nomeFila);
    printf("\n\n");

    printf(filaCircular01->firstItem->nomeFila);
    printf("\n");
    printf("Primeira senha eh %d\n\n",filaCircular01->firstItem->first->first->senha);
    printf(filaCircular01->lastItem->nomeFila);
    printf("\n");
    printf("Primeira senha eh %d\n\n",filaCircular01->lastItem->first->first->senha);

    //removerItemFC(filaCircular01);
    //removerItemFC(filaCircular01);

    //percorrerFilaCircular(filaCircular01);
    //percorrerFilaCircular(filaCircular01);
    //percorrerFilaCircular(filaCircular01);
    //percorrerFilaCircular(filaCircular01);

    printf(filaCircular01->firstItem->proximaFila->nomeFila);
    printf("\n");
    printf("Primeira senha eh %d\n\n",filaCircular01->firstItem->proximaFila->first->first->senha);
    printf(filaCircular01->lastItem->proximaFila->nomeFila);
    printf("\n");
    printf("Primeira senha eh %d\n\n",filaCircular01->lastItem->proximaFila->first->first->senha);
    printf("O tamanho da fila circular eh: %d\n\n", filaCircular01->tamanho);
    //printf("O numero de filas vazias na fila circular eh: %d\n\n", filaCircular01->vazias);

    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    adcionarItemFS(fila04);
    adcionarItemFS(fila03);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);
    imprimePrimeiraPercorre(filaCircular01);

    printf("O tamanho da fila circular eh: %d\n\n", filaCircular01->tamanho);

    int interface = 0;
    printf("\nDigite um numero maior que 0 para entrar na interface: ");
    scanf("%d", &interface);

    if(interface > 0){
        criaInterface();
    }
}
