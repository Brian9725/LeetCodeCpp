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
				//���ӵ�nextΪ�Һ���
				curr->left->next = curr->right;
				//�Һ��ӵ�nextΪ���ڵ�next������
				if (curr->next)
					curr->right->next = curr->next->left;
				curr = curr->next;
			}
			first = first->left;
		}
		return root;
	}

	/*�ݹ鷽��
	void dfs(Node* node) {
		if (node->left) {
			//���ӵ�nextΪ�Һ���
			node->left->next = node->right;
			//�Һ��ӵ�nextΪ���ڵ�next������
			if (node->next) {
				node->right->next = node->next->left;
			}
			dfs(node->left);
			dfs(node->right);
		}
	}

	Node* connect(Node* root) {
		if (root != NULL) 
			dfs(root);
		return root;
	}
	*/
};