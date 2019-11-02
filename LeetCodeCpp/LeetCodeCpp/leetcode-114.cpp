#include<iostream>
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
	//相当于进行一次前序遍历
	void flatten(TreeNode* root) {
		if (root == NULL)
			return;
		stack<TreeNode*> nodeStack;
		nodeStack.push(root->right);
		nodeStack.push(root->left);
		TreeNode* temp = root;
		while (!nodeStack.empty()) {
			TreeNode* node = nodeStack.top(); nodeStack.pop();
			if (node) {
				temp->left = NULL;
				temp->right = node;
				temp = temp->right;
				nodeStack.push(node->right);
				nodeStack.push(node->left);
			}
		}
	}
};