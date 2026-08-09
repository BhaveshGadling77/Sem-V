#include<bits/stdc++.h>
using namespace std;
class Node {
	private:
		Node* left;
		Node* right;
		int val; // value of the Node 
	public:	
		/* this will set val = -1;
		 */ 
		Node() {
			this->left = NULL;
			this->right = NULL;
			this->val = -1;
		}
		/* this will set this.val = val;
		 */
		Node(int val) {
			this->left = NULL;
			this->right = NULL;
			this->val = val;	
		}

		void add(int data, Node* &root) {
			if (root == NULL) {
    			root = new Node(data);
    			return;
			}
			
			Node* newNode = new Node(data);
			Node* temp = root;

			while (temp != NULL) {
				if (temp->val > data) {
					if (temp->left == NULL) {
						temp->left = newNode;
						return;
					}
					temp = temp->left;
				} else if (temp->val < data) {
					if (temp->right == NULL) {
						temp->right = newNode;
						return;
					}
					temp = temp->right;
				} else {
					delete newNode;
					return;
				}
			}
		}
		/* if the node not exist in BST then it will return NULL;
		 */
		Node* search(Node* root, int data) {
			Node* temp = root;
			
			if (temp == NULL)
				return NULL;

			while (temp->right != NULL || temp->left != NULL) {
				if (temp->val > data) {
					temp = temp->left;
				} else if (temp->val < data) {
					temp = temp->right;
				} else {
					return temp;
				}

			}
			if (temp->val == data)
				return temp;

			return NULL;
		}

		int maxi(Node* root) {
			if (root == NULL)
				return INT_MIN; 
			if (root->right == NULL) 
				return root->val;
			
			return maxi(root->right);
		}

		void print(Node* root) {

		}

		void preorderRec(Node* root) {
			if (root == NULL) {
				return;
			}

			cout << root->val << " ";

			preorderRec(root->left);
			preorderRec(root->right);
		}

		void preorderIte(Node* root) {
			Node* temp = root;
			if (temp == NULL) {
				return;
			}
			stack<Node*> st;
			
			st.push(root);

			while (!st.empty()) {
				Node* val = st.top();
				cout << val->val << " ";
				st.pop();

				if (temp->left) {
					st.push(temp->left);
					temp = temp->left;
				}

				if (temp->right) {
					st.push(temp->right);
					temp = temp->right;
				}
			}
		}

		void levelorder(Node* root) {
			queue<int>q;
			
			q.push(root->val);

			while(!q.empty()) {
				
			}
		}

};
