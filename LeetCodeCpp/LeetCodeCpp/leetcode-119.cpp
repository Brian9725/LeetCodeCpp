#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1);
		result[0] = result[rowIndex] = 1;
		//�����i���������
		for (int i = 1; i <= rowIndex; i++) {
			//result�Ѿ������˵�i-1��������ǣ���i�����ɵ�i-1�����ڵ�������ӵõ�
			//��Ϊ�м�����ļ������������ߵ��������Բ����ȼ����м����
			for (int j = i / 2; j >= 1; j--) {
				result[j] += result[j - 1];
				result[i - j] = result[j];
			}
			result[i] = 1;
		}
		return result;
	}
};