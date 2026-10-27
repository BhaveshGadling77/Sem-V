#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    int degree;
    struct Node *parent;
    struct Node *child;
    struct Node *prev;
    struct Node *next;
};

struct BinomialHeap {
    struct Node *head;
};

struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = val;
    newNode->degree = 0;
    newNode->parent = NULL;
    newNode->child = NULL;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

struct BinomialHeap* makeBinomialHeap() {
    struct BinomialHeap *H =
        (struct BinomialHeap*)malloc(sizeof(struct BinomialHeap));

    H->head = NULL;

    return H;
}

void insertAtBeginning(struct Node **head, struct Node *node) {
    node->prev = NULL;
    node->next = *head;

    if (*head != NULL) {
        (*head)->prev = node;
    }

    *head = node;
}

void removeNode(struct Node **head, struct Node *node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        *head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    node->prev = NULL;
    node->next = NULL;
}

void linkTrees(struct Node *y, struct Node *z) {
    y->parent = z;

    y->prev = NULL;
    y->next = z->child;

    if (z->child != NULL) {
        z->child->prev = y;
    }

    z->child = y;
    z->degree++;
}

struct Node* mergeHeaps(struct Node *h1, struct Node *h2) {
    if (h1 == NULL) {
        return h2;
    }

    if (h2 == NULL) {
        return h1;
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;

    while (h1 != NULL && h2 != NULL) {
        struct Node *temp;

        if (h1->degree <= h2->degree) {
            temp = h1;
            h1 = h1->next;
        } else {
            temp = h2;
            h2 = h2->next;
        }

        temp->prev = tail;
        temp->next = NULL;

        if (tail != NULL) {
            tail->next = temp;
        } else {
            head = temp;
        }

        tail = temp;
    }

    while (h1 != NULL) {
        struct Node *temp = h1;
        h1 = h1->next;

        temp->prev = tail;
        temp->next = NULL;

        if (tail != NULL) {
            tail->next = temp;
        } else {
            head = temp;
        }

        tail = temp;
    }

    while (h2 != NULL) {
        struct Node *temp = h2;
        h2 = h2->next;

        temp->prev = tail;
        temp->next = NULL;

        if (tail != NULL) {
            tail->next = temp;
        } else {
            head = temp;
        }

        tail = temp;
    }

    return head;
}

struct Node* unionHeaps(struct Node *h1, struct Node *h2) {
    if (h1 == NULL && h2 == NULL) {
        return NULL;
    }

    struct Node *head = mergeHeaps(h1, h2);

    if (head == NULL) {
        return NULL;
    }

    struct Node *prev_x = NULL;
    struct Node *x = head;
    struct Node *next_x = x->next;

    while (next_x != NULL) {
        if (x->degree != next_x->degree ||
            (next_x->next != NULL &&
             next_x->next->degree == x->degree)) {

            prev_x = x;
            x = next_x;
        }
        else if (x->data <= next_x->data) {
            x->next = next_x->next;

            if (next_x->next != NULL) {
                next_x->next->prev = x;
            }

            next_x->prev = NULL;
            next_x->next = NULL;

            linkTrees(next_x, x);
        }
        else {
            if (prev_x == NULL) {
                head = next_x;
            } else {
                prev_x->next = next_x;
            }

            next_x->prev = prev_x;

            x->prev = NULL;
            x->next = NULL;

            linkTrees(x, next_x);

            x = next_x;
        }

        next_x = x->next;
    }

    return head;
}

void unionBinomialHeaps(
    struct BinomialHeap *H1,
    struct BinomialHeap *H2
) {
    H1->head = unionHeaps(H1->head, H2->head);
    H2->head = NULL;
}

void insert(struct BinomialHeap *H, int val) {
    struct Node *newNode = createNode(val);

    H->head = unionHeaps(H->head, newNode);
}

struct Node* findMinimum(struct BinomialHeap *H) {
    if (H->head == NULL) {
        return NULL;
    }

    struct Node *minNode = H->head;
    struct Node *curr = H->head->next;

    while (curr != NULL) {
        if (curr->data < minNode->data) {
            minNode = curr;
        }

        curr = curr->next;
    }

