#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//判断board[i][j]附近活细胞的数量
	int judge(vector<vector<int>>& board, int x, int y) {
		int res = 0;
		for (int i = x - 1; i <= x + 1; ++i) {
			if (i < 0 || i >= (int)board.size()) continue;
			for (int j = y - 1; j <= y + 1; ++j) {
				if (j < 0 || j >= (int)board[0].size()) continue;
				if (i == x && j == y) continue;
				if (board[i][j] == 1 || board[i][j] == 2) res++;
			}
		}
		return res;
	}

	//用-1暂时表示复活的死细胞，2表示死去的活细胞
	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() == 0 || board[0].size() == 0) return;
		int row = board.size(), col = board[0].size();
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				int num = judge(board, i, j);
				if (board[i][j] == 1 && (num < 2 || num > 3))
					board[i][j] = 2;
				if (board[i][j] == 0 && num == 3)
					board[i][j] = -1;
			}
		}
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == 2)
					board[i][j] = 0;
				if (board[i][j] == -1)
					board[i][j] = 1;
			}
		}
	}
};