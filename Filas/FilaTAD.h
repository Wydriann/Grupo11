#ifndef FILATAD_H_INCLUDED
#define FILATAD_H_INCLUDED


typedef struct item{
    struct item* proximo;
    int senha;
}Item;

typedef struct firstFila{
    int tamanho;
    Item* first;
    int senhaInicial;
}FirstFila;

typedef struct tipoFila{
    FirstFila* first;
    char nomeFila[30];
    int tamanhoNome;
    struct tipoFila* proximaFila;
}TipoFila;


typedef struct filaCircularFirst{
    int tamanho;
    TipoFila* firstItem;
    TipoFila* lastItem;
}FilaCircularFirst;

FirstFila* criarFilaSimples(int senhaInicial);

void adcionarItemFS(FirstFila* first);

void removerItemFS(FirstFila* first);

TipoFila* criarTipoFila(FirstFila* fila, char nomeDaFila[30]);

FilaCircularFirst* criarFilaCircular();

void adcionarItemFC(FilaCircularFirst* first, TipoFila* tipo);

void removerItemFC(FilaCircularFirst* first);

void percorrerFilaCircular(FilaCircularFirst* first);

TipoFila* buscarTipoFila(char nomeDaFila[30]);

void imprimeNomeFila(TipoFila* fila);

void imprimePrimeiraPercorre(FilaCircularFirst* fila);

void criaInterface();

#endif // FILATAD_H_INCLUDED
