#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	//visit[i][j]表示board[i][j]是否被访问
	int visit[9][9];
	//rowNum[i][j]表示第i行是否可以填写数字j
	int rowNum[9][10];
	//colNum[i][j]表示第i列是否可以填写数字j
	int colNum[9][10];
	//boxNum[i][j]表示第i个大方格是否可以填写数字j
	int boxNum[9][10];

	void init(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				rowNum[i][j] = 1;
				colNum[i][j] = 1;
				boxNum[i][j] = 1;
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					visit[i][j] = 0;
				else {
					visit[i][j] = 1;
					rowNum[i][board[i][j] - '0'] = 0;
					colNum[j][board[i][j] - '0'] = 0;
					boxNum[(i / 3) * 3 + j / 3][board[i][j] - '0'] = 0;
				}
			}
		}
	}

	void dfs(vector<vector<char>>& board, int row, int col, bool& end) {
		if (row == 9) {
			end = true; return;
		}
		//如果board[row][col]还没有填入数字
		if (visit[row][col] == 0) {
			//尝试将数字i填入board[row][col]
			for (int i = 1; i <= 9; i++) {
				if (rowNum[row][i] == 1 && colNum[col][i] == 1 && boxNum[(row / 3) * 3 + col / 3][i] == 1) {
					visit[row][col] = 1;
					//cout << "put(" << row << "," << col << "):" << i << endl;
					board[row][col] = (char)('0' + i);
					rowNum[row][i] = 0; colNum[col][i] = 0; boxNum[(row / 3) * 3 + col / 3][i] = 0;
					col++;
					if (col == 9) {
						row++; col = 0;
					}
					dfs(board, row, col, end);
					//如果已经得到结果，直接返回
					if (end) {
						return;
					}
					col--;
					if (col == -1) {
						row--; col = 8;
					}
					//cout << "del(" << row << "," << col << "):" << i << endl;
					rowNum[row][i] = 1; colNum[col][i] = 1; boxNum[(row / 3) * 3 + col / 3][i] = 1;
					board[row][col] = '.';
					visit[row][col] = 0;
				}
			}
		}
		else {
			col++;
			if (col == 9) {
				row++; col = 0;
			}
			dfs(board, row, col, end);
		}
	}

	void solveSudoku(vector<vector<char>>& board) {
		init(board);
		bool end = false;
		dfs(board, 0, 0, end);
	}
};