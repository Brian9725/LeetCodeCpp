#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (!root)
			return root;
		Node* first = root;
		while (first->left) {
			Node* curr = first;
			while (curr) {
				//左孩子的next为右孩子
				curr->left->next = curr->right;
				//右孩子的next为父节点next的左孩子
				if (curr->next)
					curr->right->next = curr->next->left;
				curr = curr->next;
			}
			first = first->left;
		}
		return root;
	}

	/*递归方法
	Node* connect(Node* root) {
		if (root != NULL && root->left != NULL) {
			//左孩子的next为右孩子
			root->left->next = root->right;
			//右孩子的next为父节点next的左孩子
			if (root->next) {
				root->right->next = root->next->left;
			}
			connect(root->left);
			connect(root->right);
		}
		return root;
	}
	*/
};