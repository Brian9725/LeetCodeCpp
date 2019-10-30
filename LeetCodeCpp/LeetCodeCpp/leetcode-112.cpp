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
	bool hasPathSum(TreeNode* root, int sum) {
		//����������ΪNULL���߼���֤��������hasPathSum�Ľ�㲻ΪNULL
		if (root == NULL)
			return false;
		if (root->left == NULL && root->right == NULL && root->val == sum)
			return true;
		if (root->left && hasPathSum(root->left, sum - root->val))
			return true;
		if (root->right && hasPathSum(root->right, sum - root->val))
			return true;
		return false;
	}
};