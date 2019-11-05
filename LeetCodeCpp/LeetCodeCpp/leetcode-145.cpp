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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> treeStack;
		//pre指向前一个被访问的结点
		TreeNode *temp = root, *pre = NULL;
		while (temp || !treeStack.empty()) {
			if (temp) {
				treeStack.push(temp);
				temp = temp->left;
			}
			else {
				temp = treeStack.top();
				//如果temp的右结点之前没有被访问过，访问其右子树
				if (temp->right && temp->right != pre) {
					temp = temp->right;
					treeStack.push(temp);
					temp = temp->left;
				}
				//如果temp的右结点是前一个被访问过的结点，此时应该访问temp
				else {
					temp = treeStack.top(); treeStack.pop();
					result.push_back(temp->val);
					pre = temp; temp = NULL;
				}
			}
		}
		return result;
	}

	/*递归算法
	void dfs(TreeNode* root, vector<int> &result) {
		//逻辑保证root不为NULL
		if (root->left)
			dfs(root->left, result);
		if (root->right)
			dfs(root->right, result);
		result.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		dfs(root, result);
		return result;
	}
	*/
};