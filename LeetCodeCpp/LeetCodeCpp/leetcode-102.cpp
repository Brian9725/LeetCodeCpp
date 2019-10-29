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
		//使用BFS，一个队列记录结点，一个队列记录对应的几点是第几层
		queue<TreeNode*> qNode;
		queue<int> qLv;
		qNode.push(root);
		qLv.push(0);
		vector<int> tempRes;
		int cur = 0;
		while (!qNode.empty()) {
			//逻辑保证每次取出的tempNode不为NULL
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
			//将tempNode不为空的左右子节点入队
			if (tempNode->left) {
				qNode.push(tempNode->left);
				qLv.push(cur + 1);
			}
			if (tempNode->right) {
				qNode.push(tempNode->right);
				qLv.push(cur + 1);
			}
		}
		//将最后一层加入result
		result.push_back(tempRes);
		return result;
	}
};