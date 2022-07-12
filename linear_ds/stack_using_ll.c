#include <stdio.h>
#include <stdlib.h>

#define TYPE int

struct Node {
    TYPE data;
    struct Node* next;
};

struct Node* create_node(TYPE data) {
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
}

struct Stack {
    struct Node* top;
};

struct Stack* create_stack() {
    struct Stack * stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
}

void push(struct Stack * stack, TYPE data) {
    struct Node * data_node = create_node(data);
    if (stack->top == NULL) {
        stack->top = data_node;
        return;
    }
    data_node->next = stack->top;
    stack->top = data_node;
}

TYPE pop(struct Stack * stack) {
    if (stack->top == NULL) {
        printf("\n\n\tStack Underflow");
        exit(EXIT_FAILURE);
    }

    TYPE data = stack->top->data;

    struct Node * to_delete = stack->top;
    stack->top = stack->top->next;
    free(to_delete);

    return data;
}

TYPE peek(struct Stack * stack) {
    if (stack->top == NULL) {
        printf("\n\n\tStack Underflow");
        exit(EXIT_FAILURE);
    }

    TYPE data = stack->top->data;
    return data;
}


int main() {
    // menu driven code
    int choice;
    struct Stack *stack = create_stack();
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

