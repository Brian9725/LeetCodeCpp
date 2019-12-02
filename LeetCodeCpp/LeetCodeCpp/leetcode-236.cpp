#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q) return root;
		//��root������������Ѱ��p��q����С��������
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		//����������е�һ���������ҵ���p��q������
		if (left != NULL && right == NULL) return left;
		if (left == NULL && right != NULL) return right;
		//������߶�û��˵��p��q������rootΪ����������
		if (left == NULL && right == NULL) return NULL;
		return root;
	}
};