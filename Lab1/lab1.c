#include <stdio.h>

// enter your global variables here
// (1) An array of strings with the 12 months of the year
char *months[] = {"January", "February", "March", "April", "May", "June", "Juli", "August", "September", "October", "November", "December"};

// enter the functions reverse_string_array(…), fourth(…) and get_value(…) here
void reverse_string_array(char* array[], int size);
double fourth(int number);
int get_value(int* val);

void main(void)
{

    int i = 5;         	// (2) integer variable i, set to 5
    int *ip = &i;      	// (3) ip is a pointer to an int, points to i.
    int **ipp = &ip;    // (4) ipp is a pointer to a pointer to an int,
                       	//     initialized with the address of ip

    // (5) points to ber_string on “ber” in september of months
    char *ber_string = &months[8][6];

    // Reverse the order of the words in string array months
    reverse_string_array(months, 12);

    printf("%s, %s, %s and %s are the months of the year that end with '%s'.\n\n",
           months[3], months[2], months[1], months[0],
           ber_string);

    printf("fourth(%d) = %.0lf\n", **ipp, fourth(get_value(*ipp)));
}

void reverse_string_array(char* array[], int size){
    char *tmp;
    int i = 0;
    for(i = 0; i < (size/2); i++){
        tmp = array[i];
        array[i] = array[size-i-1];
        array[size-i-1] = tmp;
    }
}

double fourth(int number){
    return (((double) number)*((double) number)*((double) number)*((double) number));
}

int get_value(int *val){
    return *val;
}