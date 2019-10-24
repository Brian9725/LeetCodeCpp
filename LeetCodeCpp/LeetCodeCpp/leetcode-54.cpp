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
			//����i�м���result�����ѭ����֤��i����Ч
			for (int j = i; j <= cLen - 1 - i; j++)
				result.push_back(matrix[i][j]);
			//��������i�м���result��������i�к͵�i�в�����ͬ���Ⱥű�֤������i�к͵�i����ͬʱ���Ƚ�������i�м���result
			if (cLen - 1 - i >= i) {
				for (int j = i + 1; j <= rLen - 2 - i; j++)
					result.push_back(matrix[j][cLen - 1 - i]);
			}
			//��������i�м���result��������i�к͵�i�в�����ͬ
			if (rLen - 1 - i > i) {
				for (int j = cLen - 1 - i; j >= i; j--)
					result.push_back(matrix[rLen - 1 - i][j]);
			}
			//����i�м���result����i�к͵�����i�в�����ͬ
			if (cLen - 1 - i > i) {
				for (int j = rLen - 2 - i; j >= i + 1; j--)
					result.push_back(matrix[j][i]);
			}
		}
		return result;
	}
};