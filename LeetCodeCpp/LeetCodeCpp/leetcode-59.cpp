#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));
		int num = 1;
		for (int i = 0; i <= (n - 1) / 2; i++) {
			//设置第i行的值，外层循环保证第i行有效
			for (int j = i; j <= n - 1 - i; j++)
				result[i][j] = num++;
			//设置倒数第i列的值，倒数第i列和第i列不能相同，等号保证倒数第i列和第i列相同时优先将倒数第i列加入result
			if (n - 1 - i >= i) {
				for (int j = i + 1; j <= n - 2 - i; j++)
					result[j][n - 1 - i] = num++;
			}
			//设置倒数第i行的值，倒数第i行和第i行不能相同
			if (n - 1 - i > i) {
				for (int j = n - 1 - i; j >= i; j--)
					result[n - 1 - i][j] = num++;
			}
			//设置第i列的值，第i列和倒数第i列不能相同
			if (n - 1 - i > i) {
				for (int j = n - 2 - i; j >= i + 1; j--)
					result[j][i] = num++;
			}
		}
		return result;
	}
};