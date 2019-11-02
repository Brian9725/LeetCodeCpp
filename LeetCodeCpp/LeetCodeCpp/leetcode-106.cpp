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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() == 0)
			return NULL;
		int len = postorder.size();
		TreeNode* res = new TreeNode(postorder[len - 1]);
		if (len == 1)
			return res;
		int idx = 0;
		//找出根节点在inorder中的位置
		for (idx = 0; idx < len; idx++) {
			if (inorder[idx] == postorder[len - 1])
				break;
		}
		//构造左右子树的inorder和postorder
		vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
		vector<int> leftPostorder(postorder.begin(), postorder.begin() + idx);
		vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());
		vector<int> rightPostorder(postorder.begin() + idx, postorder.end() - 1);
		res->left = buildTree(leftInorder, leftPostorder);
		res->right = buildTree(rightInorder, rightPostorder);
		return res;
	}
};