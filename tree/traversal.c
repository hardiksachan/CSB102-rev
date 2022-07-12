#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *insert_left(struct Node *root, int data) {
    root->left = create_node(data);
    return root->left;
}

struct Node *insert_right(struct Node *root, int data) {
    root->right = create_node(data);
    return root->right;
}

struct Node *create_test_tree() {
    struct Node *root = create_node(1);
    insert_left(root, 12);
    insert_right(root, 9);

    // left
    insert_left(root->left, 5);
    insert_right(root->left, 6);

    return root;
}

// TRAVERSALS

void inorder(struct Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// END TRAVERSALS

int main() {
    struct Node *root = create_test_tree();
    printf("\nInorder\n");
    inorder(root);
    printf("\nPreorder\n");
    preorder(root);
    printf("\nPostorder\n");
    postorder(root);
}