#include<stdio.h>
#include<stdlib.h>

typedef struct Treap {
	int taskID;
	int priority;
	struct Treap *left;
	struct Treap *right;
} Treap;

/* Use Treap to implement a priority-based task scheduler where each task has a unique ID (key) and a
priority. Higher-priority tasks should be completed first while maintaining the properties of a Binary
Search Tree (BST). feature to change the priority of a particular node.
*/

Treap* insert(Treap* root, int taskID, int priority) {

    // Normal BST insertion
	
    if (root == NULL) {
		Treap *temp = malloc(sizeof(Treap));
		temp->taskID = taskID;
		temp->priority = priority;
        return temp;
	}

    if (taskID < root->taskID) {

        root->left = insert(root->left, taskID, priority);
        // Heap property violated
        if (root->left->priority > root->priority)
			root = rotateRight(root);
    } 
    else if (taskID > root->taskID) {
    	root->right = insert(root->right, taskID, priority);
    	// Heap property violated
    	if (root->right->priority > root->priority)
			root = rotateLeft(root);
    }
    return root;
}

void print(Treap* t) {

}

// execute highest priority task.
Treap* executeHighestPriority(Treap*& root) {

    if (root == NULL) {
        cout << "No tasks available\n";
        return NULL;
    }

    Treap* task = root;

    cout << "Executing Task ID: "
         << task->taskID
         << " Priority: "
         << task->priority << endl;

    // Remove root
    root = erase(root, root->taskID);

    return task;
}
int main() {
	Treap *t = malloc(sizeof(Treap));
	
	t = insert(t, 101, 40);
    t = insert(t, 102, 80);
    t = insert(t, 103, 30);
    t = insert(t, 104, 100);
    t = insert(t, 105, 60);
}
