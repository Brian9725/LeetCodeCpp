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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> treeStack;
		//preָ��ǰһ�������ʵĽ��
		TreeNode *temp = root, *pre = NULL;
		while (temp || !treeStack.empty()) {
			if (temp) {
				treeStack.push(temp);
				temp = temp->left;
			}
			else {
				temp = treeStack.top();
				//���temp���ҽ��֮ǰû�б����ʹ���������������
				if (temp->right && temp->right != pre) {
					temp = temp->right;
					treeStack.push(temp);
					temp = temp->left;
				}
				//���temp���ҽ����ǰһ�������ʹ��Ľ�㣬��ʱӦ�÷���temp
				else {
					temp = treeStack.top(); treeStack.pop();
					result.push_back(temp->val);
					pre = temp; temp = NULL;
				}
			}
		}
		return result;
	}

	/*�ݹ��㷨
	void dfs(TreeNode* root, vector<int> &result) {
		//�߼���֤root��ΪNULL
		if (root->left)
			dfs(root->left, result);
		if (root->right)
			dfs(root->right, result);
		result.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		dfs(root, result);
		return result;
	}
	*/
};