#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		//仅根结点可能为空，逻辑保证除根结点外不可能有NULL结点传入minDepth
		if (root == NULL)
			return 0;
		//如果是叶结点
		if (root->left == NULL && root->right == NULL)
			return 1;
		//如果仅有一个孩子结点
		if (root->left == NULL)
			return minDepth(root->right) + 1;
		if (root->right == NULL)
			return minDepth(root->left) + 1;
		//如果有两个孩子结点
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};