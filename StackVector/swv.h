#define LEN 100

typedef struct swv {
    char items[LEN];
    int top;
} swv;

swv* new_stack();

int is_empty(swv* stack);

int is_full(swv* stack);

void push(swv* stack, char value);

char pop(swv* stack);

void destroy(swv* stack);