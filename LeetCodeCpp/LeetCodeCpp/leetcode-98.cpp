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
	//��������������鿴�Ƿ���һ������
	bool isValidBST(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return true;
		int pre = 0;
		bool isFirst = true;
		stack<TreeNode*> treeStack;
		TreeNode *temp = root;
		while (temp != NULL || !treeStack.empty()) {
			//�ҵ���ǰ���������ӽ�㣬�ý��Ϊ�Ե�ǰ���Ϊ���������ȷ��ʵĽ��
			while (temp != NULL) {
				treeStack.push(temp);
				temp = temp->left;
			}
			//temp�����������Ѿ�ȫ�����ʹ��ģ�����ֻ�����temp��temp��������
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