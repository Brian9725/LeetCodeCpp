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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		//ʹ��BFS��һ�����м�¼��㣬һ�����м�¼��Ӧ�ļ����ǵڼ���
		queue<TreeNode*> qNode;
		queue<int> qLv;
		qNode.push(root);
		qLv.push(0);
		vector<int> tempRes;
		int cur = 0;
		while (!qNode.empty()) {
			//�߼���֤ÿ��ȡ����tempNode��ΪNULL
			TreeNode* tempNode = qNode.front();
			int tempLv = qLv.front();
			qNode.pop();
			qLv.pop();
			if (tempLv != cur) {
				result.push_back(tempRes);
				tempRes.clear();
				tempRes.push_back(tempNode->val);
				cur = tempLv;
			}
			else {
				tempRes.push_back(tempNode->val);
			}
			//��tempNode��Ϊ�յ������ӽڵ����
			if (tempNode->left) {
				qNode.push(tempNode->left);
				qLv.push(cur + 1);
			}
			if (tempNode->right) {
				qNode.push(tempNode->right);
				qLv.push(cur + 1);
			}
		}
		//�����һ�����result
		result.push_back(tempRes);
		return result;
	}
};