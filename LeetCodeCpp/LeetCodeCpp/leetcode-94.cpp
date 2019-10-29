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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
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
				result.push_back(temp->val);
				temp = temp->right;
			}
		}
		return result;
	}

	/*�ݹ鷽��
	void dfs(TreeNode* root, vector<int> &result) {
		//�߼���֤root��ΪNULL
		if (root->left)
			dfs(root->left, result);
		result.push_back(root->val);
		if (root->right)
			dfs(root->right, result);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		dfs(root, result);
		return result;
	}
	*/
};