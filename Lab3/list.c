#include "list.h"
#include <stdio.h>

List *List_create() {
    return calloc(1, sizeof(List));
}

void List_destroy(List *list){
    if(list->head == 0){
        return;
    }
    
    Node *node = list->head;
    Node *next;
    
    do {
        next = node->next;
        
        free(node->item);
        free(node);
        
    } while((node = next) != list->head);
    
    list->head = 0;
}

void List_clear(List *list){
    
}


void List_print(List *list){
    if(list->head != 0){
        Node *node = list->head;
        
        do{
            printf("-> Item id: %i\n", node->item->id);
        } while((node = node->next) != list->head);
        
    } else {
//         printf("There is no list\n");
    }
}

Node* List_find(List *list, int id){
    if(list->head == 0){
//         printf("List is empty!\n");
        return 0;
    }
    
    Node *node = list->head;
    
    do {
        if(node->item->id == id){
            return node;
        }
    } while((node = node->next) != list->head);
    
    return 0;
}


void List_append(List *list){
    Node *node = malloc(sizeof(Node));
    Item *item = malloc(sizeof(Item));
    
    item->id = list->counter;
    list->counter = list->counter + 1;
    
    node->item = item;
    
    if(list->head != 0){
        node->next = list->head;
        
        node->prev = list->head->prev;
        
        list->head->prev->next = node;
        list->head->prev = node;
        
    } else {
        node->next = node;
        node->prev = node;
        
        list->head = node;
    }
}

void List_insert(List *list){
    List_append(list);
    list->head = list->head->prev;
}

void List_remove(List *list, Node* node){
    if(node == 0){
//         printf("Node not found!\n");
        return;
    }
    
    if(node->next == node){
        list->head = 0;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        if(list->head == node){
            list->head = node->next;
        }
    }
    
    free(node->item);
    free(node);
}


void List_putfirst(List *list, Node *node){
    if(node == 0 || list->head == 0 || list->head == node){
        return;
    }
    
    node->prev->next = node->next;
    node->next->prev = node->prev;
    
    node->next = list->head;
    node->prev = list->head->prev;
    list->head->prev->next = node;
    list->head->prev = node;
    
    list->head = node;
}

void List_sort(List *list){
    Node *node = list->head;
    
    int i = list->counter;
    for(i = list->counter; i > 0; i--){
        List_putfirst(list, List_find(list, i));        
    }
}

void List_reverse(List *list){
    if(list->head == 0 || list->head->next == list->head){
        return;
    }
    
    Node *oldhead = list->head;
    Node *node = list->head;
    Node *next;
    
    do {
        next = node->next;
        List_putfirst(list, node);
        node = next;
    } while(list->head->prev != oldhead);
}
