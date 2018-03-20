
#include "tree.h"
#include <string.h>

Node* Node_create()
{
    return calloc(1,sizeof(Node));
}

//Node* Tree_insert(Node* node, char* data)
//{

//}

//void Tree_printalphabetically(Node*node)
//{

//}

//int  Tree_height(Node* node)
//{

//}

//int   Tree_count(Node* node)
//{

//}

//Node* Tree_find(Node*node,char* data)
//{

//}

void Tree_clear(Node* node)
{
    if(!node)
        return;
    Tree_clear(node->left);
    Tree_clear(node->right);
    printf(" Deleting node : %s \n",node->data);
    free(node->data);
    free(node);
}
