#ifndef SLL_H
#define SLL_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *max_node;
    Node *min_node;
    int length;
} List;

List *sll_new(void);
List *sll_insert(List *list, int data);
Node *sll_max(List *list);
Node *sll_min(List *list);
void sll_display(List *list);
List *sll_free(List *list);

#endif