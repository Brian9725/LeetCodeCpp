#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void dfs(vector<string>& result, string str, TreeNode* node) {
		if (node->left == NULL && node->right == NULL) {
			result.push_back(str);
			return;
		}
		if (node->left) 
			dfs(result, str + "->" + to_string(node->left->val), node->left);
		if(node->right)
			dfs(result, str + "->" + to_string(node->right->val), node->right);
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (root == NULL)
			return result;
		string str = to_string(root->val);
		dfs(result, str, root);
		return result;
	}
};