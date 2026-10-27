#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Node {
public:
	string val;
	Node* left;
	Node* right;
	int height;

	Node(string s) : val(s), left(nullptr), right(nullptr), height(1) {}

	// ## Helper Functions

	static int getHeight(Node* n) {
		return n ? n->height : 0;
	}

	static int getBalanceFactor(Node* n) {
		return n ? getHeight(n->left) - getHeight(n->right) : 0;
	}

	/* ## Rotations
	 * Right Rotation (for LL imbalance)
	 */
	static Node* rightRotate(Node* y) {
		Node* x = y->left;
		Node* T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
		x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

		return x;
	}

	// Left Rotation (for RR imbalance)
	static Node* leftRotate(Node* x) {
		Node* y = x->right;
		Node* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
		y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

		return y;
	}


	// Recursive Insert with Rebalancing
	static Node* insert(Node* node, const string& key) {
		// 1. Standard BST Insertion
		if (node == nullptr)
			return new Node(key);

		if (key < node->val)
			node->left = insert(node->left, key);
		else if (key > node->val)
			node->right = insert(node->right, key);
		else
			return node; // Duplicates not allowed

		// 2. Update Height of current node
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));

		// 3. Get Balance Factor
		int balance = getBalanceFactor(node);

		// 4. Rebalance if node becomes unbalanced

		// Left Left (LL) Case
		if (balance > 1 && key < node->left->val)
			return rightRotate(node);

		// Right Right (RR) Case
		if (balance < -1 && key > node->right->val)
			return leftRotate(node);

		// Left Right (LR) Case
		if (balance > 1 && key > node->left->val) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left (RL) Case
		if (balance < -1 && key < node->right->val) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}

	// BST Search
	static Node* search(Node* root, const string& key) {
		if (root == nullptr || root->val == key)
			return root;

		if (key < root->val)
			return search(root->left, key);

		return search(root->right, key);
	}

	// Inorder Print (Sorted Order)
	static void printInorder(Node* root) {
		if (root == nullptr)
			return;

		printInorder(root->left);
		cout << root->val << " (H:" << root->height << ") ";
		printInorder(root->right);
	}
};

int main() {
	Node* root = nullptr;
	int choice = 0;
	string inputStr;
	while (true) {
		cout << "   AVL TREE	  \n";
		cout << "1. Insert a String\n";
		cout << "2. Search for a String\n";
		cout << "3. Display Inorder Traversal\n";
		cout << "4. Show Tree Height\n";
		cout << "5. Exit\n";
		cout << "Enter choice (1-5): ";
		
		if (!(cin >> choice)) {
			cout << "Invalid input! Exiting...\n";
			break;
		}

		switch (choice) {
			case 1:
				cout << "Enter string to insert: ";
				cin >> inputStr;
				root = Node::insert(root, inputStr);
				cout << "Success: '" << inputStr << "' processed.\n";
				break;

			case 2: {
				cout << "Enter string to search: ";
				cin >> inputStr;
				Node* result = Node::search(root, inputStr);
				if (result)
					cout << "FOUND: '" << result->val << "' (Node Height: " << result->height << ")\n";
				else
					cout << "NOT FOUND: '" << inputStr << "' is not in the tree.\n";
				break;
			}

			case 3:
				cout << "\nSorted Inorder Traversal:\n";
				if (root == nullptr)
					cout << "Tree is empty.\n";
				else {
					Node::printInorder(root);
					cout << "\n";
				}
				break;

			case 4:
				cout << "Current Tree Height: " << Node::getHeight(root) << "\n";
				break;

			case 5:
				cout << "Exiting program...\n";
				return 0;

			default:
				cout << "Invalid choice! Please enter a number between 1 and 5.\n";
		}
	}
	return 0;
}
