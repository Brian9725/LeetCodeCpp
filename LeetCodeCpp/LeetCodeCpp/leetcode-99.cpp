#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//�жϽ��ֵ�Ĵ�С
	bool cmp(TreeNode* first, TreeNode* second) {
		if (first == NULL || second == NULL)
			return false;
		return first->val > second->val;
	}

	//ָ��Ҳ�Ǳ�������Ҫ�����ô��ݻ򴫵�ָ���ָ������ں����иı�ָ���ֵ
	bool chnode(TreeNode*& first, TreeNode*& second, TreeNode*& cur) {
		if (!cmp(first, second)) {
			first = second; second = cur;
		}
		else {
			if (cur->val < second->val) {
				second = cur; return true;
			}
			else if (cur->val > first->val)
				return true;
			else 
				second = cur;
		}
		return false;
	}

	//������������Morris����
	void recoverTree(TreeNode* root) {
		TreeNode* first = NULL, *second = NULL, *cur = root, *pre = NULL;
		bool flag = false;
		while (cur != NULL) {
			//�����ǰ�������ΪNULL�����ѱ�������ǰ���
			if (cur->left == NULL) {
				if (!flag) {
					flag = chnode(first, second, cur);
				}
				cur = cur->right; continue;
			}
			//�����ǰ������Ӳ�ΪNULL�������������ҵ���ǰ��
			pre = cur->left;
			while (pre->right != NULL && pre->right != cur) {
				pre = pre->right;
			}
			//���ǰ�����Һ���ΪNULL��������Ϊ��ǰ���
			if (pre->right == NULL) {
				pre->right = cur; cur = cur->left;
			}
			else {
				pre->right = NULL;
				if (!flag) {
					flag = chnode(first, second, cur);
				}
				cur = cur->right;
			}
		}
		if (first->val > second->val) {
			int temp = first->val; 
			first->val = second->val; 
			second->val = temp;
		}
	}
};