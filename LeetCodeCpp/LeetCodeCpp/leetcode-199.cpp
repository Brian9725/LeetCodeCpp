#include<iostream>
#include<vector>
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
	//���������������ÿ������һ������ܱ�����
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		queue<TreeNode*> treeQ; queue<int> levelQ;
		int needLv = 0;
		treeQ.push(root); levelQ.push(0);
		while (!treeQ.empty()) {
			TreeNode *tempNode = treeQ.front(); treeQ.pop();
			int tempLv = levelQ.front(); levelQ.pop();
			if (tempLv == needLv) {
				result.push_back(tempNode->val);
				needLv++;
			}
			//�������ʱ���ȱ����������������ȵõ�ÿһ�����ұߵĽ��
			if (tempNode->right) {
				treeQ.push(tempNode->right);
				levelQ.push(tempLv + 1);
			}
			if (tempNode->left) {
				treeQ.push(tempNode->left);
				levelQ.push(tempLv + 1);
			}
		}
		return result;
	}
};