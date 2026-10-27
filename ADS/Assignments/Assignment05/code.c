#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *arr;	   // dynamically allocated array
	int size;	  // current number of elements
	int capacity;  // total available capacity
} MaxHeap;

// initialize the heap with initial capacity = 1
MaxHeap* createHeap() {
	MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
	if (!heap) {
		printf("Memory allocation failed for heap structure.\n");
		exit(1);
	}
	heap->capacity = 1;
	heap->size = 0;
	heap->arr = (int *)malloc(heap->capacity * sizeof(int));
	if (!heap->arr) {
		printf("Memory allocation failed for heap array.\n");
		free(heap);
		exit(1);
	}
	return heap;
}

// insert function using array doubling
void insert(MaxHeap *heap, int value) {
	if (heap->size == heap->capacity) {
		heap->capacity *= 2;
		int *temp = (int *)realloc(heap->arr, heap->capacity * sizeof(int));
		if (!temp) {
			printf("Reallocation failed!\n");
			return;
		}
		heap->arr = temp;
		printf("-> [Capacity doubled to %d]\n", heap->capacity);
	}

	int i = heap->size;
	heap->arr[i] = value;
	heap->size++;

	// heapify 
	while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
		int temp = heap->arr[i];
		heap->arr[i] = heap->arr[(i - 1) / 2];
		heap->arr[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
	}
	printf("Successfully inserted %d\n", value);
}

// delete root maximum element
int deleteMax(MaxHeap *heap) {
	if (heap->size <= 0) {
		printf("Heap Underflow! Heap is empty.\n");
		return -1;
	}

	int root = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;

	//down heapify 
	int i = 0;
	while (1) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int largest = i;

		if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
			largest = left;
		}
		if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
			largest = right;
		}

		if (largest == i) {
			break;
		}

		int temp = heap->arr[i];
		heap->arr[i] = heap->arr[largest];
		heap->arr[largest] = temp;
		i = largest;
	}

	return root;
}

// Function to display the max heap as a tree structure
void printHeap(MaxHeap *heap, int index, int space) {
    if (index >= heap->size) {
        return;
    }

    // Increase distance between levels
    space += 6;

    // Process right child first (printed at top)
    printHeap(heap, 2 * index + 2, space);

    // Print current node after spaces
    printf("\n");
    for (int i = 6; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", heap->arr[index]);

    // Process left child (printed at bottom)
    printHeap(heap, 2 * index + 1, space);
}
// free allocated memory
void freeHeap(MaxHeap *heap) {
	if (heap) {
		free(heap->arr);
		heap->arr = NULL;
		free(heap);
	}
}

int main() {
	MaxHeap *heap = createHeap();
	int choice, val, deletedVal;

	while (1) {
		printf("\n=== MAX HEAP OPERATIONS ===\n");
		printf("1. Insert\n");
		printf("2. Delete Max\n");
		printf("3. Display Heap\n");
		printf("4. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter integer value to insert: ");
				scanf("%d", &val);
				insert(heap, val);
				break;

			case 2:
				deletedVal = deleteMax(heap);
				if (deletedVal != -1) {
					printf("Deleted Maximum Element: %d\n", deletedVal);
				}
				break;

			case 3:
				printHeap(heap, 0, 2);
				break;

			case 4:
				freeHeap(heap);
				printf("Exiting program and freeing memory...\n");
				return 0;

			default:
				printf("Invalid choice! Try again.\n");
		}
	}
}
