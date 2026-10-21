// Design data structure for single linked list. Write function to insert element in O(1) time and find the maximum and minimum element in O(1) time


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
int min, max;


void insert(int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    if (newNode->next == NULL) {
        min = max = value;
    } else {
        if (value < min)
            min = value;
        if (value > max)
            max = value;
    }

    printf("%d inserted\n", value);
}


void findMin() {
    if (head == NULL)
        printf("List is empty\n");
    else
        printf("Minimum = %d\n", min);
}


void findMax() {
    if (head == NULL)
        printf("List is empty\n");
    else
        printf("Maximum = %d\n", max);
}


void display() {
    struct Node *temp = head;

    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(30);
    insert(10);
    insert(50);
    insert(20);

    display();
    findMin();
    findMax();

    return 0;
}
