#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

static Node *_new_node_(uint32_t data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
        return NULL;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

List *dll_new(void)
{
    List *new_list = (List *)malloc(sizeof(List));

    if (new_list == NULL)
        return NULL;

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->length = 0;

    return new_list;
}


List *dll_add_head(List *list, uint32_t data)
{
    if (list == NULL)
        return NULL;

    Node *new_node = _new_node_(data);

    if (new_node == NULL)
        return list;

    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }

    ++list->length;
    return list;
}


List *dll_add_tail(List *list, uint32_t data)
{
    if (list == NULL)
        return NULL;

    Node *new_node = _new_node_(data);

    if (new_node == NULL)
        return list;

    if (list->tail == NULL) {
        list->head = list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }

    ++list->length;
    return list;
}


List *dll_delete_head(List *list)
{
    if (list == NULL)
        return NULL;

    if (list->head == NULL)
        return list;

    Node *temp = list->head;

    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }

    free(temp);
    --list->length;

    return list;
}


List *dll_delete_tail(List *list)
{
    if (list == NULL)
        return NULL;

    if (list->tail == NULL)
        return list;

    Node *temp = list->tail;

    if (list->head == list->tail) {
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }

    free(temp);
    --list->length;

    return list;
}


void dll_display(List *list)
{
    if (list == NULL)
        return;

    printf("\nDOUBLY LINKED LIST {");

    for (Node *node = list->head;
         node != NULL;
         node = node->next) {
        printf("\n\t%u", node->data);
    }

    printf("\n}");
}


List *dll_free(List *list)
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