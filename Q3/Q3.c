// Reverse first k elements of  queue.


#include <stdio.h>

int main() {
    int queue[100], stack[100];
    int n, k, i, top = -1, temp;

    printf("Enter the number of queue elements: ");
    scanf("%d", &n);

    printf("Enter the queue elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &k);

    if (k < 0 || k > n) {
        printf("Invalid value of K\n");
        return 1;
    }

  
    for (i = 0; i < k; i++) {
        stack[++top] = queue[i];
    }

    
    for (i = 0; i < k; i++) {
        queue[i] = stack[top--];
    }

    printf("Queue after reversing first %d elements:\n", k);
    for (i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    printf("\n");
    return 0;
}
