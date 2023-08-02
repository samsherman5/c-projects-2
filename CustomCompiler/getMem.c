#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

extern void run() asm("run");

int main(){
    run();
}

void* getMem(){
    return malloc(500);
}

void freeMem(void* start){
    free(start);
}

void printInt(int print){
    if(print == INT_MIN){
        printf("\n");
    }
    else {
        printf("%d\n", print);
    }
}

