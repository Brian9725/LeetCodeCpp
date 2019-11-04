#include<iostream>
#include<algorithm>
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
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		if (root->left == NULL && root->right == NULL) {
			root->val = 1;
			return true;
		}
		if (isBalanced(root->left) && isBalanced(root->right)) {
			int leftDep = (root->left == NULL) ? 0 : root->left->val;
			int rightDep = (root->right == NULL) ? 0 : root->right->val;
			if (abs(leftDep - rightDep) < 2) {
				root->val = max(leftDep, rightDep) + 1;
				return true;
			}
		}
		return false;
	}
};