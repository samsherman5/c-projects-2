#include "ArrayList.h"

ArrayList* toArrayList(void* x);

ArrayList* initArrayList(){
    if(arrayIndex==NULL){
        arrayIndex = malloc(sizeof(int));
        *arrayIndex = 0;
    }
    if(arraylists==NULL){
        arraylists = malloc(200*sizeof(ArrayList));
        ((ArrayList*)(arraylists))[*arrayIndex].startPointer = ((ArrayList*)(arraylists))+1;
    }
    else {
        for(ArrayList i = ((ArrayList*)(arraylists))[0];i<(((ArrayList*)(arraylists))+*arrayIndex);i++){
            i->startPointer = (*arrayIndex * 12) + (((ArrayList*)(arraylists)) + *arrayIndex);
        }
        int* startShift = ((ArrayList*)(arraylists))->startPointer;
        
        int* endShift = ((int*)(((ArrayList*)(arraylists))[*arrayIndex-1].startPointer)) + ((ArrayList*)(arraylists))[*arrayIndex-1].size;
        for(int* i = endShift;i>startShift;i++){
            
            *(i + 3) = *(i);
        }
        printf("%d\n",((ArrayList*)(arraylists))[*arrayIndex].startPointer);

    }
    
    (*(toArrayList(arraylists)+(*arrayIndex))).done = 0;
    (*(toArrayList(arraylists)+(*arrayIndex))).size = 0;

    (*arrayIndex) = (*arrayIndex) + 1;
    return (ArrayList*)(toArrayList(arraylists) + (*arrayIndex));
}
/*
void destroyAll(){
    for(int i = 0;i<*arrayIndex;i++){
        free(arraylists[*arrayIndex].array);
    }
}*/

void done(ArrayList* list){
    list->done=1;
}
/*
void garbageCollect(){
    int temp = *arrayIndex;
    int listIndex = 0;
    for(int i = 0;i < temp;i++){
        if(arraylists[i].done==1){
            
            if(arraylists[i].size != 0){
                free(arraylists[i].array);
            }
            for(int j = *arrayIndex;j>i;j++){
                arraylists[i-1] = arraylists[i];
            }
            *(arrayIndex) = (*arrayIndex) - 1;
        }
    }
}*/

ArrayList* toArrayList(void* x){
    return ((ArrayList*)(x));
}

int* toInt(void* x){
    return ((int*)(x));
}

void add(ArrayList* list, int value){
    if(list == &(((ArrayList*)(arraylists))[*arrayIndex])){
        //printf("\n%d\n", *((int*)(list->startPointer)));
        //printf("%d", (int*)(list->startPointer));
        list->startPointer = value;
        list->size++;
        
    }
    else{
        int* startShift = ((int*)(list->startPointer)) + list->size;
        int* endShift = ((int*)((((ArrayList*)(arraylists))[*arrayIndex]).startPointer)) + (((ArrayList*)(arraylists))[*arrayIndex]).size;
        for(int* i = endShift;i>startShift;i++){
            
            *(i + 1) = *(i);
        };
        *startShift = value;
        list->size++;
    }
}

/*
int removeAt(ArrayList* list, int index){
    if(index>=list->size){
        return -1;
    }
    int toReturn = -1;
    int* temp = malloc((list->size-1) * sizeof(int));
    for(int i = 0;i<list->size;i++){
        if(i == index){
            toReturn = list->array[i];
            continue;
        }
        temp[i] = list->array[i];
    }
    free(list->array);
    list->array = temp;
    list->size--;
    return toReturn;
}

int get(ArrayList* list, int index){
    if(index>=list->size){
        return -1;
    }
    return *(((int*)(list->startPointer))+index);
}*/