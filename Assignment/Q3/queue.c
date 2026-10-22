#include <stdio.h>
#include "queue.h"

void queue_init(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool enqueue(Queue *q, int data)
{
    if (q->size == MAX_SIZE)
        return false;

    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = data;
    q->size++;

    return true;
}

bool dequeue(Queue *q, int *data)
{
    if (q->size == 0)
        return false;

    *data = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;

    return true;
}

void display_queue(const Queue *q)
{
    printf("FRONT -> ");

    for (int i = 0; i < q->size; i++)
        printf("%d ", q->data[(q->front + i) % MAX_SIZE]);

    printf("<- REAR\n");
}

bool reverse_first_k(Queue *q, int k)
{
    if (k < 0 || k > q->size)
        return false;

    int stack[MAX_SIZE];
    int top = -1;
    int data;
    int original_size = q->size;

    
    for (int i = 0; i < k; i++) {
        dequeue(q, &data);
        stack[++top] = data;
    }

    
    while (top >= 0)
        enqueue(q, stack[top--]);

    
    for (int i = 0; i < original_size - k; i++) {
        dequeue(q, &data);
        enqueue(q, data);
    }

    return true;
}