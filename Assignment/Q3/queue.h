#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void queue_init(Queue *q);
bool enqueue(Queue *q, int data);
bool dequeue(Queue *q, int *data);
void display_queue(const Queue *q);
bool reverse_first_k(Queue *q, int k);

#endif