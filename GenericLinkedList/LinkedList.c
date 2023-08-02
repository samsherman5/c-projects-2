#include "LinkedList.h"

LinkedList* createList(int sizeOfValues){
    LinkedList* list = malloc(sizeof(LinkedList));
    list->size=0;
    list->sizeOfValues = sizeOfValues;
    list->head = createNode(0, 0, 0, 0);
    list->tail = createNode(0, 0, 0, 0);
    setNext(list->head, list->tail);
    setPrevious(list->tail, list->head);
    return list;
}

void set(LinkedList* list, int index, void* value){
    if(list->size==0 || index>list->size){
        return;
    }
    LinkedListNode* currentNode = list->head;
    for(int i = 0;i<index;i++){
        currentNode = getNext(currentNode);
    }
    setValue(getNext(currentNode), value);
}

void deconstructList(LinkedList* list){
    LinkedListNode* current = list->head;
    LinkedListNode* next = getNext(current);
    free(current);
    current=next;
    while(current!=list->tail){
        next = getNext(current);
        free(current);
        current = next;
    }
    free(list->tail);
    free(list);
}

void add(LinkedList* list, void* value){
    addAt(list, value, list->size);
}

void addAt(LinkedList* list, void* value, int index){
    LinkedListNode* currentNode = list->head;
    if(index>list->size){
        return;
    }
    for(int i = 0;i<index;i++){
        currentNode = getNext(currentNode);
    }
    LinkedListNode* newNode = createNode(value, list->sizeOfValues, currentNode, getNext(currentNode));
    LinkedListNode* oldNext = getNext(currentNode);
    setNext(currentNode, newNode);
    setPrevious(oldNext, newNode);
    setNext(newNode, oldNext);
    setPrevious(newNode, currentNode);
    list->size++;
}

void* removeAt(LinkedList* list, int index){
    if(list->size==0 || index>list->size){
        return 0;
    }
    LinkedListNode* currentNode = list->head;
    for(int i = 0;i<index;i++){
        currentNode = getNext(currentNode);
    }
    LinkedListNode* temp = getNext(getNext(currentNode));
    LinkedListNode* toRemove = getNext(currentNode);
    setNext(currentNode, temp);
    setPrevious(temp, currentNode);
    void* removeVal = toRemove->value;
    free(toRemove);
    list->size--;
    return removeVal;
}

void* get(LinkedList* list, int index){
    if(list->size==0 || index>list->size){
        return 0;
    }
    LinkedListNode* current = list->head;
    for(int i = 0;i<index;i++){
        current = current->next;
    }
    return getValue(getNext(current));
}