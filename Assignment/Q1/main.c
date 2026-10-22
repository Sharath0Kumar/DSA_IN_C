#include <stdio.h>
#include "double_linked_list.h"

int main(void)
{
    List *list = dll_new();

    if (list == NULL)
        return 1;

    dll_add_head(list, 20);
    dll_add_head(list, 10);
    dll_add_tail(list, 30);
    dll_add_tail(list, 40);

    printf("After insertion:");
    dll_display(list);

    dll_delete_head(list);

    printf("\n\nAfter deleting head:");
    dll_display(list);

    dll_delete_tail(list);

    printf("\n\nAfter deleting tail:");
    dll_display(list);

    printf("\n\nLength: %u\n", list->length);

    dll_free(list);

    return 0;
}