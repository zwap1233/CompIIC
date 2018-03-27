#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node* Tree_read(char* filename, Node* root) {
    FILE* fp = fopen(filename, "rw");
    
    Node* ret = root;
    
    char* line = calloc(99, sizeof(char));
    size_t len = 0;
    ssize_t read;
    
    while(fgets(line, 99, fp)){
        
        int i;
        for(i = 0; line[i] != '\0'; i++){
            if(line[i] == '\n'){
                line[i] = '\0';
            }
        }
        
        ret = Tree_insert(ret, line);
        
        line = calloc(99, sizeof(char));
    }
    
    fclose(fp);
    
    return ret;
}

void Tree_write(char* filename, Node* root) {
    FILE* fp = fopen(filename, "w");
    
    write_pre_order(fp, root);
    
    fclose(fp);
}



void write_pre_order(FILE* fp,Node* node) {
    fprintf(fp,"%s\n",node->data);
    if(node->left)
        write_pre_order(fp,node->left);
    if(node->right)
        write_pre_order(fp,node->right);
}

void bst_print_dot_null(char* data, int nullcount, FILE* stream) {
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %s -> null%d;\n", data, nullcount);
}

void bst_print_dot_aux(Node* node, FILE* stream) {
    static int nullcount = 0;

    if (node->left)
    {
        fprintf(stream, "    %s -> %s;\n", node->data, node->left->data);
        bst_print_dot_aux(node->left, stream);
    }
    else
        bst_print_dot_null(node->data, nullcount++, stream);

    if (node->right)
    {
        fprintf(stream, "    %s -> %s;\n", node->data, node->right->data);
        bst_print_dot_aux(node->right, stream);
    }
    else
        bst_print_dot_null(node->data, nullcount++, stream);
}

void bst_print_dot(Node* tree, char* fname) {
        if(!tree)
    {
        printf("There is no tree to save \n");
        return;
    }

    FILE* stream = fopen(fname,"w");
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %s;\n", tree->data);
    else
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
    fclose(stream);
}
