#ifndef STACK_H
#define STACK_H

#include <stdint.h>

#define MAX_DEPTH 100

#define STACK_OK    0
#define STACK_FULL  1
#define STACK_EMPTY 2

#define RESULT_INVALID -1.0f

typedef struct Node {
    float data;
    struct Node *next;
} Node;

typedef struct {
    float data;
    uint32_t status;
} StackResult;

typedef struct {
    uint32_t size;
    uint32_t capacity;
    Node *top;
} Stack;

Stack stack_create(uint32_t size);

Stack *push_stack(Stack *stack, float data,
                  StackResult *result);

Stack *pop_stack(Stack *stack, StackResult *result);

Stack *peek_stack(const Stack *stack, StackResult *result);

void display_stack(const Stack *stack, StackResult *result);

Stack *display_key(Stack *stack, uint32_t key,
                   StackResult *result);

Stack *clear_stack(Stack *stack, StackResult *result);

#endif