#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack stack = stack_create(MAX_DEPTH);
    StackResult result = {RESULT_INVALID, STACK_OK};

    push_stack(&stack, 20, &result);
    push_stack(&stack, 45, &result);
    push_stack(&stack, 65, &result);
    push_stack(&stack, 75, &result);
    push_stack(&stack, 33, &result);
    push_stack(&stack, 50, &result);

    printf("Original stack:");
    display_stack(&stack, &result);

    printf("\n\nSearching for key 65:");
    display_key(&stack, 65, &result);

    printf("\n\nStack after searching:");
    display_stack(&stack, &result);

    clear_stack(&stack, &result);

    return 0;
}