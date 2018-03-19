
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//int main();

int main() {
    
    int a;
    int *b = malloc(sizeof(int));
    int *c;
    int *array = calloc(10, sizeof(int));
    
    for(a = 0; a < 10; a++){
        array[a] = 5;
    }
    
    printf("%d\n", array[0]);
    free(array);

    *b = 3;
    c = b;
    //free(b);
    
    printf("%i\n",*c);
    free(c);

    int* myarray = allocatearray(8);
    
    myarray[1] = 42;
    printf("%i\n",myarray[1]);
    printf("Finally, i run");
    
    free(myarray);
    
    double testvar = 3;
    printf("\n%.0f should be equal to 3 \n", squareroot(square(testvar)));
    
    return 0;
}