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
			//只有temp到达最左子结点或者当前结点左孩子的最右子结点时才为NULL
			//找到当前结点的最左子结点，该结点为以当前结点为根的树最先访问的结点
			while (temp != NULL) {
				treeStack.push(temp);
				temp = temp->left;
			}
			//temp的左子树是已经全部访问过的，所以只需访问temp和temp的右子树
			if (!treeStack.empty()) {
				temp = treeStack.top(); treeStack.pop(); cur++;
				if (cur == k) return temp->val;
				temp = temp->right;
			}
		}
		return -1;
	}
};