#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Structure Definitions ---

typedef struct Node {
    char* val;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Stack {
    Node** data;
    int top;
    int capacity;
} Stack;

typedef struct Queue {
    Node** data;
    int front;
    int rear;
    int capacity;
} Queue;

// --- Node Helper Functions ---

Node* create_node(const char* val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return NULL;
    
    // Allocate memory for the string length + 1 for null terminator
    new_node->val = (char*)malloc(strlen(val) + 1);
    if (!new_node->val) {
        free(new_node);
        return NULL;
    }

    strcpy(new_node->val, val); 
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void free_tree(Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->val); // Free dynamically allocated string memory
    free(root);
}

// --- Tree Operations ---

void add(const char* data, Node** root) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    Node* temp = *root;
    while (1) {
        int cmp = strcmp(data, temp->val);
        if (cmp < 0) {
            if (temp->left == NULL) {
                temp->left = create_node(data);
                return;
            }
            temp = temp->left;
        } else if (cmp > 0) {
            if (temp->right == NULL) {
                temp->right = create_node(data);
                return;
            }
            temp = temp->right;
        } else {
            return; // Duplicate string value
        }
    }
}

Node* search(Node* root, const char* data) {
    Node* temp = root;
    while (temp != NULL) {
        int cmp = strcmp(data, temp->val);
        if (cmp < 0)
            temp = temp->left;
        else if (cmp > 0)
            temp = temp->right;
        else
            return temp;
    }
    return NULL;
}

const char* maxi(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root->val;
}

const char* mini(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root->val;
}

static inline int max_int(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max_int(height(root->left), height(root->right));
}

// --- Recursive Traversals ---

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%s ", root->val);
    inorder(root->right);
}

void preorderRec(Node* root) {
    if (root == NULL)
        return;

    printf("%s ", root->val);
    preorderRec(root->left);
    preorderRec(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%s ", root->val);
}

// --- Stack Utilities & Iterative Preorder Traversal ---

Stack* create_stack(int capacity) {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->capacity = capacity;
    st->top = -1;
    st->data = (Node**)malloc(sizeof(Node*) * capacity);
    return st;
}

void push(Stack* st, Node* node) {
    if (st->top == st->capacity - 1) {
        st->capacity *= 2;
        st->data = (Node**)realloc(st->data, sizeof(Node*) * st->capacity);
    }
    st->data[++st->top] = node;
}

Node* pop(Stack* st) {
    if (st->top == -1) return NULL;
    return st->data[st->top--];
}

int is_stack_empty(Stack* st) {
    return st->top == -1;
}

void free_stack(Stack* st) {
    free(st->data);
    free(st);
}

void preorderIte(Node* root) {
    if (root == NULL)
        return;

    Stack* st = create_stack(16);
    push(st, root);

    while (!is_stack_empty(st)) {
        Node* curr = pop(st);

        printf("%s ", curr->val);

        if (curr->right)
            push(st, curr->right);
        if (curr->left)
            push(st, curr->left);
    }

    free_stack(st);
}

// --- Queue Utilities & Levelorder / Tree Visualization ---

Queue* create_queue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->data = (Node**)malloc(sizeof(Node*) * capacity);
    return q;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear == q->capacity) {
        q->capacity *= 2;
        q->data = (Node**)realloc(q->data, sizeof(Node*) * q->capacity);
    }
    q->data[q->rear++] = node;
}

Node* dequeue(Queue* q) {
    if (q->front == q->rear) return NULL;
    return q->data[q->front++];
}

int queue_size(Queue* q) {
    return q->rear - q->front;
}

int is_queue_empty(Queue* q) {
    return q->front == q->rear;
}

void free_queue(Queue* q) {
    free(q->data);
    free(q);
}

void levelorder(Node* root) {
    if (root == NULL)
        return;

    Queue* q = create_queue(16);
    enqueue(q, root);

    while (!is_queue_empty(q)) {
        Node* curr = dequeue(q);

        printf("%s ", curr->val);

        if (curr->left)
            enqueue(q, curr->left);
        if (curr->right)
            enqueue(q, curr->right);
    }

    free_queue(q);
}

void printTree(Node* root) {
    if (root == NULL)
        return;

    int h = height(root);
    Queue* q = create_queue(32);
    enqueue(q, root);

    int level = 0;

    while (!is_queue_empty(q)) {
        int nodes = queue_size(q);
        int firstSpace = (1 << (h - level)) - 1;
        int betweenSpace = (1 << (h - level + 1)) - 1;

        for (int i = 0; i < firstSpace; i++)
            printf(" ");

        while (nodes--) {
            Node* curr = dequeue(q);

            if (curr) {
                printf("%s", curr->val);
                enqueue(q, curr->left);
                enqueue(q, curr->right);
            } else {
                printf(" ");
                enqueue(q, NULL);
                enqueue(q, NULL);
            }

            for (int i = 0; i < betweenSpace; i++)
                printf(" ");
        }

        printf("\n\n");

        level++;
        if (level == h)
            break;
    }

    free_queue(q);
}

// --- Main Executable ---

int main() {
    Node* root = NULL;

    // Building the binary search tree with strings (Lexicographical ordering)
    add("Mango", &root);
    add("Apple", &root);
    add("Peach", &root);
    add("Banana", &root);
    add("Grape", &root);
    add("Orange", &root);
    add("Plum", &root);

    printf("Visualized Tree Layout:\n");
    printTree(root);

    printf("Inorder Traversal (Alphabetical Order): ");
    inorder(root);
    printf("\n");

    printf("Preorder Recursive: ");
    preorderRec(root);
    printf("\n");

    printf("Preorder Iterative: ");
    preorderIte(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Levelorder Traversal: ");
    levelorder(root);
    printf("\n");

    printf("\nTree Statistics:\n");
    printf("Height: %d\n", height(root));
    printf("Min Value (Lexicographically First): %s\n", mini(root));
    printf("Max Value (Lexicographically Last): %s\n", maxi(root));

    const char* target = "Grape";
    Node* result = search(root, target);
    if (result) {
        printf("Search \"%s\": Found\n", target);
    } else {
        printf("Search \"%s\": Not Found\n", target);
    }

    // Clean up allocated tree nodes and string buffers
    free_tree(root);

    return 0;
}

