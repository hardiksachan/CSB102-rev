#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10
#define TYPE int

struct Stack {
    TYPE arr[CAPACITY];
    int size;
};

struct Stack *new_stack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = 0;
}

void push(struct Stack *stack, TYPE data) {
    if (stack->size == CAPACITY) {
        printf("\n\n\tStack Overflow");
        exit(EXIT_FAILURE);
    }

    stack->arr[stack->size] = data;
    stack->size++;
}

TYPE pop(struct Stack *stack) {
    if (stack->size == 0) {
        printf("\n\n\tStack Underflow");
        exit(EXIT_FAILURE);
    }

    stack->size--;
    return stack->arr[stack->size];
}

TYPE peek(struct Stack *stack) {
    if (stack->size == 0) {
        printf("\n\n\tStack Underflow");
        exit(EXIT_FAILURE);
    }

    return stack->arr[stack->size - 1];
}

int main() {
    // menu driven code
    int choice;
    struct Stack *stack = new_stack();
    do {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the data to be pushed: ");
                int data;
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                printf("\nThe popped data is: %d", pop(stack));
                break;
            case 3:
                printf("\nThe peeked data is: %d", peek(stack));
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice");
        }
    } while (choice != 4);
}
