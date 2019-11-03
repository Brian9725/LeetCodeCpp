#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//判断Queen的位置是否合法，locQueen[i]表示第i行的Queen所在的位置
	bool isQueenValid(int* locQueen, int x) {
		for (int i = 0; i < x; i++)
			if (locQueen[x] == locQueen[i] || abs(x - i) == abs(locQueen[x] - locQueen[i])) 
				return false;
		return true;
	}

	void dfsQueen(int* locQueen, int& cnt, int i, int n) {
		//已经找到一种满足条件的放置方法
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
			//初始化locQueen
			for (int j = 0; j < n; j++) 
				locQueen[j] = -1;
			locQueen[0] = i;
			dfsQueen(locQueen, cnt, 1, n);
		}
		return cnt;
	}
};