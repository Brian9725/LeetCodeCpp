#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//�ҵ�[begin..end)���е�
	ListNode* findMid(ListNode* begin, ListNode* end) {
		ListNode *mid = begin;
		while (begin != NULL && begin->next != end && 
			begin->next->next != NULL && begin->next->next != end) {
			mid = mid->next;
			begin = begin->next->next;
		}
		return mid;
	}

	//��[begin..end)����һ�ö���������
	TreeNode* buildTree(ListNode* begin, ListNode* end) {
		if (begin->next == end) {
			TreeNode* node = new TreeNode(begin->val);
			return node;
		}
		ListNode* mid = findMid(begin, end);
		TreeNode* node = new TreeNode(mid->val);
		//���mid��߻���Ԫ�أ���������������
		if (begin != mid)
			node->left = buildTree(begin, mid);
		//���mid�ұ߻���Ԫ�أ���������������
		if (mid->next != end)
			node->right = buildTree(mid->next, end);
		return node;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;
		TreeNode *root = buildTree(head, NULL);
		return root;
	}
};