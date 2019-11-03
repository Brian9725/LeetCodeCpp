#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//�ж�Queen��λ���Ƿ�Ϸ���locQueen[i]��ʾ��i�е�Queen���ڵ�λ��
	bool isQueenValid(int* locQueen, int x) {
		for (int i = 0; i < x; i++)
			if (locQueen[x] == locQueen[i] || abs(x - i) == abs(locQueen[x] - locQueen[i])) 
				return false;
		return true;
	}

	void dfsQueen(vector<vector<string>>& resultQueen, int* locQueen, int i, int n) {
		if (i == n) {
			vector<string> strs;
			//�Ѿ��ҵ�һ�����������ķ��÷���������a��locQueen[a]��λ������ΪQ������Ϊ.
			for (int a = 0; a < n; a++) {
				string str = "";
				for (int b = 0; b < n; b++) 
					str += (b == locQueen[a]) ? "Q" : ".";
				strs.push_back(str);
			}
			resultQueen.push_back(strs);
			return;
		}
		for (int j = 0; j < n; j++) {
			locQueen[i] = j;
			if (isQueenValid(locQueen, i)) 
				dfsQueen(resultQueen, locQueen, i + 1, n);
			locQueen[i] = -1;
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		int *locQueen = new int[n];
		vector<vector<string>> resultQueen;
		for (int i = 0; i < n; i++) {
			//��ʼ��locQueen
			for (int j = 0; j < n; j++) 
				locQueen[j] = -1;
			locQueen[0] = i;
			dfsQueen(resultQueen, locQueen, 1, n);
		}
		return resultQueen;
	}
};