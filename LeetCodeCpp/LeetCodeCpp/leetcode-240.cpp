#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;
		int row = matrix.size(), col = matrix[0].size(), low = 0, high = row - 1, mid = 0, idx = 0;
		//二分查找target所在的行
		while (low <= high) {
			mid = (low + high) / 2;
			if (matrix[mid][0] == target)
				return true;
			else if (matrix[mid][0] > target) 
				high = mid - 1;
			else {
				low = mid + 1; idx = low;
			}
		}
		for (int i = 0; i < idx; ++i) {
			//在第mid行二分查找target
			low = 0, high = col - 1, mid = 0;
			while (low <= high) {
				mid = (low + high) / 2;
				if (matrix[i][mid] == target)
					return true;
				else if (matrix[i][mid] < target)
					low = mid + 1;
				else
					high = mid - 1;
			}
		}
		return false;
	}
};