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
	//层序遍历二叉树，每层的最后一个结点能被看到
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
			//层序遍历时优先遍历右子树，可以先得到每一层最右边的结点
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