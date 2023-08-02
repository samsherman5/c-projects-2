#include <stdio.h>
#include "ArrayList.h"

int main(){
    //printf("%d", sizeof(ArrayList));
    ArrayList* ga1 = initArrayList();
    ArrayList* ga2 = initArrayList();
    ArrayList* ga3 = initArrayList();
    add(ga3, 7);
    ArrayList* ga4 = initArrayList();
    ArrayList* ga5 = initArrayList();
/*
    add(&ga1, 2);
    add(&ga2, 5);
    add(&ga3, 7);
    add(&ga4, 7);

    //done(ga1);
    //done(ga3);
    //done(ga5);
    //garbageCollect();
    add(&ga4, 4);
    printf("%d\n", get(&ga4, 0));
    ArrayList* ga8 = initArrayList();
    ArrayList* ga6 = initArrayList();
    ArrayList* ga7 = initArrayList();
    printf("%d\n", get(&ga4, 1));
    add(&ga2, 8);
    add(&ga6, 3);
    add(&ga7, 9);
    ArrayList* ga9 = initArrayList();
    printf("%d\n", get(&ga6, 0));
    printf("%d\n", get(&ga2, 0));
    //garbageCollect();
    destroyAll();*/
}