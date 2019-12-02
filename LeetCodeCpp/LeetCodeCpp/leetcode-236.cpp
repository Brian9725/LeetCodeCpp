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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q) return root;
		//在root的左右子树中寻找p或q的最小公共祖先
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		//如果仅在其中的一棵子树中找到了p或q的祖先
		if (left != NULL && right == NULL) return left;
		if (left == NULL && right != NULL) return right;
		//如果两边都没有说明p和q不在以root为根的子树中
		if (left == NULL && right == NULL) return NULL;
		return root;
	}
};