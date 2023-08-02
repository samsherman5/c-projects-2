#include "LinkedListNode.h"

LinkedListNode* createNode(void* value, int sizeOfValue, LinkedListNode* previous, LinkedListNode* next){
    LinkedListNode* newNode = malloc(sizeof(LinkedListNode));
    newNode->value = value;
    newNode->sizeOfValue = sizeOfValue;
    newNode->previous = previous;
    newNode->next = next;
    return newNode;
}

void* getValue(LinkedListNode* node){
    return node->value;
}

void setValue(LinkedListNode* node, void* value){
    node->value = value;
}

LinkedListNode* getNext(LinkedListNode* node){
    return node->next;
}

void setNext(LinkedListNode* node, LinkedListNode* next){
    node->next = next;
}

LinkedListNode* getPrevious(LinkedListNode* node){
    return node->previous;
}

void setPrevious(LinkedListNode* node, LinkedListNode* previous){
    node->previous = previous;
}