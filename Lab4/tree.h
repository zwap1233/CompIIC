#include<stdlib.h>
#include<stdio.h>

struct Node;
// A simple data structure that forms the core of Node
typedef struct Node
{
    struct Node* left;
    struct Node* right;
    //  void(*printalphabetically)(struct Node* node);
    char* data;
} Node;



Node* Node_create();
Node* Tree_insert(Node* node,char* data);
void  Tree_printalphabetically(Node* node);
int   Tree_height(Node* node);
int   Tree_count(Node* node);
Node* Tree_find(Node*node,char* data);
void  Tree_clear(Node*node);

void Tree_printfilealphabetically(FILE* fp, Node* node);

Node* Tree_read(char* filename,Node* root);
void write_pre_order(FILE * fp,Node* node);
void Tree_write(char*filename, Node*root);
void bst_print_dot_aux(Node* node, FILE* stream);
void bst_print_dot(Node* tree, char* fname);
void bst_print_dot_null(char* data, int nullcount, FILE* stream);
