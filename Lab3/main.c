#include <stdio.h>

#include "list.h"
//#include "item.h"

char get_command() {
    char c;
    printf("Type command: ");
    scanf(" %c",&c);
    return c;
}

void main() {
   
    List* mylist = List_create();
    
    int idnumb;
    mylist->counter = 1;
    printf("-------- Ring-style linked list base class by Wouter Schoenmakers. --------\n\n");

    char command;
    while ((command = get_command()) != 'q') {
        switch (command) {
            case 'a': // append
                List_append(mylist);
//                 printf("-> Appended item with id: %d\n", list->head->prev->item->id);
                break;
                
            case 'i': // insert
                List_insert(mylist);
//                 printf("-> Inserted item with id: %d\n", list->head->item->id);
                break;
                
            case 'd': // delete
                printf("Which item would you like to delete: ");
                scanf(" %i",&idnumb);
                Node* todel = List_find(mylist,idnumb);
//                 printf("-> Deleted item with id: %d\n", todel->item->id);
                List_remove(mylist,todel);
                break;
                
            case 'f': // put first
                printf("Which item would you like to put first: ");
                scanf(" %i",&idnumb);
                Node* tomove = List_find(mylist,idnumb);
                List_putfirst(mylist,tomove);
                break;
                
            case 'p': // print
                List_print(mylist);
                break;
                
            case 's': // sort
                List_sort(mylist);
                break;
            
            case 'r': // reverse
                List_reverse(mylist);
                break;
                
            case 'x': // destroy list
                List_destroy(mylist);
                
            case 'q':
                break;
                
            default:
                printf("Command unknown!\n");
                break;
        }
    }

    printf("Bye bye!\n");
    
    List_destroy(mylist);
    
    free(mylist);
}
