#include <stdio.h>
#include <stdlib.h>

#include "swv.h"

#define EMPTY -1

swv* new_stack() {
    swv* stack = (swv*) malloc(sizeof(swv));
    if (stack == NULL) {
        printf("ERRO: Não foi possível alocar memória.\n");
        return NULL;
    }

    stack->top = EMPTY;

    return stack;
}

int is_empty(swv* stack) {
    if (stack->top == EMPTY) {
        return 1;
    }

    return 0;
}

int is_full(swv* stack) {
    if (stack->top == LEN -1) {
        return 1;
    }

    return 0;
}

void push(swv* stack, char value) {
    if (is_full(stack)) {
        printf("Pilha cheia! Valor não empilhado.\n");
    }
    else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

char pop(swv* stack) {
    int removed;
    if (is_empty(stack)) {
        printf("Pilha vazia! Nenhum item removido.\n");
        return '\0';
    }
    else {
        removed = stack->items[stack->top];
        stack->items[stack->top] = '\0';
        stack->top--;

        return removed;
    }
}

void destroy(swv* stack) {
    free(stack);
}