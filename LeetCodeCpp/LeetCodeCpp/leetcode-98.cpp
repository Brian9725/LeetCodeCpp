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
	//中序遍历整棵树查看是否是一个升序
	bool isValidBST(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return true;
		int pre = 0;
		bool isFirst = true;
		stack<TreeNode*> treeStack;
		TreeNode *temp = root;
		while (temp != NULL || !treeStack.empty()) {
			//找到当前结点的最左子结点，该结点为以当前结点为根的树最先访问的结点
			while (temp != NULL) {
				treeStack.push(temp);
				temp = temp->left;
			}
			//temp的左子树是已经全部访问过的，所以只需访问temp和temp的右子树
			if (!treeStack.empty()) {
				temp = treeStack.top(); treeStack.pop();
				if (isFirst) {
					isFirst = false;
					pre = temp->val;
					temp = temp->right;
					continue;
				}
				if (temp->val <= pre)
					return false;
				else 
					pre = temp->val;
				temp = temp->right;
			}
		}
		return true;
	}
};