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
			//�������ұ��������Ƚ�������ջ
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
			//����������������Ƚ��Һ�����ջ
			//����if�жϱ���result������һ���յ�tempRes
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