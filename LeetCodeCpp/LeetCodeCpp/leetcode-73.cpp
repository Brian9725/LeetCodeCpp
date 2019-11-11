#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//将第1行和第1列作为保存该行或者该列是否有0的标识符
	void setZeroes(vector<vector<int>>& matrix) {
		int lenR = matrix.size();
		if (lenR == 0)
			return;
		int lenC = matrix[0].size();
		//提前确定第1行和第1列是否出现0
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
		//将出现0的那行和那列的首元素置为0
		for (int i = 1; i < lenR; i++) {
			for (int j = 1; j < lenC; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		//将所有行首为0的行元素置为0
		for (int i = 1; i < lenR; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < lenC; j++)
					matrix[i][j] = 0;
			}
		}
		//将所有列首为0的列元素置为0
		for (int i = 1; i < lenC; i++) {
			if (matrix[0][i] == 0) {
				for (int j = 0; j < lenR; j++)
					matrix[j][i] = 0;
			}
		}
		//如果第1行或者第1列出现0，将其置0
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