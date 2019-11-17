#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle.size();
		int  *result = new int[len];
		//自底向上动态规划
		for (int i = 0; i < len; i++)
			result[i] = triangle[len - 1][i];
		for (int i = len - 2; i >= 0; i--) {
			for (int j = triangle[i].size() - 1; j >= 0; j--) {
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
};