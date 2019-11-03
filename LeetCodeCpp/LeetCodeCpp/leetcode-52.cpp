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

	void dfsQueen(int* locQueen, int& cnt, int i, int n) {
		//�Ѿ��ҵ�һ�����������ķ��÷���
		if (i == n) {
			cnt++; return;
		}
		for (int j = 0; j < n; j++) {
			locQueen[i] = j;
			if (isQueenValid(locQueen, i)) 
				dfsQueen(locQueen, cnt, i + 1, n);
			locQueen[i] = -1;
		}
	}

	int totalNQueens(int n) {
		int *locQueen = new int[n], cnt = 0;
		for (int i = 0; i < n; i++) {
			//��ʼ��locQueen
			for (int j = 0; j < n; j++) 
				locQueen[j] = -1;
			locQueen[0] = i;
			dfsQueen(locQueen, cnt, 1, n);
		}
		return cnt;
	}
};