#include <stdbool.h>
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

int map(char c) {
    if (c == '(') return 1;
    if (c == ')') return -1;
    return 0;
}

bool check(char *str, int n) {
    struct Stack *stack = new_stack();
    for (int i = 0; i < n; i++) {
        int type = map(str[i]);
        if (type == 1)
            push(stack, type);
        else if (type == -1)
            pop(stack);
    }

    if (stack->size == 0) return true;
    return false;
}

int main() {
    printf("%d\n", check(")()(())()(())((())", 18));
    printf("%d\n", check("()(())()(())((())", 17));
}
