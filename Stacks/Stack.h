#include <stdio.h>
#include <stdlib.h>

typedef struct stack_struct Stack;

struct stack_struct{
    void* array;
    int currentIndex;
    int sizeOfValues;
};

Stack* createStack(int sizeOfType);

void deconstructStack(Stack* s);
void push(Stack* s, void* value);
void* pop(Stack* s);