    return minNode;
}

int extractMin(struct BinomialHeap *H) {
    if (H->head == NULL) {
        return INT_MIN;
    }

    struct Node *minNode = H->head;
    struct Node *curr = H->head->next;

    while (curr != NULL) {
        if (curr->data < minNode->data) {
            minNode = curr;
        }

        curr = curr->next;
    }

    if (minNode->prev != NULL) {
        minNode->prev->next = minNode->next;
    } else {
        H->head = minNode->next;
    }

    if (minNode->next != NULL) {
        minNode->next->prev = minNode->prev;
    }

    struct Node *childHead = NULL;
    struct Node *child = minNode->child;

    while (child != NULL) {
        struct Node *nextChild = child->next;

        child->parent = NULL;
        child->prev = NULL;
        child->next = childHead;

        if (childHead != NULL) {
            childHead->prev = child;
        }

        childHead = child;
        child = nextChild;
    }

    minNode->child = NULL;
    minNode->prev = NULL;
    minNode->next = NULL;

    H->head = unionHeaps(H->head, childHead);

    int minValue = minNode->data;

    free(minNode);

    return minValue;
}

struct Node* findNode(struct Node *root, int val) {
    if (root == NULL) {
        return NULL;
    }

    struct Node *curr = root;

    while (curr != NULL) {
        if (curr->data == val) {
            return curr;
        }

        struct Node *result = findNode(curr->child, val);

        if (result != NULL) {
            return result;
        }

        curr = curr->next;
    }

    return NULL;
}

void decreaseKey(
    struct BinomialHeap *H,
    int old_val,
    int new_val
) {
    struct Node *target = findNode(H->head, old_val);

    if (target == NULL) {
        printf("Node with value %d not found.\n", old_val);
        return;
    }

    if (new_val > target->data) {
        printf("New key is greater than current key.\n");
        return;
    }

    target->data = new_val;

    struct Node *curr = target;
    struct Node *parent = curr->parent;

    while (parent != NULL &&
           curr->data < parent->data) {

        int temp = curr->data;
        curr->data = parent->data;
        parent->data = temp;

        curr = parent;
        parent = curr->parent;
    }
}

void deleteKey(struct BinomialHeap *H, int val) {
    decreaseKey(H, val, INT_MIN);
    extractMin(H);
}

void displayRootList(struct BinomialHeap *H) {
    struct Node *curr = H->head;

    printf("Root List: ");

    while (curr != NULL) {
        printf("[Data=%d, Degree=%d]",
               curr->data,
               curr->degree);

        if (curr->next != NULL) {
            printf(" <-> ");
        }

        curr = curr->next;
    }

    printf("\n");
}

void freeTree(struct Node *root) {
    if (root == NULL) {
        return;
    }

    struct Node *child = root->child;

    while (child != NULL) {
        struct Node *nextChild = child->next;

        freeTree(child);

        child = nextChild;
    }

    free(root);
}

void freeHeap(struct BinomialHeap *H) {
    struct Node *curr = H->head;

    while (curr != NULL) {
        struct Node *next = curr->next;

        freeTree(curr);

        curr = next;
    }

    free(H);
}

int main() {
    struct BinomialHeap *heap1 = makeBinomialHeap();
    struct BinomialHeap *heap2 = makeBinomialHeap();

    insert(heap1, 10);
    insert(heap1, 20);
    insert(heap1, 5);

    insert(heap2, 7);
    insert(heap2, 30);
    insert(heap2, 15);

    struct Node *minNode = findMinimum(heap1);

    if (minNode != NULL) {
        printf("Minimum in Heap 1: %d\n", minNode->data);
    }

    unionBinomialHeaps(heap1, heap2);

    printf("Minimum after Union: %d\n",
           findMinimum(heap1)->data);

    printf("Extracted Min: %d\n",
           extractMin(heap1));

    printf("New Minimum: %d\n",
           findMinimum(heap1)->data);

    decreaseKey(heap1, 20, 2);

    printf("Minimum after decreasing 20 to 2: %d\n",
           findMinimum(heap1)->data);

    deleteKey(heap1, 10);

    printf("Minimum after deleting 10: %d\n",
           findMinimum(heap1)->data);

    freeHeap(heap1);
    freeHeap(heap2);

    return 0;
}
