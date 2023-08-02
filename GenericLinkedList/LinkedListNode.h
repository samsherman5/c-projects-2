#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlistnode_struct LinkedListNode;

struct linkedlistnode_struct{
    LinkedListNode* next;
    LinkedListNode* previous;
    void* value;
    int sizeOfValue;
};

LinkedListNode* createNode(void* value, int sizeOfValue, LinkedListNode* previous, LinkedListNode* next);
void* getValue(LinkedListNode* node);
void setValue(LinkedListNode* node, void* value);
LinkedListNode* getNext(LinkedListNode* node);
void setNext(LinkedListNode* node, LinkedListNode* next);
LinkedListNode* getPrevious(LinkedListNode* node);
void setPrevious(LinkedListNode* node, LinkedListNode* previous);