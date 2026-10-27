#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define ID_LEN 32
#define DEST_LEN 64
#define TIME_LEN 16

typedef struct {
    char id[ID_LEN];
    char destination[DEST_LEN];
    int priority;               /* Smaller number = higher priority */
    int deadlineMinutes;        /* Minutes after midnight, e.g. 10:30 = 630 */
} Truck;

typedef struct BinomialNode {
    Truck truck;
    int degree;
    struct BinomialNode *parent;
    struct BinomialNode *child;
    struct BinomialNode *sibling;
} BinomialNode;

typedef struct {
    BinomialNode *head;
} BinomialHeap;

static void initHeap(BinomialHeap *heap) {
    heap->head = NULL;
}

static int compareTrucks(const Truck *a, const Truck *b) {
    if (a->priority != b->priority)
        return (a->priority < b->priority) ? -1 : 1;
    if (a->deadlineMinutes != b->deadlineMinutes)
        return (a->deadlineMinutes < b->deadlineMinutes) ? -1 : 1;
    return strcmp(a->id, b->id);
}

static BinomialNode *createNode(const Truck *truck) {
    BinomialNode *node = malloc(sizeof(*node));
    if (!node) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    node->truck = *truck;
    node->degree = 0;
    node->parent = node->child = node->sibling = NULL;
    return node;
}

/* Make child a child of parent. Both roots must have the same degree. */
static void linkTrees(BinomialNode *child, BinomialNode *parent) {
    child->parent = parent;
    child->sibling = parent->child;
    parent->child = child;
    parent->degree++;
}

/* Merge two root lists by increasing tree degree. */
static BinomialNode *mergeRootLists(BinomialNode *a, BinomialNode *b) {
    BinomialNode dummy;
    BinomialNode *tail = &dummy;
    dummy.sibling = NULL;

    while (a && b) {
        if (a->degree <= b->degree) {
            tail->sibling = a;
            a = a->sibling;
        } else {
            tail->sibling = b;
            b = b->sibling;
        }
        tail = tail->sibling;
    }
    tail->sibling = a ? a : b;
    return dummy.sibling;
}

/* Union heaps; consumes heap b and leaves it empty. */
static void unionHeaps(BinomialHeap *a, BinomialHeap *b) {
    BinomialNode *prev, *curr, *next;

    a->head = mergeRootLists(a->head, b->head);
    b->head = NULL;

    if (!a->head)
        return;

    prev = NULL;
    curr = a->head;
    next = curr->sibling;

    while (next) {
        if (curr->degree != next->degree ||
            (next->sibling && next->sibling->degree == curr->degree)) {
            prev = curr;
            curr = next;
        } else if (compareTrucks(&curr->truck, &next->truck) <= 0) {
            curr->sibling = next->sibling;
            linkTrees(next, curr);
        } else {
            if (prev)
                prev->sibling = next;
            else
                a->head = next;
            linkTrees(curr, next);
            curr = next;
        }
        next = curr->sibling;
    }
}

static int insertTruck(BinomialHeap *heap, const Truck *truck) {
    BinomialHeap one;
    BinomialNode *node = createNode(truck);
    one.head = node;
    unionHeaps(heap, &one);
    return 1;
}

static BinomialNode *findNode(BinomialNode *root, const char *id) {
    BinomialNode *found;
    if (!root)
        return NULL;
    if (strcmp(root->truck.id, id) == 0)
        return root;
    found = findNode(root->child, id);
    if (found)
        return found;
    return findNode(root->sibling, id);
}

static BinomialNode *findMinRoot(BinomialHeap *heap, BinomialNode **previousOut) {
    BinomialNode *curr = heap->head, *prev = NULL;
    BinomialNode *minNode = NULL, *minPrev = NULL;

    while (curr) {
        if (!minNode || compareTrucks(&curr->truck, &minNode->truck) < 0) {
            minNode = curr;
            minPrev = prev;
        }
        prev = curr;
        curr = curr->sibling;
    }
    if (previousOut)
        *previousOut = minPrev;
    return minNode;
}

static int findNextTruck(BinomialHeap *heap, Truck *out) {
    BinomialNode *minNode = findMinRoot(heap, NULL);
    if (!minNode)
        return 0;
    *out = minNode->truck;
    return 1;
}

static void reverseRootList(BinomialNode *node, BinomialNode **reversed) {
    BinomialNode *prev = NULL, *next;
    while (node) {
        next = node->sibling;
        node->sibling = prev;
        node->parent = NULL;
        prev = node;
        node = next;
    }
    *reversed = prev;
}

