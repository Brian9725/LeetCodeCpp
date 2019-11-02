#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		queue<TreeNode*> qNode;
		qNode.push(root->left); qNode.push(root->right);
		while (!qNode.empty()) {
			TreeNode* node1 = qNode.front(); qNode.pop();
			TreeNode* node2 = qNode.front(); qNode.pop();
			if (node1 == NULL && node2 == NULL)
				continue;
			if (node1 == NULL || node2 == NULL)
				return false;
			if (node1->val != node2->val)
				return false;
			else {
				qNode.push(node1->left);
				qNode.push(node2->right);
				qNode.push(node2->left);
				qNode.push(node1->right);
			}
		}
		return true;
	}

	/*
	bool dfs(TreeNode* node1, TreeNode* node2) {
		if (node1 == NULL && node2 == NULL)
			return true;
		if (node1 == NULL || node2 == NULL)
			return false;
		return (node1->val == node2->val) && dfs(node1->left, node2->right) && dfs(node2->left, node1->right);
	}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		if (root->left == NULL && root->right == NULL)
			return true;
		if (root->left == NULL || root->right == NULL)
			return false;
		return dfs(root->left, root->right);
	}
	*/
};