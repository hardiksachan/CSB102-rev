#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, int data, int pos) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node *temp = *head;
    int i = 0;
    while (temp->next != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}