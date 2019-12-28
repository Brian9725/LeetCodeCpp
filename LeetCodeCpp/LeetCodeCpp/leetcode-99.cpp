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
	//判断结点值的大小
	bool cmp(TreeNode* first, TreeNode* second) {
		if (first == NULL || second == NULL)
			return false;
		return first->val > second->val;
	}

	//指针也是变量，需要按引用传递或传递指针的指针才能在函数中改变指针的值
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

	//线索二叉树，Morris遍历
	void recoverTree(TreeNode* root) {
		TreeNode* first = NULL, *second = NULL, *cur = root, *pre = NULL;
		bool flag = false;
		while (cur != NULL) {
			//如果当前结点左孩子为NULL，则已遍历到当前结点
			if (cur->left == NULL) {
				if (!flag) {
					flag = chnode(first, second, cur);
				}
				cur = cur->right; continue;
			}
			//如果当前结点左孩子不为NULL，在左子树中找到其前驱
			pre = cur->left;
			while (pre->right != NULL && pre->right != cur) {
				pre = pre->right;
			}
			//如果前驱的右孩子为NULL，将其设为当前结点
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