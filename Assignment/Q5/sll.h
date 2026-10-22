#ifndef SLL_H
#define SLL_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    int length;
} List;

List *sll_new(void);
List *sll_insert(List *list, int data);
List *sll_delete_duplicate(List *list);
void sll_display(List *list);
List *sll_free(List *list);

#endif