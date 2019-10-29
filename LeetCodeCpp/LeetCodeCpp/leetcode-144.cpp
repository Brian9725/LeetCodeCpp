#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> treeStack;
		treeStack.push(root);
		while (!treeStack.empty()) {
			TreeNode *temp = treeStack.top(); treeStack.pop();
			result.push_back(temp->val);
			//先将右孩子入栈保证左孩子先出栈被访问
			if (temp->right)
				treeStack.push(temp->right);
			if (temp->left)
				treeStack.push(temp->left);
		}
		return result;
	}

	/*递归方法
	void dfs(TreeNode* root, vector<int> &result) {
		//逻辑保证root不为NULL
		result.push_back(root->val);
		if (root->left)
			dfs(root->left, result);
		if (root->right)
			dfs(root->right, result);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		dfs(root, result);
		return result;
	}
	*/
};