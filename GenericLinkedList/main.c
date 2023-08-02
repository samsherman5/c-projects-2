#include "LinkedList.h"
#include <string.h>
#include <ctype.h>

void sort(LinkedList* list);
int compareStrings(LinkedList* a, LinkedList* b);

int main(){
    //Should be sizeof(char*) if strtok is being used
    LinkedList* list = createList(sizeof(LinkedList));
    FILE * fp;
    fp = fopen("input.txt", "r");
    if(fp==NULL) return 1;
    
    //Sets cursor to end of file then takes the index of the cursor to size
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    //Resets cursor
    rewind(fp);
    char* file = malloc(size+1);
    for(int i = 0;i<size;i++){
        file[i] = getc(fp);
    }
    file[size] = '\0';

    int previousSpace = 0;
    add(list, createList(sizeof(char*)));
    for(int i = 0;i<=(strlen(file));i++){
        if(file[i] == '\0' || file[i] == EOF){
            break;
        }
        if(isspace(file[i]) && previousSpace){
            continue;
        }
        else{
            previousSpace=0;
        }
        if(isspace(file[i])){
            add(list, createList(sizeof(char*)));
            previousSpace=1;
        }

        else{
            LinkedList* temp = (LinkedList*)(get(list, list->size-1));
            add(temp, &file[i]);
        }
    }

    /*
    char *p = NULL;
    p = strtok(file, " ");
    while(p!=NULL){
        add(list, p);
        p = strtok(NULL, " ");
    }*/


    sort(list);
    

    for(int i = 0;i<list->size;i++){
        LinkedList* tempList = (LinkedList*)(get(list, i));
        for(int x = 0;x<tempList->size;x++){
            char temp = *(char*)(get(tempList, x));
            printf("%c", temp);
            
        }
        printf("\n");
    }
    
    for(int i=0;i<list->size;i++){
        deconstructList((LinkedList*)(get(list, i)));
    }

    free(file);
    fclose(fp);
    deconstructList(list);
}

//Sorts a LinkedList of char pointers
void sort(LinkedList* list){
    for(int x=0;x<list->size;x++){
        for(int y=0;y<list->size-1;y++){
            if(compareStrings((LinkedList*)(get(list, y)), (LinkedList*)(get(list, y+1)))==1){
                LinkedList* temp = (LinkedList*)(get(list, y));
                set(list, y, get(list, y+1));
                set(list, y+1, temp);
            }
        }
    }
}

int compareStrings(LinkedList* a, LinkedList* b){
    if(a->size==0 && b->size==0){
        return 0;
    }
    if(a->size==0){
        return -1;
    }
    if(b->size==0){
        return 1;
    }
    if(tolower(*(char*)(get(a, 0)))>tolower(*(char*)(get(b, 0)))){
        return 1;
    }
    if(tolower(*(char*)(get(a, 0)))<tolower(*(char*)(get(b, 0)))){
        return -1;
    }
    else{
        char* aC = (char*)(removeAt(a, 0));
        char* bC = (char*)(removeAt(b, 0));
        int ans = compareStrings(a, b);   
        addAt(a, aC, 0);
        addAt(b, bC, 0);
        return ans;
    }
}