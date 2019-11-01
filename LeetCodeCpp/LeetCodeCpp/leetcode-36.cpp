#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		//visit[i]��ʶһ�л�һ�л�һ���Ź����к�������i�ĸ���
		int visit[10] = { 0 };
		for (int i = 0; i < 9; i++) {
			//��ʼ��visit
			for (int visitIdx = 1; visitIdx <= 9; visitIdx++) 
				visit[visitIdx] = 0;
			//�жϵ�i���Ƿ�ÿ������ֻ����һ��
			for (int j = 0; j < 9; j++) 
				if (board[i][j] > '0' && board[i][j] <= '9') 
					visit[board[i][j] - 48]++;
			for (int visitIdx = 1; visitIdx <= 9; visitIdx++) {
				if (visit[visitIdx] > 1) 
					return false;
				//Ϊ�ж����Ƿ�����������ʼ��visit
				visit[visitIdx] = 0;
			}
			//�жϵ�i���Ƿ�ÿ������ֻ����һ��
			for (int j = 0; j < 9; j++) 
				if (board[j][i] > '0' && board[j][i] <= '9') 
					visit[board[j][i] - 48]++;
			for (int visitIdx = 1; visitIdx <= 9; visitIdx++) {
				if (visit[visitIdx] > 1) 
					return false;
				//Ϊ�´��жϳ�ʼ��visit
				visit[visitIdx] = 0;
			}
		}
		//�ж�ÿ���Ź����Ƿ���������
		//i��j��ʾ��i�е�j�еľŹ���
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				//tempi��tempj��ʾ�ھŹ����е�λ��
				for (int tempi = 0; tempi < 3; tempi++) 
					for (int tempj = 0; tempj < 3; tempj++) 
						if (board[3 * i + tempi][3 * j + tempj] > '0' && board[3 * i + tempi][3 * j + tempj] <= '9') 
							visit[board[3 * i + tempi][3 * j + tempj] - 48]++;
				for (int visitIdx = 1; visitIdx <= 9; visitIdx++) {
					if (visit[visitIdx] > 1) 
						return false;
					//Ϊ�´��жϳ�ʼ��visit
					visit[visitIdx] = 0;
				}
			}
		}
		return true;
	}
};