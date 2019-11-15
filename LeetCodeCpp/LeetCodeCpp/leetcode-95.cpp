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
	vector<TreeNode*> buildTrees(int begin, int end) {
		vector<TreeNode*> result;
		if (begin > end)
			return result;
		if (begin == end) {
			TreeNode* node = new TreeNode(begin);
			result.push_back(node);
			return result;
		}
		//��iΪ������[begin,end]�����ɶ���������
		for (int i = begin; i <= end; i++) {
			vector<TreeNode*> left = buildTrees(begin, i - 1);
			vector<TreeNode*> right = buildTrees(i + 1, end);
			int lenLeft = left.size(), lenRight = right.size();
			//������Ϊ��
			if (lenLeft == 0) {
				for (int j = 0; j < lenRight; j++) {
					TreeNode* node = new TreeNode(i);
					node->right = right[j];
					result.push_back(node);
				}
				continue;
			}
			//������Ϊ��
			if (lenRight == 0) {
				for (int j = 0; j < lenLeft; j++) {
					TreeNode* node = new TreeNode(i);
					node->left = left[j];
					result.push_back(node);
				}
				continue;
			}
			//���������������Ϲ�����������������
			for (int j = 0; j < lenLeft; j++) {
				for (int k = 0; k < lenRight; k++) {
					TreeNode* node = new TreeNode(i);
					node->left = left[j];
					node->right = right[k];
					result.push_back(node);
				}
			}
		}
		return result;
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> result;
		if (n <= 0)
			return result;
		result = buildTrees(1, n);
		return result;
	}
};