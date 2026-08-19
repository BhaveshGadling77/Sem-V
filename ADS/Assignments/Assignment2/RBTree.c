#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int val;
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct RBTree {
    Node* root;
    Node* NIL; // Sentinel leaf node
} RBTree;

// --- Node & Tree Utilities ---

Node* create_node(RBTree* tree, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return NULL;

    new_node->val = val;
    new_node->color = RED;
    new_node->left = tree->NIL;
    new_node->right = tree->NIL;
    new_node->parent = tree->NIL;
    return new_node;
}

RBTree* create_tree() {
    RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
    tree->NIL = (Node*)malloc(sizeof(Node));
    tree->NIL->color = BLACK;
    tree->NIL->val = 0;
    tree->NIL->left = NULL;
    tree->NIL->right = NULL;
    tree->NIL->parent = NULL;
    tree->root = tree->NIL;
    return tree;
}

void free_tree_helper(RBTree* tree, Node* node) {
    if (node == tree->NIL) return;
    free_tree_helper(tree, node->left);
    free_tree_helper(tree, node->right);
    free(node);
}

void free_tree(RBTree* tree) {
    free_tree_helper(tree, tree->root);
    free(tree->NIL);
    free(tree);
}

// --- Rotations ---

void left_rotate(RBTree* tree, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != tree->NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == tree->NIL)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void right_rotate(RBTree* tree, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != tree->NIL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == tree->NIL)
        tree->root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

// --- Insertion & Fixing Properties ---

void insert_fixup(RBTree* tree, Node* z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right; // Uncle

            if (y->color == RED) { // Case 1: Uncle is Red
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) { // Case 2: Triangle -> Line
                    z = z->parent;
                    left_rotate(tree, z);
                }
                // Case 3: Line configuration
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(tree, z->parent->parent);
            }
        } else { // Symmetric cases for right parent
            Node* y = z->parent->parent->left; // Uncle

            if (y->color == RED) { // Case 1
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) { // Case 2
                    z = z->parent;
                    right_rotate(tree, z);
                }
                // Case 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(tree, z->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

void insert(RBTree* tree, int data) {
    Node* z = create_node(tree, data);
    Node* y = tree->NIL;
    Node* x = tree->root;

    while (x != tree->NIL) {
        y = x;
        if (z->val < x->val)
            x = x->left;
        else if (z->val > x->val)
            x = x->right;
        else {
            // Duplicate value found: discard
            free(z);
            return;
        }
    }

    z->parent = y;
    if (y == tree->NIL)
        tree->root = z;
    else if (z->val < y->val)
        y->left = z;
    else
        y->right = z;

    insert_fixup(tree, z);
}

// --- Traversals ---

void preorder_traversal(RBTree* tree, Node* root) {
    if (root == tree->NIL)
        return;

    printf("%d(%s) ", root->val, root->color == RED ? "RED" : "BLACK");
    preorder_traversal(tree, root->left);
    preorder_traversal(tree, root->right);
}

// --- Main Executable ---

int main() {
    RBTree* tree = create_tree();

    // Inserting integers into Red-Black Tree
    insert(tree, 10);
    insert(tree, 20);
    insert(tree, 30);
    insert(tree, 15);
    insert(tree, 25);
    insert(tree, 5);
    insert(tree, 1);

    printf("Preorder Traversal (Node Value and Color):\n");
    preorder_traversal(tree, tree->root);
    printf("\n");

    free_tree(tree);
    return 0;
}
