#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Do you want (1) short, (2) int, or (3) long\n");
    int choice = 0;
    scanf("%d", &choice);
    void* f;
    switch(choice){
        case 1:
            f = malloc(sizeof(short));
            scanf("%hi",  f);
            printf("Your value is %hi", *((short*)f));
            break;
        case 2:
            f = malloc(sizeof(int));
            scanf("%d", f);
            printf("Your value is %d", *((int*)f));
            break;
        case 3:
            f = malloc(sizeof(long));
            scanf("%li", f);
            printf("Your value is %li", *((long*)f));
            break;
    }
    free(f);
    return 0;
}