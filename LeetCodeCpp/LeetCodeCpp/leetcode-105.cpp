#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return NULL;
		TreeNode* res = new TreeNode(preorder[0]);
		if (preorder.size() == 1) 
			return res;
		int idx = 0, len = preorder.size();
		//找出根节点在inorder中的位置
		for (idx = 0; idx < len; idx++) {
			if (inorder[idx] == preorder[0])
				break;
		}
		//构造左右子树的preorder和inorder
		vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + idx + 1);
		vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
		vector<int> rightPreorder(preorder.begin() + idx + 1, preorder.end());
		vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());
		res->left = buildTree(leftPreorder, leftInorder);
		res->right = buildTree(rightPreorder, rightInorder);
		return res;
	}
};