/* Remove and return the highest-precedence truck. */
static int dispatchNextTruck(BinomialHeap *heap, Truck *out) {
    BinomialNode *prevMin = NULL;
    BinomialNode *minNode = findMinRoot(heap, &prevMin);
    BinomialNode *children = NULL;
    BinomialHeap childHeap;

    if (!minNode)
        return 0;

    *out = minNode->truck;

    if (prevMin)
        prevMin->sibling = minNode->sibling;
    else
        heap->head = minNode->sibling;

    reverseRootList(minNode->child, &children);
    childHeap.head = children;
    unionHeaps(heap, &childHeap);
    free(minNode);
    return 1;
}

/*
 * Decrease priority (make a truck more urgent).
 * Searches by ID in O(n); bubbling the key upward is O(log n).
 */
static int decreaseTruckPriority(BinomialHeap *heap, const char *id, int newPriority) {
    BinomialNode *node = findNode(heap->head, id);
    if (!node || newPriority > node->truck.priority)
        return 0;

    node->truck.priority = newPriority;
    while (node->parent &&
           compareTrucks(&node->truck, &node->parent->truck) < 0) {
        Truck temp = node->truck;
        node->truck = node->parent->truck;
        node->parent->truck = temp;
        node = node->parent;
    }
    return 1;
}

static void printTruck(const Truck *truck) {
    int h = truck->deadlineMinutes / 60;
    int m = truck->deadlineMinutes % 60;
    printf("ID: %-10s Destination: %-20s Priority: %-3d Deadline: %02d:%02d\n",
           truck->id, truck->destination, truck->priority, h, m);
}

static void printTree(BinomialNode *node) {
    while (node) {
        printTruck(&node->truck);
        printTree(node->child);
        node = node->sibling;
    }
}

static void displayHeap(BinomialHeap *heap) {
    BinomialNode *root = heap->head;
    if (!root) {
        puts("No trucks in this hub.");
        return;
    }
    puts("Trucks in heap (tree traversal; not globally sorted):");
    while (root) {
        printf("-- Binomial tree of degree %d --\n", root->degree);
        printTree(root);
        root = root->sibling;
    }
}

/* Copy a heap without changing the original, used for sorted display. */
static BinomialNode *cloneTree(BinomialNode *source, BinomialNode *parent) {
    BinomialNode *copy;
    if (!source)
        return NULL;
    copy = createNode(&source->truck);
    copy->degree = source->degree;
    copy->parent = parent;
    copy->child = cloneTree(source->child, copy);
    copy->sibling = cloneTree(source->sibling, parent);
    return copy;
}

static void freeForest(BinomialNode *node) {
    while (node) {
        BinomialNode *next = node->sibling;
        freeForest(node->child);
        free(node);
        node = next;
    }
}

static void displayInSchedulingOrder(BinomialHeap *heap) {
    BinomialHeap copy;
    Truck truck;
    int any = 0;
    copy.head = cloneTree(heap->head, NULL);
    puts("Pending trucks in scheduling order:");
    while (dispatchNextTruck(&copy, &truck)) {
        printTruck(&truck);
        any = 1;
    }
    if (!any)
        puts("No trucks in this hub.");
    freeForest(copy.head);
}

/*
 * Simple route split: move trucks whose destination matches destination
 * into the new heap. This rebuilds heaps and is intentionally not an
 * intrinsic O(log n) binomial-heap operation.
 */
static void splitByDestination(BinomialHeap *source, BinomialHeap *route,
                               const char *destination) {
    BinomialHeap keep;
    Truck truck;
    initHeap(&keep);
    while (dispatchNextTruck(source, &truck)) {
        if (strcmp(truck.destination, destination) == 0)
            insertTruck(route, &truck);
        else
            insertTruck(&keep, &truck);
    }
    source->head = keep.head;
}

