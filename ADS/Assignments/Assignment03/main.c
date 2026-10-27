#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char key[20];
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node* createNode(const char *key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->key, key);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

struct Node* insert(struct Node* node, const char *key) {
    if (node == NULL)
        return createNode(key);

    int cmp = strcmp(key, node->key);

    if (cmp < 0)
        node->left = insert(node->left, key);
    else if (cmp > 0)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(key, node->left->key) < 0)
        return rightRotate(node);

    if (balance < -1 && strcmp(key, node->right->key) > 0)
        return leftRotate(node);

    if (balance > 1 && strcmp(key, node->left->key) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(key, node->right->key) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void printTree(struct Node *root, int space) {
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%s\n", root->key);

    printTree(root->left, space);
}

void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%s ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    const char *months[] = {
        "December", "January", "April", "March", "July",
        "August", "October", "February", "November", "May", "June"
    };

    int n = sizeof(months) / sizeof(months[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, months[i]);
    }

    printf("Pre-order traversal:\n");
    preOrder(root);
    printf("\n\n2D Tree Structure (sideways):\n");
    printTree(root, 0);

    return 0;
}
