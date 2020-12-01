#include <stdio.h>
#include <stdlib.h>

#include "swp.h"

int main() {
    swp* stack = new_stack();
    char word[30];

    printf("Escreva uma palavra para ser invertida ultilizando Pilhas: ");
    scanf("%s", word);

    for (int i = 0; word[i]; i++) {
        push(stack, word[i]);
    }

    while (!is_empty(stack)) {
        printf("%c", pop(stack));
    }
    printf("\n");

    destroy(stack);

    return 0;
}
