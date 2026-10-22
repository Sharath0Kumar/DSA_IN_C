#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

static Node *_new_node_(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

List *sll_new(void)
{
    List *new_list = (List *)malloc(sizeof(List));

    if (new_list == NULL)
        return NULL;

    new_list->head = NULL;
    new_list->length = 0;

    return new_list;
}

List *sll_insert(List *list, int data)
{
    if (list == NULL)
        return NULL;

    Node *new_node = _new_node_(data);

    if (new_node == NULL)
        return list;

    new_node->next = list->head;
    list->head = new_node;
    ++list->length;

    return list;
}

List *sll_delete_duplicate(List *list)
{
    if (list == NULL)
        return NULL;

    Node *curr = list->head;

    while (curr != NULL) {
        Node *runner = curr;

        while (runner->next != NULL) {
            if (runner->next->data == curr->data) {
                Node *temp = runner->next;

                runner->next = temp->next;
                free(temp);

                --list->length;
            } else {
                runner = runner->next;
            }
        }

        curr = curr->next;
    }

    return list;
}

void sll_display(List *list)
{
    if (list == NULL)
        return;

    printf("\nSINGLY LINKED LIST {");

    for (Node *node = list->head;
         node != NULL;
         node = node->next) {
        printf("\n\t%d", node->data);
    }

    printf("\n}");
}

List *sll_free(List *list)
{
    if (list == NULL)
        return NULL;

    Node *curr = list->head;

    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(list);

    return NULL;
}