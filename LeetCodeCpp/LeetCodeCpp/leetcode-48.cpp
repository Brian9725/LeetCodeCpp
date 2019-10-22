#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//����matrix[rIdx][cIdx]��matrix[cIdx][maxIdx-rIdx]��matrix[maxIdx-cIdx][rIdx]��matrix[maxIdx-rIdx][maxIdx-cIdx]�ĸ�����λ��
	void changePos(vector<vector<int>>& matrix, int rIdx, int cIdx, int maxIdx) {
		swap(matrix[rIdx][cIdx], matrix[maxIdx - rIdx][maxIdx - cIdx]);
		swap(matrix[rIdx][cIdx], matrix[maxIdx - cIdx][rIdx]);
		swap(matrix[cIdx][maxIdx - rIdx], matrix[maxIdx - rIdx][maxIdx - cIdx]);
	}

	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return;
		int rLen = matrix.size(), cLen = matrix[0].size();
		for (int i = 0; i <= rLen / 2; i++)
			for (int j = i; j <= cLen - 2 - i; j++)
				changePos(matrix, i, j, rLen - 1);
	}
};