#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rLen = matrix.size();
		if (rLen == 0)
			return false;
		int cLen = matrix[0].size();
		if (cLen == 0)
			return false;
		int low = 0, high = rLen - 1, mid = 0;
		//���ֲ���target���ڵ���
		while (low <= high) {
			mid = (low + high) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		//idx��ʾtarget�����ڵ���
		int idx = mid;
		if (matrix[mid][0] > target) {
			if (mid > 0)
				idx = mid - 1;
			else
				return false;
		}
		//�ڵ�mid�ж��ֲ���target
		low = 0, high = cLen - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (matrix[idx][mid] == target)
				return true;
			else if (matrix[idx][mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return false;
	}
};