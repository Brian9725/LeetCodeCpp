#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<char>>& board, vector<vector<int>>& visit, int idx, string word, int row, int col, bool& flag) {
		if (flag)
			return;
		if (idx == word.size()) {
			flag = true;
			return;
		}
		//检查当前位置上方一个字符
		if (row > 0 && visit[row - 1][col] == 0 && board[row - 1][col] == word[idx]) {
			visit[row - 1][col] = 1;
			dfs(board, visit, idx + 1, word, row - 1, col, flag);
			visit[row - 1][col] = 0;
		}
		//检查当前位置下方一个字符
		if (row < board.size() - 1 && visit[row + 1][col] == 0 && board[row + 1][col] == word[idx]) {
			visit[row + 1][col] = 1;
			dfs(board, visit, idx + 1, word, row + 1, col, flag);
			visit[row + 1][col] = 0;
		}
		//检查当前位置左方一个字符
		if (col > 0 && visit[row][col - 1] == 0 && board[row][col - 1] == word[idx]) {
			visit[row][col - 1] = 1;
			dfs(board, visit, idx + 1, word, row, col - 1, flag);
			visit[row][col - 1] = 0;
		}
		//检查当前位置右方一个字符
		if (col < board[0].size() - 1 && visit[row][col + 1] == 0 && board[row][col + 1] == word[idx]) {
			visit[row][col + 1] = 1;
			dfs(board, visit, idx + 1, word, row, col + 1, flag);
			visit[row][col + 1] = 0;
		}
	}

	bool exist(vector<vector<char>>& board, string word) {
		int rLen = board.size();
		if (rLen == 0) return false;
		int cLen = board[0].size();
		if (cLen == 0) return false;
		vector<vector<int>> visit(rLen, vector<int>(cLen, 0));
		bool flag = false;
		for (int i = 0; i < rLen; i++) {
			for (int j = 0; j < cLen; j++) {
				flag = false;
				if (board[i][j] == word[0]) {
					visit[i][j] = 1;
					dfs(board, visit, 1, word, i, j, flag);
					visit[i][j] = 0;
					if (flag)
						return true;
				}
			}
		}
		return false;
	}
};