// Given a stack[ ] = { 20,45,65,75,33,50} with top pointing to 50. Write a function to display the key 65.

#include <stdio.h>

void display() {
    int stack[] = {20, 45, 65, 75, 33, 50};
    int top = 5;
    int i;

    for (i = 0; i <= top; i++) {
        if (stack[i] == 65) {
            printf("Key found: %d\n", stack[i]);
            return;
        }
    }

    printf("Key not found\n");
}

int main() {
    display();
    return 0;
}