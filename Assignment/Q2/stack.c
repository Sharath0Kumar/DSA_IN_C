#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "stack.h"

static void set_result(StackResult *result,
                       float data, uint32_t status)
{
    result->data = data;
    result->status = status;
}

Stack stack_create(uint32_t size)
{
    Stack stack = {0, size, NULL};
    return stack;
}

Stack *push_stack(Stack *stack, float data,
                  StackResult *result)
{
    if (stack->size < stack->capacity) {
        Node *new_node = malloc(sizeof(Node));

        if (new_node == NULL) {
            set_result(result, data, STACK_FULL);
            return stack;
        }

        new_node->data = data;
        new_node->next = stack->top;

        stack->top = new_node;
        stack->size++;

        set_result(result, data, STACK_OK);
    } else {
        set_result(result, data, STACK_FULL);
    }

    return stack;
}

Stack *pop_stack(Stack *stack, StackResult *result)
{
    if (stack->top != NULL) {
        Node *temp = stack->top;

        set_result(result, temp->data, STACK_OK);

        stack->top = temp->next;
        free(temp);

        stack->size--;
    } else {
        set_result(result, RESULT_INVALID, STACK_EMPTY);
    }

    return stack;
}

Stack *peek_stack(const Stack *stack, StackResult *result)
{
    if (stack->top != NULL) {
        set_result(result, stack->top->data, STACK_OK);
    } else {
        set_result(result, RESULT_INVALID, STACK_EMPTY);
    }

    return (Stack *)stack;
}

void display_stack(const Stack *stack, StackResult *result)
{
    printf("\nSTACK {");
    printf("\n\tsize : %u", stack->size);
    printf("\n\tstack:");

    if (stack->top == NULL) {
        printf("\n\t\tEMPTY");
    } else {
        Node *curr = stack->top;

        while (curr != NULL) {
            printf("\n\t\t%5.2f", curr->data);

            if (curr == stack->top)
                printf(" <-- TOP OF STACK");

            curr = curr->next;
        }
    }

    printf("\n\tSTACK_RESULT {");
    printf("\n\t\tdata   : %5.2f", result->data);
    printf("\n\t\tstatus : %u", result->status);
    printf("\n\t}");
    printf("\n}");
}

Stack *display_key(Stack *stack, uint32_t key,
                   StackResult *result)
{
    Node *curr = stack->top;
    bool found = false;

    while (curr != NULL) {
        if (curr->data == (float)key) {
            set_result(result, curr->data, STACK_OK);

            printf("\nFound key: %u", key);
            found = true;
            break;
        }

        curr = curr->next;
    }

    if (!found) {
        set_result(result, RESULT_INVALID, STACK_EMPTY);
        printf("\nKey %u not found", key);
    }

    return stack;
}

Stack *clear_stack(Stack *stack, StackResult *result)
{
    Node *curr = stack->top;

    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    stack->top = NULL;
    stack->size = 0;

    set_result(result, RESULT_INVALID, STACK_OK);

    return stack;
}