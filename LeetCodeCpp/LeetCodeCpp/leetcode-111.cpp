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
	int minDepth(TreeNode* root) {
		//����������Ϊ�գ��߼���֤��������ⲻ������NULL��㴫��minDepth
		if (root == NULL)
			return 0;
		//�����Ҷ���
		if (root->left == NULL && root->right == NULL)
			return 1;
		//�������һ�����ӽ��
		if (root->left == NULL)
			return minDepth(root->right) + 1;
		if (root->right == NULL)
			return minDepth(root->left) + 1;
		//������������ӽ��
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};