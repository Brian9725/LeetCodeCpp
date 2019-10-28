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
	void dfs(TreeNode* p, TreeNode* q, bool &flag) {
		if (!flag)
			return;
		if (p == NULL && q == NULL)
			return;
		else if ((p == NULL && q != NULL) || (p != NULL&&q == NULL)) {
			flag = false;
			return;
		}
		if (p->val != q->val) {
			flag = false;
			return;
		}
		dfs(p->left, q->left, flag);
		dfs(p->right, q->right, flag);
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		bool flag = true;
		dfs(p, q, flag);
		return flag;
	}
};