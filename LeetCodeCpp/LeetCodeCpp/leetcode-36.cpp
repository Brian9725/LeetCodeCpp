#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//visit[i]标识一行或一列或一个九宫格中含有数字i的个数
		int visit[10] = { 0 };
		for (int i = 0; i < 9; i++) {
			//初始化visit
			for (int visitIdx = 1; visitIdx <= 9; visitIdx++) 
				visit[visitIdx] = 0;
			//判断第i行是否每个数字只出现一次
			for (int j = 0; j < 9; j++) 
				if (board[i][j] > '0' && board[i][j] <= '9') 
					visit[board[i][j] - 48]++;
			for (int visitIdx = 1; visitIdx <= 9; visitIdx++) {
				if (visit[visitIdx] > 1) 
					return false;
				//为判断列是否满足条件初始化visit
				visit[visitIdx] = 0;
			}
			//判断第i列是否每个数字只出现一次
			for (int j = 0; j < 9; j++) 
				if (board[j][i] > '0' && board[j][i] <= '9') 
					visit[board[j][i] - 48]++;
			for (int visitIdx = 1; visitIdx <= 9; visitIdx++) {
				if (visit[visitIdx] > 1) 
					return false;
				//为下次判断初始化visit
				visit[visitIdx] = 0;
			}
		}
		//判断每个九宫格是否满足条件
		//i和j表示第i行第j列的九宫格
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				//tempi和tempj表示在九宫格中的位置
				for (int tempi = 0; tempi < 3; tempi++) 
					for (int tempj = 0; tempj < 3; tempj++) 
						if (board[3 * i + tempi][3 * j + tempj] > '0' && board[3 * i + tempi][3 * j + tempj] <= '9') 
							visit[board[3 * i + tempi][3 * j + tempj] - 48]++;
				for (int visitIdx = 1; visitIdx <= 9; visitIdx++) {
					if (visit[visitIdx] > 1) 
						return false;
					//为下次判断初始化visit
					visit[visitIdx] = 0;
				}
			}
		}
		return true;
	}
};