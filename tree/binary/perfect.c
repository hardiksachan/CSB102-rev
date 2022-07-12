#include <stdbool.h>
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
    insert_left(root, 2);
    insert_right(root, 3);

    // left
    insert_left(root->left, 4);
    insert_right(root->left, 5);

    // right
    insert_left(root->right, 6);
    insert_right(root->right, 7);

    return root;
}

int height(struct Node *root) {
    int h = 0;
    while (root != NULL) {
        root = root->left;
        h++;
    }

    return h;
}

int is_perfect(struct Node *root, int h, int level) {
    if (root == NULL) return true;

    if (root->left == NULL && root->right == NULL) return (h == level + 1);

    if (root->left != NULL && root->right != NULL)
        return is_perfect(root->left, h, level + 1) &&
               is_perfect(root->right, h, level + 1);
    return false;
}


int main() {
    struct Node *root = create_test_tree();
    printf("%d\n", is_perfect(root, height(root), 0));
    return 0;
}