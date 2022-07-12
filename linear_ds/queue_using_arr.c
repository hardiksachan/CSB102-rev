#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

struct Queue {
    int arr[CAPACITY];
    int front;
    int back;
};

struct Queue *create_queue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->back = -1;
}

int size(struct Queue *queue) {
    if (queue->front == -1) {
        return 0;
    }

    return queue->back - queue->front + 1;
}

void enque(struct Queue *queue, int data) {
    if (size(queue) == 0) {
        queue->front = 0;
        queue->back = 0;
        queue->arr[queue->back] = data;
        return;
    }

    if (queue->back == CAPACITY - 1) {
        printf("\n\nOVERFLOW\n");
        exit(EXIT_FAILURE);
    }

    queue->back++;
    queue->arr[queue->back] = data;
}

int deque(struct Queue *queue) {
    if (size(queue) == 0) {
        printf("\n\nUNDERFLOW\n");
        exit(EXIT_FAILURE);
    }

    if (size(queue) == 1) {
        int data = queue->arr[queue->front];
        queue->front = -1;
        queue->back = -1;
        return data;
    }

    queue->front++;
    return queue->arr[queue->front - 1];
}

int main() {
    // menu driven code
    int choice;
    struct Queue *queue = create_queue();
    do {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Size\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                enque(queue, data);
                break;
            case 2:
                printf("Dequeued data: %d\n", deque(queue));
                break;
            case 3:
                printf("Size: %d\n", size(queue));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
}