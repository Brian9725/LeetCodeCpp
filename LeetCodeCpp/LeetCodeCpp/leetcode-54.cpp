#include<vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.size() == 0)
			return result;
		int rLen = matrix.size(), cLen = matrix[0].size();
		for (int i = 0; i <= (rLen - 1) / 2; i++) {
			//将第i行加入result，外层循环保证第i行有效
			for (int j = i; j <= cLen - 1 - i; j++)
				result.push_back(matrix[i][j]);
			//将倒数第i列加入result，倒数第i列和第i列不能相同，等号保证倒数第i列和第i列相同时优先将倒数第i列加入result
			if (cLen - 1 - i >= i) {
				for (int j = i + 1; j <= rLen - 2 - i; j++)
					result.push_back(matrix[j][cLen - 1 - i]);
			}
			//将倒数第i行加入result，倒数第i行和第i行不能相同
			if (rLen - 1 - i > i) {
				for (int j = cLen - 1 - i; j >= i; j--)
					result.push_back(matrix[rLen - 1 - i][j]);
			}
			//将第i列加入result，第i列和倒数第i列不能相同
			if (cLen - 1 - i > i) {
				for (int j = rLen - 2 - i; j >= i + 1; j--)
					result.push_back(matrix[j][i]);
			}
		}
		return result;
	}
};