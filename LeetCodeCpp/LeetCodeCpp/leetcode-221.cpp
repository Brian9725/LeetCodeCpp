#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		int row = matrix.size(), col = matrix[0].size(), res = 0;
		//dp[i][j]表示以matrix[i][j]为右下角的正方形面积
		vector<vector<int>> dp(row, vector<int>(col, 0));
		//初始化dp
		for (int i = 0; i < row; ++i) {
			if (matrix[i][0] == '1') {
				dp[i][0] = 1; res = 1;
			}
		}
		for (int i = 1; i < col; ++i) {
			if (matrix[0][i] == '1') {
				dp[0][i] = 1; res = 1;
			}
		}
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				if (matrix[i][j] == '0') continue;
				if (dp[i - 1][j] == 0 || dp[i][j - 1] == 0) {
					dp[i][j] = 1; res = max(res, 1);
					continue;
				}
				int width = min(sqrt(dp[i - 1][j]), sqrt(dp[i][j - 1]));
				if (matrix[i - width][j - width] == '1')
					dp[i][j] = (width + 1)*(width + 1);
				else
					dp[i][j] = width*width;
				res = max(res, dp[i][j]);
			}
		}
		return res;
	}
};