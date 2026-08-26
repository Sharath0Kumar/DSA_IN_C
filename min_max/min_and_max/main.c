#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void findMinMax(struct Node *head, int *min, int *max) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    *min = head->data;
    *max = head->data;

    struct Node *current = head->next;

    while (current != NULL) {
        if (current->data < *min)
            *min = current->data;

        if (current->data > *max)
            *max = current->data;

        current = current->next;
    }
}

int main() {
    struct Node *head = NULL;

    // Create nodes
    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));
    struct Node *n4 = malloc(sizeof(struct Node));

    n1->data = 10;
    n1->next = n2;

    n2->data = 5;
    n2->next = n3;

    n3->data = 25;
    n3->next = n4;

    n4->data = 3;
    n4->next = NULL;

    head = n1;

    int min, max;

    findMinMax(head, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return 0;
}
