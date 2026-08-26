#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* reverseList(struct Node *head){
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(struct Node *head){
    while(head != NULL){
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc (sizeof(struct Node));

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL;

    printf("Original :");
    printList(head);

    head = reverseList(head);

    printf("Reversed :");
    printList(head);

    free(third);
    free(second);
    free(head);

    return 0;
}
