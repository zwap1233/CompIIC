#include <math.h>
#include <stdlib.h>
#include "functions.h"

int* allocatearray(int length) {
    int* intermediate = calloc(length,sizeof(int));
    return intermediate;
}

double square(double input) {
    return input*input;
}

double squareroot(double input) {
    return sqrt(input);
}