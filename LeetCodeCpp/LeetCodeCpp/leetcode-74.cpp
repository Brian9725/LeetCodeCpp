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
		//二分查找target所在的行
		while (low <= high) {
			mid = (low + high) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		//idx表示target可能在的行
		int idx = mid;
		if (matrix[mid][0] > target) {
			if (mid > 0)
				idx = mid - 1;
			else
				return false;
		}
		//在第mid行二分查找target
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