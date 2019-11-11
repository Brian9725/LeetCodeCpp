#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//����1�к͵�1����Ϊ������л��߸����Ƿ���0�ı�ʶ��
	void setZeroes(vector<vector<int>>& matrix) {
		int lenR = matrix.size();
		if (lenR == 0)
			return;
		int lenC = matrix[0].size();
		//��ǰȷ����1�к͵�1���Ƿ����0
		bool existR = false, existC = false;
		for (int i = 0; i < lenC; i++) {
			if (matrix[0][i] == 0) {
				existR = true;
				break;
			}
		}
		for (int i = 0; i < lenR; i++) {
			if (matrix[i][0] == 0) {
				existC = true;
				break;
			}
		}
		//������0�����к����е���Ԫ����Ϊ0
		for (int i = 1; i < lenR; i++) {
			for (int j = 1; j < lenC; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		//����������Ϊ0����Ԫ����Ϊ0
		for (int i = 1; i < lenR; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < lenC; j++)
					matrix[i][j] = 0;
			}
		}
		//����������Ϊ0����Ԫ����Ϊ0
		for (int i = 1; i < lenC; i++) {
			if (matrix[0][i] == 0) {
				for (int j = 0; j < lenR; j++)
					matrix[j][i] = 0;
			}
		}
		//�����1�л��ߵ�1�г���0��������0
		if (existR) {
			for (int i = 0; i < lenC; i++)
				matrix[0][i] = 0;
		}
		if(existC){
			for (int i = 0; i < lenR; i++)
				matrix[i][0] = 0;
		}
	}
};