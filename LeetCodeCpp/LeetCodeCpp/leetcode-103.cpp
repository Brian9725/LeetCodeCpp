#include<iostream>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> lStack;
		stack<TreeNode*> rStack;
		vector<int> tempRes;
		lStack.push(root);
		while (!lStack.empty() || !rStack.empty()) {
			//从左向右遍历，优先将左孩子入栈
			while (!lStack.empty()) {
				TreeNode* tempNode = lStack.top(); lStack.pop();
				tempRes.push_back(tempNode->val);
				if (tempNode->left)
					rStack.push(tempNode->left);
				if (tempNode->right)
					rStack.push(tempNode->right);
			}
			result.push_back(tempRes);
			tempRes.clear();
			//从右向左遍历，优先将右孩子入栈
			//加入if判断避免result最后加入一个空的tempRes
			if (!rStack.empty()) {
				while (!rStack.empty()) {
					TreeNode* p = rStack.top(); rStack.pop();
					tempRes.push_back(p->val);
					if (p->right)
						lStack.push(p->right);
					if (p->left)
						lStack.push(p->left);
				}
				result.push_back(tempRes);
				tempRes.clear();
			}
		}
		return result;
	}
};