#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//������node���߾���node����һ���������ܵõ������ֵ������node->val��
	int dfs(TreeNode* node, int& maxRes) {
		//���node��Ҷ���
		if (node->left == NULL && node->right == NULL) {
			maxRes = max(maxRes, node->val);
			return node->val;
		}
		//�ֱ��ҳ�����node�������������������ܵõ������ֵ
		int leftVal = 0, rightVal = 0;
		if (node->left) 
			leftVal = dfs(node->left, maxRes);
		if (node->right)
			rightVal = dfs(node->right, maxRes);
		//ֻ����һ��������ֻ��������·����һ�루������һ�����õ���ֵС��0����������������node����ƴ�ӳ�һ������·�����ó���·����ֵ
		int tempRes = node->val;
		if (leftVal > 0)
			tempRes += leftVal;
		if (rightVal > 0)
			tempRes += rightVal;
		maxRes = max(maxRes, tempRes);
		//node->��ֻ�ܱ���һ��·����ֵ��������һ�����õ���ֵС��0�������������ֵ��С��0��ֻ�豣��node����
		node->val += max(max(0, leftVal), rightVal);
		return node->val;
	}

	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return 0;
		int result = INT_MIN;
		dfs(root, result);
		return result;
	}
};