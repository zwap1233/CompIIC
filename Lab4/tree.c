
#include "tree.h"
#include <string.h>

Node* Node_create() {
    return calloc(1, sizeof(Node));
}

Node* Tree_insert(Node* node, char* data) {
    if(node == 0){
        Node* ret =  Node_create();
        ret->data = data;
        return ret;
    }
    
    if(strcmp(node->data, data) > 0){
        if(node->left != 0){
            Tree_insert(node->left, data);
        } else {
            node->left = Node_create();
            node->left->data = data;
        }
    } else {
        if(node->right != 0){
            Tree_insert(node->right, data);
        } else {
            node->right = Node_create();
            node->right->data = data;
        }
    }
    
    return node;
}

void Tree_printalphabetically(Node* node) {
    if(node != 0){
        if(node->left != 0) {
            Tree_printalphabetically(node->left);
        }
        
        printf("%s\n", node->data);
        
        if(node->right != 0){
            Tree_printalphabetically(node->right);
        }
    }
}

void Tree_printfilealphabetically(FILE* fp, Node* node) {
    if(node != 0){
        if(node->left != 0) {
            Tree_printalphabetically(node->left);
        }
        
        fprintf(fp, "%s\n", node->data);
        
        if(node->right != 0){
            Tree_printalphabetically(node->right);
        }
    }
}

int Tree_height(Node* node) {
    if(node == 0){
        return 0;
    }
    
    int resl = 0;
    int resr = 0;
    
    if(node->left != 0){
        resl = Tree_height(node->left);
    }
    
    if(node->right != 0){
        resr = Tree_height(node->right);
    }
    
    if(resl > resr){
        return resl+1;
    } else {
        return resr+1;
    }
}

int Tree_count(Node* node) {
    if(node == 0){
        return 0;
    }
    
    int res = 1;
    
    if(node->left != 0){
        res += Tree_count(node->left);
    }
    
    if(node->right != 0){
        res += Tree_count(node->right);
    }
    
    return res;
}

Node* Tree_find(Node* node, char* data) {
    if(node == 0 || data == 0){
        return 0;
    }
    
    if(node->data == 0){
        return 0;
    }
    
    if(strcmp(node->data, data) > 0){
        return Tree_find(node->left, data);
    } else if(strcmp(node->data, data) < 0){
        return Tree_find(node->right, data);
    } else {
        return node;
    }
}

void Tree_clear(Node* node) {
    if(!node)
        return;
    Tree_clear(node->left);
    Tree_clear(node->right);
    printf(" Deleting node : %s \n",node->data);
    free(node->data);
    free(node);
}
