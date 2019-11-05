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
	void dfs(int& result, int& tempRes, TreeNode* node) {
		if (node->left == NULL && node->right == NULL) {
			tempRes = tempRes * 10 + node->val;
			result += tempRes;
			tempRes /= 10;
			return;
		}
		tempRes = tempRes * 10 + node->val;
		if (node->left)
			dfs(result, tempRes, node->left);
		if (node->right)
			dfs(result, tempRes, node->right);
		tempRes /= 10;
	}

	int sumNumbers(TreeNode* root) {
		if (root == NULL)
			return 0;
		int result = 0, tempRes = 0;
		dfs(result, tempRes, root);
		return result;
	}
};