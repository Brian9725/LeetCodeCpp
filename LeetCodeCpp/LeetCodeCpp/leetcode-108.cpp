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
	//��nums[begin..end]����һ�ö���������
	TreeNode* buildTree(vector<int>& nums, int begin, int end) {
		if (begin == end) {
			TreeNode* node = new TreeNode(nums[begin]);
			return node;
		}
		int idx = begin + (end - begin) / 2;
		TreeNode* node = new TreeNode(nums[idx]);
		//���idx��߻���Ԫ�أ���������������
		if (begin < idx)
			node->left = buildTree(nums, begin, idx - 1);
		//���idx�ұ߻���Ԫ�أ���������������
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