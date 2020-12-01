typedef struct item {
    char value;
    struct item* previous;
} item;

typedef struct swp {
    item* top;
} swp;

item* new_item(char v);

swp* new_stack();

int is_empty(swp* s);

void push(swp* s, char value);

char pop(swp* s);

void destroy(swp* s);