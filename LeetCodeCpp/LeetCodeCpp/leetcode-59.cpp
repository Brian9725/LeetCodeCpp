#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));
		int num = 1;
		for (int i = 0; i <= (n - 1) / 2; i++) {
			//���õ�i�е�ֵ�����ѭ����֤��i����Ч
			for (int j = i; j <= n - 1 - i; j++)
				result[i][j] = num++;
			//���õ�����i�е�ֵ��������i�к͵�i�в�����ͬ���Ⱥű�֤������i�к͵�i����ͬʱ���Ƚ�������i�м���result
			if (n - 1 - i >= i) {
				for (int j = i + 1; j <= n - 2 - i; j++)
					result[j][n - 1 - i] = num++;
			}
			//���õ�����i�е�ֵ��������i�к͵�i�в�����ͬ
			if (n - 1 - i > i) {
				for (int j = n - 1 - i; j >= i; j--)
					result[n - 1 - i][j] = num++;
			}
			//���õ�i�е�ֵ����i�к͵�����i�в�����ͬ
			if (n - 1 - i > i) {
				for (int j = n - 2 - i; j >= i + 1; j--)
					result[j][i] = num++;
			}
		}
		return result;
	}
};