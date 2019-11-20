#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//������nodeΪ�������ĸ߶ȣ�ʱ�临�Ӷ�O(logn)
	int countDepth(TreeNode* node) {
		int height = 0;
		while (node != NULL) {
			height++; node = node->left;
		}
		return height;
	}

	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		int res = 1;
		int leftDepth = countDepth(root->left), rightDepth = countDepth(root->right);
		//������������߶���ͬ����˵���������Ѿ�����������
		if (leftDepth == rightDepth) {
			res += (1 << leftDepth) - 1;
			res += countNodes(root->right);
		}
		//������������߶Ȳ�ͬ����˵���������Ѿ�����������
		else {
			res += (1 << rightDepth) - 1;
			res += countNodes(root->left);
		}
		return res;
	}

	/*�����㷨��������������
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*> treeQ;	treeQ.push(root);
		int res = 0;
		while (!treeQ.empty()) {
			TreeNode *temp = treeQ.front(); treeQ.pop(); res++;
			if (temp->left)
				treeQ.push(temp->left);
			if (temp->right)
				treeQ.push(temp->right);
		}
		return res;
	}
	*/
};