#include <stdlib.h>
#include <stdio.h>
#pragma once

typedef struct arraylist_struct ArrayList;

void* arraylists;
int* arrayIndex;

struct arraylist_struct{
    int size;
    int done;
    void* startPointer;
};

ArrayList* initArrayList();
void done(ArrayList* list);
void add(ArrayList* list, int value);
int removeAt(ArrayList* list, int index);
int get(ArrayList* list, int index);
void garbageCollect();
void destroyAll();