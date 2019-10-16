#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int lenRow = obstacleGrid.size();
		int lenCol = obstacleGrid[0].size();
		//使用long long防止中间结果溢出
		long long *result = new long long[lenCol];
		for (int i = 0; i < lenRow; i++) {
			//如果第一列某个点由障碍物，则到其下方所有点的路径数量为0
			if (obstacleGrid[i][0] == 1 || (i > 0 && result[0] == 0)) {
				result[0] = 0;
			}
			else {
				result[0] = 1;
			}
			for (int j = 1; j < lenCol; j++) {
				if (i == 0) {
					//如果第一行某个点由障碍物，则到其右方所有点的路径数量为0
					if (obstacleGrid[0][j] == 1 || (j > 0 && result[j - 1] == 0)) {
						result[j] = 0;
					}
					else {
						result[j] = 1;
					}
					continue;
				}
				//到某点的路径数为到期左侧点和上方点的路径数量之和
				if (obstacleGrid[i][j] == 0) {
					result[j] += result[j - 1];
				}
				else {
					result[j] = 0;
				}
			}
		}
		return result[lenCol - 1];
	}
};