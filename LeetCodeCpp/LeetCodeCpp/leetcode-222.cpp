#include<iostream>
#include<algorithm>
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
	//计算以node为根的树的高度，时间复杂度O(logn)
	int countDepth(TreeNode* node) {
		int height = 0;
		while (node != NULL) {
			height++; node = node->left;
		}
		return height;
	}

	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		int res = 1;
		int leftDepth = countDepth(root->left), rightDepth = countDepth(root->right);
		//如果左右子树高度相同，则说明左子树已经是满二叉树
		if (leftDepth == rightDepth) {
			res += (1 << leftDepth) - 1;
			res += countNodes(root->right);
		}
		//如果左右子树高度不同，则说明右子树已经是满二叉树
		else {
			res += (1 << rightDepth) - 1;
			res += countNodes(root->left);
		}
		return res;
	}

	/*常规算法，所有树都适用
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*> treeQ;	treeQ.push(root);
		int res = 0;
		while (!treeQ.empty()) {
			TreeNode *temp = treeQ.front(); treeQ.pop(); res++;
			if (temp->left)
				treeQ.push(temp->left);
			if (temp->right)
				treeQ.push(temp->right);
		}
		return res;
	}
	*/
};