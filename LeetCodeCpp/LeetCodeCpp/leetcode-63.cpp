#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int lenRow = obstacleGrid.size();
		int lenCol = obstacleGrid[0].size();
		//ʹ��long long��ֹ�м������
		long long *result = new long long[lenCol];
		for (int i = 0; i < lenRow; i++) {
			//�����һ��ĳ�������ϰ�������·����е��·������Ϊ0
			if (obstacleGrid[i][0] == 1 || (i > 0 && result[0] == 0)) {
				result[0] = 0;
			}
			else {
				result[0] = 1;
			}
			for (int j = 1; j < lenCol; j++) {
				if (i == 0) {
					//�����һ��ĳ�������ϰ�������ҷ����е��·������Ϊ0
					if (obstacleGrid[0][j] == 1 || (j > 0 && result[j - 1] == 0)) {
						result[j] = 0;
					}
					else {
						result[j] = 1;
					}
					continue;
				}
				//��ĳ���·����Ϊ����������Ϸ����·������֮��
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