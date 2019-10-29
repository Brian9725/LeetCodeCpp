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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		stack<TreeNode*> treeStack;
		treeStack.push(root);
		while (!treeStack.empty()) {
			TreeNode *temp = treeStack.top(); treeStack.pop();
			result.push_back(temp->val);
			//�Ƚ��Һ�����ջ��֤�����ȳ�ջ������
			if (temp->right)
				treeStack.push(temp->right);
			if (temp->left)
				treeStack.push(temp->left);
		}
		return result;
	}

	/*�ݹ鷽��
	void dfs(TreeNode* root, vector<int> &result) {
		//�߼���֤root��ΪNULL
		result.push_back(root->val);
		if (root->left)
			dfs(root->left, result);
		if (root->right)
			dfs(root->right, result);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		dfs(root, result);
		return result;
	}
	*/
};