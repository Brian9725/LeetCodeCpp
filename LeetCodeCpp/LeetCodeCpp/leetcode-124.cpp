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
	//将经过node或者经过node和其一个子树所能得到的最大值保存在node->val中
	int dfs(TreeNode* node, int& maxRes) {
		//如果node是叶结点
		if (node->left == NULL && node->right == NULL) {
			maxRes = max(maxRes, node->val);
			return node->val;
		}
		//分别找出经过node的左子树和右子树所能得到的最大值
		int leftVal = 0, rightVal = 0;
		if (node->left) 
			leftVal = dfs(node->left, maxRes);
		if (node->right)
			rightVal = dfs(node->right, maxRes);
		//只经过一条子树，只能算完整路径的一半（除非另一子树得到的值小于0），将左右子树和node本身拼接成一条完整路径，得出该路径的值
		int tempRes = node->val;
		if (leftVal > 0)
			tempRes += leftVal;
		if (rightVal > 0)
			tempRes += rightVal;
		maxRes = max(maxRes, tempRes);
		//node->中只能保存一半路径的值，除非另一子树得到的值小于0；如果两个子树值都小于0，只需保存node本身
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