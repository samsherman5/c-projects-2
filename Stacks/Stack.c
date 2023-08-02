#include "Stack.h"

Stack* createStack(int sizeOfType){
    Stack* s = malloc(sizeof(int*) + sizeOfType);
    s->array = malloc(5*sizeOfType);
    s->currentIndex = 0;
    s->sizeOfValues = sizeOfType;
    return s;
}

void deconstructStack(Stack* s){
    free(s->array);
    free(s);
}

void push(Stack* s, void* value){
    if(s->currentIndex==5){
        printf("Illegal Opperation on Stack@%d", s);
        exit(1);
    }
    *(((char*)(s->array)) + (s->sizeOfValues * s->currentIndex)) = value;
    s->currentIndex +=1;
}

void* pop(Stack* s){
    if(s->currentIndex==0){
        printf("Illegal Opperation on Stack@%d", s);
        exit(1);
    }
    s->currentIndex -=1;
    return (void*)(*((char*)(s->array)) + (s->sizeOfValues * s->currentIndex));
}