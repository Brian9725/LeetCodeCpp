#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//将nums[begin..end]做成一棵二叉搜索树
	TreeNode* buildTree(vector<int>& nums, int begin, int end) {
		if (begin == end) {
			TreeNode* node = new TreeNode(nums[begin]);
			return node;
		}
		int idx = begin + (end - begin) / 2;
		TreeNode* node = new TreeNode(nums[idx]);
		//如果idx左边还有元素，将其做成左子树
		if (begin < idx)
			node->left = buildTree(nums, begin, idx - 1);
		//如果idx右边还有元素，将其做成右子树
		if (idx < end)
			node->right = buildTree(nums, idx + 1, end);
		return node;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return NULL;
		TreeNode* root = buildTree(nums, 0, len - 1);
		return root;
	}
};