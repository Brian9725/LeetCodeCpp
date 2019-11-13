#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	//visit[i][j]��ʾboard[i][j]�Ƿ񱻷���
	int visit[9][9];
	//rowNum[i][j]��ʾ��i���Ƿ������д����j
	int rowNum[9][10];
	//colNum[i][j]��ʾ��i���Ƿ������д����j
	int colNum[9][10];
	//boxNum[i][j]��ʾ��i���󷽸��Ƿ������д����j
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
		//���board[row][col]��û����������
		if (visit[row][col] == 0) {
			//���Խ�����i����board[row][col]
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
					//����Ѿ��õ������ֱ�ӷ���
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