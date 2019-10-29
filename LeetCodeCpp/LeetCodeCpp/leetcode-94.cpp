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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> treeStack;
		TreeNode *temp = root;
		while (temp != NULL || !treeStack.empty()) {
			//找到当前结点的最左子结点，该结点为以当前结点为根的树最先访问的结点
			while (temp != NULL) {
				treeStack.push(temp);
				temp = temp->left;
			}
			//temp的左子树是已经全部访问过的，所以只需访问temp和temp的右子树
			if (!treeStack.empty()) {
				temp = treeStack.top(); treeStack.pop();
				result.push_back(temp->val);
				temp = temp->right;
			}
		}
		return result;
	}

	/*递归方法
	void dfs(TreeNode* root, vector<int> &result) {
		//逻辑保证root不为NULL
		if (root->left)
			dfs(root->left, result);
		result.push_back(root->val);
		if (root->right)
			dfs(root->right, result);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		dfs(root, result);
		return result;
	}
	*/
};