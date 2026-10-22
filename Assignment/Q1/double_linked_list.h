#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdint.h>

typedef struct Node {
    uint32_t data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    uint32_t length;
} List;

List *dll_new(void);
List *dll_add_head(List *list, uint32_t data);
List *dll_add_tail(List *list, uint32_t data);
List *dll_delete_head(List *list);
List *dll_delete_tail(List *list);
void dll_display(List *list);
List *dll_free(List *list);

#endif