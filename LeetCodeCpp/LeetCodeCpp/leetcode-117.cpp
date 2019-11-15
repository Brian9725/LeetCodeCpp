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
		Node* first = root;
		while (first) {
			//在first这一层找到第一个有孩子的结点
			while (first && !first->left && !first->right) {
				first = first->next;
			}
			//如果这一层没有有孩子的结点，说明是最后一层
			if (!first)
				break;
			Node *tempFirst = first;
			//first成为下一层的最左边结点
			first = (first->left) ? first->left : first->right;
			while (tempFirst) {
				if (!tempFirst->left && !tempFirst->right) {
					tempFirst = tempFirst->next;
					continue;
				}
				if (tempFirst->left && tempFirst->right)
					tempFirst->left->next = tempFirst->right;
				Node *temp = (tempFirst->right) ? tempFirst->right : tempFirst->left;
				Node *head = tempFirst->next;
				while (head != NULL && (head->left == NULL && head->right == NULL)) {
					head = head->next;
				}
				if (head != NULL)
					temp->next = (head->left != NULL) ? head->left : head->right;
				tempFirst = tempFirst->next;
			}
		}
		return root;
	}

	/*递归方法
	Node* connect(Node* root) {
		if (root != NULL && (root->left != NULL || root->right != NULL)) {
			if (root->left != NULL && root->right != NULL)
				root->left->next = root->right;
			Node* temp = (root->right != NULL) ? root->right : root->left;
			Node* head = root->next;
			while (head != NULL && (head->left == NULL && head->right == NULL)) {
				head = head->next;
			}
			if (head != NULL)
				temp->next = (head->left != NULL) ? head->left : head->right;
			//必须先连接右孩子，因为连接左孩子时可能会访问到右孩子的next
			connect(root->right);
			connect(root->left);
		}
		return root;
	}
	*/
};