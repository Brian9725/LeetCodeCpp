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
			//��first��һ���ҵ���һ���к��ӵĽ��
			while (first && !first->left && !first->right) {
				first = first->next;
			}
			//�����һ��û���к��ӵĽ�㣬˵�������һ��
			if (!first)
				break;
			Node *tempFirst = first;
			//first��Ϊ��һ�������߽��
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

	/*�ݹ鷽��
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
			//�����������Һ��ӣ���Ϊ��������ʱ���ܻ���ʵ��Һ��ӵ�next
			connect(root->right);
			connect(root->left);
		}
		return root;
	}
	*/
};