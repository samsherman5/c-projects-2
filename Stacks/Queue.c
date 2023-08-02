#include "Queue.h"

Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->array = malloc(5*sizeof(int));
    q->currentIndex = 0;
    q->startIndex = 0;
    q->size = 0;
    return q;
}

void deconstructQueue(Queue* q){
    free(q->array);
    free(q);
}

void enqueue(Queue* q, int value){
    //printf("Size: %d\n", q->size);
    if(!(q->size<5)){
        printf("Illegal Opperation on Queue@%d", q);
        exit(1);
    }
    q->array[q->currentIndex] = value;
    ++q->currentIndex;
    q->currentIndex %=5;
    ++q->size;
}

int dequeue(Queue* q){
    
    if(q->size==0){
        printf("Illegal Opperation on Queue@%d", q);
        exit(1);
    }
    int toReturn = q->array[q->startIndex];
    ++q->startIndex;
    q->startIndex %=5;
    --q->size;
    return toReturn;
}

int findLargest(Queue* q){
    int largest = dequeue(q);
    enqueue(q, largest);
    for(int i = 0;i<q->size-1;i++){
        int temp = dequeue(q);
        largest = (temp > largest) ? temp : largest;
        enqueue(q, temp);
    }
    return largest;
}

void dequeueValue(Queue* q, int value){
    for(int i = 0;i<q->size+1;i++){
        int temp = dequeue(q);
        if(temp==value){
            continue;
        }
        enqueue(q, temp);
    }
}

void sortQueue(Queue* q){
    if(q->size==1){
        return;
    }
    int temp = findLargest(q);
    dequeueValue(q, temp);
    sortQueue(q);
    enqueue(q, temp);
}

