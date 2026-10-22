#include <stdio.h>
#include "sll.h"

int main(void)
{
    List *list = sll_new();

    if (list == NULL)
        return 1;

    sll_insert(list, 10);
    sll_insert(list, 20);
    sll_insert(list, 10);
    sll_insert(list, 30);
    sll_insert(list, 20);
    sll_insert(list, 40);

    printf("Before deleting duplicates:");
    sll_display(list);

    sll_delete_duplicate(list);

    printf("\n\nAfter deleting duplicates:");
    sll_display(list);

    printf("\n\nLength: %d\n", list->length);

    sll_free(list);

    return 0;
}