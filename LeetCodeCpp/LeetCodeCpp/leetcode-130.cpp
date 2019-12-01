#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	//��������߽��O
	void bfs(vector<vector<char>>& board, vector<vector<bool>>& visit, int x, int y) {
		queue<pair<int, int>> q;
		q.push(make_pair(x, y));
		visit[x][y] = true;
		while (!q.empty()) {
			pair<int, int> node = q.front(); q.pop();
			int tempX = node.first, tempY = node.second;
			//�����Ϸ����ַ�
			if (tempX - 1 >= 0 && board[tempX - 1][tempY] == 'O' && !visit[tempX - 1][tempY]) {
				visit[tempX - 1][tempY] = true;
				q.push(make_pair(tempX - 1, tempY));
			}
			//�����·����ַ�
			if (tempX + 1 < (int)board.size() && board[tempX + 1][tempY] == 'O' && !visit[tempX + 1][tempY]) {
				visit[tempX + 1][tempY] = true;
				q.push(make_pair(tempX + 1, tempY));
			}
			//�����󷽵��ַ�
			if (tempY - 1 >= 0 && board[tempX][tempY - 1] == 'O' && !visit[tempX][tempY - 1]) {
				visit[tempX][tempY - 1] = true;
				q.push(make_pair(tempX, tempY - 1));
			}
			//�����ҷ����ַ�
			if (tempY + 1 < (int)board[0].size() && board[tempX][tempY + 1] == 'O' && !visit[tempX][tempY + 1]) {
				visit[tempX][tempY + 1] = true;
				q.push(make_pair(tempX, tempY + 1));
			}
		}
	}
	
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0 || board[0].size() == 0) return;
		int row = board.size(), col = board[0].size();
		//visit[i][j]��ʾboard[i][j]�Ƿ�Ϊ�߽��O
		vector<vector<bool>> visit(row, vector<bool>(col, false));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				//���board[i][j]���Ǳ߽磬ֱ������
				if (!(i == 0 || i == row - 1 || j == 0 || j == col - 1)) continue;
				//����߽�����δ�����ʹ���O
				if (board[i][j] == 'O' && !visit[i][j]) {
					if (i == 3)
						int aaa = 1;
					bfs(board, visit, i, j);
				}
			}
		}
		//���Ǳ߽��Oȫ����ΪX
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == 'O' && !visit[i][j])
					board[i][j] = 'X';
			}
		}
	}
};