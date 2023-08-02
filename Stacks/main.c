//#include "Stack.h"
/*#include "Queue.h"

void main(){
    /*
    Stack* s = createStack();
    push(s, 5);
    push(s, 4);
    push(s, 3);
    printf("%d\n",pop(s));
    push(s, 2);
    push(s, 1);
    push(s, 0);
    for(int i = 0;i<5;i++){
        printf("%d\n", pop(s));
    }
    deconstructStack(s);*//*
    Queue* q = createQueue();
    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 11);
    enqueue(q, 2);
    enqueue(q, 9);
    sortQueue(q);
    //printf("%d\n\n", findLargest(q));
    
    for(int i = 0;i<5;i++){
        printf("%d\n", dequeue(q));
    }
    deconstructQueue(q);
}*/

#include "Stack.h"

int main(){
    Stack* s = createStack(sizeof(int));
    int* a = malloc(sizeof(int));
    *(a) = 5;
    push(s, a);
    printf("%d", *(int*)(pop(s)));
}