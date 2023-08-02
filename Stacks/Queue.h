#include <stdio.h>
#include <stdlib.h>

typedef struct queue_struct Queue;

struct queue_struct{
    int* array;
    int startIndex;
    int currentIndex;
    int size;
};

Queue* createQueue();
void deconstructQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int findLargest(Queue* q);
void dequeueValue(Queue* q, int value);
void sortQueue(Queue* q);