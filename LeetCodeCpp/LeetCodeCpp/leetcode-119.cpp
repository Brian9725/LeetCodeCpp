#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1);
		result[0] = result[rowIndex] = 1;
		//计算第i行杨辉三角
		for (int i = 1; i <= rowIndex; i++) {
			//result已经保存了第i-1行杨辉三角，第i行是由第i-1行相邻的两数相加得到
			//因为中间的数的计算依赖于两边的数，所以不能先计算中间的数
			for (int j = i / 2; j >= 1; j--) {
				result[j] += result[j - 1];
				result[i - j] = result[j];
			}
			result[i] = 1;
		}
		return result;
	}
};