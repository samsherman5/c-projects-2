#include "LinkedListNode.h"

typedef struct linkedlist_struct LinkedList;

struct linkedlist_struct{
    LinkedListNode* head;
    LinkedListNode* tail;
    int size;
    int sizeOfValues;
};

void set(LinkedList* list, int index, void* value);
LinkedList* createList(int sizeOfValues);
void deconstructList(LinkedList* list);
void add(LinkedList* list, void* value);
void addAt(LinkedList* list, void* value, int index);
void* removeAt(LinkedList* list, int index);
void* get(LinkedList* list, int index);