/* Read one line safely and remove the trailing newline. */
static void readLine(const char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    if (!fgets(buffer, (int)size, stdin)) {
        puts("\nInput ended.");
        exit(EXIT_SUCCESS);
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

static int readInt(const char *prompt) {
    char line[64], *end;
    long value;
    for (;;) {
        readLine(prompt, line, sizeof(line));
        value = strtol(line, &end, 10);
        while (*end == ' ' || *end == '\t')
            end++;
        if (end != line && *end == '\0' && value >= INT_MIN && value <= INT_MAX)
            return (int)value;
        puts("Please enter a valid integer.");
    }
}

static int readTimeMinutes(const char *prompt) {
    char line[TIME_LEN];
    int h, m;
    char extra;
    for (;;) {
        readLine(prompt, line, sizeof(line));
        if (sscanf(line, "%d:%d%c", &h, &m, &extra) == 2 &&
            h >= 0 && h <= 23 && m >= 0 && m <= 59)
            return h * 60 + m;
        puts("Enter time in 24-hour HH:MM format, e.g. 09:45.");
    }
}

static int idExists(BinomialHeap *heap, const char *id) {
    return findNode(heap->head, id) != NULL;
}

static int addTruckFromInput(BinomialHeap *heap) {
    Truck truck;
    readLine("Truck ID: ", truck.id, sizeof(truck.id));
    if (truck.id[0] == '\0') {
        puts("Truck ID cannot be empty.");
        return 0;
    }
    if (idExists(heap, truck.id)) {
        puts("That truck ID already exists in this hub.");
        return 0;
    }
    readLine("Destination: ", truck.destination, sizeof(truck.destination));
    truck.priority = readInt("Priority (smaller = more urgent): ");
    truck.deadlineMinutes = readTimeMinutes("Deadline (HH:MM): ");
    insertTruck(heap, &truck);
    puts("Truck registered.");
    return 1;
}

static void printMenu(void) {
    puts("\n=== Truck Scheduling System (Binomial Heap) ===");
    puts("1. Register truck in Hub A");
    puts("2. Register truck in Hub B");
    puts("3. Find next truck in a hub");
    puts("4. Dispatch next truck from a hub");
    puts("5. Make a truck more urgent (decrease priority)");
    puts("6. Merge Hub B into Hub A");
    puts("7. Display a hub's heap");
    puts("8. Display a hub in scheduling order");
    puts("9. Split trucks by destination from Hub A into Route C");
    puts("0. Exit");
}

int main(void) {
    BinomialHeap hubA, hubB, routeC;
    int choice, hubChoice;
    char id[ID_LEN], destination[DEST_LEN];
    Truck truck;

    initHeap(&hubA);
    initHeap(&hubB);
    initHeap(&routeC);

    for (;;) {
        printMenu();
        choice = readInt("Choose an option: ");
        switch (choice) {
            case 1:
                addTruckFromInput(&hubA);
                break;
            case 2:
                addTruckFromInput(&hubB);
                break;
            case 3: {
                hubChoice = readInt("Choose hub (1=A, 2=B, 3=C): ");
                BinomialHeap *hub = hubChoice == 1 ? &hubA :
                                    hubChoice == 2 ? &hubB :
                                    hubChoice == 3 ? &routeC : NULL;
                if (!hub) {
                    puts("Invalid hub.");
                } else if (findNextTruck(hub, &truck)) {
                    puts("Next truck:");
                    printTruck(&truck);
                } else {
                    puts("No trucks in this hub.");
                }
                break;
            }
            case 4: {
                hubChoice = readInt("Choose hub (1=A, 2=B, 3=C): ");
                BinomialHeap *hub = hubChoice == 1 ? &hubA :
                                    hubChoice == 2 ? &hubB :
                                    hubChoice == 3 ? &routeC : NULL;
                if (!hub) {
                    puts("Invalid hub.");
                } else if (dispatchNextTruck(hub, &truck)) {
                    puts("Truck dispatched:");
                    printTruck(&truck);
                } else {
                    puts("No trucks to dispatch.");
                }
                break;
            }
            case 5:
                readLine("Truck ID: ", id, sizeof(id));
                hubChoice = readInt("Choose hub (1=A, 2=B, 3=C): ");
                {
                    BinomialHeap *hub = hubChoice == 1 ? &hubA :
                                        hubChoice == 2 ? &hubB :
                                        hubChoice == 3 ? &routeC : NULL;
                    int priority;
                    if (!hub) {
                        puts("Invalid hub.");
                        break;
                    }
                    priority = readInt("New priority (must be <= current priority): ");
                    if (decreaseTruckPriority(hub, id, priority))
                        puts("Priority updated.");
                    else
                        puts("Truck not found, or new priority is not more urgent.");
                }
                break;
            case 6:
                unionHeaps(&hubA, &hubB);
                puts("Hub B's queue merged into Hub A. Hub B is now empty.");
                break;
            case 7:
                hubChoice = readInt("Choose hub (1=A, 2=B, 3=C): ");
                if (hubChoice == 1) displayHeap(&hubA);
                else if (hubChoice == 2) displayHeap(&hubB);
                else if (hubChoice == 3) displayHeap(&routeC);
                else puts("Invalid hub.");
                break;
            case 8:
                hubChoice = readInt("Choose hub (1=A, 2=B, 3=C): ");
                if (hubChoice == 1) displayInSchedulingOrder(&hubA);
                else if (hubChoice == 2) displayInSchedulingOrder(&hubB);
                else if (hubChoice == 3) displayInSchedulingOrder(&routeC);
                else puts("Invalid hub.");
                break;
            case 9:
                readLine("Destination to move into Route C: ",
                         destination, sizeof(destination));
                splitByDestination(&hubA, &routeC, destination);
                puts("Matching trucks moved from Hub A into Route C.");
                break;
            case 0:
                freeForest(hubA.head);
                freeForest(hubB.head);
                freeForest(routeC.head);
                puts("Goodbye.");
                return 0;
            default:
                puts("Invalid option.");
        }
    }
}
