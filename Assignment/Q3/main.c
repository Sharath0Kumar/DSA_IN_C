#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q;
    int k = 3;

    queue_init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Original queue:\n");
    display_queue(&q);

    if (reverse_first_k(&q, k)) {
        printf("Queue after reversing first %d elements:\n", k);
        display_queue(&q);
    } else {
        printf("Invalid value of K\n");
    }

    return 0;
}