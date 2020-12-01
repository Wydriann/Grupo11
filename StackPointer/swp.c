#include <stdio.h>
#include <stdlib.h>

#include "swp.h"

item* new_item(char v) {
    item* i = (item*) malloc(sizeof(item));
    if (i == NULL) {
        printf("ERRO: Não foi possível alocar memória.\n");
        return NULL;
    }

    i->value = v;
    i->previous =  NULL;

    return i;
}

swp* new_stack() {
    swp* s = (swp*) malloc(sizeof(swp));
    if (s == NULL) {
        printf("ERRO: Não foi possível alocar memória.\n");
        return NULL;
    }

    s->top = NULL;

    return s;
}

int is_empty(swp* s) {
    if (s->top == NULL) {
        return 1;
    }

    return 0;
}

void push(swp* s, char value) {
    item* i = new_item(value);

    if (is_empty(s)) {
        s->top = i;
    }
    else {
        i->previous = s->top;
        s->top = i;
    }
}

char pop(swp* s) {
    item* aux;
    int removed;

    if (is_empty(s)) {
        printf("Pilha vazia! Nenhum item removido.\n");
        return '\0';
    }
    else {
        removed = s->top->value;
        aux = s->top;

        s->top = s->top->previous;
        
        free(aux);

        return removed;
    }
}

void destroy(swp* s) {
    while (s->top) {
        pop(s);
    }

    free(s);
}