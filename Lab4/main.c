
///////////////////////////////////////////////////
//
// Task Binary Tree
// Name: _________________fill in your name________
//
// File: main.cpp
//
// Contents: The main() of the binary tree function
//           function with the command parser
//
// This file is fully implemented. Do not mail it in
// if you left it unchanged.
///////////////////////////////////////////////////

#include "tree.h"      // contains class definitions
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




// prototypes of some help functions we need below
void print_help(void);
char read_command(void);
char* read_word(void);

//
// Main routine of our binary tree based string database.
// This contains just a simple command parser.
// It instantiates as single object of class tree (my_tree)
// that maintains the tree structure.
// The commands in the case switch call the individual member
// functions on the object my_tree.
//
// Hint: implement the missing commands in the order of the
// switch() statement below.
//

int main() {
    //
    // We're instantiating a single object of type tree
    // The root is a stack object, so at the end of thins
    // main function, the destructor for the tree elements will be
    // called.
    //
    Node* root = NULL;
    /*
    * Our 'endless' command parsing loop
    */
    while(1) {
        switch(read_command()) {  // gets a single-character command from the command line

        case 'a':   /* a - Adds a string to the database. */
            root = Tree_insert(root,read_word());
            break;
        case 'l':   /* l - Lists the database alphabetically. */
            Tree_printalphabetically(root);
            break;
        case 'h':   /* h - Prints the maximum height of the tree. */
            printf("The height of the tree is %i \n",Tree_height(root));
            break;
        case 'f':   /* f - Finds a string in the database. */
            if(Tree_find(root,read_word())) {
                printf("This element is in the list\n");
            } else {
                printf("This element is not in the list\n");
            }
            break;
        case 'd':   /* d - Destroys all strings in the tree database */
            Tree_clear(root);
            root =0;
            break;
        case 'c':   /* c - Counts & prints the number of entries in the tree. */
                printf("There are %i elements in the tree \n",Tree_count(root));
            break;
        case 's':   /* s - Saves the database to a file. */
                Tree_write(read_word(), root);
            break;
        case 'o':   /* o - Opens a file: read all strings from a file. */
                root = Tree_read(read_word(), root);
            break;
        case 'v':
                bst_print_dot(root, read_word());
                break;
        case 'q':   /* q - Quits the program. */
                printf(" Bye bye \n") ;
                // Note: the death of my_tree will remove the objects!
                return 0; // done
        default:
                printf("Unknown command");
                // no break statement here: always print help in this case
        case '?':   /* ? - Prints help. */
                print_help();
                break;
        }
    }
    Tree_clear(root);
    return 0;
}



//
// Read a one-character command from the input.
// Function will return a char
//
char read_command(void) {
    char val;
    printf("Command: ");
    scanf(" %c",&val);
    return val;
}

char* read_word(void) {
    char* temp = calloc(255,sizeof(char));
    printf("Enter a string: ");
    scanf(" %s",temp);
    return temp;
}

//
// Print help command.
//
void print_help(void) {
    printf(" Command list: \n") ;
    printf(" a - Add a string to the database.\n") ;
    printf(" f - Find a string in the database.\n") ;
    printf(" c - Clear all strings in the database.\n") ;
    printf(" l - List the database alphabetically.\n") ;
    printf(" v - Writes the tree into a dot file for visualization\n") ;
    printf(" h - Height: print the maximum height of the tree.\n") ;
    printf(" c - Count: print the number of words in the tree.\n") ;
    printf(" s - Save the database into a file.\n") ;
    printf(" o - Open a file: read all words from a file.\n") ;
    printf(" q - Quit the program.\n") ;
    printf(" ? - Print this help.\n") ;
}
