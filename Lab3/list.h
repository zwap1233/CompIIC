#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>

struct Node;
// A simple data structure that forms the core of List
typedef struct Node {
    struct Node* next;
    struct Node* prev;

    struct Item* item;

} Node;

typedef struct List {
    int counter;
    Node* head;
    
} List;

typedef struct Item {
    int id;
    
} Item;

List *List_create();
void List_destroy(List *list);
void List_clear(List *list);

Node* List_find(List *list,int id);
void List_print(List*list);

void List_append(List *list);
void List_insert(List *list);
void List_remove(List* list, Node* node);

void List_putfirst(List *list,Node* node);
void List_sort(List* list);
void List_reverse(List *list);

#endif // _LIST_H_
