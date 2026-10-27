#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    bool color; //true -> black, false -> red
    Node *left, *right, *parent;
	
	Node(int data) {
		this->data = data;
		this->color = false;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
};

class RedBlackTree {
private:
	Node* root;
	/* left rotation algorithm:- 
	 * suppose the tree is this 10
	 * 							  \ 
	 * 							   20
	 * 							     \
	 * 							      30
	 * what we will do suppose we detach the 10 somehow
	 * suppose we are given x = 10;
	 * step 1: detach the 10;
	 * step 2: make the 20 root;
	 * step 3: attach node 10 correctly.
	 */ 
	void _leftRot(Node* x) {
		Node* y = x->right;

		x->right = y->left;

    	if (y->left != nullptr)
        	y->left->parent = x;

    	y->parent = x->parent;

    	if (x->parent == nullptr)
        	root = y;
    	else if (x == x->parent->left)
       		x->parent->left = y;
    	else
        	x->parent->right = y;

	    y->left = x;
    	x->parent = y;
	}

	void _rightRot(Node* x) {
	}
	
};
