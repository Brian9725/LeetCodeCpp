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
	void dfs(vector<vector<int>> &result, vector<int> &tempRes, TreeNode* node, int sum) {
		if (node->left == NULL && node->right == NULL && node->val == sum) {
			tempRes.push_back(node->val);
			result.push_back(tempRes);
			//记录完tempRes后需要将最后一个元素弹出，否则每找到一个答案，tempRes中便多一个元素
			tempRes.pop_back();
			return;
		}
		tempRes.push_back(node->val);
		if (node->left)
			dfs(result, tempRes, node->left, sum - node->val);
		if (node->right)
			dfs(result, tempRes, node->right, sum - node->val);
		tempRes.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		vector<int> tempRes;
		dfs(result, tempRes, root, sum);
		return result;
	}
};