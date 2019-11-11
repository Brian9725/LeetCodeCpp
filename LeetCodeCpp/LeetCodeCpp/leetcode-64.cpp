#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int lenR = grid.size(), lenC = grid[0].size();
		for (int i = 1; i < lenR; i++)
			grid[i][0] += grid[i - 1][0];
		for (int i = 1; i < lenC; i++)
			grid[0][i] += grid[0][i - 1];
		for (int i = 1; i < lenR; i++)
			for (int j = 1; j < lenC; j++)
				grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
		return grid[lenR - 1][lenC - 1];
	}
};