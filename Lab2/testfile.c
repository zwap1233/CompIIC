#include <stdio.h>
#include <stdlib.h>

int* allocatearray(int length) {
    int* intermediate = calloc(length,sizeof(int));
    return intermediate;
}

int main() {
    
    int a;
    int *b = malloc(sizeof(int));
    int *c;
    int *array = calloc(10,sizeof(int));
    
    for(a = 0; a<=10; a++){
        array[a] = 5;
    }
    
    free(array);
    printf("%d",array[0]);


    *b = 3;
    c = b;
    free(b);
    printf("%i",*c);
    free(c);

    int* myarray = allocatearray(7);
    
    myarray[1] = 42;
    printf("%i",myarray[7]);
    printf("Finally, i run");
    
    return 0;
}