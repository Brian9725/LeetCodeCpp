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
	int kthSmallest(TreeNode* root, int k) {
		int cur = 0;
		stack<TreeNode*> treeStack;
		TreeNode *temp = root;
		while (temp != NULL || !treeStack.empty()) {
			//ֻ��temp���������ӽ����ߵ�ǰ������ӵ������ӽ��ʱ��ΪNULL
			//�ҵ���ǰ���������ӽ�㣬�ý��Ϊ�Ե�ǰ���Ϊ���������ȷ��ʵĽ��
			while (temp != NULL) {
				treeStack.push(temp);
				temp = temp->left;
			}
			//temp�����������Ѿ�ȫ�����ʹ��ģ�����ֻ�����temp��temp��������
			if (!treeStack.empty()) {
				temp = treeStack.top(); treeStack.pop(); cur++;
				if (cur == k) return temp->val;
				temp = temp->right;
			}
		}
		return -1;
	}
};