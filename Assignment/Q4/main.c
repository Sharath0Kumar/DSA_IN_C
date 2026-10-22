#include <stdio.h>
#include "sll.h"

int main(void)
{
    List *list = sll_new();

    if (list == NULL)
        return 1;

    sll_insert(list, 20);
    sll_insert(list, 45);
    sll_insert(list, 10);
    sll_insert(list, 65);
    sll_insert(list, 5);

    sll_display(list);

    Node *max = sll_max(list);
    Node *min = sll_min(list);

    if (max != NULL)
        printf("\nMaximum element: %d", max->data);

    if (min != NULL)
        printf("\nMinimum element: %d", min->data);

    printf("\n");

    sll_free(list);

    return 0;
}